#pragma once
#include <iostream>
#include <string>
#include "Mine.h"
#include "Tank.h"
#include "Board.h"
#include <stdio.h>
#include <Windows.h>

using namespace std;

 class IO
{
public:
    static void ShowBoard(Board board, Tank tank)
    {


        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "---------" << endl;
        for (int i = 0; i < board.SIZEBOARD; i++)
        {
            cout << "|";
            for (int j = 0; j < board.SIZEBOARD; j++)
            {
                if (board.GetCoordinate(i, j) == 'T' && tank.GetColor() == 1)
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
                    cout << board.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                }
                else if (board.GetCoordinate(i, j) == 'T' && tank.GetColor() == 2)
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 1));
                    cout << board.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                }
                else if(board.GetCoordinate(i, j) == '*')
                {

                    SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 4));
                    cout << board.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

				}
                else
                {
                    cout << board.GetCoordinate(i, j);
                }
                cout << "|";
            }
            cout << endl;
            cout << "---------" << endl;
        }
    }
	static void ShowShot(int damage, Tank tank1, Tank tank2)// для отображения здоровья и полученого урона танка
	{
		cout << tank1.GetName() << " Good shot !!!" << endl;
		cout << "Tank - " << tank2.GetName() << " Have damage - " << damage << " .HP " << tank2.GetName() << "= " << tank2.GetHP() << endl;

	}
	/*static void ShowMineStat(Tank tank, Mine mine)
    {
		cout << "Tank - " << tank.GetName() << " Have damage - " << mine.GetDamageMine() << " By mine!!! " << " HP " << tank.GetName() << " = " << tank.GetHP() << endl;
	}*/
};