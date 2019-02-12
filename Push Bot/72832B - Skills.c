#pragma config(Sensor, dgtl1,  rightDrive,     sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftDrive,      sensorQuadEncoder)
#pragma config(Motor,  port1,           mongoLeft,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftDrive1,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftDrive2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftDrive3,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightLift,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftLift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightDrive3,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightDrive2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightDrive1,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          mongoRight,    tmotorVex393_HBridge, openLoop)

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(0)
#pragma userControlDuration(60)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                         Driver Skills Template
//
// This is a template for the driver skills competition. It is identical in structure to
// the standard competition template except that the two "#pragma' statements above (and
// copied below) adjust the time limits for the competition.
//				#pragma autonomousDuration(0)
//				#pragma userControlDuration(60)
// The autonomous duration for "Driver Skills" is zero; i.e. there is no autonomous phase.
// The user control duration is 60 seconds
//
// NOTE: The above two pragmas only impact the Crystal implementation. For systems using
//       VEXNET, the VEXNET system ignores these statements as it has the durations
//       for the competition built-in.
//
// Whenever this user program is run, the duration is automatically sent to the VEX master
// processor. The master CPU will only accept these commands once per power=on cycle. So, it's
// best to power cycle your VEX to ensure that they get recognized in case you were
// previously running a standard competition program with different durations.
//
// Testing Via Crystals:
// ====================
//
// The procedure to test a Driver Skills program using the crystals is as follows:
//
// 1. Turn off power to the Crystal transmitter/joysticks.
//
// 2. Turn on your VEX so that the Driver Skills program is running.
//
// 3. Driver skills program segment of your program will start running. At the end of 60
//    seconds the VEX Master CPU will turn off the motors.
//
// 4. Repeat the above sequence
//
//
// Testing Via VEXNET Using VEXNET Competition Switch
// ==================================================
//
// The procedure to test a Driver Skills program using VEXNET Competition Switch is as follows:
//
// 1. Set the two switches on the Competition switch to "DISABLE" and "USER CONTROL"
//
// 2. Start the Driver skills program
//
// 3. Set Switch to ENABLE from DISABLE
//
// 4. You need to manually time the 60 second duration.
//
// 5. Set Switch to DISABLE
//
// 6. Repeat from step (3) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
//
// Testing Via VEXNET Using ROBOTC IDE
// ==================================================
//
// It is not necessary to own a VEXNET switch. ROBOTC has a test window that allows the same functionality.
// The test window has three buttons for "DISABLE", "AUTONOMOUS", "USER CONTROL".
//
// 1. Open the ROBOTC Debugger. Then open the "Competition Control" Debugger window.
//
// 2. Start your Driver Skills program running.
//
// 3. Click the "DISABLED" button on the "Competition Control" window.
//
// 4. Click the "USER CONTROL" button on the "Competition Control" window.
//
// 5. You need to manually time the 60 second duration.
//
// 6. Click the "DISABLED" button on the "Competition Control" window.
//
// 7. Repeat from step (4) to run subsequent test runs. There's no need to reset the VEX or
//    restart your user program.
//
/////////////////////////////////////////////////////////////////////////////////////////

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

	SensorValue[rightDrive] = 0;
	SensorValue[leftDrive] = 0;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// The "Driver Skills" competition has no autonomous phase. Simply leave the following
// placeholder.
//
/////////////////////////////////////////////////////////////////////////////////////////

//functions for Autonomous

void moveForward()
{
	motor[leftDrive1] = 127;
	motor[leftDrive2] = 127;
	motor[leftDrive3] = 127;
	motor[rightDrive3] = 127;
	motor[rightDrive2] = 127;
	motor[rightDrive1] = 127;
}

void moveBackward()
{
	motor[leftDrive1] = -127;
	motor[leftDrive2] = -127;
	motor[leftDrive3] = -127;
	motor[rightDrive3] = -127;
	motor[rightDrive2] = -127;
	motor[rightDrive1] = -127;
}

// Stop all drive motors
void stopDrive()
{
	motor[leftDrive1] = 0;
	motor[leftDrive2] = 0;
	motor[leftDrive3] = 0;
	motor[rightDrive3] = 0;
	motor[rightDrive2] = 0;
	motor[rightDrive1] = 0;
}

void rotateLeft()
{
	motor[leftDrive1] = -127;
	motor[leftDrive2] = -127;
	motor[leftDrive3] = -127;
	motor[rightDrive3] = 127;
	motor[rightDrive2] = 127;
	motor[rightDrive1] = 127;
}

void rotateRight()
{
	motor[leftDrive1] = 127;
	motor[leftDrive2] = 127;
	motor[leftDrive3] = 127;
	motor[rightDrive3] = -127;
	motor[rightDrive2] = -127;
	motor[rightDrive1] = -127;
}

void mongoUp()
{
	motor[mongoRight] = 127;
	motor[mongoLeft] = 127;
}

void mongoDown()
{
	motor[mongoRight] = -127;
	motor[mongoLeft] = -127;
}

void mongoStop()
{
	motor[mongoRight] = 0;
	motor[mongoLeft] = 0;
}

//End of Functions List


task autonomous()
{

	//flag
	moveBackward();
	wait1Msec(1750);
	moveForward();
	wait1Msec(3000);

	//Turn
	rotateRight();
	wait1Msec(500);
	moveForward();
	wait1Msec(1000);

	//Platform
	moveBackward();
	wait1Msec(3000);
	moveForward();
	wait1Msec(15);
	stopDrive();


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
		// Drive controls
		motor[rightDrive1] = vexRT[Ch2];
		motor[rightDrive2] = vexRT[Ch2];
		motor[rightDrive3] = vexRT[Ch2];
		motor[leftDrive1] = vexRT[Ch3];
		motor[leftDrive2] = vexRT[Ch3];
		motor[leftDrive3] = vexRT[Ch3];

		// Six bar controls
		if (vexRT[Btn6U] == 1)
		{
			motor[rightLift] = 127;
			motor[leftLift] = 127;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[rightLift] = -127;
			motor[leftLift] = -127;
		}
		else
		{
			motor[rightLift] = 0;
			motor[leftLift] = 0;
		}

		// Four bar controls
		if (vexRT[Btn5U] == 1)
		{
			motor[mongoRight] = 127;
			motor[mongoLeft] = 127;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[mongoRight] = -127;
			motor[mongoLeft] = -127;
		}
		else
		{
			motor[mongoRight] = 0;
			motor[mongoLeft] = 0;
		}

	}
}
