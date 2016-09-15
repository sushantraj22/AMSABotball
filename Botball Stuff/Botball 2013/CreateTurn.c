// Created on Fri April 5 2013

int main()
{
	create_connect();
	set_create_total_angle(0);
	get_create_total_angle(0);
	create_drive_direct(-100,100);
	msleep(2100);
	int angle = get_create_total_angle();
	printf("create angle %i\n", angle);
	/*if(angle>90){
			create_drive_direct(-100,100);
			msleep(1000);
	}
	*/
	if (angle<=91 || angle>=89){
		create_drive_direct(100,100);
		msleep(1000);
	}
	else{
		printf("create angle %i", get_create_total_angle());
	}
	
	create_disconnect();
	return 0;
}
