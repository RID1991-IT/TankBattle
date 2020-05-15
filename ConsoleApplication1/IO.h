#pragma once
#include <iostream>
#include <string>
#include "Mine.h"
#include "Tank.h"
#include "Board.h"
#include "Logo.h"
#include <stdio.h>
#include <Windows.h>

using namespace std;

class IO
{
public:
    static void ShowBoard(Board board, Tank tank)
    {

        board.TempBoard(tank.GetCoordinateX(), tank.GetCoordinateY(), 'T');
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "\t\t\t|\t\t-----------\t\t|" << endl;
        for (int i = 0; i < board.SIZEBOARD; i++)
        {
            cout << "\t\t\t|\t\t|";
            for (int j = 0; j < board.SIZEBOARD; j++)
            {
                if (board.GetCoordinate(i, j) == 'T' && tank.GetPlayerIndex() == 1)
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
                    cout << board.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    cout << "|";
                }
                else if (board.GetCoordinate(i, j) == 'T' && tank.GetPlayerIndex() == 2)
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 1));
                    cout << board.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    cout << "|";
                }
                else if (board.GetCoordinate(i, j) == '*')
                {

                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    cout << board.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    cout << "|";

                }
                else if (board.GetCoordinate(i, j) == 'X')
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 15));
                    cout << board.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    cout << "|";


                }
                else
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
                    cout << board.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                    cout << "|";
                }

            }
            cout << "\t\t|";
            cout << "\n";
            cout << "\t\t\t|\t\t-----------\t\t|" << "\n";
        }
    }
    static void Interface(Board board1, Board board2, Tank tank1, Tank tank2, int changed, int actionPoints)
    {
        cout << "\n" << endl;
        Logo::LogoTank();
        cout << "\n" << endl;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        cout << "\t\t\t_________________________________________" << endl;
        cout << "\t\t\t|                                       |" << endl;
        cout << "\t\t\t|     ";
        SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
        cout << "Player name - " << tank1.GetName(); cout << "  HP =" << tank1.GetHP();
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); cout << "   |" << endl;
        IO::ShowBoard(board1, tank1);
        IO::ShowBoard(board2, tank2);
        cout << "\t\t\t|     ";
        SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 1));
        cout << "Player name - " << tank2.GetName(); cout << "  HP =" << tank2.GetHP();
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); cout << "   |" << endl;
        cout << "\t\t\t|_______________________________________|" << endl;
        cout << "\t      _                                 " << endl;
        cout << "\t     |W|                                " << endl;
        cout << "\t   _______            _____             _                    _            " << endl;
        cout << "\t   |A|D|S| - to MOVE |SPACE| - to SHOT |M| - Put your MINE  |H| - to HEAL " << endl;
        cout << "\t   -------            -----             -                    -            " << endl;
        if (changed == 1)
        {
            SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
            cout << "\t\t\t\t\t" << tank1.GetName() << " Move " << endl;
            cout << "\t\t\t\t   You have -" << actionPoints << " action points " << endl;

            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
        }
        else if (changed == 2)
        {
            SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 1));
            cout << "\t\t\t\t\t" << tank2.GetName() << " Move " << endl;
            cout << "\t\t\t\t   You have -" << actionPoints << " action points " << endl;
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

        }

    }

    static void ShowMineStat(Tank tank, Mine mine)
    {
        cout << "Tank - " << tank.GetName() << " Have damage - " << mine.GetDamageMine() << " By mine!!! " << " HP " << tank.GetName() << " = " << tank.GetHP() << endl;
        system("pause");
    }

    static void ShowShot(int damage, Tank tank1, Tank tank2)// для отображения здоровья и полученого урона танка
    {
        cout << tank1.GetName() << " Good shot !!!" << "\n";
        cout << "Tank - " << tank2.GetName() << " Have damage - " << damage << " .HP " << tank2.GetName() << "= " << tank2.GetHP() << "\n";
        system("pause");

    }
    static void CtiticalDamageIO()
    {
        cout << "!!!Critical damage!!!" << endl;
        system("pause");
    }
    static void MissIo()
    {
        cout << "Yoy are Miss" << endl;
        system("pause");
    }

};