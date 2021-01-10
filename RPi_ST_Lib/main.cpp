// COMPILATION COMMAND:
// g++ main.cpp lis2de12_reg.c -o LIS2DE12_Driver -lwiringPi

#include <iostream>
#include <thread>
#include <chrono>
#include "lis2de12_reg.h"


int main (int argc, char **argv){
	// Setup I2C communication
	fd = wiringPiI2CSetup(DEVICE_ID);
	//run();
	return 0;
}