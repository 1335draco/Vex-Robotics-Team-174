#pragma config(Motor,  port1,           RightDriveA,   tmotorVex269, openLoop)
#pragma config(Motor,  port2,           RightDriveB,   tmotorVex269, openLoop)
#pragma config(Motor,  port3,           LeftDriveA,    tmotorVex269, openLoop)
#pragma config(Motor,  port4,           LeftDriveB,    tmotorVex269, openLoop)
#pragma config(Motor,  port5,           Flipper,       tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

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

void setDriveLeftRight(int aLeft, int aRight)
{
  motor[LeftDriveA]   = aLeft;
  motor[LeftDriveB]   = aLeft;
  motor[RightDriveA]  = aRight;
  motor[RightDriveB]  = aRight;
}

void controlFlipper()
{
    if(vexRT[Btn5D])
    {
    	motor[Flipper]  = -127;
    }
    else if(vexRT[Btn5U])
    {
    	motor[Flipper]  = 127;
    }
    else
    {
    	motor[Flipper]  = 0;
    }
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
		  setDriveLeftRight(vexRT[Ch3], vexRT[Ch2]);
      controlFlipper();
	}
}
