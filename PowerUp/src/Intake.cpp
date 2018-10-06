/*
 * Intake.cpp
 *
 *  Created on: Sep 16, 2018
 *      Author: romellmertis
 */

#include <Intake.h>
#include "WPILib.h"
#include <ctre/Phoenix.h>

Intake::Intake() {

	intR = new WPI_TalonSRX(29);
	intL = new WPI_TalonSRX(30);

}
void Intake::intakeToggleOn() {

	intL->Set(-0.15); // toggle on
	intR->Set(0.15);
}

void Intake::intakeToggleOff() {
	intL->Set(0); // toggle off
	intR->Set(0);
}

void Intake::intakeIn() {

	intL->Set(0.9); // suck cube
	intR->Set(-0.9);
}

void Intake::intakeOut() {
	intL->Set(-0.9); // spit cube
	intR->Set(0.9);

}

void Intake::intakeStop() {
	intL->Set(0);
	intR->Set(0);
}
