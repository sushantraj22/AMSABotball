#include <stdio.h>
// Code starts after in "hotspot" where it can view all 3 blocks //
// Consider location of arm and claw
int turn(int times);

int main() 
{
	int totalTurn = turn(34);
	printf("The total turn is %d\n", totalTurn);
	return 0;
}

int turn(int times)
{
	int found = 0;
	int totalTurn = 0;
	int i = 0;
	while (i < times) {
		totalTurn += 50;
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(3, 100, 50);  // 1100 is full 360 turn
		mtp(0, 100, -50);
		bmd(3);
		bmd(0);
		
		i++;

	}
	return totalTurn;
}
	

