//code from spot
//these are defining color returns and color order
#define BLUE 3
#define YELLOW 1
#define RED 0
#define GREEN 2
#define BLUE_ORD 0
#define YELLOW_ORD 1
#define RED_ORD 2
#define GREEN_ORD 3





#ifdef SIM
/*defines for constants for use in simulator */

#define TICKS_PER_INCHES_LEFT 120
#define TICKS_PER_INCHES_RIGHT 120
#define SPEED_LEFT 900
#define SPEED_RIGHT 900
#define TURN_LEFT 500 //not to be confused with the function turn_left/turn_right,(called later) TURN_LEFT/TURN_RIGHT are defined constants for speed
#define TURN_RIGHT 500
#define ONE_DEGREE 7.0
#define DA 42.0
#define DB 64.0
#define DC 37.0
#define DD 22.0
#define DE 33.0
#define DF 13.0
#define DG 28.0
#define ROBOT_LENGTH 11.0

#else
/*defines for constants for actual game */


/* wheels not perfectly straight, adjust ticks to stop bot from turning */
#define TICKS_PER_INCHES_LEFT 159
#define TICKS_PER_INCHES_RIGHT 155

/* speed for wheels when going straight */
#define SPEED_LEFT 500
#define SPEED_RIGHT 491

/* speed for wheels when turning */
#define TURN_LEFT 400
#define TURN_RIGHT 400

// number of ticks for a wheel to turn 90 degrees
#define ONE_DEGREE (757.0/90)

/* distances from board */
#define DA 48.0
#define DB 59.0
#define DC 33.8
#define DD 25.0
#define DE 22.0
#define DF 10.0
#define DG 26.0
#define ROBOT_LENGTH 11.0
#endif


/* claw lift positions for the lift() function  
lift_pos[0] : lowest position claw can go, for picking up block
lift_pos[1] : lift block or carrying *make sure it is high enough to go over pipe around MPA 
lift_pos[2] : position for stacking second block
lift_pos[3] : position for stacking third block
*/
int lift_pos[]= {0,1000,1700,2700};


#define claw_servo_close 350 //claw servo closed
#define claw_servo_open 2000 //claw servo open, can not be greater than 2048!!!!


void open_claw() //function to open claw, servo in servo port 0
{ 
 set_servo_position(0, claw_servo_open);//servo is to open
 sleep(1);//waiting for servo to close
}
void lift(int l)//function to lift arm, motor in port 1
{
 
 mtp(1,500,lift_pos[l]);
 bmd(1); //block motor untill done
}

void close_claw()//function to close claw, servo in servo port 0
{
 set_servo_position(0, claw_servo_close); //servo is now closed
 sleep(2);//wait for servo to close, adjust as needed
}

int fwd(float distance)
{
   long distance_right, distance_left;

/* get the number of ticks for each wheel, which have to be different to stop the bot from turning */
   distance_right = distance * TICKS_PER_INCHES_RIGHT;
   distance_left = distance * TICKS_PER_INCHES_LEFT;
   mrp(0,SPEED_LEFT,distance_left);
   mrp(3,SPEED_RIGHT,distance_right);
/* motor three is the slower motor so we stop when it stops */
   bmd(3);
   return 1;
}

int reverse(float distance)
{
   long distance_right, distance_left;
/* get the number of ticks for each wheel, which have to be different to stop the bot from turning */
   distance_right = distance * TICKS_PER_INCHES_RIGHT;
   distance_left = distance * TICKS_PER_INCHES_RIGHT;
   mrp(0,SPEED_LEFT,-distance_left);
   mrp(3,SPEED_RIGHT,-distance_right);
/* motor three is the slower motor so we stop when it stops */
   bmd(3);
   return 1;
}


int turn_right(int deg)
{
   long turn = (ONE_DEGREE *deg);

   mrp(0,TURN_LEFT,turn); //not to be confused with the function turn_left/turn_right, TURN_LEFT/TURN_RIGHT are defined constants for speed
   mrp(3,TURN_RIGHT,-turn);
   bmd(3);
   return 1;
}

