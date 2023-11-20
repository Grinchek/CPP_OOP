#include <iostream>
#include <random>
#include <iomanip>

using namespace std;
int Product(int* a, int* b, int* c);
float Arithmetic_mean(int* a, int* b, int* c);
int Min(int* a, int* b, int* c);
int Product(int& a, int& b, int& c);
float Arithmetic_mean(int& a, int& b, int& c);
int Min(int& a, int& b, int& c);
void Swap(int& a, int& b);
void Init_matrix(int arr[][10], int row, int col);
void Show_matrix(int arr[][10], int row, int col);
void Init_arr(int* arr, int size);
void Show_arr(int* arr, int size);
void Reverse_show_arr(int* arr, int size);
int Summ_arr(int* arr, int size);
int Max_arr(int* arr, int size);
int Min_arr(int* arr, int size);


void main() {
	srand(time(NULL));
	const int size = 10;
	int arr[size]{};
	/*int a = 1;
	int b = 2;
	int c = 3;
	int* pa = &a;
	int* pb = &b;
	int* pc = &c;
	int product = 0; Product(pa, pb, pc);
	float arithmetic_mean = 0; Arithmetic_mean(pa, pb, pc);
	int min = 0; Min(pa, pb, pc);*/


	/*1.Three numbers are given. Declare the pointers to these numbers. Get the product of three
	given numbers, the arithmetic mean, the smallest of them, using
	indirect access to numbers (through pointers).*/
	//product = Product(pa, pb, pc);
	//arithmetic_mean = Arithmetic_mean(pa, pb, pc);
	//min = Min(pa, pb, pc);
	//cout << "a = " << a << ". b = " << b << ". c = " << c << ".\n";
	//cout << "product = " << product << ". arithmetic mean = " << arithmetic_mean << ". min = " << min << ".\n";
	/*2.Three numbers are given. Declare the references to these numbers.
	Get the product of the three given numbers, the arithmetic mean, the smallest of them,
	using indirect access to numbers (through a link)*/
	/*product = Product(&a, &b, &c);
	arithmetic_mean = Arithmetic_mean(&a, &b, &c);
	min = Min(&a, &b, &c);
	cout << "a = " << a << ". b = " << b << ". c = " << c << ".\n";
	cout << "product = " << product << ". arithmetic mean = " << arithmetic_mean << ". min = " << min << ".\n";*/
	/*3.Write a function (or template) that accepts two references to variables and
	performs the exchange of values. Using the written function, swap
	in the matrix, swap the first and second columns.*/
	/*const int row = 10;
	const int col = 10;
	int arr[row][col]{};
	Init_matrix(arr, row, col);
	Show_matrix(arr, row, col);
	for (int i = 0; i < row; i++) {
		Swap(arr[i][0], arr[i][1]);
	}
	cout << "==============================\n";
	Show_matrix(arr, row, col);*/

	/*4.An integer one-dimensional array is given. Fill it in, 
	display it in forward and reverse order and calculate 
	the sum of the elements using pointers.*/


	/*Init_arr(arr, size);
	Show_arr(arr, size);
	cout << "===============================\n";
	Reverse_show_arr(arr, size);
	int sum = Summ_arr(arr, size);
	cout << "Summ = " << sum << endl;*/
	
	/*5.Given a one-dimensional array. Find the largest and smallest values in 
	array and swap them in the array. Print the transformed 
	array on the screen.*/
	Init_arr(arr, size);
	Show_arr(arr, size);
	int min_idx = Min_arr(arr, size);
	int max_idx=Max_arr(arr, size);
	cout << "Maximal = " << arr[max_idx] << " Minimal = " << arr[min_idx] << endl;
	Swap(arr[min_idx], arr[max_idx]);
	Show_arr(arr, size);

}
int Product(int* a, int* b, int* c) {
	int product = (*a)*(*b)*(*c);
	return product;
}
float Arithmetic_mean(int* a, int* b, int* c) {
	float arithmetic_mean = ((*a) + (*b) + (*c)) / 4.0;
	return arithmetic_mean;
}
int Min(int* a, int* b, int* c) {
	if ((*a) < (*b) && (*a) < (*c)) {
		return *a;
	}
	else if ((*a) > (*b) && (*b) < (*c)) {
		return *b;
	}
	else if ((*c) < (*b) && (*a) > (*c)) {
		return *c;
	}
	
}
int Product(int& a, int& b, int& c) {
	int product = a * b * c;
	return product;
}
float Arithmetic_mean(int& a, int& b, int& c) {
	float arithmetic_mean = (a + b + c) / 4.0;
	return arithmetic_mean;
}
int Min(int& a, int& b, int& c) {
	int min = 0;
	if( a < b && a < c) {
		int min = a;
	}
	else if (a > b && b < c) {
		int min = b;
	}
	else if (c < b && a > c) {
		int min = c;
	}

	return min;

}
void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;

}
void Init_matrix(int arr[][10], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			arr[i][j] = rand() % 20;
		}
	}
}
void Show_matrix(int arr[][10], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			cout << setw(3) << arr[i][j];
		}cout << endl;
	}
}
void Init_arr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		*(arr + i) = rand() % 20;
	}
}
void Show_arr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout<<setw(3)<<*(arr + i);
	}
	cout << endl;
}
void Reverse_show_arr(int* arr, int size) {
	for (int i = size-1; i >=0; i--) {
		cout << setw(3) << *(arr + i);
	}
	cout << endl;
}
int Summ_arr(int* arr, int size) {
	int summ = 0;
	for (int i = size - 1; i >= 0; i--) {
		summ+= *(arr + i);
	}
	return summ;
}
int Max_arr(int* arr, int size) {
	int max = *(arr);
	int idx = 0;
	for (int i = 0; i < size; i++) {
		if (*(arr + i) > max) {
			max = *(arr + i);
			idx = i;
		}
	}
	return idx;
}
int Min_arr(int* arr, int size) {
	int min = *(arr);
	int idx = 0;
	for (int i = 0; i < size; i++) {
		if (*(arr + i) < min) {
			min = *(arr + i);
			idx = i;
		}
	}
	return idx;
}