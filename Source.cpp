#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "Account.h"
#include "Book.h"
#include "Admin.h"

using namespace std;

int main() {
	Account Data("data");
	bool command = true;
	string id;
	string pass;
	while (command) {
		Data.ShowMenu();
		int service_select;
		cout << "Please select your service: " << endl;
		while (!(cin >> service_select)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "invalid input, please re-enter your selection:";
		}

		switch (service_select) {
		case 1:
			cout << "Registration" << endl;
			Data.Registrator();
			break;
		case 2:
			cout << "WriteOff" << endl;
			Data.WriteOff();
			break;
		case 3:
			cout << "Login(enter n to cancel)" << endl;
			cout << "please enter your userID: ";
			cin >> id;
			cout << "please enter your password: ";
			cin >> pass;
			while (Data.Login(id, pass) == -1) {
				cout << "uncorrect userID or password, please enter: ";
				cout << "please enter your userID: ";
				cin >> id;
				cout << "please enter your password: ";
				cin >> pass;
			}
			if (Data.Login(id, pass) == -2) {
				break;
			}
			cout << "login succesffully!" << endl;
			if (Data.Login(id, pass) == 1) { //Admin account
				cout << "Welcome adminstrator!" << endl;
				Admin Administrator;
				bool command2 = true;
				while (command2) {
					int AdminSelect;
					Administrator.ShowMenu();
					cout << "please select your service:";
					while (!(cin >> AdminSelect)) {
						cin.clear();
						cin.ignore(256, '\n');
						cout << "invalid input, please re-enter your selection:";
					}
					switch (AdminSelect)
					{
					case 1:
						cout << "Add Book" << endl;
						Administrator.AddBook();
						break;
					case 2:
						cout << "Search Book" << endl;
						Administrator.SearchBook();
						break;
					case 3:
						cout << "Borrow Book" << endl;
						Administrator.Borrow();
						break;
					case 4:
						cout << "Return Book" << endl;
						Administrator.Return();
						break;
					case 5:
						cout << "Cancel selected" << endl;
						command2 = false;
						break;
					default:
						break;
					}
				}			
			}
			else { // student user;
				cout << "Welcome!" << endl;
				Book User;
				bool command3 = true;
				while (command3) {
					int UserSelect;
					User.ShowMenu();
					cout << "please select your service:";
					while (!(cin >> UserSelect)) {
						cin.clear();
						cin.ignore(256, '\n');
						cout << "invalid input, please re-enter your selection:";
					}
					switch (UserSelect)
					{
					case 1:
						cout << "Search Book" << endl;
						User.SearchBook();
						break;
					case 2:
						cout << "Borrow Book" << endl;
						User.Borrow();
						break;
					case 3:
						cout << "Return Book" << endl;
						User.Return();
						break;
					case 4:
						cout << "Cancel Selected" << endl;
						command3 = false;
						break;
					default:
						break;
					}
				}
			}
			break;
		case 4:
			cout << "cancel action" << endl;
			command = false;
			break;
		default:
			cout << "No service selected" << endl;
			break;
		}
	}
	cout << "clear";
	system("cls");
}