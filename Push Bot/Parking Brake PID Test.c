#pragma config(Sensor, dgtl1,  leftDrive,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightDrive,     sensorQuadEncoder)
#pragma config(Motor,  port1,           mongoLeft,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftDrive1,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftDrive2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftDrive3,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           hDrive,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rightDrive3,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightDrive2,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightDrive1,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          mongoRight,    tmotorVex393_HBridge, openLoop)

// Global variables
bool brakes = false;
int targetLocationR = 0;
int targetLocationL = 0;
int drivePowerR = 0;
int drivePowerL = 0;





// This task is run when the parking brake is enabled
task parkingBrake()
{
	// Declaring Variables
	int KpR = .9;
	int KpL = .9;
	int errorR = 0;
	int errorL = 0;

	// Logging important values for debugging
	datalogDataGroupStart();
	datalogAddValue( 0, errorR );
	datalogAddValue( 1, errorL );
	datalogAddValue( 2, drivePowerR );
	datalogAddValue( 3, drivePowerL);
	datalogDataGroupEnd();

	while (brakes == true)
	{
		if (vexRT[Btn8R] == 1)
		{
			brakes = !brakes;
			stopTask(parkingBrake);
		}

		// Find error and integrate P into it
		errorR = SensorValue[rightDrive] - targetLocationR;  // Currently just P, we can add on in the future
		drivePowerR = (int)(KpR*errorR);
		errorL = SensorValue[leftDrive] - targetLocationL;
		drivePowerL = (int)(KpL*errorL);
	}
}

task main()
{
	// Logging important values for debugging
	datalogDataGroupStart();
	datalogAddValue( 4, rightDrive );
	datalogAddValue( 5, leftDrive );
	datalogAddValue( 6, rightDrive2);
	datalogAddValue( 7, leftDrive2);
	datalogDataGroupEnd();
	while (true)
	{
		// Drive controls
		if (vexRT(Ch2) > 5 || vexRT(Ch2) < -5)
		{
			motor[rightDrive1] = vexRT[Ch2];
			motor[rightDrive2] = vexRT[Ch2];
			motor[rightDrive3] = vexRT[Ch2];
		}
		if (vexRT(Ch3) > 5 || vexRT(Ch3) < -5)
		{
			motor[leftDrive1] = vexRT[Ch3];
			motor[leftDrive2] = vexRT[Ch3];
			motor[leftDrive3] = vexRT[Ch3];
		}

		// H-Drive controls
		if (vexRT(Ch4) > 5 || vexRT(Ch4) < -5)
		{
			motor[hDrive] = vexRT[Ch4];
		}

		// Six bar controls
		if (vexRT[Btn6U] == 1)
		{
			motor[lift] = 127;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[lift] = -127;
		}
		else
		{
			motor[lift] = 0;
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

		// Start parking brake task and set parking brake to the encoder's current values
		if (vexRT[Btn8D] == 1)
		{
			brakes = !brakes;
			startTask(parkingBrake);
			targetLocationR = SensorValue[rightDrive];
			targetLocationL = SensorValue[leftDrive];

			// Change drive power accoring to sensor values
			while (SensorValue[rightDrive] != targetLocationR || SensorValue[leftDrive] != targetLocationL)
			{
				if (vexRT[Btn8R] == 1)
				{
					brakes = !brakes;
					stopTask(parkingBrake);
				}
				motor[rightDrive1] = drivePowerR;
				motor[rightDrive2] = drivePowerR;
				motor[rightDrive3] = drivePowerR;
				motor[leftDrive1] = drivePowerL;
				motor[leftDrive2] = drivePowerL;
				motor[leftDrive3] = drivePowerL;
			}
		}
	}
}
