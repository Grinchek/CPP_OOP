#include <iostream>;
#include <random>

using namespace std;

void Show_rectangle(int n, int k);
void Factorial(int a);
void Prime_number(int number);
void Min_max_num_pos(int arr[],int size);

void main() {
	srand(time(NULL));

	const int size = 10;
	int array[size]{};
	for (int i = 0; i < size; i++) {
		array[i] = -10 + rand() % 21;
	}

	Show_rectangle(5, 4);
	Factorial(3);
	Prime_number(121);
	Min_max_num_pos(array, size);

}
void Show_rectangle(int n, int k) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++) {
			cout << " [] ";
		}
		cout << "\n";
	}
}
void Factorial(int a) {
	int factorial = 0;
	for (int i = 1; i < a; i++)
	{
		factorial = i * (i + 1);
	}
	cout << "Factorial of " << a << " is " << factorial<<"\n";
}
void Prime_number(int number) {
	if (number % number == 0 && number % 1 == 0) {
		cout << number << " is prime number.\n";
	}
	else {
		cout << number << " is not prime number.\n";
	}
}
void Min_max_num_pos(int arr[],int size) {
	int max_value = arr[0];
	int min_value = arr[0];
	int max_pos = 0;
	int min_pos = 0;
	for (int i = 0; i < size; i++) {
		cout << "[" << arr[i] << "]";
		if (arr[i] > max_value) {
			max_value = arr[i];
			max_pos = i+1;
		}
		if (arr[i] < min_value) {
			min_value = arr[i];
			min_pos = i+1;
		}
	}
	cout << "\nMaximal value of array is " << max_value << ". Maximal position is " << max_pos << ".\n";
	cout << "Minimal value of array is " << min_value << ". Minimal position is " << min_pos << ".\n";
}