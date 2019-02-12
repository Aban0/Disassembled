#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           backRight,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           intake,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           puncherRight,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           puncherLeft,   tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"


void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Clear encoders
	SensorValue[dgtl1] = 0;
	SensorValue[dgtl3] = 0;
}


task autonomous()
{

}


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