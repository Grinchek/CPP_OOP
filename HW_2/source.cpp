#include <iostream>

using namespace std;
#include <random>

void main() {
	srand(time(NULL));
	//==========#1==========
	//������� �� ����� n �������, ���� 2n �����,
	//���� 3n �����.����� n ������� ����������.
	/*cout << "Enter number : ";
	int n = 0; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "[1]";
	}cout << "\n";
	for (int i = 0; i < n*2; i++)
	{
		cout << "[2]";
	}cout << "\n";
	for (int i = 0; i < n*3; i++)
	{
		cout << "[3]";
	}cout << "\n";*/
	//==========#2==========
	/*������� �� ����� ������� � ���� � �������,
	������� ��� ����������� ����� �� ������� ��������.
	����� � ������� ��� ����.*/
	/*int size = 10;
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++) {
			if (j != i) {
				cout << " 1 ";
			}
			else {
				cout << " 0 ";
			}
		}cout << "\n";
	}*/
	//==========#3==========
	/*������� ��� �����: ������ �������, ���'��� ���'����, 
	��� �����, ..., ���� �������. 
	������ ���� ��� ��� �����.*/
	/*for (int i = 10; i >= 0; i--)
	{
		for (int j = 10; j >= 0; j--) {
			if (i > j) {
				cout << i;
			}
		}cout << "\n";
	}*/
	//==========#4==========
	/*������� �� ����� 15 �����. � ������ � ������� �������� 
	������� �� 8 �����, ����� ������ �����. � ������ � 
	��������� �������� ������� ������ �������.*/
	//for (int i = 1; i <= 15; i++)
	//{
	//	if (i % 2 == 0) {
	//		for (int j = 0; j < 8; j++)
	//		{
	//			cout <<"["<< i<<"]";
	//		}cout << "\n";
	//	}
	//	else {
	//		for (int k = 0; k < 10; k++)
	//		{
	//			cout <<"["<< 1<<"]";
	//		}cout << "\n";
	//	}
	//}
	//==========#5==========
	/* ������� 30 �����. ������ ����� ������ ��������� ����� 
	�� 1 �� ������ ��������� ����� ������� � ������ 1, 
	���� ����� ����������� � �'��� �������.*/
	/*	for (int i = 1; i <= 30; i++)
	{
		if (i % 2 == 0) {
			for (int j = 0; j < 5; j++)
			{
				cout <<"["<< 1<<"]";
			}cout << "\n";
		}
		else {
			for (int k = 1; k <=i; k++)
			{
				cout <<"["<< k<<"]";
			}cout << "\n";
		}
	}*/
	//==========#6==========
	/*������� �� ����� ������� �������� ��� ����� �� 1 �� 10.*/
	/*for (int i = 1; i <=10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << "[" << i << "] * [" << j << "] = [" << i * j << "]\n";
		}cout << "==================\n";
	}*/
	//==========#7==========
	/*������� ������� ����� ����� �� a �� b �������, 
	�� ������� �� 12.*/
	//cout << "Enter edges of range :\n";
	//int a=0; cin >> a;
	//int b=0; cin >> b;
	//int start = 0, end = 0;
	//int counter = 0;
	//if (a < b) {
	//	start = a;
	//	end = b;
	//}
	//else if (a > b) {
	//	start = b;
	//	end = a;
	//}
	//else {
	//	start = a;
	//	end = a;
	//}
	//for (int i = start; i <= end; i++)
	//{
	//	if (i % 12 == 0) {
	//		counter++;
	//	}
	//}
	//if (counter > 0) {
	//	cout << "Suma of number divided on 12 is " << counter<<"\n";
	//}
	//else {
	//	cout << "There is no result.";
	//}
	//==========#7==========
	//���������� ������� �������� ����� �� ��(12
	//	������).���� ���������� ������� �������(���������,
	//		3 � 6 � ����� �� ����� � ������ ������).���������
	//	��������� �����, � ����� �������� ��� ������������, �
	//	�����, � ����� �������� ��� ���������, � �����������
	//	�������� ��������.
	/*const int length = 12;
	float year[length] = {};
	for (int i = 0; i < length; i++)
	{
		year[i] = 100 + (rand() % 300);
	}
	cout << "Enter edges of range :\n";
	int start = 0; cin >> start;
	int end = 0; cin >> end;
	float max = 0;
	int max_index = 0;
	float min = year[0];
	int min_index = 0;
	int id = 1;
	for (float item : year) {
		cout <<id<<". "<< item << "\n";
		id++;
	}
	for (int i = start-1; i < end; i++)
	{
		if (year[i] > max) {
				max = year[i];
				max_index = i+1;
			}
		else if (year[i] < min) {
			min = year[i];
			min_index = i + 1;
		}
	}
	cout << "Maximum profit of the company was in month " << max_index << ". " << max << " thousands $.\n";
	cout << "Minimal profit of the company was in month " << min_index << ". " << min << " thousands $.\n";*/
	
}