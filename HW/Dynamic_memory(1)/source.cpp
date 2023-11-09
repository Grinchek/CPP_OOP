#include <iostream>
#include <random>

using namespace std;
void Thre_variable();
int* Create_fill(int size);
void Show_arr(int* arr, int size);
void Add_to_end(int* &arr, int &size);
void Add_to_pos(int*& arr, int& size,int pos);
void Delete_end(int*& arr, int& size);
void Delete_pos(int*& arr, int& size, int pos);
void main() {
	srand(time(NULL));
	/*1.Create 3 dynamic variables of different types. 
	Fill them with some values. Calculate and display their product, 
	as well as the values of the dynamic variables themselves.*/
	//Thre_variable();
	/*2.Write functions to work with a dynamic one-dimensional array:
	A function to create a dynamic array of a specified size and 
	and filling it with random numbers. 
	The function returns the address of the created array.
	Outputting an array
	Adding one element to the array. 
	The function receives the array address, size and element to be added.
	Removing an element from the end.
	Deleting an element by index.
	Insert a new element at any valid position in the array
	Menu.*/
	cout << "Enter the size of array: ";
	int size = 0; cin >> size;
	int* arr= Create_fill(size);
	Show_arr(arr, size);
	Add_to_end(arr, size);
	Show_arr(arr, size);
	Delete_end(arr, size);
	Show_arr(arr, size);
	Add_to_pos(arr, size, 2);
	Show_arr(arr, size);
	Delete_pos(arr,size, 3);
	Show_arr(arr, size);


	delete[] arr;
}
void Thre_variable() {
	int* i = new int;
	float* f = new float;
	double* d = new double;

	*i = 1 + rand() % 9;
	*f = 1 + rand() % 99/10.0;
	*d = 1 + rand() % 999/100.0;
	cout <<"i = "<< * i << "\nf = " << *f << "\nd = " << *d << endl;
	cout << "The product: " << (*i) * (*f) * (*d) << endl;

	delete i;
	delete f;
	delete d;
}
int* Create_fill(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 1 + rand() % 99;
	}
	return arr;
}
void Show_arr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << " [" << arr[i] << "] ";
	}
	cout<< " \n";
}
void Add_to_end(int* &arr, int &size) {
	int* tmp = new int[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i]=arr[i];
	}
	tmp[size] = 1 + rand() % 99;
	delete[] arr;
	size++;
	arr = tmp;
}
void Delete_end(int*& arr, int& size) {
	int* tmp = new int[size-1];
	for (int i = 0; i < size-1; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	size--;
	arr = tmp;
}
void Add_to_pos(int*& arr, int& size, int pos) {
	int* tmp = new int[size + 1];
	for (int i = 0; i < pos; i++) {
		tmp[i] = arr[i];
	}
	tmp[pos] = 1 + rand() % 99;
	for (int i = pos+1; i <= size; i++) {
		tmp[i] = arr[i-1];
	}
	delete[] arr;
	size++;
	arr = tmp;
}
void Delete_pos(int*& arr, int& size, int pos) {
	int* tmp = new int[size -1];
	for (int i = 0; i < pos; i++) {
		tmp[i] = arr[i];
	}
	for (int i = pos; i < size-1; i++) {
		tmp[i] = arr[i+1];
	}
	delete[] arr;
	size--;
	arr = tmp;
}