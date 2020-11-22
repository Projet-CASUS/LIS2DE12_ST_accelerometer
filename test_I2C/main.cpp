//g++ main.cpp registers.cpp -o LIS2DE12_Driver -lwiringPi

#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPiI2C.h>
#include "registers.h"


using namespace std;

bool setup();
void run();
Registers reg;


int main (int argc, char **argv){
	// Setup I2C communication
	
    if (reg.get_fd() == -1) {
        cout << "Failed to initiate I2C communication." << endl;
		//delete reg
        return -1;
    }
	cout << "I2C communication successfully initiated." << endl;
	
	if(!setup()){
		cout << "Failed to setup I2C communication" << endl;
	}
	cout << "I2C communication successfully setup." << endl;
	
	cout << reg.read(WHO_AM_I) << endl;
	//run();
	return 0;
}

bool setup(){
	return reg.setup_CTRL_REG1(0x1F);
}

void run(){
	while(1){
	cout 
		<< " X: " << reg.read(OUT_X_H)
		<< " Y: " << reg.read(OUT_Y_H)
		<< " Z: " << reg.read(OUT_Z_H)
		<< endl;
	}
}
