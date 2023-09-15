#include <iostream>
#include<random>
#include <iomanip>



using namespace std;

const int row = 10;
const int col = 10;
int array[row][col]{};

void init_matrix(int a, int arr[row][col]);
void show_matrix(int a, int arr[row][col]);
void right_top(int a,int arr[row][col]);
void left_top(int a, int arr[row][col]);
void right_bottom(int a, int arr[row][col]);
void left_bottom(int a, int arr[row][col]);
void inverted_pyramid(int a, int arr[row][col]);
void simple_pyramid(int a, int arr[row][col]);
void right_pyramid(int a, int arr[row][col]);
void left_pyramid(int a, int arr[row][col]);
void vertical_watch(int a, int arr[row][col]);
void horizontal_watch(int a, int arr[row][col]);

void main() {
	srand(time(NULL));
	int a = 10;
	int arr[row][col]{};
	init_matrix(a, arr);

	
	
	cout << "--------------------------------------\n";
	right_top(a,arr);
	cout << "--------------------------------------\n";
	left_top(a,arr);
	cout << "--------------------------------------\n";
	right_bottom(a,arr);
	cout << "--------------------------------------\n";
	left_bottom(a,arr);
	cout << "--------------------------------------\n";
	inverted_pyramid(a,arr);
	cout << "--------------------------------------\n";
	simple_pyramid(a,arr);
	cout << "--------------------------------------\n";
	right_pyramid(a,arr);
	cout << "--------------------------------------\n";
	left_pyramid(a,arr);
	cout << "--------------------------------------\n";
	vertical_watch(a,arr);
	cout << "--------------------------------------\n";
	horizontal_watch(a,arr);

}

void init_matrix(int a, int arr[row][col]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = -20 + rand() % 40;
		}
	}
}
void show_matrix(int a, int arr[row][col]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(5) << arr[i][j];
		}
		cout << "\n";
	}
}

void right_top(int a, int arr[row][col]) {
	int max = arr[0][0];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++)
		{
			if (j < (a - i)-1) {
				cout << "   ";
			}
			else {
				cout << setw(3)<<arr[i][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}

		}
		cout << "\n";
	}
	cout << "___________________________________\nMaximal value in area is: " << max << "\n";
}
//======================================================
void left_top(int a, int arr[row][col]) {
	int max = arr[0][0];
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++) {
			if (j > i) {
				cout << "  ";
			}
			else {
				cout <<setw(3)<<arr[i][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}
		}
		cout << "\n";
	}
	cout << "___________________________________\nMaximal value in area is: " << max << "\n";
}
//======================================================
void right_bottom(int a, int arr[row][col]) {
	int max = arr[0][0];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++)
		{
			if (j >= a - (a - i)) {
				cout << setw(3) << arr[i][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}
			else {
				cout << "   ";
			}

		}
		cout << "\n";
	}
	cout << "___________________________________\nMaximal value in area is: " << max << "\n";
}
//======================================================
void left_bottom(int a, int arr[row][col]) {
	int max = arr[0][0];
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j < a; j++)
		{
			if (j >= j && j <= (a - i) - 1) {
				cout <<setw(3)<<arr[i][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}
			else {
				cout << "   ";
			}

		}
		cout << "\n";
	}
	cout << "___________________________________\nMaximal value in area is: " << max << "\n";
}
//===========================================
void inverted_pyramid(int a, int arr[row][col]) {
	int max = arr[0][0];
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++) {
			if (j >= i && (j >= j && j <= (a - i) - 1)) {
				cout <<setw(3)<<arr[i][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}
			else {
				cout << "   ";
			}
		}
		cout << "\n";
	}
	cout << "___________________________________\nMaximal value in area is: " << max << "\n";
}
void simple_pyramid(int a, int arr[row][col]) {
	int max = arr[0][0];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++)
		{
			if (j < (a - i) - 1 || (j > i)) {
				cout << "   ";
			}
			else {
				cout <<setw(3)<<arr[i][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}

		}
		cout << "\n";
	}
	cout << "___________________________________\nMaximal value in area is: " << max << "\n";
}
void right_pyramid(int a, int arr[row][col]) {
	int max = arr[0][0];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++)
		{
			if ((j < (a - i) - 1) || (j < a - (a - i))) {
				cout << "   ";
			}
			else {
				cout << setw(3)<<arr[i][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}

		}
		cout << "\n";
	}
	cout << "___________________________________\nMaximal value in area is: " << max << "\n";
}
void left_pyramid(int a, int arr[row][col]) {
	int max = arr[0][0];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++)
		{
			if ((j > (a - i) - 1) || (j > a - (a - i))) {
				cout << "   ";
			}
			else {
				cout <<setw(3)<<arr[i][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}

		}
		cout << "\n";
	}
	cout << "___________________________________\nMaximal value in area is: " << max << "\n";
}
void vertical_watch(int a, int arr[row][col]) {
	int max = arr[0][0];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if ((j >= i && j < a - i) || (j <= i && j >= a - i - 1)) {
				cout << setw(3) << arr[i][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}
			else {
				cout << "   ";
			}
		}

		cout << "\n";
	}
	cout << "___________________________________\nMaximal value in area is: " << max << "\n";

}
void horizontal_watch(int a, int arr[row][col]) {
	int max = arr[0][0];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if ((j > i && j < a - i - 1) || (j < i && j >= a - i)) {
				cout << "   ";
			}
			else {
				cout << setw(3) << arr[i][j];
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
			}
		}

		cout << "\n";
	}
	cout << "___________________________________\nMaximal value in area is: " << max << "\n";
	}
