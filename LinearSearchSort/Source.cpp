#include <iostream>

using namespace std;

int LinearSearch(int arr[], int size, int key);
void SelectSort(int arr[], int size);
void BubleSort(int arr[], int size);
void ShakerSort(int arr[], int size);
void InsertSort(int arr[], int size);
void FirstTask(int arr[], int size, int variant=1);
int SearchNeg(int arr[],int size);
int SearchNegRev(int arr[], int size);
void SortInRange(int arr[], int size, int start, int end);

void main() {
	//===============================#1=======================
		/*1. Дан масив чисел розмірністю 10 елементів. Написа-
	ти функцію, яка сортує масив за зростанням або за
	спаданням, залежно від третього параметра функції.
	Якщо він дорівнює 1, сортування йде за спаданням,
	якщо 0, то за зростанням. Перші 2 параметри функ-
	ції — це масив і його розмір, третій параметр за за-
	мовчуванням дорівнює 1.*/
	//===============================#1=======================
	//const int size = 10;
	//int arr[size];
	//for (int i = 0; i < size; i++) {
	//	arr[i] = rand() % 100;

	//	cout << arr[i] << " ";
	//}cout << endl;
	//FirstTask(arr, size);
	//for (auto item : arr) {
	//cout << item << " ";
	//}

	//cout << endl;
	//FirstTask(arr, size,0);
	//for (auto item : arr) {
	//	cout << item << " ";
	//}
	// ===============================#2=======================
	/*2. Дан масив випадкових чисел у діапазоні від -20 до
	+20. Необхідно знайти позиції крайніх від'ємних еле-
	ментів (найлівішого від'ємного елемента і найправі-
	шого від'ємного елемента) і впорядкувати елементи,
	що знаходяться між ними.*/
	const int size = 10;
	int arr[size];
	for (int i = 0; i < size; i++) {
		arr[i] =-20+ rand() % 40;
	}
	for (auto item : arr) {
	cout << item << " ";
	}
	cout << "\n";
	int start = SearchNeg(arr, size);
	int end = SearchNegRev(arr, size);
	SortInRange(arr, size, start, end);
	// // ===============================#2=======================
	//int key, idx;
	//const int size = 50;
	//int arr[size];
	//for (int i = 0; i < size; i++) {
	//	arr[i] =-100+ rand() % 200;
	//}
	////SelectSort(arr, size);
	////BubleSort(arr, size);
	////ShakerSort(arr, size);
	////InsertSort(arr, size);
	//for (auto item : arr) {
	//	cout << item << " ";
	//}
	//cout << "Enter key to search: ";
	//cin >> key;
	//idx=LinearSearch(arr, size, key);
	//if (idx != -1) {
	//	cout << "The key was found in idx: " << idx << " \n";
	//}
	//else {
	//	cout << "Not found.\n";
	//}
}
int LinearSearch(int arr[], int size, int key) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}	
void SelectSort(int arr[], int size) {
	int tmp,idx;
	for (int i = 0; i < size; i++)
	{
		idx = i;
		tmp = arr[i];
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < tmp) {
				tmp = arr[j];
				idx = j;
			}
		}
		if (idx != i) {
			arr[idx] = arr[i];
			arr[i] = tmp;
		}

	}
}
void BubleSort(int arr[], int size) {
	int tmp;
	for (int i = 0; i < size; i++) {
		for (int j = size-1; j > i; j--)
		{
			if (arr[j - 1] > arr[j]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
void BubleSortReverse(int arr[], int size) {
	int tmp;
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] < arr[j]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
void ShakerSort(int arr[], int size) {
	int j, idx = size - 1;
	int left = 1, right = size;
	int tmp;
	do {
		for ( j = right; j > 0; j--)
		{
			if(arr[j-1]>arr[j]){
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
				idx = j;
			}
		}
		left = idx + 1;
		for (j = 1; j <= right; j++)
		{
			if (arr[j - 1] > arr[j]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
				idx = j;
			}
		}right = idx - 1;

	} while (left < right);
}
void InsertSort(int arr[], int size) {
	int tmp;
	int j;
	for (int i = 0; i < size; i++)
	{
		tmp = arr[i];
		for ( j = i-1; j >= 0 &&arr[j]>tmp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}
void FirstTask(int arr[], int size, int variant) {
	int tmp=0;
	if (variant == 0) {
		BubleSortReverse(arr, size);
	}
	else {
		BubleSort(arr, size);
	}
}
int SearchNeg(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0) {
			return i;
		}
	}
}
int SearchNegRev(int arr[], int size) {
	for (int i = size-1; i > 0; i--)
	{
		if (arr[i] < 0) {
			return i;
		}
	}
}
void SortInRange(int arr[], int size, int start, int end) {
	int tmp;
	for (int i = start; i < end; i++) {
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
		cout << arr[i] << " ";
	}

}