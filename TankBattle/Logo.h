#pragma once
#include <iostream>
#include <string>
#include "Mine.h"
#include "Tank.h"
#include "Board.h"
#include <stdio.h>
#include <Windows.h>

using namespace std;


class Logo
{
    
public:
  
    static void OkrasLogoTank(char logo[][100])
    {
       
        HANDLE consoleOutput;
        consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int i = 0; i < 13; i++) {
            if (i % 2 == 0) {
                SetConsoleTextAttribute(consoleOutput, 12); 
                cout << "\t" << logo[i] << endl;
                SetConsoleTextAttribute(consoleOutput, 15); 
            }
            else {
                SetConsoleTextAttribute(consoleOutput, 10); 
                cout << "\t" << logo[i] << endl;
                SetConsoleTextAttribute(consoleOutput, 15); 
            }
        }
    }
    static void OkrasMenuRed(char logo[][100]) {
        HANDLE consoleOutput;
        consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);


        for (int i = 0; i < 5; i++) {
            SetConsoleTextAttribute(consoleOutput, 12); 
            cout << "\t\t\t\t" << logo[i] << endl;
            SetConsoleTextAttribute(consoleOutput, 15); 
        }
    }
    static void OkrasMenuGreen(char logo[][100])
    {
        
        HANDLE consoleOutput;
        consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int i = 0; i < 5; i++) {
            SetConsoleTextAttribute(consoleOutput, 10); 
            cout << "\t\t\t\t" << logo[i] << endl;
            SetConsoleTextAttribute(consoleOutput, 15); 
        }
    }
    static void OkrasLogoAuthor(char logo[][100])
    {
        
        HANDLE consoleOutput;
        consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int i = 0; i < 6; i++)
        {
            SetConsoleTextAttribute(consoleOutput, 2); 
            cout << "\t" << logo[i] << endl;
            SetConsoleTextAttribute(consoleOutput, 15); 
        }
        for (int i = 6; i < 14; i++)
        {
            SetConsoleTextAttribute(consoleOutput, 9); 
            cout << "\t" << logo[i] << endl;
            SetConsoleTextAttribute(consoleOutput, 15); 
        };
    }
    static void OkrasWinnerRed(char logo[][100]) {
        HANDLE consoleOutput;
        consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);


        for (int i = 0; i < 14; i++) {
            SetConsoleTextAttribute(consoleOutput, 12);
            cout << "\t\t" << logo[i] << endl;
            SetConsoleTextAttribute(consoleOutput, 15);
        }
    }
    static void OkrasWinnerGreen(char logo[][100])
    {

        HANDLE consoleOutput;
        consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int i = 0; i < 14; i++) {
            SetConsoleTextAttribute(consoleOutput, 10);
            cout << "\t\t" << logo[i] << endl;
            SetConsoleTextAttribute(consoleOutput, 15);
        }
    }

   
    static void LogoTank()
    {
        
        char Logo[15][100] = {
            " #######     ###        ##      ##   ##   ##           #############                         ",
            "   ##      ##   ##     # ##    ##   ##  ##           ####################################### ",
            "  ##     ## ### ##    ##  ##  ##   ## ##            ##################                       ",
            " ##    ## ##### ##   ##    # ##   ##   ##       ###########################                  ",
            "##   ##         ##  ##      ##   ##     ##    #################################              ",
            "                                             #***O*******O*******O*******O****#              ",
            "                                              #***O*****O*******O*******O****#               ",
            "                                               ##############################                ",
            "                    ######          ###     #######  #######  ##        ######               ",
            "                   ##    ##       ##   ##     ##       ##    ##        ##                    ",
            "                  ########      ## ### ##    ##       ##    ##        #####                  ",
            "                 ##      ##   ## ##### ##   ##       ##    ##        ##                      ",
            "                ##########  ##         ##  ##       ##    ########  ######                   ",
        };
        OkrasLogoTank(Logo);
    }
    static void LogoStart(int color)
    {
        char Start[5][100] = {
            " ***  *****     *     *****  ***** ",
            " *      *      * *    *    *   *   ",
            " ***    *     *   *   *****    *   ",
            "   *    *    * *** *  *  *     *   ",
            " ***    *   *       * *    *   *   ",

        };
        if (color == 0)
        {
            OkrasMenuGreen(Start);
        } if (color == 1)
        {
            OkrasMenuRed(Start);
        }
    }
    static void LogoAuthors(int color)
    {
        char Authors[5][100] = {
            "    *     *       * ***** *     *   ***   *****  ***  ",
            "   * *    *       *   *   *     *  *   *  *    * *    ",
            "  *   *   *       *   *   * *** * *     * *****  ***  ",
            " * *** *   *     *    *   *     *  *   *  * *      *  ",
            "*       *   * * *     *   *     *   ***   *   *  ***  ",

        };
        if (color == 0)
        {
            OkrasMenuGreen(Authors);
        } if (color == 1)
        {
            OkrasMenuRed(Authors);
        }
    }
    static void LogoRules(int color)
    {
        char Rules[5][100] = {
            "*****  *       * *     ****  ***  ",
            "*    * *       * *     *     *    ",
            "*****  *       * *     ****  ***  ",
            "* *     *     *  *     *       *  ",
            "*   *    * * *   ***** ****  ***  ",
        };
        if (color == 0)
        {
            OkrasMenuGreen(Rules);
        } if (color == 1)
        {
            OkrasMenuRed(Rules);
        }
    }
    static void LogoExit(int color)
    {
        char Exit[5][100] = {
            "****  *    *  *  ***** ",
            "*      *  *   *    *   ",
            "****    *     *    *   ",
            "*     *   *   *    *   ",
            "**** *     *  *    *   ",

        };
        if (color == 0)
        {
            OkrasMenuGreen(Exit);
        } if (color == 1)
        {
            OkrasMenuRed(Exit);
        }
    }
    static void LogoWinner(int color)
    {
        char Winner[14][100] = {
            "                    #############                         ",
            "                  ####################################### ",
            "                 ##################                       ",
            "             ###########################                  ",
            "           #################################              ",
            "          #***O*******O*******O*******O****#              ",
            "           #***O*****O*******O*******O****#               ",
            "            ##############################                ",
            "                                                          ",
            "##         ##  ##  ####   ##  ####   ##  ######  ######  ## ",
            "##         ##  ##  ## ##  ##  ## ##  ##  ##      ##  ##  ## ",
            "##  ####   ##  ##  ##  ## ##  ##  ## ##  ######  ######  ## ",
            "## ##  ##  ##  ##  ##   ####  ##   ####  ##      ## ##      ",
            "####     ####  ##  ##    ###  ##    ###  ######  ##  ##  ## ",

        };
        if (color == 2)
        {
            OkrasWinnerGreen(Winner);
        } if (color == 1)
        {
            OkrasWinnerRed(Winner);
        }
    }

   
    static int  Menu()
    {
        int menuCurs = 1;
        char perehod;

        do
        {
            switch (menuCurs)
            {
            case 1:
                system("cls");
                LogoTank();
                cout << endl << endl << endl;
                LogoStart(0);
                cout << endl;
                LogoAuthors(1);
                cout << endl;
                LogoRules(1);
                cout << endl;
                LogoExit(1);
                perehod = _getch();
                if (perehod == 's' || perehod == 80)
                {
                    menuCurs++;
                }
                break;
            case 2:
                system("cls");
                LogoTank();
                cout << endl << endl << endl;
                LogoStart(1);
                cout << endl;
                LogoAuthors(0);
                cout << endl;
                LogoRules(1);
                cout << endl;
                LogoExit(1);
                perehod = _getch();
                if (perehod == 's' || perehod == 80)
                {
                    menuCurs++;
                }
                else if (perehod == 'w' || perehod == 72)
                {
                    menuCurs--;
                }
                break;
            case 3:
                system("cls");
                LogoTank();
                cout << endl << endl << endl;
                LogoStart(1);
                cout << endl;
                LogoAuthors(1);
                cout << endl;
                LogoRules(0);
                cout << endl;
                LogoExit(1);
                perehod = _getch();
                if (perehod == 's' || perehod == 80)
                {
                    menuCurs++;
                }
                else if (perehod == 'w' || perehod == 72)
                {
                    menuCurs--;
                }
                break;
            case 4:
                system("cls");
                LogoTank();
                cout << endl << endl << endl;
                LogoStart(1);
                cout << endl;
                LogoAuthors(1);
                cout << endl;
                LogoRules(1);
                cout << endl;
                LogoExit(0);
                perehod = _getch();
                if (perehod == 'w' || perehod == 72)
                {
                    menuCurs--;
                }
                break;
            default:
                break;
            }
        } while (perehod != 13);
        return menuCurs;
    }
  
    static void LogoSergeyOlisov()
    {
        char SergeyOlisov[14][100] = {
            "                                            ##                 ",
            "   #####    #####  #####   #####  #####  #    ##               ",
            " #         #      #    #  #      #      #   # #                ",
            "#         #####  #####   #      #####  #  #  #                 ",
            "#        #      #       #      #      # #   #                  ",
            " #####  #####  #       #      #####  ##    #                   ",
            "                                                               ",
            "                                                               ",
            "        ###       ###      #    ##   #####    ###      ####    ",
            "      #    #     #  #     #   # #  #        #    #    #    #   ",
            "     #     #    #   #    #  #  #  #        #     #   #####     ",
            "     #    #    #    #   # #   #   #        #    #   #      #   ",
            "      ###    #      #  ##    #     #####    ###    #######     ",
        };
        OkrasLogoAuthor(SergeyOlisov);
    }
    static void LogoSergePris()
    {
        char SergePris[14][100] = {
            "                                             ##               ",
            "   #####    #####  #####   #####  #####  #    ##              ",
            " #         #      #    #  #      #      #   # #               ",
            "#         #####  #####   #      #####  #  #  #                ",
            "#        #      #       #      #      # #   #                 ",
            " #####  #####  #       #      #####  ##    #                  ",
            "                                                              ",
            "                                                              ",
            "    #####   #####    #    ##    #####    #####  #  #   #   #    #  #       #  #     #",
            "   #    #  #     #  #   # #   #        #    #    #  #     #    #  #       #    #  #  ",
            "  #    #  ######   #  #  #   #         #####      #      ######  #####   #      #    ",
            " #    #  #        # #   #    #          # #     #  #    #    #  #     # #     #  #   ",
            "#    #  #        ##    #      #####  #   #    #  #  #  #    #  ######  #    #      # ",
        };
        OkrasLogoAuthor(SergePris);
    }
    static void LogoIliaRyazantsev()
    {
        char liaRyazantsev[14][100] = {
            "    #    ##   ###      #        ##### ",
            "   #   # #   #  #     #       #    # ",
            "  #  #  #   #   #    #####    #####  ",
            " # #   #   #    #   #     #    # #   ",
            "##    #  #      #  ######   #   #    ",
            "                                                                        ",
            "                                                                        ",
            "    #####     #####   #####    ##       #    #  #    #     #####  ####  ",
            "   #     #  #    #       #   #   #     #    #  #    #     #      #    #",
            "  ######    #####   #####   #    #    ######  #    #     #####  #####  ",
            " #           # #       #   # ### #   #    #  #    #     #      #     # ",
            "#         #   #   #####   #      #  #    #  #########  #####  ######   ",
            "                                                   #                   ",
        };
        OkrasLogoAuthor(liaRyazantsev);
    }
  /*  static void LogoRules()
    {
        char Rules[14][100] = {
            
        };
        OkrasMenuRed(Rules);
    }*/
   

};

