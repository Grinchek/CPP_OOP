#include"Menu.h"


Post p1;
void Menu::Gotoxy(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Menu::MainMenu() {
	
	int menu_item = 0, run, x = 1;
	bool running=true;
	system("cls");
	Gotoxy(2, 0); cout << "Main Menu";
	Gotoxy(0, 1); cout << "->";
	

	while (running)
	{
		
		Gotoxy(2, 1);  cout << "Show all services";
		Gotoxy(2, 2);  cout << "About";
		Gotoxy(2, 3);  cout << "Exit";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x++;
			Gotoxy(0, x); cout << "->";
			menu_item++;
			continue;

		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x--;
			Gotoxy(0, x); cout << "->";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

			case 0: {
				AllServices();
				running=false;
				break;
			}
			case 1: {
				system("cls");
				Gotoxy(30, 0);
				cout << "About application:\n";
				cout << "Lorem Ipsum is simply dummy text of the printing and typesetting industry." << endl;
				cout << "Lorem Ipsum has been the industry's standard dummy text ever since the 1500s," << endl;
				cout << "when an unknown printer took a galley of type and scrambled it to make a type " << endl;
				cout << "specimen book. It has survived not only five centuries, but also the leap" << endl;
				cout << "into electronic typesetting, remaining essentially unchanged." << endl;
				cout << "It was popularised in the 1960s with the release of Letraset sheets" << endl;
				cout << "containing Lorem Ipsum passages, and more recently with desktop publishing " << endl;
				cout << "software like Aldus PageMaker including versions of Lorem Ipsum." << endl;
				system("pause");
				running = false;
				MainMenu();
				break;
			}

			case 2: {
				Gotoxy(20, 16);
				cout << "Good bye!!"<<endl;
				running = false;
				break;
			}
			default:
				break;
			}

		}

	}

	Gotoxy(20, 21);
}
void Menu::AllServices() {
	system("cls");
	int menu_item = 0, run, x = 1;
	bool running = true;

	Gotoxy(2, 0); cout << "All services:";
	Gotoxy(0, 1); cout << "->";

	while (running)
	{
		Gotoxy(2, 1);  cout << "Acceptance of the order";
		Gotoxy(2, 2);  cout << "Mark the execution";
		Gotoxy(2, 3);  cout << "Edit an order";
		Gotoxy(2, 4);  cout << "Back";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x++;
			Gotoxy(0, x); cout << "->";
			menu_item++;
			continue;

		}

		if (GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x--;
			Gotoxy(0, x); cout << "->";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

			case 0: {
				
				p1.Accept();
				running = false;
				system("cls");
				Gotoxy(0, 2); cout << "->";
				Gotoxy(2, 1); cout << "Wold you like to pay for parcel now?";
				Gotoxy(2, 2); cout << "Yes";
				Gotoxy(2, 3); cout << "No";
				break;
			}


			case 1: {
				Gotoxy(20, 16);
				cout << "Good bye!!";
				running = false;
				break;
			}
			case 2: {
				Gotoxy(20, 16);
				cout << "Good bye!!";
				running = false;
				break;
			}
			case 3: {
				MainMenu();
				running = false;
				break;
			}
			}

		}

	}
}