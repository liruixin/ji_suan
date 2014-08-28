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
void jisuan(int value,uchar *arr)
{
   static double numa=0,numb=0,result=0;
   static uchar temp=0;
   static int flag=0;
   uchar i;
   if((value>=0)||(value==-2))
   {
       if(value!=13)
       { temp++;arr[temp]=value+48;}
   }
   if(value==13)
   {
       numb=transfer(arr);
	   if(flag==1)
	   {
	      result=numa+numb;
		  display(result);
	   }
	    if(flag==2)
	   {
	      result=numa-numb;
		  display(result);
	   }
	    if(flag==3)
	   {
	      result=numa*numb;
		  display(result);
	   }
	    if(flag==4)
	   {
	      result=numa/numb;
		  display(result);
	   }
   }
   if((value<=-1)&&(value>=-6))
   {
      if(value!=-2)
	  {
       numa=transfer(arr);
	   temp=0;
	   for(i=1;i<14;i++)
	   {
	     arr[i]=0; 
	   }
	   switch(value)
	   {
	      case -5 :flag=1; break;
		  case -3 :flag=2; break;
		  case -6 :flag=3; break;
		  case -1 :flag=4; break;
	   }
	   }
   }
}
/************************************************/
void display(double result)
{
   long zheng=0;//整数部分
   double xiao=0;//小数部分
   uchar num[16]={"0"};
   uchar i;
   result+=0.000001;//防止少数
   zheng=result;
   xiao=result-(double)zheng;
   num[0]=zheng/10000+48;
   num[1]=zheng%10000/1000+48;
   num[2]=zheng%1000/100+48;
   num[3]=zheng%100/10+48;
   num[4]=zheng%10+48;
   num[5]=46;
   xiao*=10000;
   num[6]=(int)xiao/1000+48;
   num[7]=(int)xiao%1000/100+48;
   num[8]=(int)xiao%100/10+48;
   num[9]=(int)xiao%10+48;
   for(i=0;(num[i]==48)&&(i<4);i++)//除0
   num[i]=0;
   for(i=9;(num[i]==48)&&(i>=0);i--)//除0
	num[i]=0;
	write_com(0x80+0x40); //di er hang
   for(i=0;i<=4;i++)
   {
	   if(num[i]!=0)
	   write_dat(num[i]);//write_dat
   }
   if((int)xiao!=0)
   {
        for(i=5;i<=9;i++)
      {
	    if(num[i]!=0)
     	write_dat(num[i]);//write_dat
      } 
   }
}
/********************************************************/

double transfer(uchar *arr)//the first cement of arr[] must be ':'!!!
{
   double value=0; int i;
   for(;(*arr>=48)&&(*arr<=58);arr++);//move to point--'.'
   if(*arr==0)                                 //value is int
   {
	  arr--;
	  for(i=0;(*arr>=48)&&(*arr<=57);i++)
	  {
	     value+=((double)(*arr-48))*pow(10,i);
	     arr--;
	  }
	  return value;
   }
   if(*arr==46)                               //value is float
   {
	   arr--;
	   for(i=0;(*arr>=48)&&(*arr<=57);i++)  //int part
	  {
	     value+=((double)(*arr-48))*pow(10,i);
	     arr--;
	  }
	   for(;(*arr>=48)&&(*arr<=58);arr++);//move to point--'.'
        arr++;
	   for(i=-1;(*arr>=48)&&(*arr<=57);i--) //float part
	  {
	     value+=((double)(*arr-48))*pow(10,i);
	     arr++;
	  }
	   return value;
   }
}


