#include <iostream>
#include <unistd.h>
#include "ros/ros.h"
#include <cob_canopen_motor/CanDriveHarmonica.h>
#include <cob_base_drive_chain/CanCtrlPltfCOb3.h>

// void rotate_rel(CanCtrlPltfCOb3 &ctrlCob, double deg, double speed)
// {
// 	bool positive = (speed >= 0);
// 	double angleRadStart = 0;
// 	double velRadS = 0;
//  	ctrlCob.requestDriveStatus // TODO request some how
	

// 	ctrlCob.getGearPosVelRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, &angleRadStart, &velRadS);
// 	std::cout << "start angle = " << angleRadStart << std::endl;

// 	double curAngle = angleRadStart;
// 	while (positive && (curAngle < (deg + angleRadStart)) || !positive && (curAngle > (deg + angleRadStart))) {
// 		std::cout << "angle = " << curAngle << std::endl;
// 		ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, speed);
// 		ctrlCob.getGe
// 		usleep(10000);
// 	}
// 	ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, 0);
// }

int main(int argc, char **argv)
{
	ros::init(argc, argv, "can_test");
	ros::NodeHandle n;
	CanCtrlPltfCOb3 ctrlCob("IniFiles/");
	
	ctrlCob.initPltf();
	std::cout << "Done with initPltf()" << std::endl;	

	std::cout << "Now running own commands;" << std::endl;	


	//ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1DRIVEMOTOR, -2);
	//ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, -0.5);
	// for (int i = 0; i < 20; ++i) {
	// 	usleep(500000);
	// 	ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1DRIVEMOTOR, -2);
	// }
	// for (int i = 0; i < 20; ++i) {
	// 	usleep(500000);
	// 	ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, -2);
	// }

	//ctrlCob.requestDriveStatus();

	// Spin 360 deg.
	/* ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, 3.141592); */
	/* usleep(2000000); */
	/* ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, 0); */

	// std::cout << "rotating +0.25" << std::cout; 
	// rotate_rel(ctrlCob, .25, 0.5);

	//std::cout << "rotating -0.25" << std::cout; 
	//rotate_rel(.25, 0.5);
	
	ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, -0.7);
	usleep(800000);
	ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, 0);
	
	for (int i = 0; i < 30; ++i) {
	  ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1DRIVEMOTOR, 2);
	  usleep(800000);
	}
	ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1DRIVEMOTOR, 0);

	ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, 0.7);
	usleep(800000);
	ctrlCob.setVelGearRadS(CanCtrlPltfCOb3::CANNODE_WHEEL1STEERMOTOR, 0);




	std::cout<< "Plattform is shuting down." << std::endl;
	ctrlCob.shutdownPltf();	


	return 0;
}
