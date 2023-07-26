#define __ATmegaxx0__
#include <avr/io.h>
#include <avr/iom2560.h>
#include <avr/iomxx0_1.h>
#include <avr/portpins.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "Mega2560.h"

//#define turnOn(port) ( getPort(digital_to_port(port)) |= getPort(digital_to_port(port)) | (ON << getBit(port) ))
//#define turnOff(port) ( getPort(digital_to_port(port)) |= getPort(digital_to_port(port)) & ~(ON << getBit(port) ))
void turn(uint8_t port, bool onoff) {
    volatile uint8_t *out = getPort(digital_to_port(port));
    volatile uint8_t bit = getBit(port);
    if (onoff) {
        *out |= bit;
    } else {
        *out &= ~bit;
    }
}

void bitsToArray(uint8_t num, uint8_t *bitters){
    unsigned int size = sizeof(unsigned char);
    unsigned int maxPow = 1<<(size*8-1);
    int bittsArray[7] = {0,0,0,0,0,0,0};
    int i=0,j;
    for(;i<size;++i){
        for(j=0;j<8;++j){
            for(;i<size*8;++i){
                bittsArray[i] = num&maxPow ? 1 : 0;
                num = num<<1;
            }
        }
    }
    int k = 0;
    for (int i=7; i>=0;i--) {
        bitters[k++] = bittsArray[i];
    } 
}
