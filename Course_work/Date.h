#pragma once
#include<iostream>
#include<string>

using namespace std;


class Date {
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date() :m_day(0),m_month(0),m_year(0){}
	Date(int y, int m, int d);
	void IncrementDate();
	void DecrementDate();
	friend ostream& operator << (ostream& out, const Date& date);
	friend bool operator ==(Date& date1, Date& date2);
	friend bool operator !=(Date& date1, Date& date2);
	friend bool operator >(Date& date1, Date& date2);
	friend bool operator <(Date& date1, Date& date2);
	void operator += (int n_day);
	void operator -= (int n_day);
	void operator ()(int n_day);
	void operator ()(int n_day, int n_month);
	void operator ()(int n_day, int n_month, int n_year);
};
ostream& operator << (ostream& out, const Date& date);
Date operator ++(Date& date);
Date operator --(Date& date);
Date operator ++(Date& date, int n);
Date operator --(Date& date, int n);
bool operator ==(Date& date1, Date& date2);
bool operator !=(Date& date1, Date& date2);
bool operator <(Date& date1, Date& date2);
bool operator >(Date& date1, Date& date2);





