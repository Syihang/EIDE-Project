#include <STC89C5xRC.H>
#define SMG_EN P36
#define LED_EN P34
typedef unsigned char u8;

// 数字0-9的段码            0    1    2    3    4    5    6    7    8    9
static u8 num_code[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

/**
 * @brief  让数码管显示一个数字
/**
 * @brief  内部方法，让数码管显示一位特定的数字
 * @param  position 数码管的位置，从0开始，0-7
 * @param  num_code 数码管显示的数字，0-9
*/
void DigitalTube_DisplaySingle(u8 position, u8 num_code){

    // 位选 P15 P14 P13
    // P1 = 0xFF; // 11 111 111
    position >>= 3;
    P1 &= 0xC7;
    P1 |= position;
    // 段选 P0
    P0 = num_code;

}

void main(){
    SMG_EN = 0;
    LED_EN = 0;
    DigitalTube_DisplaySingle(0, num_code[0]);
    while(1);
}