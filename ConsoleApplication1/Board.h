#pragma once
#include <string>
using namespace std;



class Board
{
public:
	static const int SIZEBOARD = 4;
private:
	char board[SIZEBOARD][SIZEBOARD];
public:
	Board() //конструктор
	{
		ClearBoard();
	}
	void ClearBoard() //очистка поля
	{
		for (int i = 0; i < SIZEBOARD; i++)
		{
			for (int j = 0; j < SIZEBOARD; j++)
			{
				board[i][j] = ' ';
			}
		}
	}
	void TempBoard(int x, int y, char essence)
	{
		for (int i = 0; i < SIZEBOARD; i++)
		{
			for (int j = 0; j < SIZEBOARD; j++)
			{
				if (i == x && j == y)
				{
					board[i][j] = essence;
				}
			}
		}
	}
	void SetCoordinate(int x, int y, char move) //заполнение массива значением
	{
		board[x][y] = move;
	}
	char GetCoordinate(int x, int y)
	{
		return board[x][y];
	}
};