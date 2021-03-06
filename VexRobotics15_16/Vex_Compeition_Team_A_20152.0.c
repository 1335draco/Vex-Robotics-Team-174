#pragma config(Motor,  port3,           LMotor,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           RMotor,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LShooter,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           RShooter,      tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

void turnMotors (int LSpeed, int RSpeed)
{
	motor[LMotor]  = LSpeed;
	motor[RMotor]  = -RSpeed;
}

void shootMotors (int aSpeed)
{
	motor[LMotor] = aSpeed;
	motor[RMotor] = aSpeed;

}

//bool checkToggleOn (bool toggleOn)
//{
//	if (toggleOn == true)
//	{
//		return 0;
//	}

void teleop()
{
	turnMotors (vexRT[Ch3], vexRT[Ch2]);




	int shootSpeed = 0;
	//bool toggleState = false;


		//shootSpeed = aSpeed;
		//if(checkToggleOn()==0)
		//{
		//	toggleState = vexRT[Btn8U];
		//}

	if (vexRT[Btn8U])
	{
		shootSpeed = 127;
	}
	else
	{
		shootSpeed = 0;
	}
	shootMotors (shootSpeed);

}


















/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

	  // .....................................................................................
	  // Insert user code here. This is where you use the joystick values to update your motors, etc.
	  // .....................................................................................

	  teleOperated();
	}
}
