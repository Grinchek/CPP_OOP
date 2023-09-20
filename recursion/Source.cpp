#include <iostream>

using namespace std;

//int Foo(int a) {
//
//	if (a < 1) {
//		return 0;
//	}
//	cout << "Hello\n";
//	a--;
//	return Foo(a);
//}
//int SummArr(int arr[], int size) {
//	int sum = 0;
//	for (int i = 0; i < size; i++) {
//		sum += arr[i];
//	}
//	return sum;
//}
//int Summa(int arr[], int size, int i) {
//	if (i + 1 == size) {
//		return arr[i];
//	}
//
//
//	return arr[i]+Summa(arr,size,i+1);
//}
//int CountNum(int arr[], int size, int i, int key) {
//	if (i == size) {
//		return 0;
//	}
//	if (key < arr[i]) {
//		return CountNum(arr, size, i + 1, key)+1;
//	}
//	else {
//		return CountNum(arr, size, i + 1, key);
//	}
//}
int Power(int num, int pow);
void Asterisk(int num);

void main() {
	//const int size = 7;
	//int arr[size]{ 1,2,3,4,5,6,7 };
	////cout << "Summ is:" << SummArr(arr, size) << "\n";
	////cout << Summa(arr, size, 0) << "\n";
	//cout << CountNum(arr, size, 0, 3) << "\n";
	/*2. Написати рекурсивну функцію знаходження ступеня числа.*/
	//cout << Power(5, 2) << "\n";
	/*3. Написати рекурсивну функцію, яка виводить N зірок
	у ряд, число N задає користувач. Проілюструйте ро-
	боту функції прикладом.*/
	Asterisk(6);
}
int Power(int num, int pow) {
	if (pow > 0) {
		num *= num;
		pow--;
		return Power(num, pow-1);
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