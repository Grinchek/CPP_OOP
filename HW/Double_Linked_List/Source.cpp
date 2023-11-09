#include <iostream>
using namespace std;

template<typename T>
class List
{
	struct Node
	{
		Node* prev;
		T value;
		Node* next;
		Node(Node* prev, T value, Node* next) :prev(prev), value(value), next(next) {}
	};
private:
	Node* head;
	Node* tail;
	int size;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	void AddToHead(T value)
	{
		Node* newNode = new Node(nullptr, value, head);

		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			head = newNode;
		}
		size++;
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
		Node* newNode = new Node(tail, value, nullptr);

		if (IsEmpty())
			head = tail = newNode;
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	void AddToPosition(int pos, T value) {
		if (pos < 1 || pos > size + 1) return;
		else if (pos == 1) {
			AddToHead(value);
		}
		else if (pos == size + 1) {
			AddToTail(value);
		}
		else {
			Node* current = head;
			for (int i = 1; i < pos - 1; i++) {
				current = current->next;
			}
			Node* newNode = new Node(current, value, current->next);
			current->next->prev = newNode;
			current->next = newNode;
			size++;
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
	T operator[](int pos)
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
		if (IsEmpty())return;
		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		size--;
	}
	void DeleteFromHead() {
		Node* current = head;
		head = head->next;
		delete current;
	}
	int GetSize()
	{
		return size;
	}
	void DeleteByPosition(int pos)//4
	{
		if (pos < 1 || pos > size)return;
		else if (pos == 1)
		{
			DeleteFromHead(); 
		}
		else if (pos == size)
		{
			DeleteFromTail();
		}
		else
		{
			Node* current;
			if (pos <= size / 2)
			{
				current = head;
				for (int i = 1; i < pos; i++)
				{
					current = current->next;
				}
			}
			else
			{
				current = tail;
				for (int i = size; i > pos; i--)
				{
					current = current->prev;
				}
			}

			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
			size--;
		}

	}
};
struct Vagon
{
	int m_seats_number;
	int m_passengers;
	Vagon()
	{
		m_seats_number = 0;
		m_passengers = 0;
	}
	Vagon(int seats_number, int passengers)
	{
		m_seats_number = seats_number;
		m_passengers = passengers;
	}

	void Show()
	{
		cout << "Amount of places: " << m_seats_number << endl;
		cout << "Amount of passengers: "<< m_passengers << endl;
	}
};

class Train
{
private:
	string m_model;
	int countVagons;
	List<Vagon> vagons;
public:
	Train(string model, int seats_number, int passengers){
		m_model = model;
		countVagons = 0;
		Vagon vagons(seats_number, passengers);
	}
	void AddToHead( int seats_number, int passengers) {
		countVagons++;
		vagons.AddToHead(Vagon( seats_number, passengers));
	}
	void AddToTail( int seats_number, int passengers) {
		countVagons++;
		vagons.AddToTail(Vagon( seats_number, passengers));
	}
	void AddByPos(int pos,Vagon v) {
		if (pos > countVagons)return;
		countVagons++;
		vagons.AddToPosition(pos, v);
	}
	void DeleteFromHead() {
		countVagons++;
		vagons.DeleteFromHead();
	}
	void DeleteFromTail() {
		countVagons--;
		vagons.DeleteFromTail();
	}
	void DeleteByPosition(int pos)
	{
		countVagons--;
		vagons.DeleteByPosition(pos);
	}
	string GetModel() {
		return m_model;
	}

	void Print() {
		for (int i = 1; i <= countVagons; i++) {
			cout << GetModel() << endl;
			cout << "Wagon number: " << i << endl;
			vagons.GetElementByPosition(i).Show();
		}
	}
};

int main()
{
	Train ukrsalisnytsia=Train("mk2", 0, 0);
	
	for (int i = 1; i <= 2; i++) {
		ukrsalisnytsia.AddToHead(i+2,i+3);
	}
	for (int i = 1; i <= 2; i++) {
		ukrsalisnytsia.AddToTail(i, i);
	}
	cout << "==========================================" << endl;
	ukrsalisnytsia.Print();
	cout << "==========================================" << endl;
	ukrsalisnytsia.AddByPos(2, Vagon(10, 10));
	cout << "Adding an element to position 2" << endl;
	cout << "==========================================" << endl;
	ukrsalisnytsia.Print();
	ukrsalisnytsia.DeleteByPosition(1);
	cout << "==========================================" << endl;
	cout << "Deleting an element from position 1" << endl;
	cout << "==========================================" << endl;
	ukrsalisnytsia.Print();
	cout << "==========================================" << endl;






}