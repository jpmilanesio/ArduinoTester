#ifdef JUAN_TESTING
#include "juan_defines_binario.h"
#endif
#include <stdio.h>
#include <stdlib.h>

int led0 = 6;
int led1 = 5;
int led2 = 4;
int led3 = 3;

int* decimal_a_binario_f(int decimal_parameter) {
  int prov_binario[4];
  int last_binary = 0;
  int decimal = decimal_parameter;
  int i = 0;
  int* binario = (int*) malloc(4 * sizeof(int));


  while (last_binary < 4) {
    prov_binario[last_binary] = decimal % 2;
    decimal = decimal / 2;
    last_binary += 1;
  }


  // AB for Actual Binary
  for (int AB = last_binary - 1; AB >= 0; AB--) {
    binario[i] = prov_binario[AB];
    i += 1;
  }
  Serial.print(binario[0]);
  Serial.print(binario[1]);
  Serial.print(binario[2]);
  Serial.println(binario[3]);
  return binario;
}

void setup() {
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 15; i += 1) {
    int* binario_loop = decimal_a_binario_f(i);
    digitalWrite(led0, binario_loop[0]);
    digitalWrite(led1, binario_loop[1]);
    digitalWrite(led2, binario_loop[2]);
    digitalWrite(led3, binario_loop[3]);
    free(binario_loop);
    delay(1000);

  }
}