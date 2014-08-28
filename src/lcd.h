#ifndef __LCD_H__
#define __LCD_H__
#include"def.h"
void delay(uint ms);
void init();
void write_com(uchar com);
void write_dat(uchar dat);
uchar read_dat() ;

#endif	