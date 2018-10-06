/*
 * AutoDrive.h
 *
 *  Created on: Sep 23, 2018
 *      Author: romellmertis
 */

#ifndef SRC_AUTODRIVE_H_
#define SRC_AUTODRIVE_H_
#include"WPILib.h"
#include"ctre/Phoenix.h"

class AutoDrive {
public:
	AutoDrive();

	void AutoStop();
	void AutoForward(double speed);
	void AutoTurn(double speed);
	void AutoLeftDrive(double speed);
	void AutoRightDrive(double speed);
	void AutoLeftStop();
	void AutoRightStop();

	struct autoList {
		WPI_TalonSRX *FL;
		WPI_TalonSRX *BL;
		WPI_TalonSRX *FR;
		WPI_TalonSRX *BR;
		double maxOutput;

	};
	struct autoList* list;
};

#endif /* SRC_AUTODRIVE_H_ */
