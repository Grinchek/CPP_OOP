#include<iostream>
#include <iomanip>
#include <string>

using namespace std;

void AnySymb(int symb, int number);
void Space(int number, string txt);
void Top();
void Bottom();
void Horizont();
void OneCol(string str1 = "No ", string str2 = "Item   ", string str3 = "Description    ", string str4 = "Quality  ", string str5 = "Price     ");
void OneColEmpty();

void main() {
	Top();
	OneColEmpty();
	OneCol();//Header
	OneColEmpty();
	Horizont();
	OneColEmpty();
	OneCol("1 ","P196   ","Samsung Color Tv  ","1     ","$ 829.00   ");
	OneCol("2 ","P020   ","Uniden Handset    ","1     ","$  29.00   ");
	OneCol("3 ","P111   ","Folder Blank      ","1     ","$  2.70    ");
	OneColEmpty();
	OneColEmpty();
	OneColEmpty();
	OneColEmpty();
	OneColEmpty();
	Horizont();
	OneColEmpty();
	Bottom();


}
void AnySymb(int symb, int number) {
	for (int i = 0; i < number; i++) {
		cout << (char)symb;
	}
}
void Top() {
	//=============header=============
	AnySymb(218, 1);
	AnySymb(196, 3);
	AnySymb(194, 1);
	AnySymb(196, 10);
	AnySymb(194, 1);
	AnySymb(196, 20);
	AnySymb(194, 1);
	AnySymb(196, 12);
	AnySymb(194, 1);
	AnySymb(196, 15);
	AnySymb(191, 1);
}
void Horizont() {
	cout << endl;
	AnySymb(195, 1);
	AnySymb(196, 3);
	AnySymb(197, 1);
	AnySymb(196, 10);
	AnySymb(197, 1);
	AnySymb(196, 20);
	AnySymb(197, 1);
	AnySymb(196, 12);
	AnySymb(197, 1);
	AnySymb(196, 15);
	AnySymb(180, 1);
}
void Bottom() {
	cout << endl;
	AnySymb(192, 1);
	AnySymb(196, 3);
	AnySymb(193, 1);
	AnySymb(196, 10);
	AnySymb(193, 1);
	AnySymb(196, 20);
	AnySymb(193, 1);
	AnySymb(196, 12);
	AnySymb(193, 1);
	AnySymb(196, 15);
	AnySymb(217, 1);
}
void Space(int number,string txt) {
	cout << setw(number)<<txt;
}
void OneCol(string str1, string str2, string str3, string str4, string str5) {
	cout << endl;
	AnySymb(179, 1);
	Space(3, str1);
	AnySymb(179, 1);
	Space(10, str2);
	AnySymb(179, 1);
	Space(20, str3);
	AnySymb(179, 1);
	Space(12, str4);
	AnySymb(179, 1);
	Space(15, str5);
	AnySymb(179, 1);
}
void OneColEmpty(){
	cout << endl;
	AnySymb(179, 1);
	Space(3, "");
	AnySymb(179, 1);
	Space(10, "");
	AnySymb(179, 1);
	Space(20, "");
	AnySymb(179, 1);
	Space(12, "");
	AnySymb(179, 1);
	Space(15, "");
	AnySymb(179, 1);
}