#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPiI2C.h>
#include "registers.h"

Registers::Registers(){
	fd = wiringPiI2CSetup(DEVICE_ID);
}

bool Registers::disable_pullup_CTRL_REG0(){
	
	return true
}

bool Registers::enable_TEMP_CFG_REG(){
	
	return true
}

bool Registers::setup_CTRL_REG1(int setup){
	
	return true;
}




int Registers::read(int reg){
	return wiringPiI2CReadReg8(fd, reg);
}

int Registers::write(int reg, int data){
	return wiringPiI2CWriteReg(fd, reg, data);
}

int Registers::get_fd(){
	return fd;
}

void Registers::set_fd(int FD){
	fd = FD;
}
