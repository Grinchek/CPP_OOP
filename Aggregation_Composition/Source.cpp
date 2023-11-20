#include<iostream>

using namespace std;

class Driver {
private:
	string m_name;
	string m_surname;
	int m_age;
	int m_expirience;
public:
	Driver() :m_name("no name"), m_surname("no surname"), m_age(0), m_expirience(0) {}
	Driver(string n,string sn,int ag,int exp) :m_name(n), m_surname(sn), m_age(ag), m_expirience(exp) {}
	void ShowInfo() const {
		cout << "Driver:\n";
		cout << "Name: " << m_name << ".\n";
		cout << "Surname: " << m_surname << ".\n";
		cout << "Age: " << m_age << " years.\n";
		cout << "Expirience: " << m_expirience << " years.\n";
	}

};
class Door {
public:
	void Open() {
		cout << "Door is open." << endl;
	}
	void Close() {
		cout << "Door is close." << endl;
	}
};
class Body{
private:
	string m_body_type;
public:
	Body():m_body_type("no type"){}
	Body(string type) :m_body_type(type) {}

	void ShowInfo() {
		cout << "Body type: " << m_body_type << endl;

	}
};
class Engine{
private:
	int m_cylinders;
	float m_volume;
	string m_fuel;
public:
	Engine():m_cylinders(0),m_volume(0),m_fuel("no type"){}
	Engine(int cylinders,float volume,string fuel):m_cylinders(cylinders),m_volume(volume),m_fuel(fuel){}
	void ShowInfo() {
		cout << "Number of cylinders: " << m_cylinders << endl;
		cout << "Working volume: " << m_volume << endl;
		cout << "Fuel: " << m_fuel<< endl;
	}
};
class Wheel{
private:
	int m_radius;
public:
	Wheel() :m_radius(0){}
	Wheel(int radius):m_radius(radius){}
	void ShowInfo() {
		cout << "Wheels have radius " << m_radius << " inches.\n";
	}
};
class HeadLight{
private:
	string m_type;
public:
	HeadLight():m_type("no type"){}
	HeadLight(string type):m_type(type){}
	void ShowInfo() {
		cout << "The headlights have " << m_type << " type\n";
	}
};
class Car{
private:
	string m_producer;
	string m_mark;
	int m_num_doors;
	Door* m_doors;
	Body m_body;
	Engine m_engine;
	Wheel* m_wheels;
	HeadLight* m_head_lights;
	Driver* m_driver;
public:
	Car():m_producer("no producer"),m_mark("no mark"),m_num_doors(0), m_doors(nullptr), m_wheels(nullptr), m_head_lights(nullptr) {}
	Car(string producer, string mark,int num) :m_producer(producer), m_mark(mark),m_num_doors(num) {
		float vol = 1.6;
		m_doors = new Door[m_num_doors];
		m_body = Body("Sedan");
		m_engine = Engine(4, vol, "diesel");
		m_wheels = new Wheel[4];
		for (int i = 0; i < 4; i++) {
			m_wheels[i] = Wheel(17);
		}
		m_head_lights =  new HeadLight[2];
		for (int i = 0; i <2 ; i++) {
			m_head_lights[i] = HeadLight("matrix");
		}
	}
	void AddDriver(Driver* dr) {
		m_driver = dr;
	}
	void ShowInfo() {
		if (m_driver != nullptr) m_driver->ShowInfo();
		else cout << "There is no drivere in the car." << endl;
		cout << "Producer: " << m_producer<<endl;
		cout << "Model: " << m_mark<<endl;
		cout << sizeof(*m_doors)* m_num_doors << " doors" << endl;
		m_body.ShowInfo();
		m_engine.ShowInfo();
		m_wheels->ShowInfo();
		m_head_lights->ShowInfo();

	}
	~Car() {
		if (m_wheels != nullptr) {
			delete[] m_wheels;
		}

		if (m_head_lights != nullptr) {
			delete[] m_head_lights;
		}
		if (m_doors != nullptr) {
			delete[]m_doors;
		}
	}
};

int main() {
	Driver driver("Ivan","Hryn",30,5);
	driver.ShowInfo();
	cout << "||||||||||||||||||||||||||||||||||||||||||\n";
	Car car1("Citroen", "C5",4);
	car1.ShowInfo();
	cout << "||||||||||||||||||||||||||||||||||||||||||\n";
	car1.AddDriver(&driver);
	car1.ShowInfo();

	return 0;
}