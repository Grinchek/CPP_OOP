#include<iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;

void Gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

enum Direction{LEFT,RIGHT,UP,DOWN};
class Hero {
private:
	int hp;
	int h, w;
	COORD position;
	Direction dir;
	string name;
	char symbol;
	void Print(char filler)const {
		for (int i = 0; i < h; i++) {
			Gotoxy(position.X, position.Y + i);
			for (int j = 0; j < w; j++) {

				cout << filler;
			}
			cout << endl;
		}
	}
public:
	Hero():hp(100),h(1),w(1),position({0,0}), dir(RIGHT),name("no name"),symbol('#'){}
	Hero(string name, int h, int w, char symb) :hp(100), position({ 0,0 }),dir(RIGHT), name(name), symbol(symb) {
		this->h = h >= 1 ? h : 1;
		this->w = w >= 1 ? w : 1;
	}
	void ShowInfo() {
		cout << "======================= Player [" << name << "] Hp : " << hp << "=============" << endl;
	}

	void PrintHero()const {
		Print(symbol);
	}
	void ClearHero()const {
		Print(' ');
	}
	void SetPosition(int x, int y) {
		position.X = x >= 0 ? x : 0;
		position.Y = y >= 0 ? y : 0;
	}
	void Move() {
		switch (dir)
		{
		case LEFT:
			MoveLeft();
			break;
		case RIGHT:
			MoveRight();
			break;
		case UP:
			MoveUp();
			break;
		case DOWN:
			MoveDown();
			break;
		default:
			break;
		}
	}
	void ChangeDirection(Direction dir) {
		this->dir = dir;
	}
	bool IsValidPosition(int x, int y) {
		return x >= 0 && y >= 0;
	}
	void MoveRight() {
		if (IsValidPosition(0, 0)) {
			ClearHero();
			position.X += 2;
			PrintHero();
		}
	
	}
	void MoveLeft() {
		if (IsValidPosition(position.X - 2, position.Y)) {
			ClearHero();
			position.X -= 2;
			PrintHero();
		}
	
	}
	bool MoveUp() {
		if (IsValidPosition(position.X, position.Y - 1)) {
			position.Y--;

		}

	}
	bool MoveDown() {
		if (IsValidPosition(0, 0)) {
			position.Y++;
			return true;
		}
		return false;
	}

};

void main() {
	hidecursor();
	system("Color 0A");
	Hero hero("Bill", 1, 2, 219);
	time_t interval = 500;
	time_t start = clock();
	int key = 0;
	while (true) {
		if (clock() >= start + interval) {
			hero.MoveRight();
			start = clock();
		}
		if (_kbhit()) {
				key = _getch();
		if (key == 224) {
			key = _getch();
			switch (key)
			{
			case 77:hero.ChangeDirection(RIGHT);break;
			case 80:hero.ChangeDirection(DOWN); break;
			case 72:hero.ChangeDirection(UP); break;
			case 75:hero.ChangeDirection(LEFT); break;
			default:
				break;
			}
		}
		}
	
	}





}