task rightDrive()
{
	// Drive controls with deadzone
	if (vexRT(Ch2) > 10 || vexRT(Ch2) < -10)
	{
		motor[frontRight] = vexRT[Ch2];
		motor[midRight] = vexRT[Ch2];
		motor[backRight] = vexRT[Ch2];
	}
	else
	{
		motor[frontRight] = 0;
		motor[midRight] = 0;
		motor[backRight] = 0;
	}
}

task leftDrive()
{
	if (vexRT(Ch3) > 10 || vexRT(Ch3) < -10)
	{
		motor[frontLeft] = vexRT[Ch3];
		motor[midLeft] = vexRT[Ch3];
		motor[backLeft] = vexRT[Ch3];
	}
	else
	{
		motor[frontLeft] = 0;
		motor[midLeft] = 0;
		motor[backLeft] = 0;
	}
}
