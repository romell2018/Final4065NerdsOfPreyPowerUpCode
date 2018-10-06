/*
 * Lift.cpp
 *
 *  Created on: Sep 16, 2018
 *      Author: romellmertis
 */

#include <Lift.h>
#include"WPILib.h"
#include <ctre/Phoenix.h>

Lift::Lift() {
	list = new struct liftList;
	list->liftMotor = new WPI_TalonSRX(24);

	list->toplimit = new DigitalInput(0);
	list->bottomlimit = new DigitalInput(1);

}
void Lift::Top(double speed) {
	list->liftMotor->Set(speed); // move up
	if (list->toplimit->Get() == true) {
		list->liftMotor->Set(0);
	}
}
void Lift::Bottom(double speed) {
	list->liftMotor->Set(speed); // move down
	if (list->bottomlimit->Get() == true) {
		list->liftMotor->Set(0);
	}
}
void Lift::Move(double speed) {
	list->liftMotor->Set(speed); // move up

}
void Lift::Stop(double speed) {
	list->liftMotor->Set(0);
}
