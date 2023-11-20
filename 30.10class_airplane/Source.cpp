#include <iostream>
#include <string>


using namespace std;

class Airplane {
private:
    string model;
    string type;
    int passengers;
    const int MAX_PASSENGERS;



public:

    Airplane() : MAX_PASSENGERS(100), model("no"), type("no"), passengers(0) {}
    explicit Airplane(int max_passangers) : MAX_PASSENGERS(max_passangers), model("no"), type("no"), passengers(0) {}



    friend ostream& operator << (ostream& out, const Airplane& point);
    friend istream& operator >>(istream& in, Airplane& other);
    friend bool operator == (const Airplane plane1, const Airplane plane2);
    friend bool operator > (const Airplane plane1, const Airplane plane2);
    int operator ++() {
        if ((this->passengers + 1) <= this->MAX_PASSENGERS) {
            return ++passengers;
        }
    }
    int operator --() {
        if ((this->passengers - 1) >= 0) {
            return --passengers;
        }
    }
    int& operator ()(const int num) {
        if ((this->passengers + num) <= this->MAX_PASSENGERS) {
            return this->passengers += num;
        }
    }



    operator string() {
        return model;
    }
};
ostream& operator << (ostream& out, const Airplane& point) {
    out << "Model: " << point.model << endl;
    out << "Type: " << point.type << endl;
    out << "Passengers: " << point.passengers << endl;
    out << "MAX_PASSENGERS: " << point.MAX_PASSENGERS << endl;
    return out;
}
istream& operator >>(istream& in, Airplane& other) {
    cout << "Enter model:" << endl;
    in >> other.model;
    cout << "Enter type: " << endl;
    in >> other.type;
    cout << "Enter passengers: " << endl;
    in >> other.passengers;

    return in;
}
bool operator == (const Airplane plane1, const Airplane plane2) {
    return (plane1.type == plane2.type);
}
bool operator > (const Airplane plane1, const Airplane plane2) {
    return (plane1.MAX_PASSENGERS > plane2.MAX_PASSENGERS);
}


void main() {
    /*  Airplane plane(20);
      cin >> plane;
      cout << plane<<endl;
      string str = "";
      str = plane;
      cout << str;*/
    Airplane plane1(5);
    cin >> plane1;
    Airplane plane2(10);
    cin >> plane2;
    if (plane1 == plane2) {
        cout << "Types of plane id equal." << endl;
    }
    else {
        cout << "The planes have different types." << endl;
    }
    if (plane1 > plane2) {
        cout << "Maximal load ability of plane1 is biger tan plane2" << endl;
    }
    else {
        cout << "Maximal load ability of plane1 is not biger tan plane2" << endl;
    }
    cout << "Before increment: \n" << plane1 << endl;
    ++plane1;
    cout << "After increment before decrement: \n" << plane1 << endl;
    --plane1;
    cout << "After decrement: \n" << plane1 << endl;
    plane1(2);
    cout << "After adding 2 passangers: \n" << plane1 << endl;







}