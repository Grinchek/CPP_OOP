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
Service Post::Feel() {
            system("cls");
            cout << "Name: ";string name;getline(cin, name);
            cout << "Surname: ";string surname;getline(cin, surname);
            cout << "Delivery address: ";string del_addr;getline(cin, del_addr);
            int y, m, d;
            bool validInput = false;
            do {
                cout << "Date of admission (YYYY:MM:DD):\n ";
                cout << "Year: ";
                if (!(cin >> y) || cin.peek() != '\n') {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input. Please enter a valid integer for the year.\n";
                    continue;
                }
                cout << "Month: ";
                if (!(cin >> m) || cin.peek() != '\n') {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input. Please enter a valid integer for the month.\n";
                    continue;
                }
                cout << "Day: ";
                if (!(cin >> d) || cin.peek() != '\n') {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input. Please enter a valid integer for the day.\n";
                    continue;
                }
                cin.ignore();
                validInput = true;

            } while (!validInput);

            Date date(y, m, d);
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
    cout << "Enter name: "; string sch; getline(cin, sch);
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
