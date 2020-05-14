#pragma once
#include <string>
#include <conio.h>

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

	void MoveDown(Board& board)
	{
		if (GetCoordinateX() == board.SIZEBOARD - 1 || board.GetCoordinate(GetCoordinateX() + 1, GetCoordinateY()) == 'X')
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), '*');
		}
		else if (GetCoordinateX() < board.SIZEBOARD - 1)
		{
			board.SetCoordinate(GetCoordinateX() + 1, GetCoordinateY(), '*');
			SetCoordinateMineX(GetCoordinateX() + 1);
		}
	}
	void MoveUp(Board& board)
	{
		if (GetCoordinateX() == 0 || board.GetCoordinate(GetCoordinateX() - 1, GetCoordinateY()) == 'X')
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), '*');
		}
		else if (GetCoordinateX() > 0)
		{
			board.SetCoordinate(GetCoordinateX() - 1, GetCoordinateY(), '*');
			SetCoordinateMineX(GetCoordinateX() - 1);
		}
	}
	void MoveRight(Board& board)
	{
		if (GetCoordinateY() == board.SIZEBOARD - 1 || board.GetCoordinate(GetCoordinateX(), GetCoordinateY() + 1) == 'X')
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), '*');
		}
		else if (GetCoordinateY() < board.SIZEBOARD - 1)
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY() + 1, '*');
			SetCoordinateMineY(GetCoordinateY() + 1);
		}
	}
	void MoveLeft(Board& board)
	{
		if (GetCoordinateY() == 0 || board.GetCoordinate(GetCoordinateX(), GetCoordinateY() - 1) == 'X')
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), '*');
		}
		 else if (GetCoordinateY() > 0)
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY() - 1, '*');
			SetCoordinateMineY(GetCoordinateY() - 1);
		}
	}
	bool CheckMine(Board& boardDefenceMine, Tank& tankDefence, int x, int y)
	{
		
		if (boardDefenceMine.GetCoordinate(x, y) == '*')
		{
			tankDefence.SetHP(GetDamageMine());
			boardDefenceMine.SetCoordinate(x, y, ' ');
			return true;
		} 
		else
		{
			return false;
		}
	}
};