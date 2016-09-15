// Created on Sat Mar 24 2012

int main() 
{
	//block height=1
	//color=blue;
	//go to the central point
	if //colorseen(?)=color
		(track_update();
		//track_x(color,);
		mrp (0,250, 1000);
		mrp (3,250, 1000);
		sleep(4);
		set_servo_position(0,2000);
		sleep(2));
	else
		//turn right 45 deg
		mav(0, 250);
		mav(3, -250);
		sleep(0.5);
		if //colorseen(?)=color
			mrp (0,250, 1414);
			mrp (3,250, 1414);
			sleep(4);
			set_servo_position(0,2000);
			sleep(2);
		else
			//turn right 45 deg
			mav(0, 250);
			mav(3, -250);
			mrp (0,250, 1000);
			mrp (3,250, 1000);
			sleep(4);
			set_servo_position(0,2000);
			sleep(2);
	//return to central point
	//put block in mpa at block height
	//add 1 to block height
	//color=yellow
	//return to central point
	//repeat for yellow block
	//color=red
	//repeat for red block
	//go to point between blocks 1 and 2
}
