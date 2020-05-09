#pragma once
#include <string>
using namespace std;
#include<stdlib.h>//� ���� ����� ���������� ������� rand
#include<time.h> //� ���� ����� ���������� ������� time
#include <stdio.h>
#include <Windows.h>
#include "Board.h"

class Tank
{
private:
	string name;
	int hp;
	int damage;
	int initiative;
	int ongoingInitiative;
	int coordinateX;
	int coordinateY;
	int playerIndex;//���������� ����� ���� ����� 1 ��� 2
public:
	Tank() //����������� �� ���������
	{}

	Tank(string name, int hp, int damage,int initiative,int playerIndex, int x, int y) //�����������
	{
		this->name = name;
		this->hp = hp;
		this->damage = damage;
		this->initiative = initiative;
		ongoingInitiative = initiative;
		coordinateX = x;
		coordinateY = y;
		this->playerIndex = playerIndex;
	}

	void SetHP(int damage) //��������� ����� ������
	{
		hp -= damage;
	}
	void SetInitiative(int initiative)
	{
		ongoingInitiative += initiative;
	}
	void ZeroingInitiative()
	{
		ongoingInitiative = 0;
	}

	void SetHealHP(int heal)
	{
		hp += heal;
		if (hp > 100)
		{
			hp = 100;
		}
	}
	void MoveDown(Board& board)
	{
		if (GetCoordinateX() == board.SIZEBOARD - 1)
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), 'T');
		}
		if (GetCoordinateX() < board.SIZEBOARD - 1)
		{
			board.SetCoordinate(GetCoordinateX() + 1, GetCoordinateY(), 'T');
			SetCoordinateX(GetCoordinateX() + 1);
		}
	}
	void MoveUp(Board& board)
	{
		if (GetCoordinateX() == 0)
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), 'T');
		}
		if (GetCoordinateX() > 0)
		{
			board.SetCoordinate(GetCoordinateX() - 1, GetCoordinateY(), 'T');
			SetCoordinateX(GetCoordinateX() - 1);
		}
	}
	void MoveRight(Board& board)
	{
		if (GetCoordinateY() == board.SIZEBOARD - 1)
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), 'T');
		}
		if (GetCoordinateY() < board.SIZEBOARD - 1)
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY() + 1, 'T');
			SetCoordinateY(GetCoordinateY() + 1);
		}
	}
	void MoveLeft(Board& board)
	{
		if (GetCoordinateY() == 0)
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), 'T');
		}
		if (GetCoordinateY() > 0)
		{
			board.SetCoordinate(GetCoordinateX(), GetCoordinateY() - 1, 'T');
			SetCoordinateY(GetCoordinateY() - 1);
		}
	}
	int GetHP()
	{
		return hp;
	}
	int GetDamage()
	{
		srand(time(0));
		int critical = 1+rand() % 5;
		int probability = 5 + rand() % damage;
		if(critical==5)
		{
			return 2*probability;
		}
		else 
		{
			return probability;
		}
	}
	static int CheckInitiative(Tank& tank1, Tank& tank2)
	{
		int movedTankIndex;
		do {
			if (tank1.ongoingInitiative >= 20 && tank2.ongoingInitiative >= 20) // ���� � ����� ������� ���������� �������� �������� ����
			{
				srand(time(0));
				movedTankIndex = 1 + rand() % 2; // �������� ���������� ����� ����� �����
				if (movedTankIndex == 1) //���� ����� ������ ������� ������, �� �������� ��� ����������
				{
					tank1.ongoingInitiative -= 20;
				}
				else if (movedTankIndex == 2) // ���� �������, �� ��� ���������� ��������
				{
					tank2.ongoingInitiative -= 20;
				}
				return movedTankIndex;
				break;
			}
			else if (tank1.ongoingInitiative >= 20) //��� ���������� - ���� ������ ����� ������, �� � ���� �������� ����������
			{
				tank1.ongoingInitiative -= 20;
				movedTankIndex = 1;
				return movedTankIndex;
				break;
			}
			else if (tank2.ongoingInitiative >= 20) // �� � �� ������ ��� ��
			{
				tank2.ongoingInitiative -= 20;
				movedTankIndex = 2;
				return movedTankIndex;
				break;
			}
			tank1.ongoingInitiative += tank1.initiative; // ���� ���������� �������, �������� � ����� �����
			tank2.ongoingInitiative += tank2.initiative; // ����� ���-�� �� ������� ��� ����� ������, ��� �� �� ���� ��-��������
		} while (tank1.ongoingInitiative != 20 && tank2.ongoingInitiative != 20);
	}
	string GetName()
	{
		return name;
	}
	int GetInitiative()
	{
		return initiative;
	}
	int GetOngoingIniciative()
	{
		return ongoingInitiative;
	}
	int GetCoordinateX()
	{
		return coordinateX;
	}
	int GetCoordinateY()
	{
		return coordinateY;
	}
	void SetCoordinateX(int x)
	{
		 coordinateX = x;
	}
	void SetCoordinateY(int y)
	{	
		 coordinateY = y;
	}
	int GetPlayerIndex()
	{
		return playerIndex;
	}
};