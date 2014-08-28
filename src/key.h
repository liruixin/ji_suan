#ifndef __KEY_H__
#define __KEY_H__
#include "lcd.h"
void keyscan();
void jisuan(int value,uchar *arr);
double transfer(uchar *arr);
void display(double result);
#endif