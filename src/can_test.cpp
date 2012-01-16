#include <iostream>
#include <unistd.h>
#include "ros/ros.h"
#include <cob_canopen_motor/CanDriveHarmonica.h>
#include <cob_base_drive_chain/CanCtrlPltfCOb3.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "can_test");
	ros::NodeHandle n;
	//sleep(10);
	//can_ctrl ctrlCob("IniFiles/");
	CanCtrlPltfCOb3 ctrlCob("IniFiles/");
	
	ctrlCob.initPltf();
	std::cout << "Done with initPltf()" << std::endl;	
		
	//ctrlCob.setVelGearRadS(CANNODE_WHEEL1STEERMOTOR, 0.5);

	//ctrlCob.requestDriveStatus();
	//std::cout << "Now sleeping..." << std::endl;
	//sleep(10);

	ctrlCob.shutdownPltf();	
	std::cout<< "Plattform shut down." << std::endl;


	return 0;
}
