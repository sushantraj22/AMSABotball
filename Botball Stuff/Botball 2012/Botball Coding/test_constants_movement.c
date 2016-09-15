// Created on Tue Mar 20 2012

#define TPIL 188
#define TPIR 180

int main() 
{
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	
	
	//mrp(0,500,12*960);
	//mrp(3,490,12*-960); 
	//bmd(3);
	
	
	mrp(0,500,62 * TPIL);
	mrp(3,490,62 * TPIR); 
	
	mrp(0,500,-19 * TPIL);
	mrp(3,490,-519 * TPIR); 
	bmd(0);
	
	bmd(3);
	
	exit(0);
	
	
}
