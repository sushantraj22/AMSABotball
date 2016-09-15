// Created on Wed Mar 14 2012

#include <stdio.h>
void moveForwardET(int distance);
void moveBackwardET(int distance);
int main() 
{
	moveForwardET(1000);
	moveBackwardET(200);
	return 0;
}
void moveForwardET(int distance) {
	while(1){ //loop forever
		if (analog10(0)<=distance){ //if too far away
			fd(0); //get closer
			fd(3);
		}
		bk(0); //back up
		bk(3);
		break;

	}
}

void moveBackwardET(int distance) 
{
	while(1){ //loop forever
		if(analog10(0)>distance){ //if too close
			bk(0); //back up
			bk(3);
		}
		fd(0); //get closer
		fd(3);
		break;
	}
}
