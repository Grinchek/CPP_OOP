#include<iostream>
#include<string>

using namespace std;


class Date {
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int y, int m, int d) :m_day(d), m_month(m), m_year(y) {
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
			else if(d < 1 || d > 31) {
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
	void IncrementDate() {
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
				m_month=1;
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
				m_day=1;
				break;
			}
			else {
				m_day++;
				break;
			}
			
		case 2:
			if (m_year % 4 == 0 && m_day > 29) {
				m_month++;
				m_day =1;
				break;
			}
			else if (m_year % 4 != 0 &&m_day > 28) {
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
	void DecrementDate() {
		switch (m_month) {
		case 3:
			if (m_year % 4 == 0 && m_day < 1) {
				m_month--;
				m_day = 29;
				break;
			}
			else if (m_year % 4 != 0 && m_day <1) {
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
			if (m_day -1 < 1) {
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
	friend ostream& operator << (ostream& out, const Date& date);
	friend bool operator ==(Date& date1, Date& date2);
	friend bool operator !=(Date& date1, Date& date2);
	friend bool operator >(Date& date1, Date& date2);
	friend bool operator <(Date& date1, Date& date2);
	void operator += (int n_day) {
		for (int i = 0; i < n_day; i++) {
			IncrementDate();
		}
	}
	void operator -= (int n_day) {
		for (int i = 0; i < n_day; i++) {
			DecrementDate();
		}
	}
	void operator ()(int n_day) {
		for (int i = 0; i < n_day; i++) {
			IncrementDate();
		}
	}
	void operator ()(int n_day,int n_month) {
		m_month += n_month;
		if (m_month > 12 ) {
			m_year += (m_month/12);
			m_month = (m_month % 12);
	  }

		for (int i = 0; i < n_day; i++) {
			IncrementDate();
		}
	}
	void operator ()(int n_day, int n_month,int n_year) {
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




};
ostream& operator << (ostream& out,const Date &date) {
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
	out << date.m_year ;
	return out;
}
 Date operator ++(Date &date){
	 date.IncrementDate();
	 return date;
}
 Date operator --(Date& date) {
	 date.DecrementDate();
	 return date;
 }
 Date operator ++(Date& date,int n) {
	 return ++date;
 }
 Date operator --(Date& date,int n) {
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




void main() {
	Date date(1994, 12, 1);
	cout<<"date [ " << date<<" ]"<<endl;
	Date date1(1995, 1, 1);
	cout << "date1 [" << date1 << " ]" << endl;

	++date;
	date++;
	--date;
	date--;
	if (date < date1) {
		cout << "Date1 is biger." << endl;
	}
	else if (date > date1) {
		cout << "Date is biger." << endl;
	}
	date1 += 25;
	cout << date1<<endl;
	date1 -= 5;
	cout << date1<<endl;
	date(1);
	cout << date<<endl;
	date(0,1);
	cout << date<<endl;
	date(0, 12);
	cout << date<<endl;
	date(0, 0,1);
	cout << date<<endl;
	date(0, 13, 1);
	cout << date<<endl;

}


