#include <iostream>
#include "Tank.h"
#include "Board.h"
#include "Mine.h"
#include "Heal.h"
#include "IO.h"
#include "Logo.h"
#include "GameInConsole.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;

int main()
{
    system("title TANK BATTLE");

    Tank tank1("_PLayer_1", 99, 6, 10, 1, 1, 1);
    Tank tank2("_Looper_2", 99, 6, 10, 2, 3, 3);
    Mine mine;
    Heal heal1;
    Heal heal2;
    Board board1;
    Board board2;
    Board boardMine1;
    Board boardMine2;
    int movedTank;
    HWND hwnd;
    char Title[1024];
    hwnd = GetConsoleWindow();
    MoveWindow(hwnd, 500, 30, 850, 1000, TRUE);//xnew,ynew,wnew,hnew -новые положение x,y, ширина и высота
    int check = 0;
    bool end = true;
    do
    {
        int check = Logo::Menu();
        if (check == 1)
        {
            tank1.SetPullHp(99);
            tank2.SetPullHp(99);
            tank1.SetCoordinateX(1);
            tank1.SetCoordinateY(1);
            tank2.SetCoordinateX(3);
            tank2.SetCoordinateY(3);
            boardMine1.ClearBoard();
            boardMine2.ClearBoard();
            while (tank1.GetHP() >= 0 && tank2.GetHP() >= 0)
            {
                movedTank = Tank::CheckInitiative(tank1, tank2);

                //player1 play
                GameInConsole::PlayerGameIO(tank1, tank2, board1, board2, boardMine1, boardMine2, mine, heal1, tank1.GetPlayerIndex());

                if (tank2.GetHP() <= 0)
                {
                    system("cls");
                    Logo::LogoWiner(tank1.GetPlayerIndex());
                    system("pause");
                    break;
                }
                else if (tank1.GetHP() <= 0)
                {
                    system("cls");
                    Logo::LogoWiner(tank2.GetPlayerIndex());
                    system("pause");
                    break;
                }
                //player2 play
                GameInConsole::PlayerGameIO(tank2, tank1, board2, board1, boardMine2, boardMine1, mine, heal2, tank2.GetPlayerIndex());
                if (tank2.GetHP() <= 0)
                {
                    system("cls");
                    Logo::LogoWiner(tank1.GetPlayerIndex());
                    system("pause");
                    break;
                }
                else if (tank1.GetHP() <= 0)
                {
                    system("cls");
                    Logo::LogoWiner(tank2.GetPlayerIndex());
                    system("pause");
                    break;
                }
            }
        }
        else if (check == 2)
        {
            system("cls");
            Logo::LogoSergeyOlisov();
            cout << endl << endl;
            Logo::LogoIliaRyazantsev();
            cout << endl << endl;
            Logo::LogoSergePris();
            system("pause");
        }
        else if (check == 3)
        {
            system("cls");
            Logo::LogoRules();
            system("pause");
        }
        else if (check == 4)
        {
            end = false;
        }

    } while (end != false);
}





