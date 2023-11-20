#include <iostream>
#include <vector>

using namespace std;

void main() {
	//==========1==========
	/*Користувач вводить число.Визначити кількість цифр у цьому числі, порахувати їхню суму та середнє
	арифметичне.Визначити кількість нулів у цьому числі.
	Спілкування з користувачем організувати через меню.*/

	//bool ex = false;

	//while (ex==false)
	//{
	//	string enter="";
	//	int sum = 0;
	//	float arithmetic_mean = 0.0;
	//	int count_of_zero = 0;
	//	int counter = 0;
	//	cout << "Enter number: ";
	//	cin >> enter; cin.ignore();
	//	vector <int> num;
	//	for (auto item : enter) {
	//		num.push_back(int(item)-48);
	//	}
	//	for (int number : num) {
	//		counter++;
	//		sum += number;
	//		if (number == 0) {
	//			count_of_zero++;
	//		}
	//	}
	//	arithmetic_mean = (sum / float(num.size()));
	//	while (ex == false) {
	//		system("cls");
	//		cout << "Please, make your choice:\n";
	//		cout << "1.Show number of digits.\n";
	//		cout << "2.Show the sum of all members of entered number.\n";
	//		cout << "3.Show the arithmetic mean of members of entered number.\n";
	//		cout << "4.Show the sum of zero in entered number.\n";
	//		cout << "5.Chooce all options.\n";
	//		cout << "0.Exit.\n";
	//		int choice = 0; cin >> choice;
	//		switch (choice) {
	//		case 1:
	//			cout << "There are " << counter << " digits\n";
	//			break;
	//		case 2:
	//			cout << "The sum of all members is " << sum << ".\n";
	//			break;
	//		case 3:
	//			cout << "The arithmetic mean of all members is " << arithmetic_mean << ".\n";
	//			break;
	//		case 4:
	//			cout << "The sum of zero is " << count_of_zero << ".\n";
	//			break;
	//		case 5:
	//			cout << "There are " << counter << " digits\n";
	//			cout << "The sum of all members is " << sum << ".\n";
	//			cout << "The arithmetic mean of all members is " << arithmetic_mean << ".\n";
	//			cout << "The sum of zero is " << count_of_zero << ".\n";
	//			break;
	//		case 0:
	//			ex = true;
	//			break;
	//		default:
	//			cout << "Wrong choise.";
	//		}
	//		system("pause");
	//	}
	//	
	//}
	//==========#2==========
	/*Написати програму, яка виводить на екран
	шахову дошку із заданим розміром клітинки.Наприклад,
	***---***---***---***---
	---***---***---***---***
	***---***---***---***---
	---***---***---***---***
	***---***---***---***---
	---***---***---***---***
	*/
	int row = 7;
	int col = 2;
	char sign = 219;
	cout << "Enter the size of unit :\n";
	int unit = 0; cin >> unit;
	for (int uper_line = 0; uper_line < (col *2) * unit; uper_line++) {
		cout << "-";
	}cout<<"--\n";
	for (int i = 0; i < row; i++)
	{
		cout << "|";
		for (int j = 0; j < col; j++)
		{
			if(i%2!=0){
				for (int k = 0; k < unit; k++) {
					cout << " ";
				}
				for (int k = 0; k < unit; k++) {
					cout << sign;
				}
			}
			else {
				for (int k = 0; k < unit; k++) {
					cout << sign;
				}
				for (int k = 0; k < unit; k++) {
					cout << " ";
				}
				
			}

	
		}cout << "|\n";
	}
	for (int uper_line = 0; uper_line < (col * 2) * unit; uper_line++) {
		cout << "-";
	}cout << "--\n";
}