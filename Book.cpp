#include "Book.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

Book::Book() {
	const string FileName = "LibBase.csv";
	ifstream in(FileName);
	string line;
	if (!in) {
		cout << "Library Data file is damaged" << endl;
	}
	else {
		while (getline(in, line)) {
			istringstream read(line);
			string taken;
			vector <string> temp;
			BookData tempdata;
			while (getline(read, taken, ',')) {
				temp.push_back(taken);
			}
			tempdata.Name = temp[1];
			tempdata.author = temp[2];
			tempdata.InStore = stoi(temp[3]);
			tempdata.ToBeReturn = stoi(temp[4]);
			BookInfor.insert(make_pair(temp[0], tempdata));
		}
	}
}

Book::~Book() {
}

void Book::ShowMenu() {
	system("cls");
	cout << "=======================Book Information=================" << endl;
	cout << setw(20) << "1.Search Book" << endl;
	cout << setw(20) << "2.Borrow Book" << endl;
	cout << setw(20) << "3.Return Book" << endl;
	cout << setw(20) << "4.Cancel" << endl;
	cout << endl;
}

bool Book::AddBook() {
	cout << setw(20) << "Add Book selected" << endl;
	cin >> SeriesID;
	BookData tempdata;
	while (true) {
		if (BookInfor.count(SeriesID) != 0) {
			cout << "This book has already exist" << endl;
			cout << "Please enter another boook (enter N/n to cancel): ";
			cin >> SeriesID;
		}
		if (SeriesID == "N" || SeriesID == "n") {
			cout << "Cancel selected" << endl;
			return 0;
		}
		else break;
	}
	cout << "Enter Book Name: ";
	cin >> tempdata.Name;
	cout << "Enter Auhthor name: ";
	cin >> tempdata.author;
	cout << "Number of Book purchased: ";
	cin >> tempdata.InStore;
	tempdata.ToBeReturn = 0;

	ofstream out("LibBase.csv", ios::app);
	out << "\n" << SeriesID << "," << tempdata.Name << "," << tempdata.author << ","
		<< tempdata.InStore << "," << tempdata.ToBeReturn;
	out.close();
	return 1;
}

bool Book::SearchBook() {
	cout << "please enter Book's seriesID: ";
	cin >> SeriesID;
	while (true) {
		if (BookInfor.count(SeriesID) == 0) {
			cout << "No book has been found please enter another one" << endl;
			cout << "or enter N or n to cancel" << endl;
			cin >> SeriesID;
		}
		else if (SeriesID == "n" || SeriesID == "N") {
			cout << "cancel selected";
			return 0;
		}
		else break;
	}
	cout << "Book Name --- Book Author --- Number in Store --- ToBe Return" << endl;
	cout << BookInfor.at(SeriesID).Name <<" " << BookInfor.at(SeriesID).author << " "
		<< BookInfor.at(SeriesID).InStore << " " << BookInfor.at(SeriesID).ToBeReturn << endl;
	

	cout << "Enter Y/y if you want to borrow:";
	string command;
	cin >> command;
	if (command == "Y" || command == "y") {
		Borrow(SeriesID);
	}
	return 1;
}

bool Book::Borrow(string SeriesID) {
	while (true) {
		if (BookInfor.at(SeriesID).InStore > 0) {
			--BookInfor.at(SeriesID).InStore;
			++BookInfor.at(SeriesID).ToBeReturn;
			return 1;
		}
		else {
			cout << "Curently there is no book left" << endl;
			cout << "Borrow another book? or enter N/n to cancel: ";
			cin >> SeriesID;
			if (SeriesID == "N" || SeriesID == "n") {
				Borrow(SeriesID);
			}
			else return 0;
		}
	}
}

bool Book::Borrow() {
	cout << "please enter Book's seriesID: ";
	cin >> SeriesID;
	while (true) {
		if (BookInfor.count(SeriesID) == 0) {
			cout << "No book has been found please enter another one" << endl;
			cout << "or enter N or n to cancel" << endl;
			cin >> SeriesID;
		}
		if (SeriesID == "n" || SeriesID == "N") {
			cout << "cancel selected";
			return 0;
		}
	}
	if (BookInfor.at(SeriesID).InStore == 0) {
		cout << "Curently there is no book left" << endl;
		cout << "Borrow another book? or enter N/n to cancel: ";
		cin >> SeriesID;
		Borrow(SeriesID);
	}
	else {
		--BookInfor.at(SeriesID).InStore;
		++BookInfor.at(SeriesID).ToBeReturn;
	}
	return 1;
}

bool Book::Return() {
	cout << "enter book's seriesID: ";
	cin >> SeriesID;
	while (true) {
		if (BookInfor.count(SeriesID) != 0) {
			cout << "un-correct seriesID, please re-enter your seriesID: ";
			cout << "(enter N/n to cancel) ";
			cin >> SeriesID;
		}
		if (SeriesID == "N" || SeriesID == "n") {
			return 0;
		}
		else break;
	}
	++BookInfor.at(SeriesID).InStore;
	--BookInfor.at(SeriesID).ToBeReturn;
	return 1;
}

void Book::Readbook() {
	unordered_map<string, BookData>::iterator iter = BookInfor.begin();
	for (iter; iter != BookInfor.end(); ++iter) {
		
		cout << (*iter).first << " " << (*iter).second.Name << " " << (*iter).second.InStore << endl;
	}
}
