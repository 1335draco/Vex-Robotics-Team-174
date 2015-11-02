#pragma config(Motor,  port2,           rDrive,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lDrive,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           harvesterLower, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           harvesterUpper, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           sRightBack, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           sLeftBack,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           sRightFront, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           sLeftFront,  tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


void turnMotors (int lSpeed, int rSpeed)
{
	motor[lDrive] = -lSpeed;
	motor[rDrive] = rSpeed;
}

void shootMotors (int aSpeed, int bSpeed, int cSpeed, int dSpeed)
{
	motor[sRightBack] = aSpeed;
	motor[sRightFront] = bSpeed;
	motor[sLeftBack] = cSpeed;
	motor[sLeftFront] = dSpeed;
}

void harvesterMotors (int harvestSpeedUpper, int harvestSpeedLower)
{
	motor [harvesterUpper] = harvestSpeedUpper;
	motor [harvesterLower] = harvestSpeedLower;
}

void teleop()
{
	turnMotors(vexRT[Ch3], vexRT[Ch2]);

	int aSpeed = 0;
	int bSpeed = 0;
	int cSpeed = 0;
	int dSpeed = 0;
	int harvestSpeedUpper = 0;
	int harvestSpeedLower = 0;

	if(vexRT[Btn6D])
	{
		aSpeed = 126;
	}
	else
	{
		aSpeed = 0;
	}
	//shootMotors(aSpeed);

	if(vexRT[Btn6U])
	{
		bSpeed = 126;
	}
	else
	{
		bSpeed = 0;
	}
	//shootMotors(bSpeed);

	if(vexRT[Btn5U])
	{
		dSpeed = 126;
	}
	else
	{
		dSpeed = 0;
	}
	//shootMotors(dSpeed);

	if(vexRT[Btn5D])
	{
		cSpeed = 126;
	}
	else
	{
		cSpeed = 0;
	}
	//shootMotors(cSpeed);

	shootMotors(aSpeed, bSpeed, cSpeed, dSpeed);

	if(vexRT[Btn8U])
	{
		harvestSpeedUpper = 120;
	}
	else if(vexRT[Btn8D])
	{
		harvestSpeedUpper = -120;
	}
	else
	{
		harvestSpeedUpper = harvestSpeedUpper * .5;
	}

	if(vexRT[Btn7U])
	{
		harvestSpeedLower = 120;
	}
	else if(vexRT[Btn7D])
	{
		harvestSpeedLower = -120;
	}
	else
	{
		harvestSpeedLower = harvestSpeedLower * .5;
	}

	harvesterMotors(-harvestSpeedUpper, harvestSpeedLower);

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
		teleop();
		//UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
	}
}
