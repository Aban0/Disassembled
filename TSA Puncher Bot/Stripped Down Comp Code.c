#pragma config(Motor,  port1,           intake,        tmotorVex393TurboSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           puncher,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           backLeft,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           midLeft,       tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           frontLeft,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           backRight,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           midRight,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           frontRight,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          adjuster,      tmotorVex393_HBridge, openLoop)

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

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
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
  // User control code here, inside the loop

  while (true)
  {
    motor[frontRight] = vexRT[Ch2];
		motor[midRight] = vexRT[Ch2];
		motor[backRight] = vexRT[Ch2];
		motor[frontLeft] = vexRT[Ch3];
		motor[midLeft] = vexRT[Ch3];
		motor[backLeft] = vexRT[Ch3];

		if (vexRT(Btn7R) == 1)
		{
			motor[lift] = 127;
		}
		else if (vexRT(Btn7D) == 1)
		{
			motor[lift] = -127;
		}
		else
		{
			motor[lift] = 0;
		}

		if (vexRT(Btn5U) == 1)
		{
			motor[intake] = 127;
		}
		else if (vexRT(Btn5D) == 1)
		{
			motor[intake] = -127;
		}
		else
		{
			motor[intake] = 0;
		}

		if (vexRT(Btn6U) == 1)
		{
			motor[puncher] = 127;
		}
		else
		{
			motor[puncher] = 0;
		}

		if (vexRT(Btn8U) == 1)
		{
			motor[adjuster] = 127;
		}
		else if (vexRT(Btn8D) == 1)
		{
			motor[adjuster] = -127;
		}
		else
		{
			motor[adjuster] = 0;
		}
  }
}
