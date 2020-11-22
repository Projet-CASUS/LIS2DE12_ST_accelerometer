//g++ -o i2c_wiringpi_test main.cpp -lwiringPi

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
	
	if(setup()){
		cout << "Failed to setup I2C communication" << endl;
	}
	cout << "I2C communication successfully setup." << endl;
	
	cout << reg.read(WHO_AM_I) << endl;
	//run();
	return 0;
}

bool setup(){
	
	return 0; // success
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
