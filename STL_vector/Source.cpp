#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<random>
#include<fstream>

using namespace std;


struct Time {
	int hour;
	int minute;
	int second;
};

class Train
{
private:
	int number;
	Time departureTime;
	string destination;
public:
	Train(int n,Time time,string dest):number(n),departureTime(time),destination(dest){}
	int GetNumber() {
		return number;
	}
	string GetStation() {
		return destination;
	}
	int GetHour() {
		return departureTime.hour;
	}
	int GetMinute(){
		return departureTime.minute;
	}
	int GetSecond() {
		return departureTime.second;
	}
	Train* SetTime() {
		int h, m, s;
		do {
			cout << "Enter departure hour:"; cin >> h;
			cout << "minute:"; cin >> m;
			cout << "second :"; cin >> s;
		} while ((h < 0 || h >= 24) || (m < 0 || m >= 60) || (s < 0 || s >= 60));
		departureTime.hour = h;
		departureTime.minute = m;
		departureTime.second=s;
		return this;
	}

	friend ostream& operator << (ostream& out, const Train& train);
	friend istream& operator >> (istream& in, Train& train);
	friend bool operator <(Train& train1, Train& train2);
};
ostream& operator << (ostream& out, const Train& train) {
	out << "Number: " << train.number << endl;
	out << "Time: " << train.departureTime.hour << ":";
	out << train.departureTime.minute << ":" << train.departureTime.second << endl;
	out << "Station: " << train.destination << endl;
	return out;
}
istream& operator >> (istream& in, Train& train) {
	in >> train.number;
	in >> train.departureTime.hour;
	in >> train.departureTime.minute;
	in >> train.departureTime.second;
	in >> train.destination;
	return in;
}
bool operator <(Train& train1, Train& train2) {
	if (train1.departureTime.hour < train2.departureTime.hour) {
		return true;
	}
	else if (train1.departureTime.hour <= train2.departureTime.hour && train1.departureTime.minute < train2.departureTime.minute) {
		return true;
	}
	else if (train1.departureTime.hour <= train2.departureTime.hour && train1.departureTime.minute <= train2.departureTime.minute && train1.departureTime.second < train2.departureTime.second) {
		return true;
	}
	else {
		return false;
	}
}
bool Less(Train& t1,Train& t2) {
	return t1 < t2;
}
class Railway
{
private:
	vector<Train> trains;
public:
	bool IsEmpty() {
		return trains.size() == 0;
	}
	void RandomInit() {
		int n = 1 + rand() % 998;
		unsigned short h = rand() % 24;
		unsigned short m = rand() % 60;
		unsigned short s = rand() % 60;
		int ch;
		string station;
		for (int i = 0; i < 12; i++) {
			ch = rand() % 256;
			station += char(ch);
		}
		trains.push_back(Train(n, { h,m,s }, station));
	}
	void AddTrain() {
		int h,m,s;
		cout << "Enter number of train:"; int n; cin >> n;
		do {
			cout << "Enter departure hour:"; cin >> h;
			cout << "minute:"; cin >> m;
			cout << "second :"; cin >> s;
		} while (( h<0 ||h >= 24) || (m<0 ||m >= 60) || (s<0 ||s >=60));
		cout << "Enter destination station:";
		cin.ignore();
		string station;
		getline(cin, station);
		trains.push_back(Train(n, { h,m,s }, station));
	}
	void DeleteTrain() {
		cout << "Enter number of train:"; int sch; cin >> sch; cin.ignore();
		for (int i = 0; i < trains.size();i++) {
			if (trains[i].GetNumber() == sch) {
				trains.erase(trains.begin() + i);
			}
		}
	}
	void ShowAll() {
		for (auto item : trains) {
			cout << item;
			cout << "################################################\n";
		}
		cout << endl;
	}
	void ShowByNumber() {
		cout << "Enter number of train:"; int sch; cin >> sch; cin.ignore();
		for (auto item : trains) {
			if (item.GetNumber() == sch) {
				cout << item;
				cout << "################################################\n";
			}
		}
	}
	void ShowByStation() {
		cin.ignore();
		cout << "Enter destination station:"; string sch; getline(cin,sch);
		system("cls");
		for (auto item : trains) {
			if (item.GetStation() == sch) {
				cout << item;
				cout << "################################################\n";
			}
		}
	}
	void EditTime() {
		cout << "Enter number of train:"; int sch; cin >> sch; cin.ignore();
	for(int i=0;i<trains.size();i++){
		if (trains[i].GetNumber() == sch) {
			trains[i].SetTime();
		}
		}
	}
	void SortByTime() {
		sort(trains.begin(), trains.end(), Less);
	}
	//Function for writing info into file
	void WriteInfo() {
		fstream file;
		file.open("Traines registration.txt", ios_base::out);
		if (file.is_open()) {
			for (auto item : trains) {
				file << item.GetNumber() << "\n";
				file << item.GetHour() << "\n";
				file << item.GetMinute() << "\n";
				file << item.GetSecond() << "\n";
				file << item.GetStation() << "\n";
			}
		}
		file.close();
	}
	//Function for geting info from file and put it on dynamic array
void GetInfo() {
	fstream file;
	file.open("Traines registration.txt", ios_base::in);
	if (file.is_open()) {
		string line;
		int count = 0;
		while (getline(file, line)) {
			count++;
		}
		int size = count / 5;
		file.clear();
		file.seekg(0, ios::beg);
		int i = 0;
		while (i < size) {
			int n; getline(file, line);
			n = stoi(line);
			unsigned short h, m, s;
			getline(file, line);
			h = stoi(line);
			getline(file, line);
			m = stoi(line);
			getline(file, line);
			s = stoi(line);
			getline(file, line);
			string st = line;
			trains.push_back(Train(n,{h,m,s},st));
			i++;
		}
	}
	file.close();
}

};
void Menu(Railway& station) {
	station.GetInfo();
	if (station.IsEmpty()) {
		cout << "There are no trains in the list yet." << endl;
		system("pause");
		system("cls");
	}
	bool ex = false;
	while (!ex) {
		int choice = 0;
		int iner = 0;
		cout << "Welcome to our railway station:";
		cout << "Please, make your choice:\n";
		cout << "1-add/create a new train.\n";
		cout << "2-show the list of the trains.\n";
		cout << "3-edit time in train.\n";
		cout << "4-delete the train.\n";
		cout << "0-exit.\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "1-add random train.\n2-add train manualy.";
			cin >> iner;
			switch (iner) {
			case 1:
				station.RandomInit();
				system("cls");
				break;
			case 2:
				system("cls");
				station.AddTrain();
				break;
			default:
				break;
			}	
			system("cls");
			break;
		case 2:
			station.SortByTime();
			cout << "1-show all trains.\n2-show trains by number.\n3-show by station." << endl;
			cin >> iner;
			switch (iner)
			{
			case 1:
				system("cls");
				station.ShowAll();
				break;
			case 2:
				system("cls");
				station.ShowByNumber();
				break;
			case 3:
				system("cls");
				station.ShowByStation();
				break;
			default:
				break;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			station.EditTime();
			system("cls");
			break;
		case 4:
			station.DeleteTrain();
			system("cls");
			break;
		case 0:
			ex = true;
		default:
			break;
		}
	}
	station.WriteInfo();
}

void main() {
	srand(time(NULL));
	Railway station;
	Menu(station);
}