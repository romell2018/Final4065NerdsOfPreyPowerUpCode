/*
 * Autonomous.h
 *
 *  Created on: Sep 20, 2018
 *      Author: romellmertis
 */

#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_

#include <iostream>

#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <AutoDrive.h>
#include <Lift.h>
#include <Intake.h>
#include <AHRS.h>

class Autonomous {
public:
	Autonomous();

	void LeftPostionLeftSwitch();
	void LeftPostionRightSwitch();

	void MiddlePostionRightSwitch();
	void MiddlePostionLeftSwitch();

	void RightPostionLeftSwitch();
	void RightPostionRightSwitch();


	void LeftPostionDefaultRightSwitch();
	void LeftPostionDefaultLeftSwitch();
	void RightPostionDefaultLeftSwitch();
	void RightPostionDefaultRightSwitch();

	void DefaultDriveScore();
	void DefaultDriveDontScore();

	AutoDrive autodrive; //drive class
	Lift lift; //lift class
	Intake intake; //intake class

	struct AutoList {

		AnalogInput *distanceSensor;
		AHRS *NavX;

		bool leftDistCheck;
		bool rightDistCheck;
		int autoStage;


	};
	struct AutoList* autolist;

};

#endif /* SRC_AUTONOMOUS_H_ */
