#include<iostream>
#include <iomanip>

using namespace std;

void AnyLine(int symb, int number);
void Top();
void Bottom();
void Horizont();
void OneCol(int num);
void TextLine(string t1, string t2, string t3, string t4, string t5);


void main() {
	Top();
	OneCol(2);
	Horizont();
	OneCol(6);
	Horizont();
	OneCol(1);
	Bottom();
	

}
void AnyLine(int symb, int number) {
	for (int i = 0; i < number; i++) {
		cout << (char)symb;
	}
}
void Top() {
	//=============header=============
	AnyLine(218, 1);
	AnyLine(196, 3);
	AnyLine(194, 1);
	AnyLine(196, 10);
	AnyLine(194, 1);
	AnyLine(196, 20);
	AnyLine(194, 1);
	AnyLine(196, 12);
	AnyLine(194, 1);
	AnyLine(196, 15);
	AnyLine(191, 1);
}
void Horizont() {
	cout << endl;
	AnyLine(195, 1);
	AnyLine(196, 3);
	AnyLine(197, 1);
	AnyLine(196, 10);
	AnyLine(197, 1);
	AnyLine(196, 20);
	AnyLine(197, 1);
	AnyLine(196, 12);
	AnyLine(197, 1);
	AnyLine(196, 15);
	AnyLine(180, 1);
}
void OneCol(int num) {
	for (int i = 0; i < num; i++) {
	cout << endl;
	AnyLine(179, 1);
	AnyLine(255, 3);
	AnyLine(179, 1);
	AnyLine(255, 10);
	AnyLine(179, 1);
	AnyLine(255, 20);
	AnyLine(179, 1);
	AnyLine(255, 12);
	AnyLine(179, 1);
	AnyLine(255, 15);
	AnyLine(179, 1);
	}
}
void Bottom() {
	cout << endl;
	AnyLine(192, 1);
	AnyLine(196, 3);
	AnyLine(193, 1);
	AnyLine(196, 10);
	AnyLine(193, 1);
	AnyLine(196, 20);
	AnyLine(193, 1);
	AnyLine(196, 12);
	AnyLine(193, 1);
	AnyLine(196, 15);
	AnyLine(217, 1);
}
void TextLine(string t1, string t2, string t3, string t4, string t5) {

}