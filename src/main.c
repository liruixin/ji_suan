#include <reg52.h>
#include "lcd.h"
#include "key.h"
#include "jisuan.h"
void main()
{
  init();
  //write_dat(48);
  //display(1);
  while(1)
  {
     keyscan();	
  }
}