int turn_left(int deg)
{
   long turn = (ONE_DEGREE *deg);

   mrp(0,TURN_LEFT,-turn);//not to be confused with the function turn_left/turn_right, TURN_LEFT/TURN_RIGHT are defined constants for speed
   mrp(3,TURN_RIGHT,turn);
   bmd(3);
   return 1;
}


// keep track of which block position to go to in the right order..... not really used since the camera code isn't finished 
int positions[]={0,0,0,0};
int color_map[4];
//assume that we are facing location L. Assume that c is value returned from color sensor. 
//positions[color_map[c]]=L
//I am assuming we are facing position 0

int move_to_center()
{
 fwd(DA);
 turn_left(90);
 fwd(DF);
 // scan
 
}
int get_block_a()
{
 open_claw();
 fwd(DC-DF-ROBOT_LENGTH+.5);
 close_claw();
 reverse(1);
 lift(1);
 reverse(DC-ROBOT_LENGTH-.5);
 turn_right(90);
}
int get_block_b()
{
 turn_right(45);
 fwd(11);
 turn_right(45);
 fwd(12.5);
 turn_left(45);
 fwd(5);
 turn_left(45);
 fwd(3);
 close_claw();
 lift(1);
 reverse(3);
 turn_right(45);
 reverse(5);
 turn_right(45);
 reverse(12.5);
 turn_left(45);
 reverse(11);
 turn_right(45);
 
}

 
int get_block_c()
{
 turn_left(90);
 fwd(DF);
 turn_right(90);
 open_claw();
 fwd(DD-ROBOT_LENGTH);
 close_claw();
 lift(1);
 reverse(DD-ROBOT_LENGTH);
 turn_left(90);
 reverse(DF);
 turn_right(90);
}
int drop_block(int L)
{
// will be called with L = 0,1,2 but lift(0) is at the bottom, so add one to L before calling lift
 lift(L+1);
 fwd(DD-ROBOT_LENGTH-1);
 open_claw();
 reverse(DD-ROBOT_LENGTH-1);
 lift(0);
 
 /*ends facing block c*/
}
int do_block(int block)
{
 switch(block){
 case 0: //case 1 with block you want in pos a
 get_block_a();
 break; // to keep from continuing with the code
 case 1: //case 2 with block you want in pos b
 get_block_b();
 break;
 case 2: //case 3 with block you want in pos c
 get_block_c();
 break;
 default: //kinda like an else statement...but not really...
 printf("invalid block number %d\n",block);//error in case of wrong number
 break;
 }
 
 return(1);
}
int main()
{
 int i; 
 //dont have camera code so im putting in temporary positions
 positions[0]=0; //blue block in position c
 positions[1]=1; //yellow block in position a
 positions[2]=2; //red block in position b
 color_map[BLUE]=BLUE_ORD;
 color_map[YELLOW]=YELLOW_ORD;
 color_map[RED]=RED_ORD;
 color_map[GREEN]=GREEN_ORD;
	wait_for_light(0); // light sensor in analog port 0
	shut_down_in(120.0);
	while (black_button()==0)
	{
		// clear motor position for the claw lift, always remember to make sure the claw is at the bottom before the run since it doesn't go automatically 
		clear_motor_position_counter(1);
                  
		// get clear of the pipe at the start
		fwd(2);
		// turn to face the MPA
		turn_left(90);
		sleep(1);
		// now open the claw once we are clear of the create 
		//open_claw();
 

		move_to_center();
		//just do blocks A and C
		do_block(positions[0]);
		drop_block(0);
		
		// since we skipped block B, only raise block B to the 2nd block stack position not to the top of the stack
		
		exit(1);

		/* code to do all three blocks 
		for(i=0; i<3; i++){ //loop thru, starting with 0, up until 2, adding one every time
		do_block(positions[i]);
		drop_block(i);
		*/
		}

 
 
		}
	

   exit(1);

	}
