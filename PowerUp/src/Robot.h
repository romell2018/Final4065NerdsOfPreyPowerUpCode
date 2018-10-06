#pragma once

#include <string>

#include <IterativeRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <CANLight.h>
#include <mindsensors.h>
#include <AutoDrive.h>
#include <Autonomous.h>
#include <ExtraMath.h>
#include <DriveTrain.h>
#include <Intake.h>
#include <Lift.h>
#include <AHRS.h>
#include <LED.h>

using mindsensors::CANLight;

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;

	Autonomous autonomous;
	DriveTrain drive; //drive class
	Lift lift; //lift class
	Intake intake; //intake class
	AutoDrive autodrive;
	ExtraMath math;

	//LED canlight;//canlight/LED class

private:

	frc::SendableChooser<std::string> m_chooser; //pick auto
	const std::string kAutoDefault = "Default";
	const std::string kAutoLeft = "My Auto Left";
	const std::string kAutoMiddle = "My Auto Middle";
	const std::string kAutoRight = "My Auto Right";
	std::string m_autoSelected;

	cs::UsbCamera cam1;

	frc::Joystick *romell = new Joystick(0); //Romell Controller
	frc::Joystick *zack = new Joystick(1); //Zack Controller

	enum Controller {
		Normal, Flip
	};

	Controller controllerFlip = Controller::Normal; //start with normal control

	bool switchTogglePressed = false; //romell inverted drive control
	bool switchToggleOn = false;

	bool flipTogglePressed = false; //romell inverted drive control
	bool flipToggleOn = false;

	bool toggleOn = false; //intakes toggle
	bool togglePressed = false;

	//TODO CanLight LED

};
