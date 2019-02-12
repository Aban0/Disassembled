#pragma config(Motor,  port1,           backRight,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           intake,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           puncherRight,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           puncherLeft,   tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}




/* A list of functions to make programming quicker and easier
while also making the code much cleaner. */


// Sets motors to full speed forward until code changes it
void moveForward()
{
	motor[frontRight] = 127;
	motor[backRight] = 127;
	motor[frontLeft] = 127;
	motor[backLeft] = 127;
}

// Sets motors to full speed reverse until code changes it
void moveBack()
{
	motor[frontRight] = -127;
	motor[backRight] = -127;
	motor[frontLeft] = -127;
	motor[backLeft] = -127;
}

// Turns right 90 degrees
void turnRight90()
{
	motor[frontRight] = -127;
	motor[backRight] = -127;
	motor[frontLeft] = 127;
	motor[backLeft] = 127;
	wait1Msec(300);
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[backLeft] = 0;
}

// Turns left 90 degrees
void turnLeft90()
{
	motor[frontRight] = 127;
	motor[backRight] = 127;
	motor[frontLeft] = -127;
	motor[backLeft] = -127;
	wait1Msec(300);
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[backLeft] = 0;
}

// Stops all drive motors
void stopDriveMotors()
{
	motor[frontRight] = 0;
	motor[frontLeft] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
}

// Fires puncher
void punch()
{
	motor[port7] = 127;
	motor[port8] = 127;
	wait1Msec(900);
	motor[port7] = 0;
	motor[port8] = 0;
}

// End of function list


// Auton functions for the different starting positions
void blueFlagSide()
{
	// Drive forward into shooting position
	motor[frontRight] = 127;
	motor[frontLeft] = 127;
	motor[backRight] = 127;
	motor[backLeft] = 127;
	wait1Msec(250);
	stopDriveMotors();

	// Shoot top flag
	motor[port7] = 127;
	motor[port8] = 127;
	wait1Msec(900);
	motor[port7] = 0;
	motor[port8] = 0;

	// Turn right
	turnRight90();


}

void blueAltSide()
{

}

void redFlagSide()
{

}

void redAltSide()
{

}

// Code that is run when autonomous starts
task autonomous()
{
	// Variables
	int jumper1 = SensorValue(dgtl1);
	int jumper2 = SensorValue(dgtl2);
	int jumper3 = SensorValue(dgtl3);

	// Choosing which function to call for auton
	if (jumper3 == 0)
	{
		// Blank statement as a failsafe in case wrong jumper clip
	}
	else if (jumper1 == 0)
	{
		blueFlagSide();
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	while (true)
	{
		// Drive Controls
		motor[frontRight] = vexRT[Ch2];
		motor[backRight] = vexRT[Ch2];
		motor[frontLeft] = vexRT[Ch3];
		motor[backLeft] = vexRT[Ch3];


		// Intake Controls
		if (vexRT[Btn5U] == 1)
		{
			motor[intake] = 127;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[intake] = -127;
		}
		else
		{
			motor[intake] = 0;
		}


		// Puncher Controls
		if (vexRT[Btn6U] == 1)
		{
			motor[puncherRight] = 127;
			motor[puncherLeft] = 127;
		}
		else
		{
			motor[puncherRight] = 0;
			motor[puncherLeft] = 0;
		}
	}
}
