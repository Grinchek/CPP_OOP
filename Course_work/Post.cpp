#include "Post.h"


void Post::Accept() {
	system("cls");
	cout << "Name: "; string name; getline(cin, name);
	cout << "Surname: "; string surname; getline(cin, surname);
	cout << "Delivery address: "; string del_addr; getline(cin, del_addr);
	cout << "Date of admissiion(YYYY:MM:DD): "; int y, m, d; cin >> y; cin >> m; cin >> d;
	Service temp(name, surname, del_addr, y, m, d);
	accepted.push_back(temp);
}
