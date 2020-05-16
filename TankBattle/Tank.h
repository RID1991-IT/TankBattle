#pragma once
#include <string>
using namespace std;
#include <stdlib.h>
#include <time.h> 
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
    int playerIndex;
    int actionPoits = 3;
public:
   

    Tank(string name, int hp, int damage, int initiative, int playerIndex, int x, int y) 
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
    void SetPullHp(int health)
    {
        hp = health;
    }

    void SetHP(int damage) 
    {
        hp -= damage;
    }
   
    void SetHealHP(int heal)
    {
        hp += heal;
        if (hp > 100)
        {
            hp = 100;
        }
    }
   
    int GetHP()
    {
        return hp;
    }
    int GetDamage()
    {
        srand(time(0));
        int critical = 1 + rand() % 5;
        int probability = 5 + rand() % damage;
        if (critical == 5)
        {
            return 2 * probability;
        }
        else
        {
            return probability;
        }
    }
   
    string GetName()
    {
        return name;
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
    int GetPlayerActionPoints()
    {
        return actionPoits;

    }
    //движение танка
    void MoveDown(Board& board)
    {
        if (GetCoordinateX() == board.SIZEBOARD - 1 || board.GetCoordinate(GetCoordinateX() + 1, GetCoordinateY()) == 'X')
        {
            board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), 'T');
            if (board.GetCoordinate(GetCoordinateX() + 1, GetCoordinateY()) == 'X')
            {
                hp -= 2;
            }
        }
        else if (GetCoordinateX() < board.SIZEBOARD - 1)
        {
            board.SetCoordinate(GetCoordinateX() + 1, GetCoordinateY(), 'T');
            SetCoordinateX(GetCoordinateX() + 1);
        }
    }
    void MoveUp(Board& board)
    {
        if (GetCoordinateX() == 0 || board.GetCoordinate(GetCoordinateX() - 1, GetCoordinateY()) == 'X')
        {
            board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), 'T');
            if (board.GetCoordinate(GetCoordinateX() - 1, GetCoordinateY()) == 'X')
            {
                hp -= 2;
            }
        }
        else if (GetCoordinateX() > 0)
        {
            board.SetCoordinate(GetCoordinateX() - 1, GetCoordinateY(), 'T');
            SetCoordinateX(GetCoordinateX() - 1);
        }
    }
    void MoveRight(Board& board)
    {
        if (GetCoordinateY() == board.SIZEBOARD - 1 || board.GetCoordinate(GetCoordinateX(), GetCoordinateY() + 1) == 'X')
        {
            board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), 'T');
            if (board.GetCoordinate(GetCoordinateX(), GetCoordinateY() + 1) == 'X')
            {
                hp -= 2;
            }
        }
        else if (GetCoordinateY() < board.SIZEBOARD - 1)
        {
            board.SetCoordinate(GetCoordinateX(), GetCoordinateY() + 1, 'T');
            SetCoordinateY(GetCoordinateY() + 1);
        }
    }
    void MoveLeft(Board& board)
    {
        if (GetCoordinateY() == 0 || board.GetCoordinate(GetCoordinateX(), GetCoordinateY() - 1) == 'X')
        {
            board.SetCoordinate(GetCoordinateX(), GetCoordinateY(), 'T');
            if (board.GetCoordinate(GetCoordinateX(), GetCoordinateY() - 1) == 'X')
            {
                hp -= 2;
            }
        }
        else if (GetCoordinateY() > 0)
        {
            board.SetCoordinate(GetCoordinateX(), GetCoordinateY() - 1, 'T');
            SetCoordinateY(GetCoordinateY() - 1);
        }
    }
    //Прототип для инициативы
    void SetInitiative(int initiative)
    {
        ongoingInitiative += initiative;
    }
    void ZeroingInitiative()
    {
        ongoingInitiative = 0;
    }
    static int CheckInitiative(Tank& tank1, Tank& tank2)
    {
        int movedTankIndex;
        if (tank1.ongoingInitiative >= 20 && tank2.ongoingInitiative >= 20)
        {
            srand(time(0));
            movedTankIndex = 1 + rand() % 2;
            if (movedTankIndex == 1)
            {
                tank1.ongoingInitiative -= 20;
                return movedTankIndex;
            }
            else if (movedTankIndex == 2)
            {
                tank2.ongoingInitiative -= 20;
                return movedTankIndex;
            }
        }
        else if (tank1.ongoingInitiative >= 20)
        {
            tank1.ongoingInitiative -= 20;
            movedTankIndex = 1;
            return movedTankIndex;
        }
        else if (tank2.ongoingInitiative >= 20)
        {
            tank2.ongoingInitiative -= 20;
            movedTankIndex = 2;
            return movedTankIndex;
        }
        tank1.ongoingInitiative += tank1.initiative;
        tank2.ongoingInitiative += tank2.initiative;
    }
    int GetInitiative()
    {
        return initiative;
    }
    int GetOngoingIniciative()
    {
        return ongoingInitiative;
    }

};