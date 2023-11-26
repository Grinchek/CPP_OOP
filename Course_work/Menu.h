#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include"Post.h"

using namespace std;
class Menu {

public:
	void Gotoxy(int x, int y);
	void MainMenu();
	void HomePage();
	void AllServices();
	bool Payment();
	void ShowOrders(); 

};



