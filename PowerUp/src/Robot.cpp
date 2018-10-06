/*
 *
 *
 * 	Romell Controls:
 *
 * 	Joystick LeftAxisY controls left motors
 *
 *	Joystick RightAxisY controls right motors
 *
 *	Button A - flip axis sides, invert drive
 *
 *
 * 	Zack Controls:
 *
 * 	Button Y - LiftUp
 *
 *	Button A - LiftDown
 *
 *	Button B -IntakeToggle
 *
 * 	Left Bumper -  IntakeIn
 *
 * 	Right Bumper - IntakeOut
 *
 */

#include "Robot.h"
#include <iostream>


void Robot::RobotInit() {
	m_chooser.AddDefault(kAutoDefault, kAutoDefault);
	m_chooser.AddObject(kAutoLeft, kAutoLeft);
	m_chooser.AddObject(kAutoMiddle, kAutoMiddle);
	m_chooser.AddObject(kAutoRight, kAutoRight);
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

	cam1 = CameraServer::GetInstance()->StartAutomaticCapture("Back Cam ", 0);

}

void Robot::AutonomousInit() {

	//m_autoSelected = m_chooser.GetSelected();
	m_autoSelected = kAutoDefault;
	std::cout << "Auto selected: " << m_autoSelected << std::endl;

}

void Robot::AutonomousPeriodic() {
	std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

	if (m_autoSelected == kAutoLeft) {
		if (gameData.length() > 0) {

			if (gameData[0] == 'L') {
				autonomous.LeftPostionLeftSwitch();
			}
		else {
			autonomous.LeftPostionRightSwitch();
		}
		}
	}

	if (m_autoSelected == kAutoMiddle) {
		if (gameData.length() > 0) {

			if (gameData[0] == 'L') {
				autonomous.MiddlePostionLeftSwitch();
			} else {
				autonomous.MiddlePostionRightSwitch();
			}
		}
	}
	if (m_autoSelected == kAutoRight) {
		if (gameData.length() > 0) {

			if (gameData[0] == 'L') {
				autonomous.RightPostionLeftSwitch();
			} else {
				autonomous.RightPostionRightSwitch();
			}
		}
	}
	if (m_autoSelected == kAutoDefault) {
		autonomous.DefaultDriveDontScore();
	}
}

void Robot::TeleopInit() {
}
void Robot::TeleopPeriodic() {
	/*

	 drive.ArcadeDrive(romell->GetRawAxis(1), romell->GetRawAxis(4), true);
	 if (romell->GetRawButton(4)) {
	 lift.Top(-0.9);
	 } else if (romell->GetRawButton(1)) {
	 lift.Move(0.5);
	 } else {
	 lift.Stop(0);
	 }

	 // ToggleButtonForIntake
	 if (romell->GetRawButton(2)) {
	 if (!togglePressed) {
	 toggleOn = !toggleOn;
	 togglePressed = true;
	 }
	 } else {
	 togglePressed = false;
	 }
	 if (toggleOn) {
	 std::cout << "Toggle On " << std::endl;
	 intake.intakeToggleOn();
	 } else {
	 intake.intakeToggleOff();
	 // INTAKE
	 if (romell->GetRawButton(5)) {
	 std::cout << "Intake In" << std::endl;
	 intake.intakeIn();
	 } else if (romell->GetRawButton(6)) {
	 std::cout << "Intake Out" << std::endl;
	 intake.intakeOut();
	 } else {
	 intake.intakeStop();
	 }
	 */
	switch (controllerFlip) {
	case Normal:
		drive.ArcadeDrive(-1 * romell->GetRawAxis(1), romell->GetRawAxis(4),
				true);
		//drive.TankDrive(deadzone(romell->GetRawAxis(1)),deadzone(romell->GetRawAxis(5)));
		break;
	case Flip:
		drive.ArcadeDrive(romell->GetRawAxis(1), romell->GetRawAxis(4), true);
		//drive.FlipDrive(romell->GetRawAxis(5), romell->GetRawAxis(1));
		break;
	}
	if (romell->GetRawButton(1)) {
		if (!flipTogglePressed) {
			flipToggleOn = !flipToggleOn;
			flipTogglePressed = true;
		}
	} else {
		flipTogglePressed = false;
	}
	if (flipToggleOn) {
		// ("Toggle On ");
		controllerFlip = Controller::Flip;
	} else {
		// ("Toggle Off ");
		controllerFlip = Controller::Normal;
	}

	if (zack->GetRawButton(4)) {
		lift.Top(-0.9);
	} else if (zack->GetRawButton(1)) {
		lift.Move(0.5);
	} else {
		lift.Stop(0);
	}
	// ToggleButtonForIntake
	if (zack->GetRawButton(2)) {
		if (!togglePressed) {
			toggleOn = !toggleOn;
			togglePressed = true;
		}
	} else {
		togglePressed = false;
	}
	if (toggleOn) {
		std::cout << "ZACK THE  INTAKE  IS Toggle On " << std::endl;
		intake.intakeToggleOn();
	} else {
		intake.intakeToggleOff();
		// INTAKE
		if (zack->GetRawButton(5)) {
			std::cout << "Intake In" << std::endl;
			intake.intakeIn();
		} else if (zack->GetRawButton(6)) {
			std::cout << "Intake Out" << std::endl;
			intake.intakeOut();
		} else {
			intake.intakeStop();
		}
	}
}
START_ROBOT_CLASS(Robot)
