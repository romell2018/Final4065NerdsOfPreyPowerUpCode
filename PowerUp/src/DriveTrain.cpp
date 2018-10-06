/*
 * DriveTrain.cpp
 *
 *  Created on: Sep 16, 2018
 *      Author: romellmertis
 */

#include <DriveTrain.h>
#include <ctre/Phoenix.h>
#include <cmath>
DriveTrain::DriveTrain() {
	list = new struct driveList;

	list->FL = new WPI_TalonSRX(26);
	list->BL = new WPI_TalonSRX(25);
	list->FR = new WPI_TalonSRX(27);
	list->BR = new WPI_TalonSRX(28);
	list->maxOutput = 1.0;

}

double DriveTrain::getMaxOutput() {
	return list->maxOutput;
}
/**
 * Single stick driving. This is done by using one axis for forwards/backwards,
 * and another for turning right/left. This method allows direct input from any joystick
 * value. This assumes that the control mode for the back has been properly setClawState.
 *
 *  moveVal      Value for forwards/backwards
 * rotateVal    Value for rotation right/left
 *  squareInputs If set, decreases sensitivity at lower speeds
 */

void DriveTrain::ArcadeDrive(double moveVal, double rotateVal,

bool squareInputs) {
	double leftPercent, rightPercent;

	// Clamp moveVal and rotateVal.
	// Assume a deadzone is already being applied to these values.
	moveVal = math.clamp(moveVal, -1.0, 1.0);
	rotateVal = math.clamp(rotateVal, -0.5, 0.5);

	// Square inputs, but maintain their signs.
	// This allows for more precise control at lower speeds,
	// but permits full power.`
	if (squareInputs) {
		moveVal = copysign(moveVal * moveVal, moveVal);
		rotateVal = copysign(rotateVal * rotateVal, rotateVal);
	}

	// Set left and right motor speeds.
	if (moveVal > 0) {
		if (rotateVal > 0) {
			rightPercent = moveVal - rotateVal;
			leftPercent = std::max(moveVal, rotateVal);
		} else {
			rightPercent = std::max(moveVal, -rotateVal);
			leftPercent = moveVal + rotateVal;
		}
	} else {
		if (rotateVal > 0) {
			rightPercent = -std::max(-moveVal, rotateVal);
			leftPercent = moveVal + rotateVal;
		} else {
			rightPercent = moveVal - rotateVal;
			leftPercent = -std::max(-moveVal, -rotateVal);
		}
	}

	// Clamp motor percents
	leftPercent = math.clamp(leftPercent, -1.0, 1.0);
	rightPercent = math.clamp(rightPercent, -1.0, 1.0);

	// Apply speeds to motors.
	list->FL->Set(leftPercent * list->maxOutput);
	list->FR->Set(-rightPercent * list->maxOutput);
	list->BL->Set(leftPercent * list->maxOutput);
	list->BR->Set(-rightPercent * list->maxOutput);
}

void DriveTrain::TankDrive(double leftStickValue, double rightStickValue) {
	if (fabs(leftStickValue) > 0.1 || fabs(rightStickValue) > 0.1) {

		list->FL->Set(leftStickValue);
		list->FR->Set(rightStickValue);
		list->BL->Set(-leftStickValue);
		list->BR->Set(-rightStickValue);
	} else {
		list->FL->Set(0);
		list->FR->Set(0);
		list->BL->Set(0);
		list->BR->Set(0);
	}
}

void DriveTrain::FlipDrive(double leftStickValue, double rightStickValue) {
	if (fabs(leftStickValue) > 0.1 || fabs(rightStickValue) > 0.1) {
		list->FL->Set(leftStickValue);
		list->FR->Set(rightStickValue);
		list->BL->Set(leftStickValue);
		list->BR->Set(rightStickValue);
	} else {
		list->FL->Set(0);
		list->FR->Set(0);
		list->BL->Set(0);
		list->BR->Set(0);
	}
}

