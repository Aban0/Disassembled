#pragma config(Sensor, in1,    autonPot,       sensorPotentiometer)
#pragma config(Sensor, in2,    platPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEnc,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEnc,        sensorQuadEncoder)
#pragma config(Motor,  port1,           intake,        tmotorVex393TurboSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           puncher,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           midLeft,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           adjuster,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           frontRight,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           midRight,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          backRight,     tmotorVex393HighSpeed_HBridge, openLoop, reversed)

task main()
{
	while (true)
	{
		motor[frontRight] = 127;
		motor[midRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[midLeft] = 127;
		motor[backLeft] = 127;
		motor[puncher] = 127;
		motor[intake] = 127;
		motor[adjuster] = 127;
		motor[lift] = 127;
	}
}
