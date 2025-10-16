#include <iostream>
#include <conio.h>
#include <ctime>
#include "tasti.h"
using namespace std;

int TastiOk[NUMTASTI] = {RETURN, SPACE, CntrlS, CntrlK, CntrlZ, CntrlJ, CntrlW, UP, DOWN, LEFT, RIGHT, CntrlL, CntrlG, CntrlR, CntrlN, CntrlQ, CntrlH, CntrlT, ESC, knum0, knum1, knum2, knum3, knum4, knum5, knum6, knum7, knum8, knum9, Si, No, CntrlP, CntrlU};

void delay(int ms)
{
    clock_t goal = ms * CLOCKS_PER_SEC / 1000 + clock();
    while (goal > clock())
        ;
}

int get_input()
{
    int input = 0, digits = 0;
    input = _getch();
    return ((input == 224 ? _getch() : input));
}
// whatKey decide che tasto è stato digitato
int what_key()
{

    int valore = 0;
    valore = get_input();
    if (valore == CntrlQ)
    {
        exit(1);
    }

    return valore;
}

// attendiTasti() permette di rilevare combinazioni di Cntrl+tasto e un solo tasto numerico
// mentre attendiUnoODueDigit() rileva Cntrl+tasto e due digit numerici
int attendiTasti()
{

    bool continua = true;
    do
    {

        unsigned int tasto = 0, valore = 0;
        bool testok = false;

        delay(1300);
        if (_kbhit())
        {
            tasto = what_key();
            valore = tasto;
            for (int i = 0; i < NUMTASTI; i++)
            {
                if (tasto == TastiOk[i])
                {
                    testok = true;
                    break;
                }
            }
            if (testok)
            {
                return (valore);
            }
            else
            {
                printf("Tasto non consentito\n");
                testok = false;
            }
        }
    } while (continua);

    return (0);
}

// attende per uno o due digit
int attendiUnoODueDigit()
{

    int count = 0, digits = 0, tasto = 0;
    do
    {
        delay(1300);
        if (_kbhit())
        {
            tasto = what_key();
            count++;
            if (count == 1)
            {
                digits = (tasto - knum0) * 10;
            }
            if (count == 2)
            {
                digits += (tasto - knum0);
            }
        }
        else
        {
            // seconda parte
            if (count == 1)
            {
                return (tasto - knum0);
            }
            if (count >= 2)
            {
                return (digits);
            }
        }

    } while (1);
    return (0);
}
