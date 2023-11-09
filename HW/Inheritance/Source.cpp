#include<iostream>
#include<string>

using namespace std;
enum Habitat { Terrestrial_air=1, Aquatic=2, Soil=3, Gostal=4, None=5 };
class Animal {
private:
	string m_type;
	int m_speed;
	int m_weight;
	Habitat m_habitat;
public:
	Animal():m_type("none"),m_speed(0),m_weight(0),m_habitat(None){}
	Animal(string type, int speed, int weight, Habitat habitat) :m_type(type), m_speed(speed), m_weight(weight), m_habitat(habitat) {}
	void Show() {
		cout << "Type: " << m_type << endl;
		cout << "Speed: " << m_speed << endl;
		cout << "Weight: " << m_weight << endl;
		cout << "Habitat: " << m_habitat<< endl;
	}
	void Move(string move) {
		cout << "I am " << move << "ing" << endl;
	}
	void Say(string say) {
		cout << "I say " << say << endl;
	}

};
class Bird:public Animal{
	string m_move;
public:
	Bird(string type, int speed, int weight, Habitat habitat,string move) :m_move("fly"), Animal(type, speed, weight, Terrestrial_air) {}
	void Show() {
		Animal::Show();
	}
	void Move() {
		Animal::Move(m_move);
	}



};
class Reptile:public Animal{
	string m_move;
public:
	Reptile(string type, int speed, int weight, Habitat habitat, string move) :m_move("crawl"), Animal(type, speed, weight, Terrestrial_air) {}
	void Show() {
		Animal::Show();
	}
	void Move() {
		Animal::Move(m_move);
	}
};
class Fish:public Animal{
private:
	string m_move;
public:
	Fish(string type, int speed, int weight, Habitat habitat, string move) :m_move("swim"), Animal(type, speed, weight, Aquatic) {}
	void Show() {
		Animal::Show();
	}
	void Move() {
		Animal::Move(m_move);
	}
};
class Duck:public Bird{
private:
	string m_say;
public:
	Duck(string type, int speed, int weight, Habitat habitat, string move,string say="quack-quack") :m_say(say), Bird(type, speed, weight, habitat, move) {}
	void Show() {
		Bird::Show();
		Bird::Say(m_say);
		Bird::Move();
	}
};
class Cayman:public Reptile {
private:
	string m_say;
public:
	Cayman(string type, int speed, int weight, Habitat habitat, string move, string say = "shsss-shsss") :m_say(say), Reptile(type, speed, weight, habitat, move) {}
	void Show() {
		Reptile::Show();
		Reptile::Say(m_say);
		Reptile::Move();
	}
};
class Dorada:public Fish {
private:
	string m_say;
public:
	Dorada(string type, int speed, int weight, Habitat habitat, string move, string say = "---") :m_say(say), Fish(type, speed, weight, habitat, move) {}
	void Show() {
		Fish::Show();
		Fish::Say(m_say);
		Fish::Move();
	}
};

void main() {
	Animal animal= Animal();
	animal.Show();
	cout << "-----------------------------------" << endl;
	Bird b = Bird("Bird", 20, 2, Terrestrial_air, "fly");
	Reptile r = Reptile("Reptile", 20, 2, Terrestrial_air, "crawl");
	Fish f = Fish("Fish", 22, 12, Terrestrial_air, "swim");
	Duck duck = Duck("Bird", 15, 1, Terrestrial_air, "fly", "qua-qua");
	duck.Show();
	cout << "-----------------------------------" << endl;
	Cayman cayman = Cayman("Cayman", 20, 2, Terrestrial_air, "crawl", "shsss");
	cayman.Show();
	cout << "-----------------------------------" << endl;
	Dorada dorada = Dorada("Dorada", 20, 2, Terrestrial_air, "swim", "---");
	dorada.Show();
	cout << "-----------------------------------" << endl;


}
/*Завдання 1:
Створити базовий клас «Animal», який буде описувати тварину. 
Цей клас буде містити загальні характеристики, які притаманні 
кожній тварині:
•вид
•швидкість
•вага
•середовище мешкання
•і тд…
А також методи:
• Move – метод руху
• Show – вивід інформації на екран
• Say – подача звуку
• і тд…	
Створити похідні класи: Bird, Reptile, Fish.
Ці класи будуть наслідувати базовий клас Animal, додаючи до 
нього певні характкристики та методи, які притаманні кожному об’єкту.
Для кожного з видів створити хоча б по одному класу, який 
буде описувати конкретну тварину-представника. 
Ці класи повинні наслідувати характерний для них базовий клас 
(Bird, Reptile, Fish) та ініціалізувати їхні характеристики 
відповідно до тварини-представника.*/