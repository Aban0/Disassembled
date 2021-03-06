#pragma config(Motor,  port1,           left,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           right,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           claw,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true)
	{
		motor[left] = vexRT(Ch2);
		motor[right] = vexRT(Ch3);

		if (vexRT[Btn5U] == 1)
		{
			motor[lift] = 127;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[lift] = -127;
		}
		else
		{
			motor[lift] = 0;
		}

		if (vexRT[Btn6U] == 1)
		{
			motor[claw] = 127;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[claw] = -127;
		}
		else
		{
			motor[claw] = 0;
		}
	}
}
