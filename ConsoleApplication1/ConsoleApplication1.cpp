#include <iostream>
#include "Tank.h"
#include "Board.h"
#include "Mine.h"
#include "Heal.h"
#include "IO.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;


void HealTank(Tank& tank, Heal& heal);
void CheckShot(Tank& attack, Tank& defence);
  
int main()
{
	system("title TANK BATTLE");

	Tank tank1("_PLayer_1", 100, 6, 10, 1, 1, 1);
	Tank tank2("_Player_2", 100, 6, 10, 2, 2, 2);
	Mine mine1;
	Mine mine2;
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
	MoveWindow(hwnd, 500, 50, 850, 900, TRUE);//xnew,ynew,wnew,hnew -новые положение x,y, ширина и высота

	IO::LogoTank();
	system("pause");
	

	char action;

	while (tank1.GetHP() >= 0 && tank2.GetHP() >= 0)
	{
		movedTank = Tank::CheckInitiative(tank1, tank2);
		if (movedTank == 1)
		{
			//player1 play
			
			IO::Interface(board1, board2, tank1, tank2);
			cout << "Player 1 move" << endl;
			
			action = _getch();
			switch (action)
			{
			case 'a':
				IO::MoveTank(tank1, tank2, board1, board2);
				IO::Interface(board1, board2, tank1, tank2);
				if (mine2.CheckMine(boardMine1, tank1, tank1.GetCoordinateX(), tank1.GetCoordinateY()) == true)
				{
					IO::ShowMineStat(tank1, mine1);
				}
				break;
			case 'm':
				IO::MoveMine(mine1, board1, board2, boardMine2, tank1, tank2, tank1.GetPlayerIndex());
				break;
			case 'h':
				HealTank(tank1, heal1);
				break;
			case 'p':
				CheckShot(tank1, tank2);
				break;
			default:
				break;
			}
			
		}
		else if (movedTank == 2)
		{//player2 play
			//
			//IO::Interface(board1, board2, tank1, tank2);
			//cout << "Player 2 move" << endl;
			//IO::MoveTank(tank2, tank1, board2, board1);
			//IO::Interface(board1, board2, tank1, tank2);
			//if (mine2.CheckMine(boardMine2, tank2, tank2.GetCoordinateX(), tank2.GetCoordinateY()) == true)
			//{
			//	IO::ShowMineStat(tank2, mine1);
			//}
			//IO::MoveMine(mine1, board1, board2, boardMine1, tank1, tank2, tank2.GetPlayerIndex());
			//CheckShot(tank2, tank1);
			//
		}
	}
}

void HealTank(Tank& tank,Heal &heal)
{
	if (heal.GetCounter() > 0)
	{
		cout << "Wait for reload your Heal "<< heal.GetCounter() << endl;
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
			cout << "Your HP =" << tank.GetHP() <<" After heal "<< endl;

			break;
		default:
			break;
		}	
	}
}

void CheckShot( Tank& attack, Tank& defence)
{
	if (attack.GetCoordinateY() == defence.GetCoordinateY())
	{
		int damage;
		damage = attack.GetDamage();
		if(damage>10)
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



