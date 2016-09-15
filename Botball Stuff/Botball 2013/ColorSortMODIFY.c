int main()
{
    camera_open(LOW_RES);
	int count = 0;
    while(1){
        
        camera_update();
        int orange = 0;
        int green = 1;
        if(get_object_count(orange) >0){ //motor one is the turnstile
            motor(0,0);
			motor(1,400);
			msleep(200);
			motor(1,0);
			//clear_motor_position_counter(1); //set counter to zero
            //mrp(1,  50, 1100); //turn to push the puff into the box
            //msleep(1000);
			//motor(0, 200); //motor zero is the convery belt
			printf("I see orange\n");
        }
        else if(get_object_count(green) >0){
            motor(0,0);
            clear_motor_position_counter(1); // set counter back to zero
            //mrp(1,  -50, 1000); //turn to  push the puff into the box
            //msleep(1000);
			motor(1,-400);
			msleep(200);
			motor(1,0);
			//motor(0, 200); //motor zero is the convery belt
			printf("I see green\n");
        }
		else{
			motor(0,200);
			msleep(200);
		}	
		msleep(10);
		count++;
		printf("Loop finished. count %d\n", count);
       
    }
    return 0;
}
