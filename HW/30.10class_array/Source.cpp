#include <iostream>
#include <string>


using namespace std;

class Array
{
private:
    int size;
    int* arr;
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }
    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 30;
        }
    }
    Array(int size, int a)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 30;
        }
    }
    operator int() {
        int res = 0;
        for (int i = 0; i < size; i++)
        {
            res += arr[i];
        }
        return res;
    }
    operator string() {
        string res = "";
        for (int i = 0; i < size; i++)
        {
            res += to_string(arr[i]) + " ";
        }
        return res;
    }
    int& operator  [](const int idx) {
        return arr[idx];
    }
    int* operator ()(int num) {
        for (int i = 0; i < size; i++)
        {
            arr[i]+=num;
        }
        return arr;
    }

    //ostream& operator << (ostream& out, const Array& arr)
    //{
    //    out << "X : " << point.x << " Y : " << point.y << endl;
    //    return out;
    //}
    //istream& operator >>(istream& in, Point& other)
    //{
    //    in >> other.x;
    //    in >> other.y;
    //    return in;
    //}
    ~Array()
    {
        delete[]arr;
    }

    void print()const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

    }

};

void main() {
    Array arr = Array(10);
    arr.print();
    cout << endl;
    cout << arr[1];
    cout << endl;
    arr(1);
    arr.print();
}