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
bool Service::IsValid() {
	return date_of_admission.IsValide();
}
string Service::GetName(){
	return name;
}
string Service::GetSurName() {
	return surname;
}
string Service::GetAddress(){
	return delivery_address;
}
int Service::GetYear(){
	return date_of_admission.GetYear();
}
int Service::GetMonth(){
	return date_of_admission.GetMonth();
}
int Service::GetDay(){
	return date_of_admission.GetDay();
}