#pragma once
#include<iostream>
#include<string>
#include<random>
#include"Date.h"

using namespace std;

class Service {
private:
	string name;
	string surname;
	string delivery_address;
	Date date_of_admission;
	Date date_of_delivery;

public:
	Service() :name("no name"), surname("no surname"), delivery_address("none"), date_of_admission(2024,1,1), date_of_delivery(2024,1,1){}
	Service(string n,string sn,string del,Date date) :name(n), surname(sn), delivery_address(del), date_of_admission(date){
		Date temp = date_of_admission;
		temp(3);
		date_of_delivery = temp;
	}
	void ShowInfo() const;
	bool IsValid();
	string GetName();
	string GetSurName();
	string GetAddress();
	int GetYear();
	int GetMonth();
	int GetDay();


};

