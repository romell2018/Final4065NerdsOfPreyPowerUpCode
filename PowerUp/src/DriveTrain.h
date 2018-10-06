/*
 * DriveTrain.h
 *
 *  Created on: Sep 16, 2018
 *      Author: romellmertis
 */

#ifndef SRC_DRIVETRAIN_H_
#define SRC_DRIVETRAIN_H_
#include"WPILib.h"
#include"ctre/Phoenix.h"
#include <ExtraMath.h>

class DriveTrain {
public:

	DriveTrain();
	void setMaxOutput(double max);
	double getMaxOutput();
	void ArcadeDrive(double moveVal, double rotateVal, bool squareInputs);
	void TankDrive(double leftStickValue, double rightStickValue);
	void FlipDrive(double leftStickValue, double rightStickValue);

	ExtraMath math;

	struct driveList {
		WPI_TalonSRX *FL;
		WPI_TalonSRX *BL;
		WPI_TalonSRX *FR;
		WPI_TalonSRX *BR;
		double maxOutput;

	};
	struct driveList* list;
};

#endif /* SRC_DRIVETRAIN_H_ */
