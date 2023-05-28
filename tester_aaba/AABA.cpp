#ifdef JUAN_TESTING
#include "aaba_defines.h"
#endif

#include <stdio.h>
#include <stdlib.h>

#define COLLECTING_FIRST_A 0
#define COLLECTING_SECOND_A 1
#define COLLECTING_B 2
#define COLLECTING_THIRD_A 3
#define SUCCES 4
#define A 5
#define B 6
#define BUTTON_A 10
#define BUTTON_B 9

int input_button_a = 0;
int input_button_b = 0;
int fsm_state;

void setup() {
  delay(300);
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  fsm_state = COLLECTING_FIRST_A;

}

void loop() {

}

int fsm_AABA_buttons(int state, int AorB) {
  if (state == COLLECTING_FIRST_A) {
    if (AorB == A) {
      return COLLECTING_SECOND_A;
    } else {
      return COLLECTING_FIRST_A;
    }
  } else if (state == COLLECTING_SECOND_A) {
    if (AorB == A) {
      return COLLECTING_B;
    } else {
      return COLLECTING_FIRST_A;
    }
  } else if (state == COLLECTING_B) {
    if (AorB == B) {
      return COLLECTING_THIRD_A;
    } else {
      return COLLECTING_FIRST_A;
    }
  } else if (state == COLLECTING_THIRD_A) {
    if (AorB == A) {
      return SUCCES;
    } else {
      return COLLECTING_FIRST_A;
    }
  } else {
    return COLLECTING_FIRST_A;
  }
}


