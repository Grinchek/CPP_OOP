#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

void InitArr(int* arr, int size);
void ShowArr(int arr[], int size);
void SwapEven(int* arr, int size);
void SortArr(int* arr, int size);
void CompareArr(int* arr1, int* arr2, int* arr3, int size1, int size2, int size3);

void main() {
	srand(time(NULL));
	const int size = 10;
	const int size2 = 15;
	const int size3 = 25;
	int arr[size]{};
	int a[size]{};
	int b[size2]{};
	int c[size3]{};

	InitArr(arr, size);
	ShowArr(arr, size);
	SwapEven(arr, size);
	ShowArr(arr, size);
	InitArr(a, size);
	SortArr(a, size);
	ShowArr(a, size);
	InitArr(b, size2);
	SortArr(b, size2);
	ShowArr(b, size2);
	CompareArr(a, b, c, size, size2,size3);
	SortArr(c, size3);
	ShowArr(c,size3);

}
void InitArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		*(arr+i) = rand() % 20;
	}
}
void ShowArr(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		cout<<setw(3)<<arr[i];
	}cout << endl;
}
void SwapEven(int* arr, int size) {
	for (int i = 1; i < size; i+=2) {
		int tmp = *(arr+i);
		*(arr+i) = *(arr+(i - 1));
		*(arr+(i - 1)) = tmp;
	}
}
void SortArr(int* arr, int size) {
	int tmp;
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j > i; j--)
		{
			if (*(arr+(j - 1)) > *(arr+j)) {
				tmp = *(arr+(j - 1));
				*(arr + (j - 1)) = *(arr+j);
				*(arr+j) = tmp;
			}
		}
	}
}
void CompareArr(int* arr1, int* arr2, int* arr3, int size1, int size2, int size3) {
	for (int i = 0; i < size1; i++) {
			*(arr3 + i) = *(arr1 + i);
	}
	for (int i = size1; i < size1+size2; i++) {
		*(arr3 + i) = *(arr2 + (i-size1));
	}
}