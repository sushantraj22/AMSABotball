#include <stdio.h>
// Code starts after in "hotspot" where it can view all 3 blocks //
// Consider location of arm and claw
int YELLOW	= 1;
int RED =  0;
int BLUE =  3;
int findBlock(int color);

int main() 
{
	int totalTurn = findBlock(RED);
	printf("The total turn is %d\n", totalTurn);
	return 0;
}

int findBlock(int color)
{
	int found = 0;
	int totalTurn = 50;

	while (1) {
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(3, 100, 50);  // 1100 is full 360 turn
		mtp(0, 100, -50);
		bmd(3);
		bmd(0);
		
		track_update(); //processes the most recent image

		//check if (color) block is found or make full circle, break
		if (track_count(color)>0) 
		{
			found = 1;
			mtp(3, 100, 150);  // 1100 is full 360 turn
			mtp(0, 100, -150);
			bmd(3);
			bmd(0);
			break;
		} 
		/*else if (totalTurn > 3600)//1100 TOO LITTLE!!!! 
		{
			break;
		} */
		else 
		{
			totalTurn += 50;
		}
	}
	return totalTurn;
}
	

//2 possibilities, either make function and change variable color based on situation, or copy and paste and change each time to fit situation
