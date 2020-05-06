#pragma once
#include "Mine.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Tank.h"
#include "Board.h"
#include "Heal.h"

using namespace std;

class IO
{
	
public:
    static void ShowBoard(Board& boardPlayer1, Tank& tankPlayer1,Board& boardPlayer2, Tank& tankPlayer2)
	{   boardPlayer1.ClearBoard();
	    boardPlayer2.ClearBoard();
		system("cls");
		boardPlayer1.TempBoard(tankPlayer1.GetCoordinateX(), tankPlayer1.GetCoordinateY(), 'T');
		boardPlayer2.TempBoard(tankPlayer2.GetCoordinateX(), tankPlayer2.GetCoordinateY(), 'T');
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "---------" << endl;
        for (int i = 0; i < boardPlayer1.SIZEBOARD; i++)
        {
            cout << "|";
            for (int j = 0; j < boardPlayer1.SIZEBOARD; j++)
            {
                if (boardPlayer1.GetCoordinate(i, j) == 'T' && tankPlayer1.GetPlayerIndex() == 1)
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
                    cout << boardPlayer1.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                }
               
                else if(boardPlayer1.GetCoordinate(i, j) == '*')
                {

                    SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 4));
                    cout << boardPlayer1.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

				}
                else
                {
                    cout << boardPlayer1.GetCoordinate(i, j);
                }
                cout << "|";
            }
            cout << endl;
            cout << "---------" << endl;
        }

		 cout << "---------" << endl;
        for (int i = 0; i < boardPlayer2.SIZEBOARD; i++)
        {
            cout << "|";
            for (int j = 0; j < boardPlayer2.SIZEBOARD; j++)
            {
                
			    if (boardPlayer2.GetCoordinate(i, j) == 'T' && tankPlayer2.GetPlayerIndex() == 2)
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 1));
                    cout << boardPlayer2.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
                }
                else if(boardPlayer2.GetCoordinate(i, j) == '*')
                {
                    SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 4));
                    cout << boardPlayer2.GetCoordinate(i, j);
                    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
				}
                else
                {
                    cout << boardPlayer2.GetCoordinate(i, j);
                }
                cout << "|";
            }
            cout << endl;
            cout << "---------" << endl;
        }
		cout << "S-Down,W-MoveUp,A-left,D-Right" << endl;

    }
	static void ShowShot(int damage, Tank tank1, Tank tank2)// дл€ отображени€ здоровь€ и полученого урона танка
	{
		cout << tank1.GetName() << " Good shot !!!" << endl;
		cout << "Tank - " << tank2.GetName() << " Have damage - " << damage << " .HP " << tank2.GetName() << "= " << tank2.GetHP() << endl;

	}
	static void MoveMine(Mine& mine, Board& boardMovedPlayer, Board& boardEnemy, Board& boardMine, Tank& tankMovedPlayer, Tank& tankEnemy)
	{
		char move;
		do
		{
			if (tankMovedPlayer.GetPlayerIndex()==1)
			{
				boardEnemy.TempBoard(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
			}
			else if (tankMovedPlayer.GetPlayerIndex()==2)
			{
				boardMovedPlayer.TempBoard(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
			}
			ShowBoard(boardMovedPlayer, tankMovedPlayer, boardEnemy, tankEnemy);
			if (tankMovedPlayer.GetPlayerIndex()==1)
			{
				move = _getch();
				switch (move)
				{
				case 's':
					mine.MoveDown(boardEnemy);
					break;
				case 'w':
					mine.MoveUp(boardEnemy);
					break;
				case 'a':
					mine.MoveLeft(boardEnemy);
					break;
				case 'd':
					mine.MoveRight(boardEnemy);
					break;
				case 'm':
					boardMine.SetCoordinate(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
				}
			}
			else if (tankMovedPlayer.GetPlayerIndex() == 2)
			{
				move = _getch();
				switch (move)
				{
				case 's':
					mine.MoveDown(boardMovedPlayer);
					break;
				case 'w':
					mine.MoveUp(boardMovedPlayer);
					break;
				case 'a':
					mine.MoveLeft(boardMovedPlayer);
					break;
				case 'd':
					mine.MoveRight(boardMovedPlayer);
					break;
				case 'm':
					boardMine.SetCoordinate(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
				}
			}
		} while (move != 'm');
	}
	static void MoveTank(Tank& tank1,Tank& tank2, Board& board1,Board& board2)//функци€ дл€ отображени€ движени€ танка
		{
			char move;
			board1.ClearBoard();
			board2.ClearBoard();
			move = _getch();
			switch (move)
			{
			case 's':
				tank1.MoveDown(board1);
				break;
			case 'w':
				tank1.MoveUp(board1);
				break;
			case 'a':
				tank1.MoveLeft(board1);
				break;
			case 'd':
				tank1.MoveRight(board1);
				break;
			}
		}

	/*static void ShowMineStat(Tank tank, Mine mine)
    {
		cout << "Tank - " << tank.GetName() << " Have damage - " << mine.GetDamageMine() << " By mine!!! " << " HP " << tank.GetName() << " = " << tank.GetHP() << endl;
	}*/
};