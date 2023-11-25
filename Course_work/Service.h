#pragma once
#include<iostream>
#include<string>
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
	bool paid;
	Service() :name("no name"), surname("no surname"), delivery_address("none"), date_of_admission(0,0,0), date_of_delivery(0,0,0){}
	Service(string n,string sn,string del,int y,int m,int d) :name(n), surname(sn), delivery_address(del), date_of_admission(y, m, d){
		Date temp = date_of_admission;
		temp(3);
		date_of_delivery = temp;
	}
	void ShowInfo() const;

};

