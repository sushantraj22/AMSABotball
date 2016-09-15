// Created on Sun Mar 18 2012
// This program controls the end-to-end movement of the Create
// motor 0 is for sweeper
// servo 0 is for pusher

#include <stdio.h>

void turn_left(float seconds); 
void turn_right(float seconds);

//these are the constants that represent the time needed for the create to move from one point to the next (in seconds)
const float org_to_a = 7.5;	 	//61.5"
const float a_to_b = 2.65; 	  	//20"
const float b_to_c = 2.3 ;		    //20"
const float c_to_d = .5;  	//6"
const float d_to_e = 1.6;     	//16"
const float e_to_f = 0.5; 	//3"
const float e_to_g = 3;     	//24"
const float g_to_h = 1.40; //(made longer) 1.35;   	//12"
const float twoxh_to_i = 14;//13.75; //6.875; 	//55"	ALSO CHANGED THE SPEED, so time may be different
const float i_to_j = 1.58; //made longer1.5; // 2.3;(shorten this)	//1.8;   	//12"
const float twoxj_to_k = 3.3; //2.95;(lengthened this)//1.5;   	//12"
const float angle_90 = 0.64; //0.3891;	//time it takes to turn 90 degrees at 300 velocity
const float angle_45 = 0.19455;	//time it takes to turn 45 degrees at 300 velocity

int main() 
{
	printf("Hello, World!\n");
	wait_for_light(0); //Don't have to make it a while, because it has to first go through this step before continuing
	printf("I've seen the light! Let the game begin\n");
	shut_down_in(119.0);
	
	while(create_connect());
	
	create_safe();
	
	create_stop();
	sleep(60); // put in correct time
	
	//move forward to point A (61.5 inches)
	create_drive_direct(-200,-200);
	sleep(org_to_a);
	create_stop();
	
	//turn left 90 degress 
	turn_left(angle_90);
	
	//move forward to point B (20 inches) to get ready to flip fish farm onto baord
	clear_motor_position_counter(0);
	create_drive_direct(-200,-200);
	sleep(a_to_b);
	create_stop();
	sleep(0.5);
	
	//turn sweeper on just long enough to drop the farm on the board
	clear_motor_position_counter(0);
	mtp(0, 485, 1000);
	sleep(1);
	
	//turn left to face point C
	clear_motor_position_counter(0);
	turn_left(angle_90);
	
	//move forward to point C (20 inches)
	clear_motor_position_counter(0);
	create_drive_direct(-200,-200);
	sleep(b_to_c);
	create_stop();
	
	//turn to face point D
	clear_motor_position_counter(0);
	turn_right(angle_90);
	
	//move to point D
	clear_motor_position_counter(0);
	create_drive_direct(-200, -200);
	sleep(c_to_d);
	create_stop();
	
	//turn to point E
	clear_motor_position_counter(0);
	turn_left(angle_90);
	
	//move to point E
	clear_motor_position_counter(0);
	create_drive_direct(-200,-200);
	sleep(d_to_e);
	create_stop();
	
	//turn on sweeper
	clear_motor_position_counter(0);
	mav(0, 1000);
	
	//turn to point F
	clear_motor_position_counter(0);
	turn_right(angle_90);

	
	//move to point F
	clear_motor_position_counter(0);
	create_drive_direct(-200, -200);
	sleep(e_to_f);
	create_stop();
	sleep(3);
	
	//back out of point f
	clear_motor_position_counter(0);
	create_drive_direct(200,200);
	sleep(e_to_f);
	create_stop();
	
	//turn to point g
	clear_motor_position_counter(0);
	turn_left(angle_90);
	
	//move to point g
	clear_motor_position_counter(0);
	create_drive_direct(-200,-200);
	sleep(e_to_g);
	create_stop();
	
	//turn to point h
	clear_motor_position_counter(0);
	turn_left(angle_90);
	
	//move to point h
	clear_motor_position_counter(0);
	create_drive_direct(-200,-200);
	sleep(g_to_h);
	create_stop();
	
	//turn to point I
	clear_motor_position_counter(0);
	turn_left(angle_90);
	//reate_drive_direct(300,-300);
	//turn_left(0.55);//CHANGED THE ANGLE
	sleep(0.55);
	
	//move to point I
	clear_motor_position_counter(0);
	create_drive_direct(-100,-100);
	sleep(twoxh_to_i);
	create_stop();
	
	//turn to point J
	clear_motor_position_counter(0);
	turn_right(angle_90);
	
	//move to point J
	clear_motor_position_counter(0);
	create_drive_direct(-200,-200);
	sleep(i_to_j);
	create_stop();
	
	//turn to point K
	clear_motor_position_counter(0);
	turn_left(angle_90);
	
	//move to point K
	clear_motor_position_counter(0);
	create_drive_direct(-100,-100);
	sleep(twoxj_to_k);
	create_stop();
	
	//moving the wall out to deposit the polyps
	//this is unloading the polyps, the servo will need to be in port 1
	clear_motor_position_counter(2);
	mtp(2,100,100/*This is the #of ticks the wall servo will go, i don't know this number will need to calculate*/);
	enable_servos();
	set_servo_position(0, 0);
	create_stop();
	sleep(5);	//the time needed to get all the polyps out.
	mav(0,0); //this stops the sweeper
	set_servo_position(0,2048);
	sleep(2);
	

	
	return 0;
}
 

void turn_left(float seconds) 
{
	create_drive_direct(300, -300);//turning
	sleep(seconds);//waiting for turn to finish
	create_stop();//turn done
}


void turn_right(float seconds) 
{
	create_drive_direct(-300, 300);//turning
	sleep(seconds);//waiting for turn to finish
	create_stop();//turn done
}


