 // Created on Mon March 3 2014
void turnRight(double angle); 
void turnLeft(double angle);
void moveForward(float distance, int speed); // in millimeters and millimeters per second
void moveBackward(float distance, int speed);
void raiseArm();
void hangerTurn();

int main()
{
	/*create_connect();
	turnRight(150); //Out of the Starting box (Hard coded)
    moveBackward(55,185); //orig 62
    turnLeft(90.0);
	moveBackward(93.5,250);
	turnRight(90.0);
	create_drive_direct(0,0);// Stops the robot*/
	raiseArm();
	/*msleep(10000);
	moveForward(20,0);
	moveForward(4,250);
	turnRight(90.0);
    moveForward(90,250);*/
    //create_disconnect();
	disable_servos();
	ao();
    return 0;
}

void turnRight(double angle){
    set_create_total_angle(0);
	while(1){
        if(get_create_total_angle()>-angle*0.83){//0.83 is from testing to get a right angle
            create_drive_direct(100,-100);
			msleep(1);
        }
        else{
            break;//Breaks the loop
        }
        msleep(100);
        printf("angle : %d\n", get_create_total_angle());
    }
}

void turnLeft(double angle){
    set_create_total_angle(0);
	while(1){
        if(get_create_total_angle()<angle*0.83){
            create_drive_direct(-100,100);
			msleep(1);
        }
        else{
            break;//Breaks the loop
        }
        msleep(10);
        printf("angle : %d\n", get_create_total_angle());
    }
}

void moveForward(float distance, int speed){
    distance *= 10.0;
    float time = distance/speed*1000;
    create_drive_direct(speed,speed);
    msleep(time);
}

void moveBackward(float distance, int speed){
    distance *= 10.0;
    create_drive_direct(-speed,-speed);
    msleep((distance/speed)*1000);
}
void raiseArm(){
	clear_motor_position_counter(3);
	while(1){
		if(digital(8)==0){//TOUCH Sensor. When the arm reaches is maximum height the sensor is in position to hit the lower bar
			mav(3,-400);
			msleep(1);
		}
		else{
			
			enable_servos();
			set_servo_position(1,975); //turn so hangers are erect orig 1024
			msleep(2000);
			while(digital(9)!=1){
				moveBackward(0.1,20); //back into the bar
			}
			disable_servos();
			//mav(3,-50); //go up some more
			//msleep(4000);
			//moveBackward(1.0,50);
			mav(3,430); //lower 
			msleep(3500); //orig 3200
			moveForward(1,50); //come out of the location
			printf("hi");
			break;
		}
	}
	
}




