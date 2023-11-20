#include <iostream>
#include<string>
#include "windows.h"


using namespace std;

void Gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
template<typename T>
class List

{
	struct Node
	{
		T value;
		Node* next;
		Node(T value, Node* next) :value(value), next(next) {}
	};
private:
	Node* head;
public:
	List()
	{
		head = nullptr;
	}
	void AddToHead(T value)
	{
		Node* newNode = new Node(value, head);
		head = newNode;
	}
	void PrintList()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}
	~List()
	{
		Node* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
	void AddToTail(T value)
	{
		Node* newNode = new Node(value, nullptr);

		if (head == nullptr)
			head = newNode;
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	T GetElementByPosition(int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
	}
	void DeleteFromTail()
	{
		if (head == nullptr)return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
	}
	void DeleteFromHead() {
		Node* current = head;
		head = head->next;
		delete current;
	}
};
class Point {
private:
	int m_x;
	int m_y;
public:
	Point() :m_x(0), m_y(0) {}
	Point(int x, int y) :m_x(x), m_y(y) {}
	Point operator ++ (int n) {
		m_x++, m_y++;
		return *this;
	}
	Point operator -- (int n) {
		m_x--, m_y--;
		return *this;
	}
	Point operator ! () {
		m_x = (-m_x);
		m_y = (-m_y);
		return *this;
	}
	bool operator < (Point p) {
		return (this->m_x < p.m_x && this->m_y < p.m_y);
	}
	bool operator > (Point p) {
		return (this->m_x > p.m_x && this->m_y > p.m_y);
	}
	void Print() {
		cout << "X:" << m_x << endl;
		cout << "Y:" << m_y << endl;
	}
	int GetX() {
		return m_x;
	}
	int GetY() {
		return m_y;
	}
};
class Vector
{
private:
	int size;
	List<Point> points;
public:
	Vector(int x, int y) {
		Point points(x,y);
		size = 0;
	}
	void AddToHead(int x, int y) {
		size++;
		points.AddToHead(Point(x, y));
	}
	void AddToTail(int x, int y) {
		size++;
		points.AddToTail(Point(x, y));
	}
	void DeleteFromHead() {
		size--;
		points.DeleteFromHead();
	}
	void DeleteFromTail() {
		size--;
		points.DeleteFromTail();
	}

	void PrintValue() {
		for (int i = 1; i <= size; i++) {
			points.GetElementByPosition(i).Print();
		}
	}
	void PrintPoints() {
		for (int i = 1; i <= size; i++) {
			Gotoxy(points.GetElementByPosition(i).GetX(), points.GetElementByPosition(i).GetY());
			cout << char(223) << endl;
		}
	}
};

int main()
{
	Vector v = Vector(0, 0);
	v.AddToTail(2, 2);
	v.AddToHead(1, 1);
	v.PrintValue();
	v.AddToTail(22, 10);
	v.DeleteFromHead();
	v.PrintValue();
	v.DeleteFromHead();
	v.PrintPoints();
	
}