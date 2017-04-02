#ifndef BOOK
#define BOOK
#include <unordered_map>
using namespace std;

class Book {
public:
	Book();
	~Book();
	virtual void ShowMenu();
	bool AddBook();
	bool SearchBook();
	bool Return();
	bool Borrow();
	void Readbook();
protected:
	string SeriesID;
	struct BookData {
		string Name;
		string author;
		int InStore;
		int ToBeReturn;
	};
	unordered_map <string, BookData> BookInfor;
private:
	bool Borrow(string seriesID);
};
#endif // !BOOK
#pragma once
