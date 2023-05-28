extern void loop();
extern void setup();

#include <stdio.h>

int main (){
	setup();
	for (int i = 0; i < 10;i += 1){
		loop();
	}
	return 0;
}

void digitalWrite(int input, int H_or_L){
	if (H_or_L){
		printf("ON");	
	}else{
		printf("OFF");
	}
}

void pinMode(int port, int mode){
	return;
}