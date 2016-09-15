#include <stdio.h>
// Code starts after in "hotspot" where it can view all 3 blocks //
// Consider location of arm and claw
int YELLOW	= 1;
int RED =  0;
int BLUE =  3;
int NINETY_DEGREE = 850; //ticks

//functions!

int findBlock(int color);
void setSensorPort1();
void moveForwardET(int distance);
void moveBackwardET(int distance);
int moveBlueBlock();
void turnAngle(int maxTicks);
int stackBlock(int color, int height);
void makeATurn();

int main() 
{
	int totalTurn = findBlock(BLUE);
	
	// if block is in the corner, move it
	if (totalTurn < NINETY_DEGREE)
	{
		moveBlueBlock(); //make
	}	
	
	stackBlock(YELLOW, 9);
	
	stackBlock(RED, 15);

	
	//printf("The total turn is %d\n", totalTurn);
	return 0;
}

void setSensorPort1() {
	
	set_each_analog_state(1,0,0,0,0,0,0,0);
	//set port 0 to floating
	sleep(0.02); //wait for state to change

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

int moveBlueBlock() {
	//TODO: move the block
	//go to blue block
	moveForwardET(1000);
	
	//pick up blue block
	//?? call pickUpBlock();
	
	//backward how much ???
	moveBackwardET(200);
	
	//turn 45 degree
	turnAngle(NINETY_DEGREE/2);
	
	//check for other colored blocks in front of it
	track_update();
	if (track_count(YELLOW)>0 || track_count(RED)>0) 
		{
			makeATurn();  // turn 3 times so that the manipulator will not bump into the block in front of it
			makeATurn();
			makeATurn();
		}
	
	//go until reach edge
	moveForwardET(1000);
	
	//drop the block
	//?? call dropBlock();
	
	//backward
	moveBackwardET(200);

	//current location is in the center?
}

int stackBlock(int color, int height) {
	
	findBlock(color);
	
	//go to block
	moveForwardET(1000);
	
	//pick up yellow block 
	//?? call pickupBlock();
	
	//backward 
	moveBackwardET(200);
	
	//find blue block
	findBlock(BLUE);
	
	//move to blue block
	moveForwardET(1000);
	
	//stack the  block on top of blue block
	//?? call dropBlock();
	
	// backward
	moveBackwardET(200);
	
}

int findBlock(int color)
{
	int totalTurn = 50;

	while (1) {
		makeATurn();
		track_update(); //processes the most recent image

		//check if (color) block is found, turn to face the center of the block and then break
		if (track_count(color)>0) 
		{
			mtp(3, 100, 150);
			mtp(0, 100, -150);
			bmd(3);
			bmd(0);
			break;
		} 
		else 
		{
			totalTurn += 50;
		}
	}
	return totalTurn;
}

void turnAngle(int maxTicks) 
{

	int num = 1;
	while(1) 
	{
		makeATurn();
		num++;
		if (50 * num >= maxTicks)
		{
			break;
		}	
	}
}

void makeATurn()
{
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(3, 100, 50); 
	mtp(0, 100, -50);
	bmd(3);
	bmd(0);
}
