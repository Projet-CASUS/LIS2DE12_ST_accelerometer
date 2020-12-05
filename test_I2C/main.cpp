//g++ main.cpp registers.cpp -o LIS2DE12_Driver -lwiringPi

#include <iostream>
#include <bitset>
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
	//setup();
	int a;
	int fails = 0;
	while(a==-1){
		a = reg.write(CTRL_REG1, 0b01111111);
		fails++;
	}
	bitset<8> x(a);
	cout << x << " FAILS : " << fails << endl;
	
	run();
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
	
	// Set the control register #1
	if(!reg.setup_CTRL_REG1(0x1F)){return false;}
	
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

