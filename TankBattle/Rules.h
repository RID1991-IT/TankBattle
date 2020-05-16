#pragma once
#include "Mine.h"
#include "Tank.h"
#include "Board.h"
#include "Logo.h"
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

class Rules
{
public:

    static void ShowRules()

    {
        system("cls");
        cout << "Game for 2 players" << "\n";
        cout << "There are two tanks on the field(1 - player red, 2 - player green).The goal of the game is to destroy the enemy tank. " << "\n";
        cout << "The movement of the tank is carried out with the keys “W” ”A” ”S” ”D”. Tanks are capable of firing a key “Space”." << "\n";
        cout << "To put a mine, for this you need to press the “M” key, select a place on the opponent’s fieldand use the key “Enter”" << "\n";
        cout << "put a mine (a mine can be set once per turn). Also, tanks are able to restore their HP, for this" << "\n";
        cout << "you must press the “H” key. Further, this ability will not be available for 4 turns. Player in one move " << "\n";
        cout << "can perform 3 actions. " << "\n";
        cout << "\n";
        cout << "On the fields of both players are anti-tank hedgehogs, if a player crashes into this obstacle, then he" << "\n";
        cout << "1 action point and 2 strength units of the tank are taken(-2HP)." << "\n";
        cout << "\n";
        cout << "The player who first takes all the strength points (HP) from the opponent wins. " << "\n";
        system("pause");
    }

};

