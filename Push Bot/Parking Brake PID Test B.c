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

// Declaring Variables
int KpR = .5;
int errorR = 0;
int targetLocationR = 0;
int drivePowerR = 0;
int KpL = .5;
int errorL = 0;
int targetLocationL = 0;
int drivePowerL = 0;
bool brakes = false;

task main()
{
	// Logging important values
	datalogDataGroupStart();
	datalogAddValue( 4, rightDrive );
	datalogAddValue( 5, leftDrive );
	datalogAddValue( 6, rightDrive2);
	datalogAddValue( 7, leftDrive2);
	datalogDataGroupEnd();

	// Resetting encoders
	SensorValue[rightDrive] = 0;
	SensorValue[leftDrive] = 0;

	while (true)
	{
		// Drive controls
		if (vexRT(Ch2) > 3 || vexRT(Ch2) < -3)
		{
			motor[rightDrive1] = vexRT[Ch2];
			motor[rightDrive2] = vexRT[Ch2];
			motor[rightDrive3] = vexRT[Ch2];
		}
		if (vexRT(Ch3) > 3 || vexRT(Ch3) < -3)
		{
			motor[leftDrive1] = vexRT[Ch3];
			motor[leftDrive2] = vexRT[Ch3];
			motor[leftDrive3] = vexRT[Ch3];
		}

		// H-Drive controls
		if (vexRT(Ch4) > 3 || vexRT(Ch4) < -3)
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

		/*

		// PID Parking Brake
		if (vexRT[Btn8D] == 1)
		{
		brakes = !brakes;
		targetLocationR = SensorValue[rightDrive];
		targetLocationL = SensorValue[leftDrive];
		}

		// Change drive power accoring to sensor value
		while (brakes == true && SensorValue[rightDrive] != targetLocationR || SensorValue[leftDrive] != targetLocationL)
		{
		if (vexRT[Btn8R] == 1)
		{
		brakes = !brakes;
		}

		// Find error and integrate P into it
		errorR = SensorValue[rightDrive] - targetLocationR;  // Currently just P, we can add on in the future
		drivePowerR = KpR*errorR;
		errorL = SensorValue[leftDrive] - targetLocationL;
		drivePowerL = KpL*errorL;

		// Set drive value to move back into position if needed
		motor[rightDrive1] = drivePowerR;
		motor[rightDrive2] = drivePowerR;
		motor[rightDrive3] = drivePowerR;
		motor[leftDrive1] = drivePowerL;
		motor[leftDrive2] = drivePowerL;
		motor[leftDrive3] = drivePowerL;
		}
		}

		*/
	}
}
