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
					cout << board.GetCoordinate(i,j );
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
				else if(board.GetCoordinate(i, j) == 'X')
				{
					SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 15));
					cout << board.GetCoordinate(i, j);
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					cout << "|";


				}
				else
				{
					SetConsoleTextAttribute(hConsole, (WORD)((15<< 4) | 4));
					cout << board.GetCoordinate(i, j);
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					cout << "|";
				}
			
			}
			cout << "\t\t|";
			cout << "\n";
			cout <<"\t\t\t|\t\t-----------\t\t|" << "\n";
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
	static void MoveMine(Mine& mine, Board& boardMovedPlayer, Board& boardEnemy, Board& boardMine, Tank& tankMovedPlayer, Tank& tankEnemy,int changed)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		char move;
		do
		{
			boardEnemy.ClearBoard();
			boardMovedPlayer.ClearBoard();
			system("cls");
			
			if (changed == 1)
			{
				boardEnemy.ClearBoard();
				boardEnemy.TempBoard(tankEnemy.GetCoordinateX(), tankEnemy.GetCoordinateY(), 'T');
				boardEnemy.TempBoard(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');	
				Interface(boardMovedPlayer, boardEnemy, tankMovedPlayer, tankEnemy, 0, 0);
			}
			else if (changed == 2)
			{
				boardMovedPlayer.ClearBoard();
				boardMovedPlayer.TempBoard(tankMovedPlayer.GetCoordinateX() , tankMovedPlayer.GetCoordinateY(), 'T');
				boardEnemy.TempBoard(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
				Interface(boardEnemy, boardMovedPlayer, tankEnemy, tankMovedPlayer, 0, 0);

			}
			
			if (changed==1)
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
				case 13:
					boardMine.SetCoordinate(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
				}
			}
			else if (changed == 2)
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
				case 13:
					boardMine.SetCoordinate(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
				}
			}
		} while (move != 13);
	}
	static void PlayerGameIO(Tank& tankPlayer1, Tank& tankPlayer2,Board& board1, Board& board2,Board& boardMine1, Board& boardMine2,Mine& mine,Heal& heal,int changed)
	{
		for (int i = tankPlayer1.GetPlayerActionPoints(); i > 0; i--)
		{
			system("cls");
			board1.ClearBoard();
			board2.ClearBoard();
			if (changed == 1)
			{
				Interface(board1, board2, tankPlayer1, tankPlayer2, tankPlayer1.GetPlayerIndex(), i);
			}
			else if (changed == 2)
			{
				Interface(board2, board1, tankPlayer2, tankPlayer1, tankPlayer1.GetPlayerIndex(), i);
			}
			char action = _getch();
			switch (action)
			{
			case 's':
				tankPlayer1.MoveDown(board1);
				if (mine.CheckMine(boardMine1, tankPlayer1, tankPlayer2.GetCoordinateX(), tankPlayer1.GetCoordinateY()))
				{
					ShowMineStat(tankPlayer1, mine);
				}
				break;
			case 'w':
				tankPlayer1.MoveUp(board1);
				if (mine.CheckMine(boardMine1, tankPlayer1, tankPlayer1.GetCoordinateX(), tankPlayer1.GetCoordinateY()))
				{
					ShowMineStat(tankPlayer1, mine);
				}
				break;
			case 'a':
				tankPlayer1.MoveLeft(board1);
				if (mine.CheckMine(boardMine1, tankPlayer1, tankPlayer1.GetCoordinateX(), tankPlayer1.GetCoordinateY()))
				{
					ShowMineStat(tankPlayer1, mine);
				}
				break;
			case 'd':
				tankPlayer1.MoveRight(board1);
				if (mine.CheckMine(boardMine1, tankPlayer1, tankPlayer1.GetCoordinateX(), tankPlayer1.GetCoordinateY()))
				{
					ShowMineStat(tankPlayer1, mine);
				}
				break;
			case 'm':
				MoveMine(mine, board1, board2, boardMine2, tankPlayer1, tankPlayer2, tankPlayer1.GetPlayerIndex());
				break;
			case 'h':
				HealTank(tankPlayer1, heal);
				break;
			case 32:
				CheckShot(tankPlayer1, tankPlayer2);
				break;
			default:
				i++;
				break;
			}
			if (tankPlayer1.GetHP()<=0 || tankPlayer2.GetHP()<=0)
				{
					break;
				}
		}

	}
	static void HealTank(Tank& tank, Heal& heal)
	{
		if (heal.GetCounter() > 0)
		{
			cout << "Wait for reload your Heal " << heal.GetCounter() << endl;
		}
		else
		{
			char move;//переделать используя делегаты,убрать move
			cout << "Heal you tank? y - yes, n - no" << endl;
			cin >> move;
			switch (move)
			{
			case 'y':
				tank.SetHealHP(heal.GetHeal());
				heal.SetCounter();
				cout << "Your HP =" << tank.GetHP() << " After heal " << endl;

				break;
			default:
				break;
			}
		}
	}

	static void CheckShot(Tank& attack, Tank& defence)
	{
		if (attack.GetCoordinateY() == defence.GetCoordinateY())
		{
			int damage;
			damage = attack.GetDamage();
			if (damage > 10)
			{
				cout << "!!!Critical damage!!!" << endl;
			}
			defence.SetHP(damage);
			cout << attack.GetName() << " Good shot !!!" << endl;
			cout << "Tank - " << defence.GetName() << " Have damage - " << damage << " .HP " << defence.GetName() << "= " << defence.GetHP() << endl;
			system("pause");
		}
		else
		{
			cout << "Miss" << endl;
			system("pause");
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

	}

};