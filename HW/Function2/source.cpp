#include <iostream>
#include <random>

using namespace std;

void DateDifference(int day1, int month1, int year1, int day2, int month2, int year2);
float Average(int arr[], int size);
void PosNegZero(int arr[], int size);
void main() {
	srand(time(NULL));
	//========================#1======================
	//cout << "First date___\n";
	//cout << "Enter day.\n";
	//int dayS = 0; cin >> dayS;
	//cout << "Enter month.\n";
	//int monthS = 0; cin >> monthS;
	//cout << "Enter year.\n";
	//int yearS = 0; cin >> yearS;
	//system("cls");
	//cout << "Second date___\n";
	//cout << "Enter day.";
	//int dayE = 0; cin >> dayE;
	//cout << "Enter month.\n";
	//int monthE = 0; cin >> monthE;
	//cout << "Enter year.\n";
	//int yearE = 0; cin >> yearE;
	//DateDifference(dayS, monthS,  yearS,  dayE,  monthE,  yearE);
	//===============================================================
	//=======================#2=================================
	//Function for find average of values of the array
	//const int size = 10;
	//int arr[size]{};
	//for (int i = 0; i < size; i++) {
	//	arr[i] = rand() % 20;
	//}
	//cout << "The average of values of the array is: " << Average(arr, size) << ".\n";
	//===================================================================
	//=============#3======================================
		//const int size = 10;
	//int arr[size]{};
	//for (int i = 0; i < size; i++) {
	//	arr[i] =-10+ rand() % 20;
	//}
	//PosNegZero(arr, size);
	//===========================================================

}
void DateDifference(int day1, int month1, int year1, int day2, int month2, int year2) {
	//Find the number of days from the begining of the age for first date
	unsigned int whole_days1 = 0;
	unsigned short leap_year_counter1 = 0;
	for (int i=1; i <year1; i++)
	{
		if (i % 4 == 0) {
			leap_year_counter1++;
		}
		whole_days1 += 365;

	}
	whole_days1 += leap_year_counter1;
	for (int i = 1; i < month1; i++) {
		switch (i) {
		case 1:
			whole_days1 += 30;
		case 2:
			whole_days1 += 28;
		case 3:
			whole_days1 += 31;
		case 4:
			whole_days1 += 30;
		case 5:
			whole_days1 += 31;
		case 6:
			whole_days1 += 30;
		case 7:
			whole_days1 += 31;
		case 8:
			whole_days1 += 31;
		case 9:
			whole_days1 += 30;
		case 10:
			whole_days1 += 31;
		case 11:
			whole_days1 += 30;
		case 12:
			whole_days1 += 31;
		default:
			break;
		}
	}
	whole_days1 += day1;
	//Find the number of days from the begining of the age for the second date
	unsigned int whole_days2 = 0;
	unsigned short leap_year_counter2 = 0;
	for (int i = 1; i < year2; i++)
	{
		if (i % 4 == 0) {
			leap_year_counter2++;
		}
		whole_days2 += 365;

	}
	whole_days2 += leap_year_counter2;
	for (int i = 1; i < month2; i++) {
		switch (i) {
		case 1:
			whole_days2 += 30;
		case 2:
			whole_days2 += 28;
		case 3:
			whole_days2 += 31;
		case 4:
			whole_days2 += 30;
		case 5:
			whole_days2 += 31;
		case 6:
			whole_days2 += 30;
		case 7:
			whole_days2 += 31;
		case 8:
			whole_days2 += 31;
		case 9:
			whole_days2 += 30;
		case 10:
			whole_days2 += 31;
		case 11:
			whole_days2 += 30;
		case 12:
			whole_days2 += 31;
		default:
			break;
		}
	}
	whole_days2 += day2;

	cout << "The different between the dates is " << whole_days2 - whole_days1 << " days\n";
}
float Average(int arr[], int size) {
	float average = 0.0;
	int summ = 0;
	for (int i = 0; i < size; i++)
	{
		summ += arr[i];
	}
	average = summ / float(size);
	return average;
}
void PosNegZero(int arr[], int size) {
	int posCounter = 0;
	int negCounter = 0;
	int zeroCounter = 0;
	for (int i = 0; i < size;i++) {
		if(arr[i]>0){
			posCounter++;
		}
		else if (arr[i] < 0) {
			negCounter++;
		}
		else {
			zeroCounter++;
		}
	}
	cout << "Positive elements: "<<posCounter<<".\nNegative elements: "<<negCounter<<".\nElements equal to zero: "<<zeroCounter<<".\n";
}