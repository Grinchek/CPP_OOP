#include <iostream>

using namespace std;
#include <random>

void main() {
	srand(time(NULL));
	//==========#1==========
	//Вивести на екран n одиниць, потім 2n двійок,
	//потім 3n трійок.Число n вводить користувач.
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
	/*Виведіть на екран квадрат з нулів і одиниць,
	причому нулі знаходяться тільки на діагоналі квадрата.
	сього в квадраті сто цифр.*/
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
	/*Вивести ряд чисел: десять десяток, дев'ять дев'яток, 
	вісім вісімок, ..., одну одиницю. 
	Знайти суму всіх цих чисел.*/
	/*for (int i = 10; i >= 0; i--)
	{
		for (int j = 10; j >= 0; j--) {
			if (i > j) {
				cout << i;
			}
		}cout << "\n";
	}*/
	//==========#4==========
	/*Вивести на екран 15 рядків. У рядках з парними номерами 
	вивести по 8 чисел, рівних номеру рядка. У рядках з 
	непарними номерами вивести десять одиниць.*/
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
	/* Вивести 30 рядків. Непарні рядки містять натуральні числа 
	від 1 до номера поточного рядка включно з кроком 1, 
	парні рядки складаються з п'яти одиниць.*/
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
	/*Виведіть на екран таблицю множення для чисел від 1 до 10.*/
	/*for (int i = 1; i <=10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << "[" << i << "] * [" << j << "] = [" << i * j << "]\n";
		}cout << "==================\n";
	}*/
	//==========#7==========
	/*Знайдіть кількість цілих чисел від a до b включно, 
	які діляться на 12.*/
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
	//Користувач вводить прибуток фірми за рік(12
	//	місяців).Потім користувач вводить діапазон(наприклад,
	//		3 і 6 — пошук між третім і шостим місяцем).Необхідно
	//	визначити місяць, у якому прибуток був максимальним, і
	//	місяць, у якому прибуток був мінімальним, з урахуванням
	//	обраного діапазону.
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