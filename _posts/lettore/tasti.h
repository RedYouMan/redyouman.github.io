#ifndef TASTI
#define TASTI

// gestione tasti consentiti della tastiera
#define NUMTASTI 33
const int RETURN = 13;
const int CntrlS = 19;
const int CntrlK = 11;
const int CntrlZ = 26;
const int SPACE = 32;
const int UP = 72;
const int LEFT = 75;
const int DOWN = 80;
const int RIGHT = 77;
const int CntrlW = 23;
const int CntrlL = 12;
const int ESC = 27;
const int CntrlG = 7;
const int CntrlQ = 17;
const int CntrlR = 18;
const int CntrlT = 20;
const int CntrlN = 14;
const int knum0 = 48;
const int knum1 = 49;
const int knum2 = 50;
const int knum3 = 51;
const int knum4 = 52;
const int knum5 = 53;
const int knum6 = 54;
const int knum7 = 55;
const int knum8 = 56;
const int knum9 = 57;
const int CntrlH = 8;
const int CntrlU = 21;
const int Si = 115;
const int No = 110;
const int CntrlP = 16;
const int CntrlJ = 10;
void delay(int ms);
int attendiUnoODueDigit();
int attendiTasti();
int get_input();
int what_key();
#endif