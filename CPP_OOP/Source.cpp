#include <iostream>
#include <random>

using namespace std;

void main() {
	/*bool ex = false;
	int enter = 0;
	int a = 10;
	while (!ex) {
		cout << "Choose the squere(1-10): "; cin >> enter;
		switch (enter) {
		case 1:
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < a; j++) {
					if (i > j) {
						cout << "   ";
					}
					else {
						cout << " * ";
					}

				}cout << "\n";
			}
			break;
		case 2:
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < a; j++) {
					if (i > j) {
						cout << " * ";
					}

				}cout << "\n";
			}
			break;
		case 3:

			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < a; j++) {
					if (i < j && (i + j) <= (a-1)) {
						cout << "   ";
					}
					else if (j < i && (i + j) >= (a)) {
						cout << "   ";
					}
					else {
						cout << " * ";
					}

				}cout << "\n";
			}
			break;
		case 7:
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < a; j++) {
					if (i > j && (i + j) <= (a - 1)) {
						cout << " * ";
					}
					else {
						cout << "   ";
					}

				}cout << "\n";
			}
			break;

		case 8:
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < a; j++) {
					if (j>i&&(i+j)>=a-1) {
						cout << " * ";
					}
					else {
						cout << "   ";
					}

				}cout << "\n";
			}
			break;
		case 9:
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < a; j++) {
					if (i < j) {
						cout << " * ";
					}

				}cout << "\n";
			}
			break;
		case 10:

			break;
		case 0:
			ex = true;
			break;
		default:
			break;

		}
	}*/
srand(time(NULL));
//int arr[10];
//int sum = 0;
//for (int i = 0; i < 10; i++) {
//	arr[i] =-100+(rand()%200);
//}
//for (int n : arr) {
//	cout << n << "\n";
//}
//for (int i = 0; i < 10; i++) {
//	if (arr[i] < 0) {
//		sum += arr[i];
//	}
//}
//cout << sum;

//int arr[10];
//int max = 0;
//int min = 0;
//for (int i = 0; i < 10; i++) {
//	arr[i] =-100+(rand()%200);
//}
//for (int n : arr) {
//	cout << n << "\n";
//}
//for (int i = 0; i < 10; i++) {
//	if (arr[i] < min) {
//		min = arr[i];
//	}
//	else if (arr[i] > max) {
//		max = arr[i];
//	}
//}
//cout << "max" << max<<"\n";
//cout << "min" << min<<"\n";

int arr[10];
int first = 0;
int last = 0;
for (int i = 0; i < 10; i++) {
	arr[i] =-100+(rand()%200);
}
for (int n : arr) {
	cout << n << "\n";
}
for (int i = 0; i < 10; i++) {
	if (arr[i] < 0) {
		first = arr[i];
		i = 10;
	}

}
for (int i = 0; i < 10; i++) {
		if (arr[i] > 0) {
			last = arr[i];
	}
}
{

}
cout << "first" << first<<"\n";
cout << "last" << last<<"\n";
}