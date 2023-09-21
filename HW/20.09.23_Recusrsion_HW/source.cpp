#include <iostream>
#include <random>
#include <iomanip>

using namespace std;


int Power(int num, int pow);
void Asterisk(int num);
int SummOfRange(int start, int end);
int IdxOfStart(int arr[], int size, int i, int sum, int start_idx, int current_sum);

void main() {
	srand(time(NULL));
	//===============#1================
	/*1. Write a recursive function for finding the degree of a number.*/
	/*cout << "Enter a number: ";
	int num = 0; cin >> num;
	cout << "Enter the degree: ";
	int pow = 0; cin >> pow;
	cout<<num<<" in the power of "<<pow<<" is " << Power(num, pow);*/
	//===============#2================
	/*2. Write a recursive function that prints N stars
	in a row, the number N is given by the user. Illustrate the operation of the function with an example.
	illustrate the function with an example.*/
	/*cout << "Enter the number of asterisks: ";
	int num = 0; cin >> num;
	Asterisk(num);*/
	//===============#3================
	/*3.Write a recursive function that calculates the sum of
	of all numbers in the range from a to b. The user enters
	a and b. Illustrate the function with an example.*/
	//cout << "Enter number for start: ";
	//int start = 0; cin >> start;
	//cout << "Enter number for end: ";
	//int end = 0; cin >> end;
	//if (start <= end) {
	//	cout << "The summa of elements of range is " << SummOfRange(start, end) << "\n";
	//}
	//else {
	//	int tmp = 0;
	//	tmp=start;
	//	start = end;
	//	end = tmp;
	//	cout << "The summa of elements of range is " << SummOfRange(start, end) << "\n";
	//}
	//=================#4=====================
	/*4. Write a recursive function that takes a one-dimensional
	dimensional array of 100 randomly filled integers and finds the position
	and finds the position where the sequence of 10 numbers starts.
	a sequence of 10 numbers whose sum is minimal.	*/
	const int size = 100;
	int sum = 0;
	int start_idx = 0;
	int current_sum = 0;
	int i = 0;
	int arr[size];
	for (int i = 0; i < size; i++) {

		arr[i] = -50 + rand() % 100;
	}
	for (auto item : arr) {

		cout << setw(4) << item;
	}
	cout<<"\n"<<IdxOfStart(arr, size, i, sum,start_idx,current_sum);

}

int Power(int num, int pow) {
	if (pow > 0) {
		num *= num;
		pow--;
		return Power(num, pow - 1);
	}
	else {
		return num;
	}
}
void Asterisk(int num) {
	if (num > 0) {
		cout << "*";
		Asterisk(num - 1);
	}
	else {
		return;
	}
}
int SummOfRange(int start, int end) {
	if (start == end) {
		return start;
	}
	else {
		return start + SummOfRange(start + 1, end);
	}
}
int IdxOfStart(int arr[], int size,int i,int sum, int start_idx, int current_sum) {

	while (i < size-10) {
		for (int j = i; j < i+10; j++)
		{
			current_sum += arr[j];
		}
		if (current_sum > sum) {
			current_sum = sum;
			sum = 0;
			start_idx = i;
		}
		i++;
		return IdxOfStart(arr,size,i+1,sum,start_idx,current_sum);
	}
		return start_idx;
		
}
