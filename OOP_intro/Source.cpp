#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Student
{
private:
	string first_name;
	string last_name;
	string u_city;
	string u_country;
	string group_number;
	string phone_number;
	string city;
	string country;
	int day;
	int month;
	int year;
	
public:
	Student() {
		first_name = "Def_name";
		last_name="Def_last_name";
		u_city="Def_univer_city";
		u_country="Def_univer_country";
		group_number="PR322";
		phone_number = "+111111111111";
		city = "Default student city";
		country = "Default student country";
		day = 0;
		month = 0;
		year = 0;
	}
	Student(int any_param) {
	
		SetData();
	
	}
	void SetData() {
		cout << "Enter name: " ;
		getline(cin, first_name);
		cout << "Enter surname: ";
		getline(cin, last_name);
		cout << "Enter univercity city: ";
		getline(cin, u_city);
		cout << "Enter univercity country: ";
		getline(cin, u_country);
		cout << "Enter group number: ";
		getline(cin, group_number);
		cout << "Enter phone number: ";
		getline(cin, phone_number);
		cout << "Enter student city: ";
		getline(cin, city);
		cout << "Enter student country: ";
		getline(cin, country);
		cout << "Enter day of birth: ";
		cin>> day;
		cout << "Enter month of birth: ";
		cin>>month;
		cout << "Enter year of birth: ";
		cin>>year;
	}
	void Print() {
		cout << "Name: "<< first_name<<endl;
		cout << "Surname: "<<last_name<<endl;
		cout << "Univercity city: "<<u_city << endl;
		cout << "Univercity country: "<<u_country << endl;
		cout << "Group number: "<<group_number << endl;
		cout << "Phone number: "<<phone_number << endl;
		cout << "Student city: "<<city << endl;
		cout << "Student country: "<<country << endl;
		cout << "Day of birth: "<<day << endl;
		cout << "Month of birth: "<<month << endl;
		cout << "Year of birth: "<<year << endl;
	}


};
void ShowStudent(Student group[], int &size_of_group) {
	for (int i = 0; i < size_of_group; i++)
	{
		group[i].SetData();
	}
}
class Point {
private:
	int m_x;
	int m_y;
	int m_z;
public:
	Point() {

	}
	Point(int x, int y, int z) {
		SetX(x);
		SetY(y);
		SetZ(z);
	}
	int GetX()const {
		return m_x;
	}
	int GetY()const {
		return m_y;
	}
	int GetZ()const {
		return m_z;
	}
	void SetX(int x) {
		m_x=x;
	}
	void SetY(int y) {
		m_y= y;
	}
	void SetZ(int z) {
		m_z= z;
	}

	void Print()const {
		cout << "x: "<< m_x<<endl;
		cout << "y: "<< m_y<<endl;
		cout << "z: "<< m_z<<endl;
	}

};
void GetInfo(Point*& arr, int& size);
void WriteInfo(Point*& arr, int& size);

void main() {
	////////////////PT1//////////////////
	//Student st1 = Student(1);
	//system("cls");
	//st1.Print();
	//system("pause");
	//system("cls");
	//Student st = Student();
	//cout << "Default student:" << endl;
	//st.Print();

	///////////////PT2////////////////
	fstream file;
	int size = 10;
	Point* points = new Point[size];
	for (int i = 0; i < size; i++) {
		points[i].SetX(i+size);
		points[i].SetY(i+(size-1));
		points[i].SetZ(i+(size-2));
	}
	GetInfo(points, size);
	for (int i = 0; i < size; i++) {
		points[i].Print();
	}
	WriteInfo(points, size);

	delete[]points;
}
void GetInfo(Point*& points, int& size) {
	fstream file;
	file.open("Points", ios_base::in);
	if (file.is_open()) {
		int value;
		int count = 0;
		while (file >> value) {
			count++;
		}
		size = count / 3;
		file.clear();
		file.seekg(0, ios::beg);
		if (points != nullptr) {
			delete[] points;
		}
		points = new Point[size];
		int i = 0;
		while (i < size) {
			int x, y, z;
			file >> x;
			points[i].SetX(x);
			file >> y;
			points[i].SetY(y);
			file >> z;
			points[i].SetZ(z);
			i++;
		}
	}
	file.close();
}

//void GetInfo(Point*& points, int& size) {
//	fstream file;
//	file.open("Points", ios_base::in);
//	if (file.is_open()) {
//		int value;
//		int count = 0;
//		while (file>>value) {
//			count++;
//		}
//		size = count / 3;
//		file.clear();
//		file.seekg(0, ios::beg);
//		points =new Point[size];
//		int i = 0;
//		while (i < size) {
//			int x, y, z;
//			file >> x;
//			points[i].SetX(x);
//			file >> y;
//			points[i].SetY(y);
//			file >> z;
//			points[i].SetZ(z);
//			i++;
//		}
//	}
//	file.close();
//}
void WriteInfo(Point*& arr, int& size) {
	fstream file;
	file.open("Points", ios_base::trunc);
	file.close();
	file.open("Points", ios_base::app);
	if (file.is_open()) {
		for (int i = 0; i < size; i++) {
			file << arr[i].GetX()<< "\n";
			file << arr[i].GetY() << "\n";
			file << arr[i].GetZ() << "\n";
		}
	}
	file.close();
}