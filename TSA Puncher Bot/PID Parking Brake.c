#pragma systemFile

task pBrake()
{
	// Local Variables
	int kP = 1;
	int error;
	int power;

	while(brake == true)
	{
		error = setpoint - SensorValue(rightEnc); // Error is calculated
		power = error*kP; // Proportional component is implemented
		power = power*(-1);

		// Deadband is set since integral and derivative components are not implemented
		if(error > 20 || error < -20)
		{
			motor[frontRight] = power;
			motor[midRight] = power;
			motor[backRight] = power;
			motor[frontLeft] = power;
			motor[midLeft] = power;
			motor[backLeft] = power;
		}
		// Give other tasks some time to run
		wait1Msec(10);
	}
	stopTask(pBrake);
}
