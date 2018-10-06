/*
 * Autonomous.cpp
 *
 *  Created on: Sep 20, 2018
 *      Author: romellmertis
 */

#include <Autonomous.h>

Autonomous::Autonomous() {
	autolist = new struct AutoList;

	autolist->NavX = new AHRS(SerialPort::Port::kMXP);

	autolist->distanceSensor = new AnalogInput(0);

	autolist->leftDistCheck = false;
	autolist->rightDistCheck = false;

	autolist->autoStage = 0;

	autolist->NavX->Reset();

	autodrive.list->FL->SetSelectedSensorPosition(0, 0, 10);
	autodrive.list->FR->SetSelectedSensorPosition(0, 0, 10);

	autodrive.list->FL->GetSelectedSensorPosition(0);
	autodrive.list->FR->GetSelectedSensorPosition(0);

}
void Autonomous::LeftPostionLeftSwitch() {

	std::cout << "NavX Angle: " << autolist->NavX->GetAngle() << std::endl;
	std::cout << "DistanceSensor: " << autolist->distanceSensor->GetValue()
			<< std::endl;
	std::cout << "Encoder Left:"
			<< autodrive.list->FL->GetSelectedSensorPosition()
			<< " Encoder Right: "
			<< autodrive.list->FR->GetSelectedSensorPosition() << std::endl;

	if (autolist->autoStage == 0) {
		if (autodrive.list->FR->GetSelectedSensorPosition(0) <= 40000) {
			autodrive.AutoForward(0.2); //move forward
		} else {
			autodrive.AutoStop(); //stop
			autolist->autoStage = 1;
		}

	}
	if (autolist->autoStage == 1) {
		if (autolist->NavX->GetAngle() < 90) {
			autodrive.AutoLeftDrive(0.2); //turn right
			autodrive.AutoRightDrive(-0.2);
		} else {
			autodrive.AutoStop(); //stop
			autolist->NavX->Reset();

			autodrive.list->FR->SetSelectedSensorPosition(0, 0, 10);
			autolist->autoStage = 2;
		}
	}
	if (autolist->autoStage == 2) {
		autodrive.AutoForward(0.2);
		if (autolist->distanceSensor->GetValue() <= 400) {
			autodrive.AutoRightStop();
			autodrive.AutoLeftStop();
			autolist->autoStage = 3;
		}

	}
	if (autolist->autoStage == 3) {
		lift.Top(-0.8);
	}
}

void Autonomous::LeftPostionRightSwitch() {
	std::cout << "DistanceSensor: " << autolist->distanceSensor->GetValue()
			<< std::endl;
	std::cout << "Encoder Left:"
			<< autodrive.list->FL->GetSelectedSensorPosition()
			<< " Encoder Right: "
			<< autodrive.list->FR->GetSelectedSensorPosition() << std::endl;

	if (autolist->autoStage == 0) {
		if (autodrive.list->FR->GetSelectedSensorPosition(0) <= 40000) {
			autodrive.AutoForward(0.2); //move forward
		} else {
			autodrive.AutoStop(); //stop
			autolist->autoStage = 1;
		}
	}
}

void Autonomous::MiddlePostionLeftSwitch() {
}

void Autonomous::MiddlePostionRightSwitch() {
}

void Autonomous::RightPostionLeftSwitch() {
	std::cout << "DistanceSensor: " << autolist->distanceSensor->GetValue()
			<< std::endl;
	std::cout << "Encoder Left:"
			<< autodrive.list->FL->GetSelectedSensorPosition()
			<< " Encoder Right: "
			<< autodrive.list->FR->GetSelectedSensorPosition() << std::endl;

	if (autolist->autoStage == 0) {
		if (autodrive.list->FR->GetSelectedSensorPosition(0) <= 40000) {
			autodrive.AutoForward(0.2); //move forward
		} else {
			autodrive.AutoStop(); //stop
			autolist->autoStage = 1;
		}
	}
}

void Autonomous::RightPostionRightSwitch() {
	std::cout << "NavX Angle: " << autolist->NavX->GetAngle() << std::endl;
	std::cout << "DistanceSensor: " << autolist->distanceSensor->GetValue()
			<< std::endl;
	std::cout << "Encoder Left:"
			<< autodrive.list->FL->GetSelectedSensorPosition()
			<< " Encoder Right: "
			<< autodrive.list->FR->GetSelectedSensorPosition() << std::endl;

	if (autolist->autoStage == 0) {
		if (autodrive.list->FR->GetSelectedSensorPosition(0) <= 40000) {
			autodrive.AutoForward(0.2); //move forward
		} else {
			autodrive.AutoStop(); //stop
			autolist->autoStage = 1;
		}

	}
	if (autolist->autoStage == 1) {
		if (autolist->NavX->GetAngle() > -90) {
			autodrive.AutoLeftDrive(-0.2); //turn right
			autodrive.AutoRightDrive(0.2);
		} else {
			autodrive.AutoStop(); //stop
			autolist->NavX->Reset();

			autodrive.list->FR->SetSelectedSensorPosition(0, 0, 10);
			autolist->autoStage = 2;
		}
	}
	if (autolist->autoStage == 2) {
		autodrive.AutoForward(0.2);
		if (autolist->distanceSensor->GetValue() <= 400) {
			autodrive.AutoRightStop();
			autodrive.AutoLeftStop();
			autolist->autoStage = 3;
		}

	}
	if (autolist->autoStage == 3) {
		lift.Top(-0.8);
	}
}

void Autonomous::DefaultDriveScore() {
	std::cout << "NavX Angle: " << autolist->NavX->GetAngle() << std::endl;
	std::cout << "DistanceSensor: " << autolist->distanceSensor->GetValue()
			<< std::endl;
	std::cout << "Encoder Left:"
			<< autodrive.list->FL->GetSelectedSensorPosition()
			<< " Encoder Right: "
			<< autodrive.list->FR->GetSelectedSensorPosition() << std::endl;
	if (autolist->autoStage == 0) {
		autodrive.AutoForward(0.2);
		if (autolist->distanceSensor->GetValue() <= 400) {
			autodrive.AutoRightStop();
			autodrive.AutoLeftStop();
			autolist->autoStage = 1;
		}

	}
	if (autolist->autoStage == 1) {
		lift.Top(-0.8);
	}
}

void Autonomous::DefaultDriveDontScore() {
	std::cout << "DistanceSensor: " << autolist->distanceSensor->GetValue()
			<< std::endl;
	std::cout << "Encoder Left:"
			<< autodrive.list->FL->GetSelectedSensorPosition()
			<< " Encoder Right: "
			<< autodrive.list->FR->GetSelectedSensorPosition() << std::endl;

	if (autolist->autoStage == 0) {
		if (autodrive.list->FR->GetSelectedSensorPosition(0) <= 40000) {
			autodrive.AutoForward(0.2); //move forward
		} else {
			autodrive.AutoStop(); //stop
			autolist->autoStage = 1;
		}
	}
}
