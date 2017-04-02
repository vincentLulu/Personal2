#include "Admin.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Admin::Admin() :Book() {
}

Admin::~Admin() {
}

void Admin::ShowMenu() {
	system("cls");
	cout << "=======================Book Information=================" << endl;
	cout << setw(20) << "1.Addbook" << endl;
	cout << setw(20) << "2.Search Book" << endl;
	cout << setw(20) << "3.Borrow Book" << endl;
	cout << setw(20) << "4.Return Book" << endl;
	cout << setw(20) << "5.Cancel" << endl;
	cout << endl;
}

bool Admin::AddBook() {
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