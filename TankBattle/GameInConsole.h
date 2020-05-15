#pragma once
#include"IO.h"

class GameInConsole :IO
{
public:
    static void FirstInicialization(Tank& tank1,Tank& tank2,Board& boardMine1, Board& boardMine2)
    {
        tank1.SetPullHp(99);
        tank2.SetPullHp(99);
        tank1.SetCoordinateX(1);
        tank1.SetCoordinateY(1);
        tank2.SetCoordinateX(3);
        tank2.SetCoordinateY(3);
        boardMine1.ClearBoard();
        boardMine2.ClearBoard();
    }
    static void PlayerGameIO(Tank& tankPlayer1, Tank& tankPlayer2, Board& board1, Board& board2, Board& boardMine1, Board& boardMine2, Mine& mine, Heal& heal, int changed)
    {
        for (int i = tankPlayer1.GetPlayerActionPoints(); i > 0; i--)
        {
            system("cls");
            board1.ClearBoard();
            board2.ClearBoard();
            if (changed == 1)
            {
                Interface(board1, board2, tankPlayer1, tankPlayer2, tankPlayer1.GetPlayerIndex(), i);
            }
            else if (changed == 2)
            {
                Interface(board2, board1, tankPlayer2, tankPlayer1, tankPlayer1.GetPlayerIndex(), i);
            }
            char action = _getch();
            switch (action)
            {
            case 's':
                tankPlayer1.MoveDown(board1);
                if (mine.CheckMine(boardMine1, tankPlayer1, tankPlayer2.GetCoordinateX(), tankPlayer1.GetCoordinateY()))
                {
                    ShowMineStat(tankPlayer1, mine);
                }
                break;
            case 'w':
                tankPlayer1.MoveUp(board1);
                if (mine.CheckMine(boardMine1, tankPlayer1, tankPlayer1.GetCoordinateX(), tankPlayer1.GetCoordinateY()))
                {
                    ShowMineStat(tankPlayer1, mine);
                }
                break;
            case 'a':
                tankPlayer1.MoveLeft(board1);
                if (mine.CheckMine(boardMine1, tankPlayer1, tankPlayer1.GetCoordinateX(), tankPlayer1.GetCoordinateY()))
                {
                    ShowMineStat(tankPlayer1, mine);
                }
                break;
            case 'd':
                tankPlayer1.MoveRight(board1);
                if (mine.CheckMine(boardMine1, tankPlayer1, tankPlayer1.GetCoordinateX(), tankPlayer1.GetCoordinateY()))
                {
                    ShowMineStat(tankPlayer1, mine);
                }
                break;
            case 'm':
                MoveMine(mine, board1, board2, boardMine2, tankPlayer1, tankPlayer2, tankPlayer1.GetPlayerIndex());
                break;
            case 'h':
                HealTank(tankPlayer1, heal);
                break;
            case 32:
                if (CheckShot(tankPlayer1, tankPlayer2))
                {
                    ShowShot(tankPlayer1.GetDamage(), tankPlayer1, tankPlayer2);
                }
                else
                {
                    MissIo();
                }
                break;
            default:
                i++;
                break;
            }
            if (tankPlayer1.GetHP() <= 0 || tankPlayer2.GetHP() <= 0)
            {
                break;
            }
        }

    }
    static void MoveMine(Mine& mine, Board& boardMovedPlayer, Board& boardEnemy, Board& boardMine, Tank& tankMovedPlayer, Tank& tankEnemy, int changed)
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
                Interface(boardMovedPlayer, boardEnemy, tankMovedPlayer, tankEnemy, 0, 0);
            }
            else if (changed == 2)
            {
                boardMovedPlayer.ClearBoard();
                boardMovedPlayer.TempBoard(tankMovedPlayer.GetCoordinateX(), tankMovedPlayer.GetCoordinateY(), 'T');
                boardEnemy.TempBoard(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
                Interface(boardEnemy, boardMovedPlayer, tankEnemy, tankMovedPlayer, 0, 0);

            }

            if (changed == 1)
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
                case 13:
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
                case 13:
                    boardMine.SetCoordinate(mine.GetCoordinateX(), mine.GetCoordinateY(), '*');
                }
            }
        } while (move != 13);
    }
    static void HealTank(Tank& tank, Heal& heal)
    {
        if (heal.GetCounter() > 0)
        {
            cout << "Wait for reload your Heal " << heal.GetCounter() << endl;
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
                cout << "Your HP =" << tank.GetHP() << " After heal " << endl;

                break;
            default:
                break;
            }
        }
    }
    static bool CheckShot(Tank& attack, Tank& defence)
    {
        if (attack.GetCoordinateY() == defence.GetCoordinateY())
        {
            int damage;
            damage = attack.GetDamage();
            defence.SetHP(damage);
            return true;
        }
        else
            return false;
    }

};