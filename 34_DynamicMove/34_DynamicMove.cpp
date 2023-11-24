#include"Console.h"
#include<chrono>//for clock()

enum Direction{LEFT, RIGHT, UP, DOWN};

class Hero
{
private:
    int hp;
    int h, w;
    COORD position;
    char symbol;
    string name;
    Direction dir;
    void Print()const
    {
        for (int y = 0; y < h; y++)
        {
            gotoxy(position.X, position.Y + y);
            for (int i = 0; i < w; i++)
            {
                if (i == 1)cout << "::::::::::.`     .---======------   -`::::::::::::\n";
                if (i == 2)cout << "::::::::`    ..*_*-``_   __''------'''''* ''::::::\n";
                if (i == 3)cout << "⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠔⠁⠠⠖⠡⠔⠊⠀⠀⠀⠀⠀⠀⠀⠐⡄⠀⠀⠀⠀⠀⠀⡄⠀⠀⠀⠀⠉⠲⢄⠀⠀⠀⠈⣿⣿⣿⣿⣿\n";
                if (i == 4)cout << "⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠊⠀⢀⣀⣤⣤⣤⣤⣀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠜⠀⠀⠀⠀⣀⡀⠀⠈⠃⠀⠀⠀⠸⣿⣿⣿⣿\n";
                if (i == 5)cout << "⣿⣿⣿⣿⡿⠥⠐⠂⠀⠀⠀⠀⡄⠀⠰⢺⣿⣿⣿⣿⣿⣟⠀⠈⠐⢤⠀⠀⠀⠀⠀⠀⢀⣠⣶⣾⣯⠀⠀⠉⠂⠀⠠⠤⢄⣀⠙⢿⣿⣿\n";
                if (i == 6)cout << "⣿⡿⠋⠡⠐⠈⣉⠭⠤⠤⢄⡀⠈⠀⠈⠁⠉⠁⡠⠀⠀⠀⠉⠐⠠⠔⠀⠀⠀⠀⠀⠲⣿⠿⠛⠛⠓⠒⠂⠀⠀⠀⠀⠀⠀⠠⡉⢢⠙⣿\n";
                if (i == 7)cout << "⣿⠀⢀⠁⠀⠊⠀⠀⠀⠀⠀⠈⠁⠒⠂⠀⠒⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⢀⣀⡠⠔⠒⠒⠂⠀⠈⠀⡇⣿\n";
                if (i == 8)cout << "⣿⠀⢸⠀⠀⠀⢀⣀⡠⠋⠓⠤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠈⠢⠤⡀⠀⠀⠀⠀⠀⠀⢠⠀⠀⠀⡠⠀⡇⣿\n";
                if (i == 9)cout << "⣿⡀⠘⠀⠀⠀⠀⠀⠘⡄⠀⠀⠀⠈⠑⡦⢄⣀⠀⠀⠐⠒⠁⢸⠀⠀⠠⠒⠄⠀⠀⠀⠀⠀⢀⠇⠀⣀⡀⠀⠀⢀⢾⡆⠀⠈⡀⠎⣸⣿\n";
                if (i == 10)cout << "⣿⣿⣄⡈⠢⠀⠀⠀⠀⠘⣶⣄⡀⠀⠀⡇⠀⠀⠈⠉⠒⠢⡤⣀⡀⠀⠀⠀⠀⠀⠐⠦⠤⠒⠁⠀⠀⠀⠀⣀⢴⠁⠀⢷⠀⠀⠀⢰⣿⣿\n";
                if (i == 11)cout << "⣿⣿⣿⣿⣇⠂⠀⠀⠀⠀⠈⢂⠀⠈⠹⡧⣀⠀⠀⠀⠀⠀⡇⠀⠀⠉⠉⠉⢱⠒⠒⠒⠒⢖⠒⠒⠂⠙⠏⠀⠘⡀⠀⢸⠀⠀⠀⣿⣿⣿\n";
                if (i == 12)cout << "⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠑⠄⠰⠀⠀⠁⠐⠲⣤⣴⣄⡀⠀⠀⠀⠀⢸⠀⠀⠀⠀⢸⠀⠀⠀⠀⢠⠀⣠⣷⣶⣿⠀⠀⢰⣿⣿⣿\n";
                if (i == 13)cout << "⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠁⢀⠀⠀⠀⠀⠀⡙⠋⠙⠓⠲⢤⣤⣷⣤⣤⣤⣤⣾⣦⣤⣤⣶⣿⣿⣿⣿⡟⢹⠀⠀⢸⣿⣿⣿\n";
                if (i == 14)cout << "⣿⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠑⠀⢄⠀⡰⠁⠀⠀⠀⠀⠀⠈⠉⠁⠈⠉⠻⠋⠉⠛⢛⠉⠉⢹⠁⢀⢇⠎⠀⠀⢸⣿⣿⣿\n";
                if (i == 15)cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣀⠈⠢⢄⡉⠂⠄⡀⠀⠈⠒⠢⠄⠀⢀⣀⣀⣰⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⢀⣎⠀⠼⠊⠀⠀⠀⠘⣿⣿⣿\n";
                if (i == 16)cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⡀⠉⠢⢄⡈⠑⠢⢄⡀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⢀⠀⠀⠀⠀⠀⢻⣿⣿\n";
                if (i == 17)cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣀⡈⠑⠢⢄⡀⠈⠑⠒⠤⠄⣀⣀⠀⠉⠉⠉⠉⠀⠀⠀⣀⡀⠤⠂⠁⠀⢀⠆⠀⠀⢸⣿⣿\n";
                if (i == 18)cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⡀⠁⠉⠒⠂⠤⠤⣀⣀⣉⡉⠉⠉⠉⠉⢀⣀⣀⡠⠤⠒⠈⠀⠀⠀⠀⣸⣿⣿\n";
                if (i == 19)cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿\n";
                if (i == 20)cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣤⣤⣤⣤⣀⣀⣤⣤⣤⣶⣾⣿⣿⣿⣿⣿\n";


            }
            //cout << endl;
        }
    }
public:
    Hero() : hp(100), h(1), w(1), position({ 0,0 }), symbol('#'), name("no name"), dir(RIGHT) {}
    Hero(string name, int h, int w, char symbol) : hp(100), position({ 0,0 }),
        symbol(symbol), name(name), dir(RIGHT)
    {
        this->h = h >= 1 ? h : 1;
        this->w = w >= 1 ? w : 1;
    }
    void ShowInfo()const
    {
        cout << "----------- Player [ " << name << " ] . HP : " << hp <<"---------" << endl;
    }
    void PrintHero()
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::GREEN);
        Print();
    }
    void MarkHero()
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::RED);
        Print();
    }
    void ClearHero()
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::BLACK);
        Print();
    }   
    void SetPosition(int x, int y)
    {
        position.X = x >= 0 ? x : 0;
        position.Y = y >= 0 ? y : 0;
    }
    void Move()
    {
        bool isMoved = false;
        ClearHero();
        switch (dir)
        {
        case LEFT:isMoved = MoveLeft(); break;
        case RIGHT:isMoved = MoveRight(); break;
        case UP:isMoved = MoveUp();break;
        case DOWN:isMoved = MoveDown();break;
        }
        isMoved ? PrintHero() : MarkHero();
    }
    bool MoveRight()
    {
        if (IsValidPosition(position.X+1, position.Y))
        {
            position.X++;
            return true;
        }  
        return false;
    }
    bool MoveLeft()
    {
        if (IsValidPosition(position.X - 1, position.Y))
        {
            position.X--; return true;
        }
        return false;
    }
    bool MoveUp()
    {
        if (IsValidPosition(position.X , position.Y-1))
        {
            position.Y--;
            return true;
        }
        return false;
    }
    bool MoveDown()
    {
        if (IsValidPosition(position.X, position.Y + 1))
        {
            position.Y++;
            return true;
        }
        return false;
    }
    void ChangeDirection(Direction dir)
    {
        this->dir = dir;
    }
    bool IsValidPosition(int x, int y)const
    {
        return x >= 0 && y >= 0;
    }
};

int main()
{
    hidecursor();
    Hero hero("Batman", 21, 21, (char)219);

   /* hero.ShowInfo();
    hero.PrintHero();
    hero.Move(10, 10);*/
    hero.PrintHero();
    time_t interval = 500;
    time_t start = clock();
    while (true)
    {
        if (clock() >= start + 500)
        {
            hero.Move();
            start = clock();
        }
        if (_kbhit())
        {
            int key = _getch();
            if (key == 224)
            {
                key = _getch();
                switch (key)
                {
                case 77: hero.ChangeDirection(RIGHT); break;
                case 80: hero.ChangeDirection(DOWN); break;
                case 72: hero.ChangeDirection(UP); break;
                case 75: hero.ChangeDirection(LEFT); break;
                }
            }
        }                 
    }   
}

