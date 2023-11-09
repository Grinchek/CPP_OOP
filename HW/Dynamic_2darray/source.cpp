#include <iostream>
#include <random>


void Fill(int** arr, int row, int col);
void Mini_fill(int* arr, int col);
void Show(int** arr, int row, int col);
int** Add_row(int** arr, int& row, int col);
void Add_row_beg(int**& arr, int& row, int col);
int** Add_row_by_pos(int** arr, int& row, int col, int pos);
void Dell_last_row(int**& arr, int& row);
void Dell_first_row(int**& arr, int& row);
void Dell_pos_row(int**& arr, int& row, int pos);
void Add_col_end(int**& arr, int row, int& col);
void Add_col_pos(int**& arr, int row, int& col, int pos);
void Add_col_beg(int**& arr, int row, int& col);

using namespace std;

void main() {
	srand(time(NULL));
	int row = 4;
	int col = 5;


	int** arr = new int* [row];

	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}
	Fill(arr, row, col);
	Show(arr, row, col);
	cout << "=========================\n";
	//cout << "Enter row, col" << endl;
	//cin >> row;
	//cin >> col;
	//arr=Add_row(arr, row, col);
	//arr = Add_row_by_pos(arr, row, col, 0);
	Add_row_beg(arr, row, col);
	Show(arr, row, col);
	cout << "=========================\n";
	//Dell_first_row(arr, row);
	//Dell_pos_row(arr,row,1);
	//Add_col_pos(arr,row,col, 2);
	Add_col_beg(arr, row, col);
	Show(arr, row, col);
	/*Add_col_end(arr, row, col);
	Show(arr, row, col);*/

	//==============================
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
void Fill(int** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = rand() % 90 + 10;
		}
	}
}
void Show(int** arr, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}cout << endl;
	}
}
int** Add_row(int** arr, int& row, int col) {
	int** tmp = new int* [row + 1];
	for (int i = 0; i < row; i++) {
		tmp[i] = arr[i];
	}tmp[row] = new int[col];
	Mini_fill(tmp[row], col);
	delete[] arr;
	row++;
	return tmp;
}
void Add_row_beg(int**& arr, int& row, int col) {
	int** tmp = new int* [row + 1];
	for (int i = 1; i <= row; i++) {
		tmp[i] = arr[i - 1];
	}tmp[0] = new int[col];
	Mini_fill(tmp[0], col);
	delete[] arr;
	row++;
	arr = tmp;
}
void Mini_fill(int* arr, int col) {
	for (int i = 0; i < col; i++) {
		arr[i] = 10 + rand() % 20;
	}

}
int** Add_row_by_pos(int** arr, int& row, int col, int pos) {
	int** tmp = new int* [row + 1];
	for (int i = 0; i < pos; i++) {
		tmp[i] = arr[i];
	}tmp[pos] = new int[col];
	Mini_fill(tmp[pos], col);
	for (int i = pos + 1; i <= row; i++) {
		tmp[i] = arr[i - 1];
	}
	delete[] arr;
	row++;
	return tmp;
}
void Dell_last_row(int**& arr, int& row) {
	int** tmp = new int* [row - 1];
	for (int i = 0; i < row - 1; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr[row - 1];
	delete[] arr;
	row--;
	arr = tmp;

}
void Dell_first_row(int**& arr, int& row) {
	int** tmp = new int* [row - 1];
	for (int i = 0; i < row - 1; i++) {
		tmp[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	row--;
	arr = tmp;

}
void Dell_pos_row(int**& arr, int& row, int pos) {
	int** tmp = new int* [row - 1];
	for (int i = 0; i < pos; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr[pos];
	for (int i = pos; i < row - 1; i++) {
		tmp[i] = arr[i + 1];
	}

	delete[] arr;
	row--;
	arr = tmp;

}
void Add_col_end(int**& arr, int row, int& col) {
	int** tmp = new int* [row];
	for (int i = 0; i < row; i++) {
		tmp[i] = new int[col + 1];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	for (int i = 0; i < row; i++) {
		tmp[i][col] = 7;
	}
	col++;
	arr = tmp;

}
void Add_col_pos(int**& arr, int row, int& col, int pos) {
	int** tmp = new int* [row];
	for (int i = 0; i < row; i++) {
		tmp[i] = new int[col + 1];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < pos; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		tmp[i][pos] = 7;
	}
	for (int i = 0; i < row; i++) {
		for (int j = pos + 1; j <= col; j++) {
			tmp[i][j] = arr[i][j - 1];
		}
	}
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	col++;
	arr = tmp;

}
void Add_col_beg(int**& arr, int row, int& col) {
	int** tmp = new int* [row];
	for (int i = 0; i < row; i++) {
		tmp[i] = new int[col + 1];
	}
	for (int i = 0; i < row; i++) {
		tmp[i][0] = 7;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 1; j <= col; j++) {
			tmp[i][j] = arr[i][j - 1];
		}
	}
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	col++;
	arr = tmp;

}