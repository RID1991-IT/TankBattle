#include <iostream>
#include "Tank.h"
#include "Board.h"
#include "Mine.h"
#include "Heal.h"
#include "IO.h"
#include "MoveTank.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;

void Move(Tank &name, Board& board, Board& boardMine1,Board& boardMine2, Mine mine, char action);
void Shot(Board& board, Tank& attack, Tank& defence);
void HealTank(Tank& tank, Heal& heal);
void MoveMine(Tank& tank, Board& boardMine);
void CheckShot(Tank& attack, Tank& defence);


  
int main()
{
	IO io;
	Tank tank1("Tank1", 100, 6, 10, 1, 1, 1);
	Tank tank2("Tank2", 100, 6, 10, 2, 2, 2);
	Mine mine1;
	Mine mine2;
	Heal heal1;
	Heal heal2;
	Board board1;
	Board board2;
	Board boardMine1;
	Board boardMine2;
	
	char move;
		
	while (tank1.GetHP() >= 0 && tank2.GetHP() >= 0)
	{
		board1.TempBoard(tank1.GetCoordinateX(), tank1.GetCoordinateY(), 'T');
		board2.TempBoard(tank2.GetCoordinateX(), tank2.GetCoordinateY(), 'T');
		system("cls");
		IO::ShowBoard(board1, tank1);
		IO::ShowBoard(board2, tank2);
		cout << "S-Down,W-MoveUp,A-left,D-Right" << endl;
		MoveTank::Move(tank1, tank2, board1, board2);
		system("cls");
		MoveTank::CheckMine(boardMine2, tank2, mine1, tank1.GetCoordinateX(), tank1.GetCoordinateY());
		IO::ShowBoard(board1, tank1);
		IO::ShowBoard(board2, tank2);
		Mine::MoveMine(mine1,board1, board2, boardMine1,tank1,tank2,1);
		CheckShot(tank1, tank2);
		HealTank(tank1, heal1);
		system("cls");
		IO::ShowBoard(board1, tank1);
		IO::ShowBoard(board2, tank2);
		cout << "S-Down,W-MoveUp,A-left,D-Right" << endl;
		MoveTank::Move(tank2, tank1, board2, board1);
		MoveTank::CheckMine(boardMine1, tank1, mine1, tank2.GetCoordinateX(), tank2.GetCoordinateY());
		Mine::MoveMine(mine1, board1, board2, boardMine2, tank1, tank2,2);
		CheckShot(tank2, tank1);
		HealTank(tank2, heal2);
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
		char move;
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



