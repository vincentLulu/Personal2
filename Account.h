#ifndef ACCOUNT
#define ACCOUNT	
#include <unordered_map>
using namespace std;

class Account {
public:
	Account();
	Account(const string filename);
	~Account();
	void ShowMenu();
	bool Registrator();
	bool WriteOff();
	int Login(const string id, const string pass);
	void Readuser();
private:
	string UserID;
	struct data {
		int Admin;
		string UserName;
		string Password;
		string RegistrationDate;
		double FeeToPay;
	};
	unordered_map <string, data> UserInfor;
};

#endif // !ACCOUNT
#pragma once
