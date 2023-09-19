#include <iostream>
#include <random>
#include <iomanip>

using namespace std;


void InitMatrix(int array[][10], int rows);
void InitMatrix(float array[][10], int rows);
void InitMatrix(double array[][10], int rows);
void ShowMatrix(int array[][10], int rows);
void ShowMatrix(float array[][10], int rows);
void ShowMatrix(double array[][10], int rows);
void MaxMin(int array[][10], int rows);
void MaxMin(float array[][10], int rows);
void MaxMin(double array[][10], int rows);
void SortRows(int array[][10], int rows);
void SortRows(float array[][10], int rows);
void SortRows(double array[][10], int rows);
void main() {
    srand(time(NULL));
    const int rows = 10;
    int arrInt[rows][rows]{};
    float arrFloat[rows][rows]{};
    double arrDouble[rows][rows]{};

    InitMatrix(arrInt, rows);
    InitMatrix(arrFloat,rows);
    InitMatrix( arrDouble, rows);
    ShowMatrix( arrInt, rows);
    SortRows(arrInt, rows);
    ShowMatrix(arrInt, rows);
    //MaxMin(arrInt, rows);
    ShowMatrix(arrFloat,rows);
    SortRows(arrFloat, rows);
    ShowMatrix(arrFloat, rows);
    //MaxMin(arrFloat, rows);
    ShowMatrix(arrDouble, rows);
    SortRows(arrDouble, rows);
    ShowMatrix(arrDouble, rows);
    //MaxMin(arrDouble, rows);
   
   
   

}
void InitMatrix(int array[][10], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            array[i][j] = -100+rand()%200;
        }
    }
}
void InitMatrix(float array[][10], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            array[i][j] =( - 1000 + rand() % 2000)/10.0;
        }
    }
}
void InitMatrix(double array[][10], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            array[i][j] = (-10000 + rand() % 20000) / 100.0;
        }
    }
}
void ShowMatrix(int array[][10], int rows) {
    cout << "=========== int matrix ============\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << setw(4) << array[i][j];
        }
        cout << "\n";
    }
}
void ShowMatrix(float array[][10], int rows) {
    cout << "=========== float matrix ============\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << setw(6) <<float( array[i][j]);
        }
        cout << "\n";
    }
}
void ShowMatrix(double array[][10], int rows) {
    cout << "=========== double matrix ============\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << setw(7) <<double( array[i][j]);
        }
        cout << "\n";
    }
}
void MaxMin(int array[][10], int rows) {
    int max = array[0][0];
    int min = array[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++) {
            if (j == i) {
                cout << setw(4)<< array[i][j];
                if (array[i][j] > max) {
                    max = array[i][j];
                }
                else if (array[i][j] < min) {
                    min= array[i][j];
                }
                
            }
            else {
                cout << "    ";
            }
        }
        cout << "\n";
    }
    cout << "__________________________________________\nMaximal value in area is: " << max << "\n";
    cout << "__________________________________________\nMinimal value in area is: " << min << "\n";
}
void MaxMin(float array[][10], int rows) {
    float max = array[0][0];
    float min = array[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++) {
            if (j == i) {
                cout << setw(6) << array[i][j];
                if (array[i][j] > max) {
                    max = array[i][j];
                }
                else if (array[i][j] < min) {
                    min = array[i][j];
                }

            }
            else {
                cout << "      ";
            }
        }
        cout << "\n";
    }
    cout << "____________________________________________________________\nMaximal value in area is: " << max << "\n";
    cout << "____________________________________________________________\nMinimal value in area is: " << min << "\n";
}
void MaxMin(double array[][10], int rows) {
    double max = array[0][0];
    double min = array[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++) {
            if (j == i) {
                cout << setw(7) << array[i][j];
                if (array[i][j] > max) {
                    max = array[i][j];
                }
                else if (array[i][j] < min) {
                    min = array[i][j];
                }

            }
            else {
                cout << "       ";
            }
        }
        cout << "\n";
    }
    cout << "_______________________________________________________________________\nMaximal value in area is: " << max << "\n";
    cout << "_______________________________________________________________________\nMinimal value in area is: " << min << "\n";
}
void SortRows(int array[][10], int rows) {
    cout << "=========== int matrix was sorted ============\n";
    int tmp=0;
    for (int k = 0; k < rows; k++)
    {
        for (int i = 0; i < rows; i++) {
            for (int j = rows-1; j > 0; j--)
            {
                if (array[k][j - 1] > array[k][j]) {
                    tmp = array[k][j - 1];
                    array[k][j - 1] = array[k][j];
                    array[k][j] = tmp;
                }
            }
        }
    }
    
}
void SortRows(float array[][10], int rows) {
    cout << "=========== float matrix was sorted ============\n";
    float tmp = 0;
    for (int k = 0; k < rows; k++)
    {
        for (int i = 0; i < rows; i++) {
            for (int j = rows - 1; j > 0; j--)
            {
                if (array[k][j - 1] > array[k][j]) {
                    tmp = array[k][j - 1];
                    array[k][j - 1] = array[k][j];
                    array[k][j] = tmp;
                }
            }
        }
    }
}
void SortRows(double array[][10], int rows) {
    cout << "=========== double matrix was sorted ============\n";
    double tmp = 0;
    for (int k = 0; k < rows; k++)
    {
        for (int i = 0; i < rows; i++) {
            for (int j = rows - 1; j > 0; j--)
            {
                if (array[k][j - 1] > array[k][j]) {
                    tmp = array[k][j - 1];
                    array[k][j - 1] = array[k][j];
                    array[k][j] = tmp;
                }
            }
        }
    }
}