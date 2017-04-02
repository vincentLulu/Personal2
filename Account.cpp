#include "Account.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

Account::Account() {
}

Account::Account(const string filename) {
	string InFileName = filename + ".csv";
	ifstream infile(InFileName);
	string line;
	while (getline(infile, line)) {
		istringstream in(line);
		string taken;
		data tempdata;
		vector<string> temp;
		while (getline(in, taken, ',')) {
			temp.push_back(taken);
		}
		tempdata.Admin = stoi(temp[1]);
		tempdata.UserName = temp[2];
		tempdata.Password = temp[3];
		tempdata.RegistrationDate = temp[4];
		tempdata.FeeToPay = stod(temp[5]);
		UserInfor.insert(make_pair(temp[0], tempdata));
	}
}

Account::~Account() {
}

bool Account::Registrator() {
	string userID;
	cout << "please enter your userID: ";
	cin >> userID;
	while (true) {
		if (UserInfor.count(userID)) {
			cout << "A user has already be regiestered"<< endl;
			cout << "please re-enter your userID(or enter N/n to cancel" 
				<< " registration): ";
			cin >> userID;
		}
		else if (userID == "N" || userID == "n") {
			cout << "Registration has been cancelled!" << endl;
			return 0;
		}
		else break;
	}
	data temp;
	string password, username, date;
	temp.Admin = 0;
	cout << "please enter your password: ";
	cin >> password;
	temp.Password = password;
	cout << "please enter your name: ";
	cin >> username;
	temp.UserName = username;
	time_t t = time(0);
	tm* mytime = localtime(&t);
	date = to_string(mytime->tm_mday) + "/" + to_string(mytime->tm_mon + 1) + "/" + to_string(mytime->tm_year + 1900);
	temp.RegistrationDate = date;
	temp.FeeToPay = 0.0;
	UserInfor.insert(make_pair(userID, temp));

	ofstream out("data.csv", ios_base::app);
	out << "\n" << userID << "," << temp.Admin << "," << username << "," << password << "," << date << ","  << temp.FeeToPay;
	return 1;
}

bool Account::WriteOff() {
	string userID;
	cout << "please enter your userID: ";
	cin >> userID;
	while (true) {
		if (UserInfor.at(userID).Admin == 1) {
			cout << "cannot delete a admin account" << endl;
			return 0;
		}
		else if (!UserInfor.count(userID)) {
			cout << "No user is found" << endl;
			cout << "please re-enter userID( or enter N/n to cancel this action): ";
			cin >> userID;
		}
		else if (userID == "N" || userID == "n") {
			cout << "action is cancelled" << endl;
			return 0;
		}
		else break;
	}
	UserInfor.erase(userID);
	return 1;
}

int Account::Login(const string id, const string password) {
	if (id == "N" || id == "n" || password == "N" || password == "n") {
		return -2;
	}
	else if (UserInfor.count(id) == 0) {
		return -1;
	}
	else if (stoi(UserInfor.at(id).Password) != stoi(password)){
		return -1;
	}
	else {
		return UserInfor.at(id).Admin;
	}
}


void Account::ShowMenu() {
	system("cls");
	cout << "=======================welcome=================" << endl;
	cout << "1.Registration" << endl;
	cout << "2.WriteOff" << endl;
	cout << "3.Login" << endl;
	cout << "4.Cancel" << endl;
	cout << endl;
}


void Account::Readuser() {
	unordered_map<string, data>::iterator iter = UserInfor.begin();
	for (iter; iter != UserInfor.end(); ++iter) {
		cout  << (*iter).first << " " << (*iter).second.UserName << " " << (*iter).second.RegistrationDate;
	}
}
