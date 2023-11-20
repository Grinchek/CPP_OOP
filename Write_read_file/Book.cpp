#include<iostream>
#include<fstream>
#include"Book.h"
#include <string>
using namespace std;

fstream file;
Book* library = nullptr;

//Function for create/add book
void Book::AddBook(Book*& library, int& size) {
	fstream file;
	Book book;
	system("cls");
	bool quit = false;
	while (!quit) {
		cout << "Enter the title: ";
		getline(cin, book.title);
		if (size > 0) {
			int similar = 0;
			for (int i = 0; i < size; i++) {
				if (book.title == library[i].title) {
					cout << "This book already exist." << endl;
					similar++;
				}
			}
			if (similar == 0) {
				quit = true;
			}

		}
		else if (size < 1) {
			quit = true;
		}

	}
	file.open("Library", ios_base::app);
	file << book.title << "\n";
	cout << "Enter author: ";
	getline(cin, book.author);
	file << book.author << "\n";
	cout << "Enter the publication: ";
	getline(cin, book.publication);
	file << book.publication << "\n";
	cout << "Enter the genre: ";
	getline(cin, book.genre);
	file << book.genre << "\n";
	cout << "Enter the year of publication: ";
	getline(cin, book.year);
	file << book.year << "\n";
	cout << "Enter a price of book:) ";
	getline(cin, book.price);
	file << book.price << "\n";
	file.close();
	system("pause");
	size++;
	Book* temp = new Book[size];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = library[i];
	}
	temp[size - 1] = book;
	delete[] library;
	library = temp;
}
//Function for delete wanted book
void Book::DeleteBook(Book*& library, int& size, int index) {
	if (index < 0 || index >= size) {
		cout << "Index is out of range." << endl;
	}
	size--;
	Book* temp = new Book[size];
	for (int i = 0, j = 0; i < size + 1; i++) {
		if (i != index) {
			temp[j] = library [i] ;
			j++;
		}
	}
	delete[] library;
	library = temp;

}
//Function gives the ability to reduct wanted book
int Book::EditBook(Book*& library, int& size, int index) {
	cout << "What field do you waant to edit?" << endl;
	cout << "1 - Title of book\n2 - Author\n3 - Publication" << endl;
	cout << "4 - Genre\n5 - Year\n6 - Price\n0 - Exit" << endl;
	int editchoise;
	cin >> editchoise;
	cin.ignore();
	switch (editchoise) {
	case 1: {
		Book book;
		bool quit = false;
		while (!quit) {
			cout << "Enter task's new name: " << endl;
			getline(cin, book.title);
			int similar = 0;
			for (int i = 0; i < size; i++) {
				if (book.title == library[i].title) {
					cout << "This task already exist." << endl;
					similar++;
				}
			}
			if (similar == 0) {
				library[index].title = book.title;
				quit = true;
			}
		}
		break;
	}
	case 2: {
		cout << "Enter book's new author: " << endl;
		getline(cin, library[index].author);
		break;
	}
	case 3: {
		cout << "Enter book's new publilation: " << endl;
		getline(cin, library[index].publication);
		break;
	}
	case 4: {
		cout << "Enter book's new publikation: " << endl;
		getline(cin, library[index].publication);
		break;
	}
	case 5: {
		cout << "Enter book's new year: " << endl;
		getline(cin, library[index].year);
		break;
	}
	case 6: {
		cout << "Enter book's new price: " << endl;
		getline(cin, library[index].price);
		break;
	}
	case 0: {
		break;
	}
	}

	file.open("Todolist", std::ofstream::out);
	file.close();
	return 0;

}

//Function shows info from array
void Book::ShowInfo(Book*& library, int& size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		cout << "Title: " << library[i].title << endl;
		cout << "Author: " << library[i].author << endl;
		cout << "Publication: " << library[i].publication << endl;
		cout << "Genre: " << library[i].genre << endl;
		cout << "Year: " << library[i].year << endl;
		cout << "Price: " << library[i].price << endl;
	}
	system("pause");
}



//Function helps to sort array by author 
void Book::SortByAuthor(Book*& library, int& size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		Book temp;
		for (int j = 0; j < size; j++) {
			if (library[i].author < library[j].author) {
				temp = library[j];
				library[j] = library[i];
				library[i] = temp;
			}
		}
	}
}
//Function helps to sort array by price
void Book::SortByPrice(Book*& library, int& size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		Book temp;
		for (int j = 0; j < size; j++) {
			if (library[i].price < library[j].price) {
				temp = library[j];
				library[j] = library[i];
				library[i] = temp;
			}
		}
	}
}


//Function helps to search book by it author
void Book::SearchByAuthor(Book*& library, int& size) {
	cout << "Enter the author of searching book:";
	string search;
	getline(cin, search);
	for (int i = 0; i < size; i++) {
		if (library[i].author == search) {
			cout << "Title: " << library[i].title << endl;
			cout << "Author: " << library[i].author << endl;
			cout << "Publication: " << library[i].publication << endl;
			cout << "Genre: " << library[i].genre << endl;
			cout << "Year: " << library[i].year<< endl;
			cout << "Price " << library[i].price << endl;
		}
	}
	system("pause");
}
//Function helps to search book by it title
void Book::SearchByTitle(Book*& library, int& size) {
	cout << "Enter the title of searching book:";
	string search;
	getline(cin, search);
	for (int i = 0; i < size; i++) {
		if (library[i].title == search) {
			cout << "Title: " << library[i].title << endl;
			cout << "Author: " << library[i].author << endl;
			cout << "Publication: " << library[i].publication << endl;
			cout << "Genre: " << library[i].genre << endl;
			cout << "Year: " << library[i].year << endl;
			cout << "Price " << library[i].price << endl;
		}
	}
	system("pause");
}
//Function helps to search book by it publication
void Book::SearchByPublication(Book*& library, int& size) {
	cout << "Enter the publication of searching book:";
	string search;
	getline(cin, search);
	for (int i = 0; i < size; i++) {
		if (library[i].publication == search) {
			cout << "Title: " << library[i].title << endl;
			cout << "Author: " << library[i].author << endl;
			cout << "Publication: " << library[i].publication << endl;
			cout << "Genre: " << library[i].genre << endl;
			cout << "Year: " << library[i].year << endl;
			cout << "Price " << library[i].price << endl;
		}
	}
	system("pause");
}
//Function helps to search book by it genre
void Book::SearchByGenre(Book*& library, int& size) {
	cout << "Enter the genre of searching book:";
	string search;
	getline(cin, search);
	for (int i = 0; i < size; i++) {
		if (library[i].genre == search) {
			cout << "Title: " << library[i].title << endl;
			cout << "Author: " << library[i].author << endl;
			cout << "Publication: " << library[i].publication << endl;
			cout << "Genre: " << library[i].genre << endl;
			cout << "Year: " << library[i].year << endl;
			cout << "Price " << library[i].price << endl;
		}
	}
	system("pause");
}