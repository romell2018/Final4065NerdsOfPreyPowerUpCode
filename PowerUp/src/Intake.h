/*
 * Intake.h
 *
 *  Created on: Sep 16, 2018
 *      Author: romellmertis
 */

#ifndef SRC_INTAKE_H_
#define SRC_INTAKE_H_
#include "WPILib.h"
#include <ctre/Phoenix.h>

class Intake {
public:
	Intake();
	void intakeToggleOn();
	void intakeToggleOff();
	void intakeIn();
	void intakeOut();
	void intakeStop();

private:
	WPI_TalonSRX *intL;
	WPI_TalonSRX *intR;
};

#endif /* SRC_INTAKE_H_ */
