// Created on Mon March 17 2014
// Natalie Reed, Gal Bejerano, Kasandra Yee, Christine Hsieh, James D
// Movement for getting botguy and exercise bench SEPARATELY (bench first)
#define LEFTWHEEL 2
#define RIGHTWHEEL 0
#define LIGHT 1
#define ARM 1
int start=1000;
void turn90Left(); 
void turn90Right();
void moveForward(int distance);
void moveBackward(int distance);
void grabBotGuy(); 
void liftArm(int height);
void claw(int width);
void findBlock();
/**
NOTE
PORTS: 0 = left, 1 = right, for arm = 2
Distance and Height are measured in centimeters.
**/

int main()
{
	
	//wait_for_light(0);
	clear_motor_position_counter(LEFTWHEEL);
	clear_motor_position_counter(RIGHTWHEEL);
	clear_motor_position_counter(ARM);
	start=analog10(LIGHT);
	turn90Left();
	
	moveForward(75);//distance to black line
	turn90Left();
	findBlock();
	moveForward(150);
	turn90Left();
}
void turn90Right(){ 
	clear_motor_position_counter(LEFTWHEEL);
	clear_motor_position_counter(RIGHTWHEEL);
	mtp(LEFTWHEEL,500,754); //port, speed, distance
	mtp(RIGHTWHEEL,500,-754);
	bmd(LEFTWHEEL); //makes motor stop running after finished
	bmd(RIGHTWHEEL);
}
void turn90Left(){ 
	clear_motor_position_counter(LEFTWHEEL);
	clear_motor_position_counter(RIGHTWHEEL);
	mtp(LEFTWHEEL,500,-750); //original is 759
	mtp(RIGHTWHEEL,500,750); 
	bmd(LEFTWHEEL); //makes motor stop running after finished
	bmd(RIGHTWHEEL);
}
void moveForward(int distance){   
	clear_motor_position_counter(LEFTWHEEL);
	clear_motor_position_counter(RIGHTWHEEL);
	mtp(LEFTWHEEL,500,1000/15*distance); //port, speed, distance 1000 = 15 cm
	mtp(RIGHTWHEEL,500,1000/15*distance);
	bmd(RIGHTWHEEL); //makes motor stop running after finished
	bmd(LEFTWHEEL);
} 
void moveBackward(int distance)
{   
	clear_motor_position_counter(LEFTWHEEL);
	clear_motor_position_counter(RIGHTWHEEL);
	mtp(LEFTWHEEL,500,distance); //port, speed, distance 1000 = 15 cm
	mtp(RIGHTWHEEL,500,distance);
	bmd(LEFTWHEEL); //makes motor stop running after finished
	bmd(RIGHTWHEEL);
}
void liftArm(int height)
{
	clear_motor_position_counter(1);
	printf("arm going down");
	mtp(ARM,500,height);
	bmd(ARM);
	printf("done! =)");
}
void claw(int width)
{
	enable_servos();
	set_servo_position(1,width);
	msleep(1000);
	disable_servos();
}
void findBlock()
{
	while(analog10(LIGHT)>start-5 ){
		clear_motor_position_counter(LEFTWHEEL);
		clear_motor_position_counter(RIGHTWHEEL);
		mtp(LEFTWHEEL,500,10); //original is 759
		mtp(RIGHTWHEEL,500,-10); 
		bmd(LEFTWHEEL); //makes motor stop running after finished
		bmd(RIGHTWHEEL);
	}
	printf("Found block");
	//mtp(LEFTWHEEL,500,-5); //original is 759
	//mtp(RIGHTWHEEL,500,5); 
	//bmd(LEFTWHEEL); //makes motor stop running after finished
	//bmd(RIGHTWHEEL);
}



