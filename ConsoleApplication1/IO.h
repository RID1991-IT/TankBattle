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

		board.TempBoard(tank.GetCoordinateX(), tank.GetCoordinateY(), 'T');
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "|\t\t---------\t\t|" << endl;
		for (int i = 0; i < board.SIZEBOARD; i++)
		{
			cout << "|\t\t|";
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
			cout <<"|\t\t---------\t\t|" << "\n";
		}
	}
	static void ShowShot(int damage, Tank tank1, Tank tank2)// для отображения здоровья и полученого урона танка
	{
		cout << tank1.GetName() << " Good shot !!!" << "\n";
		cout << "Tank - " << tank2.GetName() << " Have damage - " << damage << " .HP " << tank2.GetName() << "= " << tank2.GetHP() << "\n";

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
			}
			else if (changed == 2)
			{
				boardMovedPlayer.ClearBoard();
				boardMovedPlayer.TempBoard(tankMovedPlayer.GetCoordinateX() , tankMovedPlayer.GetCoordinateY(), 'T');
				boardMovedPlayer.TempBoard(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
			}
		
		
		//IO::ShowBoard(boardMovedPlayer, tankMovedPlayer);
		//IO::ShowBoard(boardEnemy, tankEnemy);
			cout << "_________________________________________" << endl;
			cout << "|                                       |" << endl;
			cout << "|     ";
			SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
			cout << "Player name - " << tankMovedPlayer.GetName(); cout << "  HP =" << tankMovedPlayer.GetHP();
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); cout << "  |" << endl;
			IO::ShowBoard(boardMovedPlayer, tankMovedPlayer);
			IO::ShowBoard(boardEnemy, tankEnemy);
			cout << "|     ";
			SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 1));
			cout << "Player name - " << tankEnemy.GetName(); cout << "  HP =" << tankEnemy.GetHP();
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); cout << "  |" << endl;
			cout << "|_______________________________________|" << endl;
			
		cout << "      _                                      " << endl;
		cout << "     |W|                                      "<< endl;
		cout << "   -------              -                    " << endl;
		cout << "   |A|D|S| - to MOVIE  |M| - Chek your MINE  " <<endl;
		cout << "   -------              -                    " << endl;
		

		

			
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
				case 'm':
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
				case 'm':
					boardMine.SetCoordinate(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
				}
			}
		} while (move != 'm');
	}
	static void MoveTank(Tank& tank1,Tank& tank2, Board& board1,Board& board2)//функция для отображения движения танка
		{
			char move;
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
	static void OkrasLogoTank(char logo[][100]) {// цвет логотипа
		HANDLE consoleOutput;
		consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

		for (int i = 0; i < 13; i++) {
			if (i % 2 == 0) {
				SetConsoleTextAttribute(consoleOutput, 12); //Перед строкой для выделения текста цветом 
				cout << "\t" << logo[i] << endl;
				SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
			}
			else {
				SetConsoleTextAttribute(consoleOutput, 10); //Перед строкой для выделения текста цветом
				cout << "\t" << logo[i] << endl;
				SetConsoleTextAttribute(consoleOutput, 15); //Возвращаем назад цвет
			}
		}
	}

	static void LogoTank() { // Логотип
		char Logo[15][100] = {
			" #######     ###        ##      ##   ##   ##           #############                         ",
			"   ##      ##   ##     # ##    ##   ##  ##           ####################################### ",
			"  ##     ## ### ##    ##  ##  ##   ## ##            ##################                       ",
			" ##    ## ##### ##   ##    # ##   ##   ##       ###########################                  ",
			"##   ##         ##  ##      ##   ##     ##    #################################              ",
			"                                             #***O*******O*******O*******O****#              ",
			"                                              #***O*****O*******O*******O****#               ",
			"                                               ##############################                ",
			"                    ######          ###     #######  ##                                      ",
			"                   ##    ##       ##   ##     ##    ##                                       ",
			"                  ########      ## ### ##    ##    ##                                        ",
			"                 ##      ##   ## ##### ##   ##    ##                                         ",
			"                ##########  ##         ##  ##    ########                                    ",
		};
		OkrasLogoTank(Logo);
	}

	static void ShowMineStat(Tank tank, Mine mine)
    {
		cout << "Tank - " << tank.GetName() << " Have damage - " << mine.GetDamageMine() << " By mine!!! " << " HP " << tank.GetName() << " = " << tank.GetHP() << endl;
		system("pause");
	}

	static void Interface(Board board1,Board board2,Tank tank1,Tank tank2)
	{
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		board1.ClearBoard();
		board2.ClearBoard();
		cout << "_________________________________________" << endl;
		cout << "|                                       |" << endl;
		cout << "|     ";
		SetConsoleTextAttribute(hConsole, (WORD)((4 << 4) | 15));
		cout << "Player name - " << tank1.GetName(); cout << "  HP =" << tank1.GetHP();
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); cout << "  |" << endl;
		IO::ShowBoard(board1, tank1);
		IO::ShowBoard(board2, tank2);
		cout << "|     ";
		SetConsoleTextAttribute(hConsole, (WORD)((2 << 4) | 1));
		cout << "Player name - " << tank2.GetName(); cout << "  HP =" << tank2.GetHP() ;
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15)); cout << "  |" << endl;
		cout << "|_______________________________________|" << endl;
		cout << "      _                                 " << endl;
		cout << "     |W|                                " << endl;
		cout << "   -------             -----            " << endl;
		cout << "   |A|D|S| - to MOVIE |SPACE| - to SHOT|" <<endl;
		cout << "   -------             -----            " << endl;
		cout << "   -                     - "              << endl;
		cout << "  |M| - Chek your MINE  |H| - to HEAL"    <<endl;
		cout << "   -                     - "              << endl;

		



	}
};