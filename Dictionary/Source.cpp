#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
using namespace std;

class Dictionary
{
private:
    string name;
    map<string, list<string>> words;//default c-tor Root= nullptr
public:
    Dictionary(string name) : name(name) {}
    bool IsExist(string word)const
    {
        return words.find(word) != words.end();
    }
    void Print()const
    {
        cout << "Dictionary " << name << endl;
        for (auto pair : words)
        {
            cout << pair.first << " - ";
            for (string t : pair.second)
            {
                cout << t << " , ";
            }
            cout << endl;
        }
    }
    void ShowTranslate(string word)const {
        if (!IsExist(word)) {
            cout << "There are no such words" << endl;
        }
        else {
            for (auto item : words) {
                if (item.first == word) {
                    cout << item.first << " - ";
                    for (auto translate : item.second) {
                        cout << translate << ", ";
                    }cout << endl;
                }

            }
        }
    }
    void InsertWord(string word, list<string> translate)
    {
        words.insert(make_pair(word, list<string>(translate)));
    }
    void AddTranslation(string word) {
        string input = "";
        cout << "Enter word to add translate : ";
        getline(cin, input);

        if (!IsExist(input))
            cout << "Word not found!" << endl;
        else {
            string translate = "";
            do
            {
                cout << "Enter translate : ";
                getline(cin, translate);
                if (!translate.empty())
                    words[word].push_back(translate);
            } while (!translate.empty());
        }
    }
    void DeleteWord(string word) {
        auto it = words.find(word);
        if (it != words.end()) {
            words.erase(it);
        }
        else {
            cout << "There are no such words" << endl;
        }
    }

    friend ostream& operator << (ostream& out, const Dictionary& d);
    friend istream& operator >> (istream& in, Dictionary& d);
};
ostream& operator << (ostream& out, const Dictionary& d)
{
    out << d.name << endl;
    for (auto pair : d.words)
    {
        out << pair.first << endl;
        for (string t : pair.second)
        {
            out << t << endl;
        }
        out << "|" << endl;
    }
    return out;
}
istream& operator >> (istream& in, Dictionary& d)
{
    string end = "|";
    getline(in, d.name);
    while (!in.eof())
    {
        string word;
        getline(in, word);
        if (word.empty())break;
        list<string> list;
        string translate = end;

        do
        {
            getline(in, translate);
            if (translate != end)
                list.push_back(translate);

        } while (translate != end);
        d.words.insert(make_pair(word, list));
    }

    return in;
}

void main()
{



    Dictionary dict("");
    ifstream in("Dictionary.txt");
    in >> dict;
    in.close();
    bool ex = false;
do{
    cout << "Menu:\n";
    cout << "1. Add word with translations\n";
    cout << "2. Find translations of a word\n";
    cout << "3. Add translation to an existing word\n";
    cout << "4. Delete word with all translations\n";
    cout << "5. Show all words in the dictionary\n";
    cout << "6. Exit\n";
    string word="";
    list <string>temp;
    string input;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice; cin.ignore();

    switch (choice)
        {
        case 1:
            system("cls");
            cout << "Enter new word: ";  getline(cin, word);
            
            do {
                cout << "Enter translate: ";
                getline(cin, input);
                temp.push_back(input);
            } while (!input.empty());
            dict.InsertWord(word,temp);
            break;
        case 2:
            system("cls");
            cout << "Enter new word: "; getline(cin, word);
            dict.ShowTranslate(word);
            break;
        case 3:
            cout << "Enter new word: "; getline(cin, word);
            dict.AddTranslation(word);
            break;
        case 4:
            system("cls");
            cout << "Enter new word: ";getline(cin, word);
            dict.DeleteWord(word);
            break;
        case 5:
            system("cls");
            dict.Print();
            break;
        case 6:
            cout << "Exiting the program.\n";
            ex = true;
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
} while (!ex);
    ofstream out("Dictionary.txt");
    out << dict;
    out.close();
}