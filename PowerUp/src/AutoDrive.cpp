/*
 * AutoDrive.cpp
 *
 *  Created on: Sep 23, 2018
 *      Author: romellmertis
 */

#include <AutoDrive.h>

AutoDrive::AutoDrive() {
	list = new struct autoList;

	list->FL = new WPI_TalonSRX(26);
	list->BL = new WPI_TalonSRX(25);
	list->FR = new WPI_TalonSRX(27);
	list->BR = new WPI_TalonSRX(28);

}
void AutoDrive::AutoStop() {
	list->FL->Set(0);
	list->BL->Set(0);
	list->FR->Set(0);
	list->BR->Set(0);

}
void AutoDrive::AutoLeftDrive(double speed) {
	list->FL->Set(speed); // move forward
	list->BL->Set(speed); // move forward
}
void AutoDrive::AutoRightDrive(double speed) {
	list->FR->Set(-1 * speed); // move forward
	list->BR->Set(-1 * speed); // move forward
}
void AutoDrive::AutoLeftStop() {
	list->FL->Set(0); // move forward
	list->BL->Set(0); // move forward
}
void AutoDrive::AutoRightStop() {
	list->FR->Set(0); // move forward
	list->BR->Set(0); // move forward
}

void AutoDrive::AutoForward(double speed) {
	list->FL->Set(speed); // move forward
	list->BL->Set(speed); // move forward
	list->FR->Set(-1 * speed); // move forward
	list->BR->Set(-1 * speed); // move forward

}
