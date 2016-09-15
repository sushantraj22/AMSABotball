// Created on Mon Feb 27 2012

#include <stdio.h>

int main() 
{
  wait_for_light(0); // light sensor in analog port 0
  shut_down_in(119.0); //turn off in 119 seconds - leaving room for error
	/*while (black_button()==0)
	{
		beep(); //beep...
		sleep(0.2); //pause 2 seconds
	} not sure if we're using... */
   printf("All done\n");  // never get to this!
   return 0;
}
