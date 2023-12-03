#include "Post.h"

void Post::ShowAccepted(){
    for (auto item : accepted) {
        item.ShowInfo();
    }
}
void Post::ShowComplited(){
    for (auto item : complited) {
        item.ShowInfo();
    }
}
Date Post::SetDate() {
    bool ex = false;
    Date date;
    int y, m, d;
    while(!ex) {
        try {
            cout << "Date of admission (YYYY:MM:DD):\n";

            cout << "Year: ";
            cin >> y;
            if (cin.fail() || y <= 0 || y > 3000) {
                throw runtime_error("Invalid input. Please enter a valid integer for the year.");
            }

            cout << "Month: ";
            cin >> m;
            if (cin.fail() || m <= 0 || m > 12) {
                throw runtime_error("Invalid input. Please enter a valid integer for the month.");
            }

            cout << "Day: ";
            cin >> d;
            if (cin.fail() || d <= 0 || d > 31) {
                throw runtime_error("Invalid input. Please enter a valid integer for the day.");
            }

            cin.ignore();
            
        }
        catch (const exception& e) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << e.what() << endl;
        }
        Date temp(y, m, d);
        date=temp;
        if (date.IsValide()) {
            ex = true;

        }
    }
 
    return date;
    
}
Service Post::Feel() {
            system("cls");
            cout << "Name: ";string name;getline(cin, name);
            cout << "Surname: ";string surname;getline(cin, surname);
            cout << "Delivery address: ";string del_addr;getline(cin, del_addr);
            Date date = SetDate();
            Service temp(name, surname, del_addr, date);

            if (temp.IsValid()) {
                return temp;
            }
        }
void Post::Accept(Service item) {
	accepted.push_back(item);
}
void Post::Complit(Service item) {
    complited.push_back(item);
}
void Post::DeleteElement(vector<Service>& vec,int index) {
    vec.erase(vec.begin()+index);
}
vector<int> Post::SearchByName(vector<Service>& vec) {
    cout << "\nEnter name: "; string sch; getline(cin, sch);
    vector<int>idx;
    for (int i = 0; i < vec.size(); i++) {
        if (sch == vec[i].GetName()) {
            idx.push_back(i);
        }
    }
    return idx;
}
int Post::GetAcceptedSize() {
	return accepted.size();
}
int Post::GetComplitedSize() {
	return complited.size();
}
vector<Service>& Post::GetAcceptedList(){
    return accepted;
}
vector<Service> Post::GetComplitedList(){
    return complited;
}
void Post::GetFromFileAccept(){
    fstream file;
    file.open("Accepted.txt", ios_base::in);
    if (file.is_open()) {
        string line;
        int count = 0;
        while (getline(file, line)) {
            count++;
        }
        int size = count / 6;
        file.clear();
        file.seekg(0, ios::beg);
        int i = 0;
        while (i < size) {
            string name; getline(file, line);
            name = line;
            string surname; getline(file, line);
            surname = line;
            string del_addr; getline(file, line);
            del_addr = line;
            int y, m, d;
            getline(file, line);
            y = stoi(line);
            getline(file, line);
            m = stoi(line);
            getline(file, line);
            d = stoi(line);
            Date acc_date(y, m, d);
            accepted.push_back(Service(name, surname, del_addr,acc_date ));
            i++;
        }
    }
    file.close();
}
void Post::WrteToFileAccept(){
    fstream file;    
    file.open("Accepted.txt", ios_base::trunc);
    file.open("Accepted.txt", ios_base::out);
    if (file.is_open()) {
        for (auto item : accepted) {
            file << item.GetName() << "\n";
            file << item.GetSurName() << "\n";
            file << item.GetAddress()<< "\n";
            file << item.GetYear() << "\n";
            file << item.GetMonth() << "\n";
            file << item.GetDay() << "\n";
        }
    }
    file.close();
}
void Post::GetFromFileCompl(){
    fstream file;
    file.open("Complited.txt", ios_base::in);
    if (file.is_open()) {
        string line;
        int count = 0;
        while (getline(file, line)) {
            count++;
        }
        int size = count / 6;
        file.clear();
        file.seekg(0, ios::beg);
        int i = 0;
        while (i < size) {
            string name; getline(file, line);
            name = line;
            string surname; getline(file, line);
            surname = line;
            string del_addr; getline(file, line);
            del_addr = line;
            int y, m, d;
            getline(file, line);
            y = stoi(line);
            getline(file, line);
            m = stoi(line);
            getline(file, line);
            d = stoi(line);
            Date acc_date(y, m, d);
            complited.push_back(Service(name, surname, del_addr, acc_date));
            i++;
        }
    }
    file.close();
}
void Post::WrteToFileCompl(){
    fstream file;
    file.open("Complited.txt", ios_base::out);
    if (file.is_open()) {
        for (auto item : complited) {
            file << item.GetName() << "\n";
            file << item.GetSurName() << "\n";
            file << item.GetAddress() << "\n";
            file << item.GetYear() << "\n";
            file << item.GetMonth() << "\n";
            file << item.GetDay() << "\n";
        }
    }
    file.close();
}
