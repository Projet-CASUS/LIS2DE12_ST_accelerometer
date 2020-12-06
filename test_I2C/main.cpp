// COMPILATION COMMAND:
// g++ main.cpp registers.cpp -o LIS2DE12_Driver -lwiringPi

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
	setup();

	//run();
	return 0;
}

bool setup(){
	//Init the device communication
    if (reg.get_fd() == -1) {
        cout << "Failed to initiate I2C communication." << endl;
		//delete regasda
        return false;
    }
	cout << "I2C communication successfully initiated." << endl;
	
	//reg.write(CTRL_REG1, 0x2F);		// DATA RATE
	//reg.write(CTRL_REG2, 0x30);		// HIGH PASS FILTERS
	//reg.write(CTRL_REG3, 0x00);		// INTERRUPTS
	//reg.write(CTRL_REG4, 0x00);		// BDU  --  +/-Xg  --  self test 
	//reg.write(CTRL_REG5, 0x00);		// FIFO ENABLE  --  [...]
	//reg.write(CTRL_REG6, 0x00);		// INTERRUPT SETUP
	
	reg.verify(WHO_AM_I, 51);
	//reg.verify(CTRL_REG1, 0x30);
	
	return true;
}

void run(){
	int fail = 0;
	int ok = 0;
	int test;
	int sample = 100;
	/*while(1){
	cout 
		<< " X: " << reg.read(OUT_X_H)
		<< " Y: " << reg.read(OUT_Y_H)
		<< " Z: " << reg.read(OUT_Z_H)
		<< endl;
	}*/
	for(int i=0; i<sample; i++){
		test = reg.read(WHO_AM_I);
		if( test == -1 || test != 51){
			fail++;
		}else{
			ok++;
		}
	}
	cout << "FAILED: " << fail << "\t\t PASS: " << ok << endl;
}

