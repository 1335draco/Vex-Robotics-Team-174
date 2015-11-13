#pragma config(Motor,  port2,           rDrive,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lDrive,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           harvesterLower, tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port5,           harvesterUpper, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           sRightBack,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           sLeftBack,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           sRightFront,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           sLeftFront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          raiseLowerShooter, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


void turnMotors (int lSpeed, int rSpeed)
{
	motor[lDrive] = lSpeed;
	motor[rDrive] = -rSpeed;
}

void shootBackMotors (int aSpeed)
{
	motor[sRightBack] = -aSpeed;
	motor[sLeftBack] = aSpeed;
}

void shootFrontMotors (int aSpeed)
{
	motor[sRightFront] = aSpeed;
	motor[sLeftFront] = -aSpeed;
}

void shootMotors (int aSpeed, int bSpeed, int cSpeed, int dSpeed)
{
	motor[sRightBack] = -aSpeed;
	motor[sLeftBack] = bSpeed;
	motor[sRightFront] = cSpeed;
	motor[sLeftFront] = -dSpeed;
}

void harvesterMotors (int harvestSpeedUpper, int harvestSpeedLower)
{
	motor [harvesterUpper] = harvestSpeedUpper;
	motor [harvesterLower] = harvestSpeedLower;
}


//void raiseLowerShoot (int raiseShooterSpeed)
//{
//	motor[raiseLowerShooter] = raiseShooterSpeed;
//}

void teleop()
{
	turnMotors(vexRT[Ch3], vexRT[Ch2]);
	//if(vexRT[Ch3]!=0)
	//{
	//	shootFrontMotors(vexRT[Ch3]);
	//}
	//else
	//{
	//	shootFrontMotors(0);
	//}

	//if(vexRT[Ch2]!=0)
	//{
	//	shootBackMotors(vexRT[Ch2]);

	//}
	//else
	//{
	//	shootBackMotors(0);
	//}

	//Shooter speed variables, harvesterSpeed variables, and counters for deceleration period
	int aSpeed = 0;
	int bSpeed = 0;
	int cSpeed = 0;
	int dSpeed = 0;
	int harvestSpeedUpper = 0;
	int harvestSpeedLower = 0;
 // int raiseShooterSpeed = 0;
	//int counter1 = 0;
	//int counter2 = 0;
	//int counter3 = 0;
	//int counter4 = 0;

	if(vexRT[Btn6U])
	{
		aSpeed = 127;
		bSpeed = 127;
		cSpeed = 127;
		dSpeed = 127;
	}
	else
	{
		aSpeed = 0;
		bSpeed = 0;
		cSpeed = 0;
		dSpeed = 0;
	}
	shootMotors(aSpeed, bSpeed, cSpeed, dSpeed);

	//if(vexRT[Btn6U])
	//{
	//	aSpeed = 126;
	//}
	//else
	//{
	//	while (counter1<4)
	//	{
	//		aSpeed = aSpeed - 35;
	//		counter1 = counter1+1;
	//		wait1Msec(70);
	//	}
	//	 counter1  =0;
	//	 aSpeed = 0;
	//}
	////shootMotors(aSpeed);

	//if(vexRT[Btn6U])
	//{
	//	bSpeed = 126;
	//}
	//else
	//{
	//	while(counter2 < 4)
	//	{
	//		bSpeed = bSpeed - 35;
	//		counter2 = counter2 + 1;
	//		wait1Msec(70);
	//	}
	//	counter2 = 0;
	//	bSpeed = 0;
	//}

	////shootMotors(bSpeed);
	//if(vexRT[Btn6U])
	//{
	//	cSpeed = 126;
	//}
	//else
	//{
	//	while(counter3 < 4)
	//	{
	//		counter3 = counter3 +1;
	//		cSpeed = cSpeed -35;
	//		wait1Msec(70);
	//	}
	//	cSpeed = 0;
	//	counter3 = 0;
	//}

	//if(vexRT[Btn6U])
	//{
	//	dSpeed = 126;
	//}
	//else
	//{
	//	while(counter4 < 4)
	//	{
	//		dSpeed = dSpeed - 35;
	//		counter4 = counter4 + 1;
	//		wait1Msec(70);
	//	}
	//	dSpeed = 0;
	//	counter4 = 0;
	//}
	//shootMotors(dSpeed);


	////shootMotors(cSpeed);

	//shootMotors(aSpeed, bSpeed, cSpeed, dSpeed);

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

	//if(vexRT[Btn7L])
	//{
 //  	raiseShooterSpeed = -127;
	//}
	//else if (vexRT[Btn7R])
	//{
	//	raiseShooterSpeed = 127;
	//}
	//else
 // {
 // 	raiseShooterSpeed = 0;
 // }

 // 	raiseLowerShoot(raiseShooterSpeed);
 // }








}

void shootFour()
	{





		shootBackMotors(40);
		wait1Msec(50);
		shootBackMotors(80);
		shootFrontMotors(40);
		wait1Msec(50);

		shootFrontMotors(80);
		wait1Msec(50);

		//wait1Msec(50);
		shootFrontMotors(127);
		shootBackMotors(127);

		//First Shot
		harvesterMotors(127, 127);
		wait1Msec(60); //TODO TEST FOR TIME IT TAKES FOR BALL TO LEAVE HARVESTER
		harvesterMotors(0,0);
		wait1Msec(5);

		shootFrontMotors(127);
		shootBackMotors(127);

		//Second Shot
		harvesterMotors(127, 127);
		wait1Msec(60); //TODO TEST FOR TIME IT TAKES FOR BALL TO LEAVE HARVESTER
		harvesterMotors(0,0);
		wait1Msec(5);

		shootFrontMotors(127);
		shootBackMotors(127);

		//Third Shot
		harvesterMotors(127, 127);
		wait1Msec(60); //TODO TEST FOR TIME IT TAKES FOR BALL TO LEAVE HARVESTER
		harvesterMotors(0,0);
		wait1Msec(5);

		shootFrontMotors(127);
		shootBackMotors(127);

		//Fourth Shot
		harvesterMotors(127, 127);
		wait1Msec(60); //TODO TEST FOR TIME IT TAKES FOR BALL TO LEAVE HARVESTER
		harvesterMotors(0,0);
		wait1Msec(5);

		shootFrontMotors(127);
		shootBackMotors(127);




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
	shootFour();
	//AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
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
