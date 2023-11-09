#pragma once

using namespace std;



struct Book {
	string title;
	string author;
	string publication;
	string genre;
	string year;
	string price;
	void AddBook(Book*&, int&);
	void DeleteBook(Book*&, int&, int);
	int EditBook(Book*&, int&, int);
	void ShowInfo(Book*&, int& size);


	void SortByAuthor(Book*&, int&);
	void SortByPrice(Book*&, int&);
	void SearchByAuthor(Book*&, int&);
	void SearchByTitle(Book*&, int&);
	void SearchByPublication(Book*&, int&);
	void SearchByGenre(Book*&, int&);
};
