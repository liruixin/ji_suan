#include "lcd.h"
void delay(uint ms)//��ʱ
{
   uint x,y;
   for(x=ms;x>0;x--)
      for(y=123;y>0;y--);
}
void init()			 //��ʼ��
{
   dula=0;wela=0;
   en=0;
   write_com(0x38);
   write_com(0x0c);
   write_com(0x06);
   write_com(0x80);
   write_com(0x01);
}
void write_com(uchar com)//д����
{
   rs=0;
   rw=0;
   LCD=com;
   delay(2);
   en=1; delay(3);en=0;
}
void write_dat(uchar dat)//д����
{
   rs=1;
   rw=0;
   LCD=dat;
   delay(2);
   en=1;delay(3);en=0;
}
uchar read_dat()       //������
{
         uchar lcd_data;
         P0=0xff;
         en=0;
         delay(3);
         rs=1;
         rw=1;
         en=1;
         lcd_data=P0;
         en=0;
        return lcd_data;
 }
