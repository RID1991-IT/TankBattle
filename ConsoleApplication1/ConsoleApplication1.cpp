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



  
int main()
{
	system("title TANK BATTLE");

	Tank tank1("_PLayer_1", 99, 6, 10, 1, 1, 1);
	Tank tank2("_Looper_2", 99, 6, 10, 2, 2, 2);
	Mine mine;
	Heal heal;
	Board board1;
	Board board2;
	Board boardMine1;
	Board boardMine2;
	int movedTank;
	HWND hwnd;
	char Title[1024];
	hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 500, 50, 850, 900, TRUE);//xnew,ynew,wnew,hnew -новые положение x,y, ширина и высота

	int check = IO::Menu();
	if (check == 1)
	{
		while (tank1.GetHP() >= 0 && tank2.GetHP() >= 0)
		{
			movedTank = Tank::CheckInitiative(tank1, tank2);


			//player1 play

			IO::PlayerGameIO(tank1, tank2, board1, board2, boardMine1, boardMine2, mine, heal, tank1.GetPlayerIndex());

			//player2 play

			IO::PlayerGameIO(tank2, tank1, board2, board1, boardMine2, boardMine1, mine, heal, tank2.GetPlayerIndex());

		}

	}
	else if (check == 2) {
		system("cls");
		IO::LogoSergeyOlisov();
		cout << endl << endl;
		IO::LogoIliaRyazantsev();
		cout << endl << endl;
		IO::LogoSergePris();

	}
	else if (check == 3) {

	}
	else if (check == 4) {
		exit(0);
	}

	

	



	
}





