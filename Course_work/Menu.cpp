#include"Menu.h"


Post p1;
void Menu::Gotoxy(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Menu::MainMenu() {
	p1.GetFromFileAccept();
	p1.GetFromFileCompl();
	HomePage(); 
	p1.WrteToFileAccept();
	p1.WrteToFileCompl();

}
void Menu::HomePage() {
	
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
			x<3?x++:x=1;
			Gotoxy(0, x); cout << "->";
			menu_item<2?menu_item++:menu_item=0;
			continue;

		}

		if (GetAsyncKeyState(VK_UP)) //up button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x>1?x--:x=3;
			Gotoxy(0, x); cout << "->";
			menu_item>0?menu_item--:menu_item=2;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

			case 0: {
				AllServices();
				running=false;
				HomePage();
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
				HomePage();
				break;
			}

			case 2: {
				cout << "\nGood bye!!"<<endl;
				running = false;
				break;
			}
			default:
				break;
			}

		}

	}
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
		Gotoxy(2, 2);  cout << "Show orders";
		Gotoxy(2, 3);  cout << "Mark the execution";
		Gotoxy(2, 4);  cout << "Edit an order";
		Gotoxy(2, 5);  cout << "Cancel an order";
		Gotoxy(2, 6);  cout << "Back";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN)) //down button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x<6?x++:x=1;
			Gotoxy(0, x); cout << "->";
			menu_item<5?menu_item++:menu_item=0;
			continue;

		}

		if (GetAsyncKeyState(VK_UP)) //up button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x>1?x--:x=6;
			Gotoxy(0, x); cout << "->";
			menu_item>0?menu_item--: menu_item=5;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

			case 0: {
				Service tmp = p1.Feel();
					p1.Accept(tmp);
					running = false;
					system("cls");
					cout << "Your order has been accepted." << endl;
					system("pause");
					break;
				}
			case 1: {
				ShowOrders();
				running = false;
				break;
			}
			case 2: {
				system("cls");
				vector<Service> temp =p1.GetAcceptedList();
				vector<int>items = p1.SearchByName(temp);
				for (int idx : items) {
					p1.Complit(temp[idx]);
					p1.DeleteElement(p1.GetAcceptedList(), idx);
				}
				running = false;
				break;
			}
			case 3: {
				vector<Service> accepted = p1.GetAcceptedList();
				vector<int>items = p1.SearchByName(accepted);
				for (int idx : items) {
					Service temp=p1.Feel();
					p1.EditElement(p1.GetAcceptedList(), idx,temp);
				}
				running = false;
				break;
			}
			case 4: {
				vector<Service> temp = p1.GetAcceptedList();
				vector<int>items = p1.SearchByName(temp);
				for (int idx : items) {
					p1.DeleteElement(p1.GetAcceptedList(), idx);
				}
				running = false;
				break;
			}
			case 5: {
				running = false;
				break;
			}
			default: {
				break;
			}
			}
		}

		}

	}
bool Menu::Payment() {
	system("cls");
	int menu_item = 0, run, x = 2;
	bool running = true;
	Gotoxy(0, 2); cout << "->";
	
	while (running)
	{
		Gotoxy(2, 1); cout << "Wold you like to pay for parcel?";
		Gotoxy(2, 2); cout << "Yes";
		Gotoxy(2, 3); cout << "No";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN)) //down button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x<3?x++:x=2;
			Gotoxy(0, x); cout << "->";
			menu_item<1?menu_item++: menu_item=0;
			continue;

		}

		if (GetAsyncKeyState(VK_UP)) //up button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x>2?x--:x=3;
			Gotoxy(0, x); cout << "->";
			menu_item>0?menu_item--: menu_item=1;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

			case 0: {
				return true;
				running = false;
				break;
			}
			case 1: {
				return false;
				running = false;
				break;
			}
			}

		}

	}
}
void Menu::ShowOrders() {
	system("cls");
	int menu_item = 0, run, x = 1;
	bool running = true;
	Gotoxy(6, 0); cout << "~~Orders~~";
	Gotoxy(0, 1); cout << "->";

	while (running)
	{
		Gotoxy(2, 1); cout << "Show accepted orders";
		Gotoxy(2, 2); cout << "Show complited orders";
		Gotoxy(2, 3); cout << "Search order by customer";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN)) //down button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x < 3 ? x++ : x = 1;
			Gotoxy(0, x); cout << "->";
			menu_item < 2 ? menu_item++ : menu_item = 0;
			continue;

		}

		if (GetAsyncKeyState(VK_UP)) //up button pressed
		{
			Gotoxy(0, x); cout << "  ";
			x > 1 ? x-- : x = 3;
			Gotoxy(0, x); cout << "->";
			menu_item > 0 ? menu_item-- : menu_item = 2;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

			case 0: {
				cout << endl;
				p1.ShowAccepted();
				system("pause");
				running = false;
				break;
			}
			case 1: {
				cout << endl;
				p1.ShowComplited();
				system("pause");
				running = false;
				break;
			}
			case 2: {
				vector <Service>& tmp = p1.GetAcceptedList();
				vector<int> size= p1.SearchByName(tmp);
				for (int item:size) {
					tmp[item].ShowInfo();
				}
				system("pause");
				running = false;
				break;
			}
			}

		}

	}
}
