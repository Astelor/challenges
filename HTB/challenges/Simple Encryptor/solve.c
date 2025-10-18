#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 28

static uint8_t rotr8 (uint8_t n, unsigned int c){
	return  (n >> c) | (n << (8 - c));
}

int main(){
    int i;
    uint32_t seed = 0x62b1355a;
    uint8_t enc[28] = {
		0x00,0xf5,0x3e,0x12,0xc0,0xbd,0x8d,
		0x16,0xf0,0xfd,0x75,0x99,0xfa,0xef,
		0x39,0x9a,0x4b,0x96,0x21,0xa1,0x43,
		0x16,0x23,0x71,0x65,0xfb,0x27,0x4b
	};
    uint16_t random[2][SIZE];
	srand(seed);
    for(i = 0; i < SIZE ; i++){
		random[0][i] = rand();
		random[1][i] = rand();
	}
    for(i = 0; i < SIZE; i++){
        char temp = (rotr8(enc[i], (random[1][i] & 0x7)) ^ (random[0][i] & 0xff));
        printf("%c",temp);
    }
    printf("\n");
    return 0;
}