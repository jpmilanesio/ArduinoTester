extern int fsm_AABA_buttons(int state, int AorB);

#include<iostream>
#include <cstdlib>
#include <unistd.h>
#include <cassert>


#define COLLECTING_FIRST_A 0
#define COLLECTING_SECOND_A 1
#define COLLECTING_B 2
#define COLLECTING_THIRD_A 3
#define SUCCES 4
#define A 5
#define B 6

uint8_t fsm_wrapper[4] = { 'A', 'A', 'B', 'A' };
typedef struct fsm_wrapper_combinations {
	uint8_t fsm_num_str[5];
} fsm_wrapper_combs;
fsm_wrapper_combs fsm_wrapper_comb[16];

void create_posibilities() {
  uint8_t A_B_list[2] = { 'A', 'B' };
  int A_B_posibilities = 0;
  for (int d1 = 0; d1 < 2; d1 += 1) {
    for (int d2 = 0; d2 < 2; d2 += 1) {
      for (int d3 = 0; d3 < 2; d3 += 1) {
        for (int d4 = 0; d4 < 2; d4 += 1) {
          fsm_wrapper_comb[A_B_posibilities].fsm_num_str[0] = A_B_list[d1];
          fsm_wrapper_comb[A_B_posibilities].fsm_num_str[1] = A_B_list[d2];
          fsm_wrapper_comb[A_B_posibilities].fsm_num_str[2] = A_B_list[d3];
          fsm_wrapper_comb[A_B_posibilities].fsm_num_str[3] = A_B_list[d4];
          A_B_posibilities += 1;
        }
      }
    }
  }
}

bool fsm_AABA_wrapper(uint8_t A_and_B[4]) {
  int wrapper_state = COLLECTING_FIRST_A;
  for (int i = 0; i < 4; i += 1) {
    if (A_and_B[i] == 'A') {
      wrapper_state = fsm_AABA_buttons(wrapper_state, A);
    } else {
      wrapper_state = fsm_AABA_buttons(wrapper_state, B);
    }
    if (wrapper_state == SUCCES) {
      return true;
    }
  }
  return false;
}

bool check_for_AABA(uint8_t to_analize[4]) {
  if (to_analize[0] == 'A' && to_analize[1] == 'A' && to_analize[2] == 'B' && to_analize[3] == 'A') {
    return true;
  }
  return false;
}



int main(){
	create_posibilities();
	for (int i = 0; i < 16; i += 1) {
		if (check_for_AABA(fsm_wrapper_comb[i].fsm_num_str)) {
			assert(fsm_AABA_wrapper(fsm_wrapper_comb[i].fsm_num_str));
		} else {
			assert(!fsm_AABA_wrapper(fsm_wrapper_comb[i].fsm_num_str));
		}
	}

	
	return 0;
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