#include <iostream>
#include <cctype>

using namespace std;

void Counter_a_o(char str[]);
void Reverse_capitalize(char str[]);
void Length_str(char str[]);
void Delete_char(char str[], char a);

void main() {
	/*1.A string is entered. Which letters in the string are more 'a' or 'o'?
	2.A string is given. Count the number of Latin letters, numbers 
	and spaces in the string.
	3.The string is given. Replace all uppercase letters with lowercase letters and vice versa.
	4.Write a function that takes a string and returns the length of the string. 
	Without using the strlen() function
	5***.A string is given. Remove the specified character from the string. 
	Place the result on a new line.
	6.Develop a program that reads a string from the screen, 
	and then displays the statistics: 
	number of whitespaces, 
	vowels, consonants, and punctuation marks. 
	The input is assumed to be in English.*/
	char str[] = "Hello there, my name is Ivan";
	/*Counter_a_o(str);
	Reverse_capitalize(str);
	Reverse_capitalize(str);
	Length_str(str);*/
	cout << str << endl;
	cout << "Enter the character which would you like to delete: ";
	char a; cin >> a; cin.ignore();
	Delete_char(str, a);

}
void Counter_a_o(char str[]) {
	int countA = 0;
	int countO = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'a' || str[i] == 'A') {
			countA++;
		}
		if (str[i] == 'o' || str[i] == 'O') {
			countO++;
		}
	}
	cout << "Number of 'a', or 'A' is: " << countA << endl;
	cout << "Number of 'o', or 'O' is: " << countO << endl;
}
void Reverse_capitalize(char str[]) {
	for (int i = 0; i < strlen(str); i++) {
		if (isupper(str[i])) {
			str[i] = tolower(str[i]);
		}
		else if (islower(str[i])) {
			str[i] = toupper(str[i]);
		}
		
	}
	cout << str<<endl;
}
void Length_str(char str[]) {
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	cout << "The length of str is: " << length << endl;
}
void Delete_char(char str[], char a) {
	int count = 0;
	for(int i=0;i<strlen(str);i++) {
		if (str[i] != a) {
			str[count++] = str[i];
		}
	}
	str[count] = '\0';
	cout << str << endl;
}