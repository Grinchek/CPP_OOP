
/*■ Редагувати книгу; (ChangeData)
	■ Друк усіх книг; (Show);
■ Пошук книг за автором;
■ Пошук книги за назвою;
■ Пошук книги за видавництвом
	■ Пошук книги за жанром
	■ Add new book
	■ Save to File
	■ Load from file*/

#include<iostream>
#include<string>
#include<fstream>
#include "Book.h"

using namespace std;

void GetInfo(Book*&, int&);
void WriteInfo(Book*&, int&);
//int Unic(Todo*&, int&);

int main() {

	Book book;
	fstream file;
	int size = 0;
	Book* library = nullptr;
	GetInfo(library, size);
	system("pause");
	system("cls");
	int index = 0;
	GetInfo(library, size);
	bool exit = false;
	while (!exit) {
		system("cls");
		cout << "Choose an option:" << endl;
		cout << "1 - Create/Add a new book" << endl;
		cout << "2 - Show books" << endl;
		cout << "3 - Redurkt books" << endl;
		cout << "4 - Search by author" << endl;
		cout << "5 - Search by title" << endl;
		cout << "6 - Search by publication" << endl;
		cout << "7 - Search by genre" << endl;
		cout << "8 - Delete book" << endl;
		cout << "0 - Exit" << endl;
		int choice;
		cin >> choice;
		system("cls");
		cin.ignore();
		switch (choice) {
		case 1: {
			book.AddBook(library, size);
			break;
		}
		case 2: {
			if (size == 0) {
				cout << "There are no book yet" << endl;
				system("pause");
			}
			else {
				cout << "By wich parameter wold you like to show info? " << endl;
				cout << "1 - By author " << endl;
				cout << "2 - By price " << endl;
				cout << "3 - Show all books " << endl;
				cout << "0 - Exit " << endl;
				int showChoice;
				cin >> showChoice;
				cin.ignore();
				switch (showChoice) {
				case 1: {
					book.SortByAuthor(library, size);
					book.ShowInfo(library, size);
				}
					  break;
				case 2: {
					book.SortByPrice(library, size);
					book.ShowInfo(library, size);
				}
					  break;
				case 3: {
					book.ShowInfo(library, size);
				}
					  break;
				case 0: {
					break;
				}
				default: {
					cout << "Wrong choise" << endl;
				}
					   break;
				}
			}
			break;
		}
		case 3: {
			if (size == 0) {
				cout << "There are no book yet" << endl;
				system("pause");
			}
			else {
				cout << "Enter book to reduct: ";
				string redBook;
				getline(cin, redBook);
				for (int i = 0; i < size; i++) {
					if (redBook == library[i].title) {
						index = i;
						book.EditBook(library, size, index);
					}
					else {

					}
				}
			}
			WriteInfo(library, size);
			break;
		}
		case 4: {
			book.SearchByAuthor(library, size);
			break;
		}
		case 5: {
			book.SearchByTitle(library, size);
			break;
		}
		case 6: {
			book.SearchByPublication(library, size);
			break;
		}
		case 7: {
			book.SearchByGenre(library, size);
			break;
		}
		case 8: {
			if (size == 0) {
				cout << "There are no book yet" << endl;
				system("pause");
			}
			else if (size == 1) {
				book.DeleteBook(library, size, 0);
				file.open("Library", std::ofstream::out);
				file.close();
			}
			else {
				cout << "Enter book to delete: ";
				string delBook;
				cin >> delBook;
				cin.ignore();
				for (int i = 0; i < size; i++) {
					if (delBook == library [i] .title) {
						index = i;
						book.DeleteBook(library, size, index);
						file.open("Library", std::ofstream::out);
						file.close();
						WriteInfo(library, size);
					}
					else {
						cout << "Wrong book entered." << endl;
					}
				}
			}
			break;
		}
		case 0: {
			system("cls");
			exit = true;
			break;
		}
		default:
			cout << "Invalid choice. Try again." << endl;
			break;
		}

	}
	delete[] library;
}

//Function for geting info from file and put it on dynamic array
void GetInfo(Book*& library, int& size) {
	fstream file;
	file.open("Library", ios_base::in);
	if (file.is_open()) {
		string line;
		int count = 0;
		while (getline(file, line)) {
			count++;
		}
		size = count / 6;
		file.clear();
		file.seekg(0, ios::beg);
		library = new Book[size];
		int i = 0;
		while (i < size) {
			getline(file, library[i].title);
			getline(file, library[i].author);
			getline(file, library[i].publication);
			getline(file, library[i].genre);
			getline(file, library[i].year);
			getline(file, library[i].price);
			i++;
		}
	}
	file.close();
}
//Function for writing info into file
void WriteInfo(Book*& library, int& size) {
	fstream file;
	file.open("Todolist", ios_base::trunc);
	file.close();
	file.open("Todolist", ios_base::app);
	if (file.is_open()) {
		for (int i = 0; i < size; i++) {
			file << library[i].title << "\n";
			file << library[i].author << "\n";
			file << library[i].publication << "\n";
			file << library[i].genre << "\n";
			file << library[i].year << "\n";
			file << library[i].price << "\n";
		}
	}
	file.close();
}
