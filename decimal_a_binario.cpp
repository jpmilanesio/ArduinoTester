
#include <unistd.h>
#include <iostream>
#include <cstdlib>

int binario[32];

void decimal_a_binario_f(int decimal_parameter) {
	int prov_binario[32];
	int last_binary = 0;
	int decimal = decimal_parameter;
	int i = 0;
	while (last_binary < 4) {
		prov_binario[last_binary] = decimal % 2;
		decimal = decimal/2;
		last_binary += 1;
	}

	// AB for Actual Binary
	for (int AB = last_binary-1; AB >= 0; AB--){
		binario[i] = prov_binario[AB];
		i += 1;
		
	}

	return;

}

int main(){
	for (int i = 0; i <= 15; i++){
     std::cout << "El arreglo es: ";
     	for (int b = 0; b < 4; b++){
			decimal_a_binario_f(i);
     		std::cout << binario[b] << " ";
     	}
     std::cout << std::endl;

	usleep(1000000);
	}
	return 0;

}

