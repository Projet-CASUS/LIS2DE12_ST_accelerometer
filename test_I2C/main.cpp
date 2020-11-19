#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPiI2C.h>

#define DEVICE_ID 0x19
#define WHO_AM_I 0x0FH

int main (int argc, char **argv){
	// Setup I2C communication
    int fd = wiringPiI2CSetup(DEVICE_ID);
    if (fd == -1) {
        std::cout << "Failed to init I2C communication.\n";
        return -1;
    }
	std::cout << "I2C communication successfully setup.\n" << endl;
	
	std::cout << wiringPiI2CReadReg16(fd, WHO_AM_I);
}