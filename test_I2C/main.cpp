//g++ -o i2c_wiringpi_test main.cpp -lwiringPi

#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPiI2C.h>
#include "registers.h"


using namespace std;

void setup_bypass();
void run_bypass();


int main (int argc, char **argv){
	// Setup I2C communication
    fd = wiringPiI2CSetup(DEVICE_ID);
    if (fd == -1) {
        std::cout << "Failed to init I2C communication." << endl;
        return -1;
    }
	cout << "I2C communication successfully setup." << endl;
	
	cout << wiringPiI2CReadReg8(fd, WHO_AM_I) << endl;
	setup_bypass();
	run_bypass();
}

void setup_bypass(){
	
}

void run_bypass(){
	while(1){
	cout 
		<< " X: " << wiringPiI2CReadReg8(fd, OUT_X_H)
		<< " Y: " << wiringPiI2CReadReg8(fd, OUT_Y_H)
		<< " Z: " << wiringPiI2CReadReg8(fd, OUT_Z_H)
		<< endl;
	}
}
