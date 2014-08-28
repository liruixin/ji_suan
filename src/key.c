#include "key.h"
uchar array[16]={":"};
void keyscan()	   //这个键盘检测是普中的写法，很简洁
{
   int value;
   KEY=0x0f;
   if(KEY!=0X0F)
   {
      delay(10);
	if(KEY!=0x0f)
	{
	   KEY=0xf0;
	   switch(KEY)
	   {
	    case(0xe0):value=-2;break;
		case(0xd0):value=-1;break;
		case(0xb0):value= 0;break;
		case(0x70):value=-5;break;
	   }
	   KEY=0x0f;
	   switch(KEY)
	   {
	    case(0x0e):value+=0;break;
		case(0x0d):value+=3;break;
		case(0x0b):value+=6;break;
		case(0x07):value+=9;break;
	   }
	   KEY=0xfe;
	   switch(KEY)
	   {
	    case(0xee):value=0;break;
		case(0xde):value=-2;break;
		case(0xbe):value=13;break;
		case(0x7e):value=-5;break;
	   }
	   KEY=0x7f;
	   switch(KEY)
	   {
	    case(0x7e):value=-5;break;
		case(0x7d):value=-3;break;
		case(0x7b):value=-6;break;
		case(0x77):value=-1;break;
	   }
	   KEY=0xf0;
	   while(KEY!=0Xf0);
	   write_dat(value+48);
	   jisuan(value,array);
	}
   }
}
/*******************************************/
