#ifdef JUAN_TESTING
#include "juan_defines.h"
#endif

#include <stdio.h>

int led = 10;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  digitalWrite(led,LOW);
}
