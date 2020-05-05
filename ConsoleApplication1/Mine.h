#pragma once
#include <string>
#include <conio.h>
#include "IO.h"
using namespace std;

class Mine
{
private:
	int counter = 0;
	string name = "Mine";
	int damageMine = 15;
	int coordinateX=1;
	int coordinateY=1;
public:
	Mine() {}
	void ActivateCounter()
	{
		counter = 5;
	}
	void Countdown()
	{
		counter--;
		if (counter < 0)
		{
			counter = 0;
		}
	}
	void SetCoordinateMineX(int x)
	{
		coordinateX = x;

	}
	void SetCoordinateMineY(int y)
	{
		coordinateY = y;

	}

	int GetDamageMine() 
	{
		return damageMine;
	}
	int GetCounter() 
	{
		return counter;
	}
	int GetCoordinateX()
	{
		return coordinateX;
	}
	int GetCoordinateY()
	{
		return coordinateY;
	}

	static void MoveMine(Mine mine,Board& boardMovedPlayer,Board& boardEnemy, Board& boardMine,Tank& tankMovedPlayer,Tank& tankEnemy,int changed)
	{

		char move;
		do
		{
			system("cls");
			if (changed == 1)
			{
				boardEnemy.ClearBoard();
				boardEnemy.TempBoard(tankEnemy.GetCoordinateX(), tankEnemy.GetCoordinateY(), 'T');
				boardEnemy.TempBoard(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
			}
			else if(changed == 2)
			{
				boardMovedPlayer.ClearBoard();
				boardMovedPlayer.TempBoard(tankMovedPlayer.GetCoordinateX(), tankMovedPlayer.GetCoordinateY(), 'T');
				boardMovedPlayer.TempBoard(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
			}
			IO::ShowBoard(boardMovedPlayer, tankMovedPlayer);
			IO::ShowBoard(boardEnemy, tankEnemy);
			if (changed == 1)
			{
				move = _getch();
				switch (move)
				{
				case 's':
					MoveDown(mine, boardEnemy);
					break;
				case 'w':
					MoveUp(mine, boardEnemy);
					break;
				case 'a':
					MoveLeft(mine, boardEnemy);
					break;
				case 'd':
					MoveRight(mine, boardEnemy);
					break;
				case 'm':
					boardMine.SetCoordinate(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
				}
			}
			else if (changed==2)
			{

				move = _getch();
				switch (move)
				{
				case 's':
					MoveDown(mine, boardMovedPlayer);
					break;
				case 'w':
					MoveUp(mine, boardMovedPlayer);
					break;
				case 'a':
					MoveLeft(mine, boardMovedPlayer);
					break;
				case 'd':
					MoveRight(mine, boardMovedPlayer);
					break;
				case 'm':
					boardMine.SetCoordinate(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
				}

			}
		} while (move != 'm');
	}

	static void MoveDown(Mine& mine1, Board& board)
	{
		if (mine1.GetCoordinateX() == board.SIZEBOARD - 1)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY(), '*');
		}
		if (mine1.GetCoordinateX() < board.SIZEBOARD - 1)
		{
			board.SetCoordinate(mine1.GetCoordinateX() + 1, mine1.GetCoordinateY(), '*');
			mine1.SetCoordinateMineX(mine1.GetCoordinateX() + 1);
		}
	}
	static void MoveUp(Mine& mine1, Board& board)
	{
		if (mine1.GetCoordinateX() == 0)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY(), '*');
		}
		if (mine1.GetCoordinateX() > 0)
		{
			board.SetCoordinate(mine1.GetCoordinateX() - 1, mine1.GetCoordinateY(), '*');
			mine1.SetCoordinateMineX(mine1.GetCoordinateX() - 1);
		}
	}
	static void MoveRight(Mine& mine1, Board& board)
	{
		if (mine1.GetCoordinateY() == board.SIZEBOARD - 1)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY(), '*');
		}
		if (mine1.GetCoordinateY() < board.SIZEBOARD - 1)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY() + 1, '*');
			mine1.SetCoordinateMineY(mine1.GetCoordinateY() + 1);
		}
	}
	static void MoveLeft(Mine& mine1, Board& board)
	{
		if (mine1.GetCoordinateY() == 0)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY(), '*');
		}
		if (mine1.GetCoordinateY() > 0)
		{
			board.SetCoordinate(mine1.GetCoordinateX(), mine1.GetCoordinateY() - 1, '*');
			mine1.SetCoordinateMineY(mine1.GetCoordinateY() - 1);
		}
	}

};