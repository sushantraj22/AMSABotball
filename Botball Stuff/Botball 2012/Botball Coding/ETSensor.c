// Created on Wed Mar 14 2012
/*This program demonstrates how to use the ET for sensing distances. This program uses an ET in port 0 and motors in ports 0 and 3. The robot drives forward until it detects an object. If the object gets closer, the robot backs up, if the object gets further away, the robot moves closer. When using this type of programming watch out for dead zones (where the sensor values do nothing).*/
#include <stdio.h>

int main()
{
	set_each_analog_state(1,0,0,0,0,0,0,0);
	//set port 0 to floating
	sleep(0.02); //wait for state to change
	while(1){ //loop forever
		if(analog10(0)>512){ //if too close
			bk(0); //back up
			bk(3);
		}
		if (analog10(0)<=512){ //if too far away
			fd(0); //get closer
			fd(3);
		}
	}
}
