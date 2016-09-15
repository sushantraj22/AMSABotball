//

#include <stdio.h>

void openClaw();
void closeClaw();
void liftArm();
void dropArm();
int main() 
{
	enable_servo();//servos are live
	liftArm();//motor in port 3, arm is now up
	openClaw();//servo in port 3, claw is now open
	closeClaw();//servo in port 3, claw is now closed
	dropArm();//drop arm motor in port 3
}
void openClaw() //function to open claw, servo in port 3
{ 
	int C=0, R=500;//C=closed, R=open, adjust values as needed
	set_servo_position(3, R);//servo is to open
	sleep(0.1)//waiting for servo to close
void liftArm()//function to lift arm, motor in port 3
{
	{
	clear_motor_position_counter(3);
	mtp(3,250,1050);
	sleep(4);//waiting for arm to reach full height, adjust as needed
}

void closeClaw()//function to close claw, servo in port 3
{
	int C=0, R=500 ; //C=closed, R=open, adjust values as needed
	set_servo_position(3, C); //servo is now closed
	sleep(2);//wait for servo to close, adjust as needed
}
void dropArm()//function to drop arm
{
	clear_motor_position_counter(3);
	mtp(3, -250, 1050);
	sleep(4);
}
