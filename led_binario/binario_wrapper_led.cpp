
extern void loop();
extern void setup();
extern int* decimal_a_binario_f(int decimal_parameter);

#include<iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <cassert>

void test_code(){
	int supossed_binary[16][4] = { 
		{0, 0, 0, 0},
		{0, 0, 0, 1},
	    {0, 0, 1, 0},
	    {0, 0, 1, 1},
		{0, 1, 0, 0},
		{0, 1, 0, 1},
	    {0, 1, 1, 0},
	    {0, 1, 1, 1},
	    {1, 0, 0, 0},
	    {1, 0, 0, 1},
	    {1, 0, 1, 0},
	    {1, 0, 1, 1},
	    {1, 1, 0, 0},
	    {1, 1, 0, 1},
		{1, 1, 1, 0},
	    {1, 1, 1, 1}	
	};
	
	for (int b = 0; b <= 15; b++){
	int* actual_binary = decimal_a_binario_f(b);
		for (int d = 0;d < 4; d++){
			assert(actual_binary[d] == supossed_binary[b][d]);
		}
		free(actual_binary);
	}
	return;
}	

int main (){
	test_code();
}

void digitalWrite(int input, int H_or_L){
	if (H_or_L){
    		std::cout << "ON";
	}else{
		std::cout << "OFF";
	}
}

void pinMode(int port, int mode){
	return;
}

void delay(unsigned long miliseconds){
	usleep(miliseconds*1000); // pass to microseconds
	return;
}

void delayMicroseconds(unsigned long microseconds){
	usleep(microseconds);
	return;
}

