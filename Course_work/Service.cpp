#include"Service.h"

void Service::ShowInfo() const {
	cout << "------------------------" << endl;
	cout << "Name: " << name << endl;
	cout << "Sur name: " << surname << endl;
	cout << "Delivery address: " << delivery_address << endl;
	cout << "Date of admissiion: " << date_of_admission << endl;
	cout << "Date of delivery: " << date_of_delivery << endl;
	cout << "------------------------" << endl;
}