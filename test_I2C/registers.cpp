#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPiI2C.h>
#include "registers.h"

using namespace std;

Registers::Registers(){
	fd = wiringPiI2CSetup(DEVICE_ID);
}

bool Registers::disable_pullup_CTRL_REG0(){
	
	return true;
}

bool Registers::enable_TEMP_CFG_REG(){
	
	return true;
}

bool Registers::setup_CTRL_REG1(int setup){
	cout << "Setting up control register #1" << endl;
	int fails = 0;
	while(1){
		write(CTRL_REG1, setup);
		int verify = read(CTRL_REG1);
		if(verify == 0x1F){
			cout << "Control registery #1 succeeded after <" << fails << "> attemps"<< endl;
			return true;
		}
		fails++;
	}
	return false;
}



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ELEMENTARY FUNCTIONS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int Registers::read(int reg){
	cout << "READING register " << reg << endl;
	int result;
	int fails = 0;
	while(1){
		result = wiringPiI2CReadReg8(fd, reg);
		if(!result == -1){
			cout << " Failed READ attemp to register" << reg << " :  " << fails << endl;
			return result;
		}
		fails++;
	}
	return -1;
}

int Registers::write(int reg, int data){
	cout << "WRITING "<< data << " to register : " << reg << endl;
	int result;
	int fails = 0;
	while(1){
		result = wiringPiI2CWriteReg8(fd, reg, data);
		cout << result << endl;
		if(!result == -1){
			cout << " Failed WRITE attemp to register" << reg << " :  " << fails << endl;
			return result;
		}
		fails++;
	}
	return -1;
}

// Built just in case... remove if not needed
int Registers::get_fd(){
	return fd;
}

