#include <iostream>
#include <string>

using namespace std;

struct Washing_nashine {
	string producer="";
	string color="";
	int width=0;
	int length=0;
	int heigh=0;
	int power=0;
	int spin=0;
	int boiling=0;
};
struct Car {
	string color;
	string mark;
	string number;

	void Fill() {
		system("cls");
		cout << "Enter color: ";
		getline(cin,color);
		cout << "Enter mark: ";
		getline(cin, mark);
		cout << "Enter number: ";
		getline(cin, number);
	}
	void Fill(int idx) {
		string str = to_string(idx+1);
		color = "Default color "+str;
		mark = "Default mark "  +str;
		number = "Default number " + str;
	}
	void Print() {
		cout << "Color: " << color << ". \n" << "Mark: " 
			<< mark << ". \n" << "Number: " << number 
			<<".\n==========================================" << endl;
	}
};
void Edit_car(Car cars[], int size) {
	string search_num;
	cout << "Enter number to edit: ";
	getline(cin, search_num);
	for (int i = 0; i < size; i++) {
		if (search_num == cars[i].number) {
			cars[i].Fill();
			i = size;
		}
	}
	system("cls");
}
void Sow_all_cars(Car cars[],int size) {
	for (int i = 0; i < size; i++) {
		cars[i].Print();
	}
}
void Search_by_number(Car cars[], int size) {
	string search_num;
	cout << "Enter number: ";
	getline(cin, search_num);
	for (int i = 0; i < size; i++) {
		if (search_num == cars[i].number) {
			cars[i].Print();
			i = size;
		}
	}
}
void main() {
	/*Washing_nashine mk1;
	mk1.producer = "Samsung";
	mk1.color = "White";
	mk1.width = 72;
	mk1.length = 40;
	mk1.heigh = 100;
	mk1.power = 2000;
	mk1.spin = 1500;
	mk1.boiling = 80;
	cout << "Producer: " << mk1.producer<<" ;\n" << "Color: " 
	<< mk1.color << " ;\n" << "Width: " << mk1.width << " sm;\n" 
	<< "Length: " << mk1.length << " sm;\n" << "Heigh: " << mk1.heigh
	<< " sm;\n" << "Spin: " << mk1.spin << " r/pm;\n" << "Power: " 
	<< mk1.power << " wat'\n" << "Boiling: " << mk1.boiling << " degree. " << endl;*/
	const int size = 10;
	Car cars[size]{};
	for (int i = 0; i < size; i++) {
		Car curent_car;
		curent_car.Fill(i);

		cars[i] = curent_car;
	}
	Search_by_number(cars, size);
	Edit_car(cars, size);
	Sow_all_cars(cars, size);


}