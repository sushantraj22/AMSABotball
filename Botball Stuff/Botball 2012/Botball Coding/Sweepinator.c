#include <stdio.h>

/* note: in create_drive_direct(100, -100); is left and (-100,100) is right */
int main() 
{
	printf("Hello, World!\n");
	//wait_for_light(0); //Don't have to make it a while, because it has to first go through this step before continuing
	printf("I've seen the light! Let the game begin\n");
	shut_down_in(119.0);

	while(create_connect());
	
	//create_full();
	set_create_distance(0);
	set_create_normalized_angle(0);
	
	//move forward to point A
	printf("move forward to point A\n");
	while(get_create_distance(.05) > -1562.1){
		create_drive_straight(-250);}
	//turn left 90 degree to face point B
	printf("turn left 90 degree to face point B\n");
	while(get_create_normalized_angle(.05)<=77){
		create_drive_direct(100,-100);}
		
	set_create_distance(0);
	set_create_normalized_angle(0);	
	//move forward to point B
	printf("move forward to point B\n");
	while(get_create_distance(.05) > -300){
		create_drive_straight(-250);}
	//turn right 90 degree to face point C
	printf("turn right 90 degree to face point C\n");
	while(get_create_normalized_angle(.05)<=77){
		create_drive_direct(100,-100);}
	
	set_create_distance(0);
	set_create_normalized_angle(0);	
	//move forward to point C
	printf("move forward to point C\n");	
	while(get_create_distance(.05) > -508){
		create_drive_straight(-250);}
	
	//turn left 90 degree to face D
	printf(" left 90 degree to face D\n");
	while(get_create_normalized_angle(.05)<=77){
		create_drive_direct(-100,100);}

	set_create_distance(0);
	set_create_normalized_angle(0);	
	//move forward to point D
	while(get_create_distance(.05) > -152.4){
		create_drive_straight(-250);}
	//turn left 90 degree to face point E
	while(get_create_normalized_angle(.05)<=77){
		create_drive_direct(100,-100);}	
	
	set_create_distance(0);
	set_create_normalized_angle(0);	
	//move forward to point E
	while(get_create_distance(.05) > -406.4){
		create_drive_straight(-250);}
	//turn right 90 degree to face point F
	while(get_create_normalized_angle(.05)<=77){
		create_drive_direct(-100,100);}
		
	//turn on sweeper
		mav(0, 1000);
		
	set_create_distance(0);
	//move forward to point F
	while(get_create_distance(.05) > -76.2){
		create_drive_straight(-100);}
	//pause to sweep polyps	
	create_stop();
	sleep(3);
		
	set_create_distance(0);
	//back out of point F to point E	
	while(get_create_distance(.05) > 76.2){
		create_drive_straight(100);}
		
	set_create_normalized_angle(0);	
	//turn left 90 degree to face point G
	while(get_create_normalized_angle(.05)<=77){
		create_drive_direct(100,-100);}	
		
	set_create_distance(0);
	set_create_normalized_angle(0);	
	//move forward to point G
	while(get_create_distance(.05) > -609.6){
		create_drive_straight(-250);}
	//turn left 90 degree to face point H
	while(get_create_normalized_angle(.05)<=77){
		create_drive_direct(100,-100);}
		
	set_create_distance(0);
	set_create_normalized_angle(0);	
	//move forward to point H
	while(get_create_distance(.05) > -304.8){
		create_drive_straight(-250);}
	//turn left 90 degree to face point C
	while(get_create_normalized_angle(.05)<=77){
		create_drive_direct(100,-100);}
	
	set_create_distance(0);
	set_create_normalized_angle(0);	
	//move forward to point I
	while(get_create_distance(.05) > -1397){
		create_drive_straight(-100);}
	//turn right 90 degree to face point J
	while(get_create_normalized_angle(.05)<=77){
		create_drive_direct(-100,100);}	
		
	set_create_distance(0);
	set_create_normalized_angle(0);	
	//move forward to point J
	while(get_create_distance(.05) > -304.8){
		create_drive_straight(-200);}
	//turn left 90 degree to face point K
	while(get_create_normalized_angle(.05)<=77){
		create_drive_direct(100,-100);}
		
	//Using the servo to push the polyps out
	clear_motor_position_counter(2);
	mtp(2,100,1024);
	*/
		
	return 0;
		
	}
	
