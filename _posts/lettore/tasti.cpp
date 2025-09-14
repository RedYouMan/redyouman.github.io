#include <iostream>
#include <conio.h>
#include <ctime>
#include "tasti.h"
using namespace std;
int TastiOk[NUMTASTI] = {SPACE, CntrlS, CntrlK, CntrlZ, CntrlJ, CntrlW, UP, DOWN, LEFT, RIGHT, CntrlL, CntrlG, CntrlR, CntrlN, CntrlQ, CntrlH, CntrlT, ESC, knum0, knum1, knum2, knum3, knum4, knum5, knum6, knum7, knum8, knum9, Si, No, CntrlP, CntrlU};
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

    int val_ret = 0;
    int valore = get_input();
    switch (valore)
    {

    case CntrlS:
        val_ret = CntrlS;
        break;

    case CntrlK:
        val_ret = CntrlK;
        break;
    case CntrlZ:
        val_ret = CntrlZ;
        break;
    case SPACE:
        val_ret = SPACE;
        break;
    case ESC:
        val_ret = ESC;
        break;
    case CntrlJ:
        val_ret = CntrlJ;
        break;
    case CntrlP:
        val_ret = CntrlP;
        break;
    case CntrlW:
        val_ret = CntrlW;
        break;
    case UP:
        val_ret = UP;
        break;
    case DOWN:
        val_ret = DOWN;
        break;
    case RIGHT:
        val_ret = RIGHT;
        break;
    case LEFT:
        val_ret = LEFT;
        break;
    case CntrlL:
        val_ret = CntrlL;
        break;
    case CntrlG:
        val_ret = CntrlG;
        break;
        ;
    case CntrlQ:
        exit(0);
        break;
    case CntrlU:
        val_ret = CntrlU;
        break;
    case CntrlH:
        val_ret = CntrlH;
        break;
    case CntrlR:
        val_ret = CntrlR; // chiede viewManoG();
        break;
    case CntrlT:
        val_ret = CntrlT;
        break;
    case CntrlN:
        val_ret = CntrlN;
        break;
    case knum0:
        val_ret = knum0;
        break;
    case knum1:
        val_ret = knum1;
        break;
    case knum2:
        val_ret = knum2;
        break;
    case knum3:
        val_ret = knum3;
        break;
    case knum4:
        val_ret = knum4;
        break;
    case knum5:
        val_ret = knum5;
        break;
    case knum6:
        val_ret = knum6;
        break;
    case knum7:
        val_ret = knum7;
        break;
    case knum8:
        val_ret = knum8;
        break;
    case knum9:
        val_ret = knum9;
        break;
    case No:
        val_ret = No;
        break;

    case Si:
        val_ret = Si; // adattamento
        break;
    default:
        break;
    }
    // printf("ritorno valore key %d\n", val_ret);
    return (val_ret);
}
int attendiTasti()
{

    bool continua = true;
    do
    {

        unsigned int tasto = 0;
        bool testok = false;

        delay(1300);
        if (_kbhit())
        {
            tasto = what_key();

            // printf("debug: tasto %d\n", tasto);
            for (int i = 0; i < NUMTASTI; i++)
            {
                if (tasto == TastiOk[i])
                {
                    testok = true;
                    // printf("tastotastiok ok\n");
                    break;
                }
            }
            if (testok)
            {
                return (tasto);
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