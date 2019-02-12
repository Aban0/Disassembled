#pragma config(Motor,  port1,           backRight,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           intake,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           puncherRight,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           puncherLeft,   tmotorVex393_MC29, openLoop, reversed)

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

// PID using optical shaft encoder
//
// Shaft encoder has 360 pulses per revolution
//

#define PID_SENSOR_INDEX    myEncoder
#define PID_SENSOR_SCALE    1

#define PID_MOTOR_INDEX     myMotor
#define PID_MOTOR_SCALE     -1

#define PID_DRIVE_MAX       127
#define PID_DRIVE_MIN     (-127)

#define PID_INTEGRAL_LIMIT  50

// These could be constants but leaving
// as variables allows them to be modified in the debugger "live"
float  pid_Kp = 2.0;
float  pid_Ki = 0.04;
float  pid_Kd = 0.0;

static int   pidRunning = 1;
static float pidRequestedValue;

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*  pid control task                                                           */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

task pidController()
{
    float  pidSensorCurrentValue;
    float  pidError;
    float  pidLastError;
    float  pidIntegral;
    float  pidDerivative;
    float  pidDrive;

    // If we are using an encoder then clear it
    if( SensorType[ PID_SENSOR_INDEX ] == sensorQuadEncoder )
        SensorValue[ PID_SENSOR_INDEX ] = 0;

    // Init the variables
    pidLastError  = 0;
    pidIntegral   = 0;

    while( true )
        {
        // Is PID control active ?
        if( pidRunning )
            {
            // Read the sensor value and scale
            pidSensorCurrentValue = SensorValue[ PID_SENSOR_INDEX ] * PID_SENSOR_SCALE;

            // calculate error
            pidError = pidSensorCurrentValue - pidRequestedValue;

            // integral - if Ki is not 0
            if( pid_Ki != 0 )
                {
                // If we are inside controlable window then integrate the error
                if( abs(pidError) < PID_INTEGRAL_LIMIT )
                    pidIntegral = pidIntegral + pidError;
                else
                    pidIntegral = 0;
                }
            else
                pidIntegral = 0;

            // calculate the derivative
            pidDerivative = pidError - pidLastError;
            pidLastError  = pidError;

            // calculate drive
            pidDrive = (pid_Kp * pidError) + (pid_Ki * pidIntegral) + (pid_Kd * pidDerivative);

            // limit drive
            if( pidDrive > PID_DRIVE_MAX )
                pidDrive = PID_DRIVE_MAX;
            if( pidDrive < PID_DRIVE_MIN )
                pidDrive = PID_DRIVE_MIN;

            // send to motor
            motor[ PID_MOTOR_INDEX ] = pidDrive * PID_MOTOR_SCALE;
            }
        else
            {
            // clear all
            pidError      = 0;
            pidLastError  = 0;
            pidIntegral   = 0;
            pidDerivative = 0;
            motor[ PID_MOTOR_INDEX ] = 0;
            }

        // Run at 50Hz
        wait1Msec( 25 );
        }
}

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
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
