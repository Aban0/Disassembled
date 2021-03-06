#pragma config(Motor,  port1,           LeftDriveMotor, tmotorVex393_HBridge, openLoop, driveLeft)
#pragma config(Motor,  port3,           ArmLvl1Left,   tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           ArmLvl1Right,  tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port5,           ArmLvl2Left,   tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port6,           ArmLvl2Right,  tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port7,           ClawLeft,      tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port8,           ClawRight,     tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port9,           BackMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          RightDriveMotor, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	clearTimer(T1);
	while(time1[T1] < 2000)
	{
		motor[port10] = 127;
		motor[port2] = -127;
	}

}
