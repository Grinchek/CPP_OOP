#include <iostream>
#include <iomanip>

using namespace std;


void main() {
	srand(time(NULL));
	//const int rows = 5;
	//const int cols = 6;

	//int arr[rows][cols]{ {},{} };
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++) {
	//		arr[i][j] = rand() % 100; cout <<setw(5)<< arr[i][j]<<" ";

	//	}cout << "\n";
	//}
	/*.Дано масив розміром 4×3 з елементами цілого типу.
	Визначити кількість елементів відмінних від нуля.*/
	/*const int rows = 4;
	const int cols = 3;
	int arr[rows][cols]{};
	int counter = 0;
	for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				arr[i][j] =-100+ rand() % 200; cout <<setw(5)<< arr[i][j]<<" ";
				if (arr[i][j] !=0 ) {
					counter++;
				}

			}cout << "\n";
		}
	cout << counter << "\n";*/
	/*Дано масив розміром 3×3 з елементами цілого типу.
	Визначити кількість елементів які б дорівнювали нулю.*/
	/*const int rows = 3;
	const int cols = 3;
	int arr[rows][cols]{};
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			arr[i][j] =-100+ rand() % 200; cout <<setw(5)<< arr[i][j]<<" ";
			if (arr[i][j] ==0 ) {
				counter++;
			}

		}cout << "\n";*/
		/*Дано масив розміром 7×3 з елементами цілого типу.
		Визначити кількість елементів, модуль яких менший 12. rand()%24- 12*/
	//const int rows = 7;
	//const int cols = 3;
	//int arr[rows][cols]{};
	//int counter = 0;
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++) {
	//		arr[i][j] = -20 + rand() % 40; cout << setw(5) << arr[i][j] << " ";
	//		if (arr[i][j] > -12 && arr[i][j]< 12) {
	//			counter++;
	//		}

	//	}cout << "\n";
	//}
	//cout << counter;
	/*.Дано масив розміром 4×5 з елементами цілого типу (позитивні та від’ємні). 
	Визначити кількість позитивних елементів.*/
	/*const int rows = 4;
	const int cols = 5;
	int arr[rows][cols]{};
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			arr[i][j] = -20 + rand() % 40; cout << setw(5) << arr[i][j] << " ";
			if (arr[i][j] > 0) {
				counter++;
			}

		}cout << "\n";
	}
	cout << counter; */
	/*Дано масив розміром 5×4 з елементами дійсного типу (додатні та від’ємні). 
	Визначити добуток всіх додатніх елементів.*/
	/*const int rows = 4;
	const int cols = 5;
	float arr[rows][cols]{};
	double counter=1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			arr[i][j] =( - 200 + rand() % 400)/10.0; cout << setw(5) << arr[i][j] << " ";
			if (arr[i][j] > 0) {
				counter *= arr[i][j];
			}

		}cout << "\n";
	}
	cout << counter;*/
	/*.Дано масив розміром 5×4 з елементами дійсного типу (позитивні та від’ємні). 
	Визначити добуток всіх від’ємних елементів.*/
	//const int rows = 4;
	//const int rows = 5;
	//const int cols = 4;
	//float arr[rows][cols]{};
	//double counter=1;
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++) {
	//		arr[i][j] =( - 200 + rand() % 400)/10.0; cout << setw(5) << arr[i][j] << " ";
	//		if (arr[i][j] < 0) {
	//			counter *= arr[i][j];
	//		}

	//	}cout << "\n";
	//}
	//cout << counter;
	/*.Дано масив розміром 4×4 з елементами цілого типу. Визначити кількість 
	елементів, які б при діленні на 6 давали залишок 1.*/
	//const int rows = 4;
	//const int cols = 4;
	//int arr[rows][cols]{};
	//int counter=0;
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++) {
	//		arr[i][j] =- 20 + rand() % 40; cout << setw(5) << arr[i][j] << " ";
	//		if (arr[i][j]%6== 1) {
	//			counter ++;
	//		}

	//	}cout << "\n";
	//}
	//cout << counter;
	/*Дано масив розміром 5хб цілого типу. Знайти мінімальний елемент.*/
	//const int rows = 4;
	//const int cols = 4;
	//int arr[rows][cols]{};
	//int min=0;
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++) {
	//		arr[i][j] =- 20 + rand() % 40; cout << setw(5) << arr[i][j] << " ";
	//		if (arr[i][j]<min) {
	//			min= arr[i][j];
	//		}

	//	}cout << "\n";
	//}
	//cout << min;
	/*.Дано масив розміром 5×6 цілого типу. Знайти максимальний елемент.*/
	//const int rows = 5;
	//const int cols = 6;
	//int arr[rows][cols]{};
	//int max=0;
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++) {
	//		arr[i][j] =- 20 + rand() % 40; cout << setw(5) << arr[i][j] << " ";
	//		if (arr[i][j]>max) {
	//			max= arr[i][j];
	//		}

	//	}cout << "\n";
	//}
	//cout << max;
	/*Дано масив розміром 5×4 з елементами дійсного типу (позитивні та від’ємні). 
	Визначити суму всіх від’ємних елементів.*/
	//const int rows = 5;
	//const int cols = 4;
	//int arr[rows][cols]{};
	//int counter=0;
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++) {
	//		arr[i][j] =- 20 + rand() % 40; cout << setw(5) << arr[i][j] << " ";
	//		if (arr[i][j]<0) {
	//			counter++;
	//		}

	//	}cout << "\n";
	//}
	//cout << counter;
	
}