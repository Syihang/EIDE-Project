#include "Int_DigitalTube.h"
#include <STC89C5xRC.H>

static void Int_DigitalTube_DisplaySingle(u8 position, u8 num_code);
void Int_DigitalTube_Init(){
    // 初始化GPIO
    SMG_EN = 0;
    LED_EN = 0;
    Int_DigitalTube_DisplaySingle(7, 0x3F);
}

// 数字0-9的段码            0    1     2     3      4     5     6     7     8    9
static u8 num_code[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

static void Int_DigitalTube_DisplaySingle(u8 position, u8 num_code){

    // 位选 P15 P14 P13
    // P1 = 0xFF; // 11 111 111
    P0 = 0x00;

    position <<= 3;
    P1 &= 0xC7;
    P1 |= position;

    // 段选 P0
    P0 = num_code;
    // P0 = 0x00;

}

// 显示指定数字
void Int_DigitalTube_DisplayNum(u32 num){
	u8 i = 0, j = 0;
    u8 num_arr[8];

    if(num == 0) {
        num_arr[0] = 0;
        Int_DigitalTube_DisplaySingle(7 - j, num_code[num_arr[j]]);
        Com_Util_Delay_1MS(1); 
    }

    num %= 100000000;

    while(num > 0){
        num_arr[i] = num % 10;
        num /= 10;
        i++;
    }

    for(j = 0; ;j++){
        if(j >= i){
            j = 0;
            return;
        }
        Int_DigitalTube_DisplaySingle(7 - j, num_code[num_arr[j]]);
        Com_Util_Delay_1MS(2); 
    }
}