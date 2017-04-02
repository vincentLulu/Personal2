#ifndef ADMIN
#define ADMIN
#include "Book.h"

//Derived from Book.h by adding extra function of adding
//new books


class Admin:public Book {
public:
	Admin();
	~Admin();
	virtual void ShowMenu();
	bool AddBook();
};
#endif // !ADMIN
#pragma once
