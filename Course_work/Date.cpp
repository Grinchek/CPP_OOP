#include "Date.h"

Date::Date(int y, int m, int d) :m_day(d), m_month(m), m_year(y) {
	if (y > 0 && y < 3000) {
		m_year = y;
	}
	if (m > 0 && m <= 12) {
		m_month = m;

	}
	switch (m_month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (d > 1 && d <= 31) {
			m_day = d;
			break;
		}
		else if (d < 1 || d > 31) {
			cout << "Wrong day." << endl;
			m_day = 0;
			m_month = 0;
			m_year = 0;
			break;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		if (d > 1 && d <= 30) {
			m_day = d;
			break;
		}
		else if (d < 1 || d > 30) {
			cout << "Wrong day." << endl;
			m_day = 0;
			m_month = 0;
			m_year = 0;
			break;
		}
	case 2:
		if (y % 4 == 0 && d > 1 && d <= 29) {
			m_day = d;
			break;
		}
		else if (y % 4 != 0 && d > 1 && d <= 28) {
			m_day = d;
			break;
		}
		else if (d < 1 || d > 29) {
			cout << "Wrong day." << endl;
			m_day = 0;
			m_month = 0;
			m_year = 0;
			break;
		}

	default:
		break;
	}

}
void Date::IncrementDate() {
	switch (m_month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
		if (m_day + 1 > 31) {
			m_month++;
			m_day = 1;
			break;
		}
		else {
			m_day++;
			break;
		}

	case 12:
		if (m_day + 1 > 31) {
			m_year++;
			m_month = 1;
			m_day = 1;
			break;
		}
		else {
			m_day++;
			break;
		}

	case 4:
	case 6:
	case 9:
	case 11:
		if (m_day > 30) {
			m_month++;
			m_day = 1;
			break;
		}
		else {
			m_day++;
			break;
		}

	case 2:
		if (m_year % 4 == 0 && m_day > 29) {
			m_month++;
			m_day = 1;
			break;
		}
		else if (m_year % 4 != 0 && m_day > 28) {
			m_month++;
			m_day = 1;
			break;
		}
		else {
			m_day++;
			break;
		}


	default:
		break;
	}

}
void Date::DecrementDate() {
	switch (m_month) {
	case 3:
		if (m_year % 4 == 0 && m_day < 1) {
			m_month--;
			m_day = 29;
			break;
		}
		else if (m_year % 4 != 0 && m_day < 1) {
			m_month--;
			m_day = 28;
			break;
		}
		else {
			m_day--;
			break;
		}
	case 5:
	case 7:
	case 10:
	case 12:
		if (m_day - 1 < 1) {
			m_month--;
			m_day = 30;
			break;
		}
		else {
			m_day--;
			break;
		}

	case 1:
	case 2:
	case 4:
	case 6:
	case 8:
	case 9:
	case 11:
		if (m_day < 1) {
			m_month--;
			m_day = 31;
			break;
		}
		else {
			m_day--;
			break;
		}
	default:
		break;
	}
}
bool Date::IsValide() {
	return (m_year > 0 && m_month > 0 && m_day > 0);
}
int Date::GetYear() {
	return m_year;
}
int Date::GetMonth() {
	return m_month;
}
int Date::GetDay() {
	return m_day;
}
void Date::operator += (int n_day) {
	for (int i = 0; i < n_day; i++) {
		IncrementDate();
	}
}
void Date::operator -= (int n_day) {
	for (int i = 0; i < n_day; i++) {
		DecrementDate();
	}
}
void Date::operator ()(int n_day) {
	for (int i = 0; i < n_day; i++) {
		IncrementDate();
	}
}
void Date::operator ()(int n_day, int n_month) {
	m_month += n_month;
	if (m_month > 12) {
		m_year += (m_month / 12);
		m_month = (m_month % 12);
	}

	for (int i = 0; i < n_day; i++) {
		IncrementDate();
	}
}
void Date::operator ()(int n_day, int n_month, int n_year) {
	m_year += n_year;
	m_month += n_month;
	if (m_month > 12) {
		m_year += (m_month / 12);
		m_month = (m_month % 12);
	}

	for (int i = 0; i < n_day; i++) {
		IncrementDate();
	}
}
ostream& operator << (ostream& out, const Date& date) {
	out << date.m_day << ".";
	switch (date.m_month) {
	case 1:
		out << "January.";
		break;
	case 2:
		out << "February.";
		break;
	case 3:
		out << "March.";
		break;
	case 4:
		out << "April.";
		break;
	case 5:
		out << "May.";
		break;
	case 6:
		out << "June.";
		break;
	case 7:
		out << "July.";
		break;
	case 8:
		out << "August.";
		break;
	case 9:
		out << "Septeember.";
		break;
	case 10:
		out << "October.";
		break;
	case 11:
		out << "Nowember.";
		break;
	case 12:
		out << "December.";
		break;
	default:
		out << "Unexptected date.";
		break;
	}
	out << date.m_year;
	return out;
}
Date operator ++(Date& date) {
	date.IncrementDate();
	return date;
}
Date operator --(Date& date) {
	date.DecrementDate();
	return date;
}
Date operator ++(Date& date, int n) {
	return ++date;
}
Date operator --(Date& date, int n) {
	return --date;
}
bool operator ==(Date& date1, Date& date2) {
	return (date1.m_year == date2.m_year && date1.m_month == date2.m_month && date1.m_day == date2.m_day);
}
bool operator !=(Date& date1, Date& date2) {
	return (date1.m_year != date2.m_year || date1.m_month != date2.m_month || date1.m_day != date2.m_day);
}
bool operator <(Date& date1, Date& date2) {
	if (date1.m_year < date2.m_year) {
		return true;
	}
	else if (date1.m_year <= date2.m_year && date1.m_month < date2.m_month) {
		return true;
	}
	else if (date1.m_year <= date2.m_year && date1.m_month <= date2.m_month && date1.m_day < date2.m_day) {
		return true;
	}
	else {
		return false;
	}
}
bool operator >(Date& date1, Date& date2) {
	if (date1.m_year > date2.m_year) {
		return true;
	}
	else if (date1.m_year >= date2.m_year && date1.m_month > date2.m_month) {
		return true;
	}
	else if (date1.m_year >= date2.m_year && date1.m_month >= date2.m_month && date1.m_day > date2.m_day) {
		return true;
	}
	else {
		return false;
	}
}
