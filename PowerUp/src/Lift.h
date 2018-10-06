/*
 * Lift.h
 *
 *  Created on: Sep 16, 2018
 *      Author: romellmertis
 */

#ifndef SRC_LIFT_H_
#define SRC_LIFT_H_
#include <ctre/Phoenix.h>
#include "WPILib.h"

class Lift {
public:
	Lift();
	void Move(double speed);
	void Top(double speed);
	void Bottom(double speed);
	void Stop(double speed);
private:
	struct liftList {

		WPI_TalonSRX *liftMotor;
		DigitalInput *toplimit;
		DigitalInput *bottomlimit;

	};
	struct liftList* list;
};

#endif /* SRC_LIFT_H_ */
