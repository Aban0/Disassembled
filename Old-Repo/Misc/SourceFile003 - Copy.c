#pragma config(Motor,  port1,           rightMotor,    tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           backMotor,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           flipperMotor,  tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           elbowMotor,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           shoulderMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           flipperMotorREVERSED, tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           elbowMotorREVERSE, tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           shoulderMotorREVERSE, tmotorVex393HighSpeed_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
while(true)
{
	int threshold = 10;
	if(vexRT[Ch2] > threshold)
	{
		motor(rightMotor) = vexRT[Ch2];
		motor(leftMotor) = vexRT[Ch2];
	}
	else if(vexRT[Ch2] < -threshold)
	{
		motor(rightMotor) = -vexRT[Ch2];
		motor(leftMotor) = -vexRT[Ch2];
	}
	else if(vexRT[Ch3] > threshold)
	{
		motor(rightMotor) = vexRT[Ch3];
		motor(leftMotor) = vexRT[Ch3];
	}
	else if(vexRT[Ch3] < -threshold)
	{
		motor(rightMotor) = -vexRT[Ch3];
		motor(leftMotor) = -vexRT[Ch3];
	}
	else if(vexRT[Ch1] > threshold)
	{
		motor(rightMotor) = vexRT[Ch1];
		motor(leftMotor) = -vexRT[Ch1];
		motor(backMotor) = 0;
	}
	else if(vexRT[Ch1] < -threshold)
	{
		motor(rightMotor) = -vexRT[Ch1];
		motor(leftMotor) = vexRT[Ch1];
		motor(backMotor) = 0;
	}
	else if(vexRT[Ch4] > 0)
	{
		motor(backMotor) = vexRT[Ch4];
		motor(rightMotor) = 0;
		motor(leftMotor) = 0;
	}
	if(vexRT[Ch4] < -threshold)
	{
		motor(backMotor) = -vexRT[Ch4];
		motor(rightMotor) = 0;
		motor(leftMotor) = 0;
	}
	else
	{
		motor(rightMotor) = 0;
		motor(leftMotor) = 0;
		motor(backMotor) = 0;
	}

	if(vexRT[Btn5U] == 1)
	{
		motor(shoulderMotor) = 127;
		motor(shoulderMotorREVERSE) = 127;
	}
	else if(vexRT[Btn5D] == 1)
	{
		motor(shoulderMotor) = -127;
		motor(shoulderMotorREVERSE) = -127;
	}
	else
	{
		motor(shoulderMotor) = 0;
		motor(shoulderMotorREVERSE) = 0;
	}

	if(vexRT[Btn6U] == 1)
	{
		motor(elbowMotor) = 50;
		motor(elbowMotorREVERSE) = 50;
	}
	else if(vexRT[Btn6D] == 1)
	{
		motor(elbowMotor) = -50;
		motor(elbowMotorREVERSE) = -50;
	}
	else
	{
		motor(elbowMotor) = 0;
		motor(elbowMotorREVERSE) = 0;
	}

	if(vexRT[Btn7L] == 1)
	{
		motor(flipperMotor) = 20;
		motor(flipperMotorREVERSED) = 20;
	}
	else if(vexRT[Btn8R] == 1)
	{
		motor(flipperMotor) = -20;
		motor(flipperMotorREVERSED) = -20;
	}
	else
	{
		motor(flipperMotor) = 0;
		motor(flipperMotorREVERSED) = 0;
	}
}
}
