#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;
void Init_arr(int* arr, int size);
void Switch(int* arr, int size);


void main() {
	srand(time(NULL));
	const int size = 11;
	int arr[size]{};
	Init_arr(arr, size);
	for (auto item : arr) {
		cout << setw(3) << item;
	}cout << endl;
	Switch(arr, size);
	for (auto item : arr) {
		cout << setw(3) << item;
	}cout << endl;
}
void Init_arr(int* arr,int size) {
	for (int i = 0; i < size; i++) {
		*(arr + i) = rand() % 50;
	}
}
void Switch(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		//if (i > 0) {
		//	int temp = *(arr+i);
		//	*(arr ) = *(arr + i+1);
		//	*(arr + i+1) = temp;
		//}
		if (i!=0||i % 2 == 0) {
			int temp = *(arr + i);
			*(arr + i) = *(arr + i - 1);
			*(arr + i - 1) = temp;
		}
	}
}