// Created on Tue April 16 2013
   
void turnRight(); 
void turnLeft();
void moveForward(int distance, int speed); // in millimeters and millimeters per second
void moveBackward(int distance, int speed);

int main()
{
	create_connect();
	moveForward(100, 100); // TEST: should move 10 cm 
	/*Transport Movement*/
	
	/*moveBackward(100,100);
	TurnRight();
	moveBackward(300,100);*/
	
	//bam bam
	/*create_drive_direct(500, 500);
	msleep(50);
	create_drive_direct(-100, -100);
	msleep(150);
	create_drive_direct(500, 500);
	msleep(50);
	create_drive_direct(-100, -100);
	msleep(150);*/
	
	/* Stacking Movements */
	//forward 106 cm
	//turnRight();
	//turn right
	//forward 22 cm
	//backward
	//turnleft
	//backward 54  cm
	//backward 3.5 cm
	//turn left
	//forward 3 cm
	int a = get_create_distance();
	printf("The distance so far is %i mm", a );
	create_disconnect();
	return 0;
}

void turnRight(){
	create_drive_direct(100,-100);
	msleep(2000);
}
void turnLeft(){
	create_drive_direct(-100,100);
	msleep(2000);
}
void moveForward(int distance, int speed){
	create_drive_direct(speed,speed);
	int time = distance/speed;
	msleep(time*10);
}
void moveBackward(int distance, int speed){
	create_drive_direct(-speed,-speed);
	int time = distance/speed;
	msleep(time*10);
}
	
/*void bamBam()
{
create_connect();
create_drive_direct(500, 500);
msleep(50);
create_drive_direct(-100, -100);
msleep(250);
create_drive_direct(500, 500);
msleep(50);
create_drive_direct(-100, -100);
}
*/
