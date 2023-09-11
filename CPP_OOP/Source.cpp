#include <iostream>

using namespace std;

void main() {
	bool ex = false;
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
	}


}