#include <STC89C5xRC.H>
#include <INTRINS.H>
#define SMG_EN P36
#define LED_EN P34
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

// 数字0-9的段码            0    1     2     3      4     5     6     7     8    9
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
    P0 = 0x00;

    position <<= 3;
    P1 &= 0xC7;
    P1 |= position;

    // 段选 P0
    P0 = num_code;
    // P0 = 0x00;

}

// 延时函数
void Delay_1MS(u16 count){
	unsigned char data i, j;

    while (count > 0) {
        count--;
        _nop_();
        i = 2;
        j = 199;
        do {
            while (--j);
        } while (--i);
    }

}


// 显示指定数字
void DigitalTube_DisplayNum(u32 num){
	u8 i = 0, j = 0;
    u8 num_arr[8];

    if(num == 0) {
        num_arr[0] = 0;
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
        }
        DigitalTube_DisplaySingle(7 - j, num_code[num_arr[j]]);
         Delay_1MS(1); 
    }

}
void main(){
    SMG_EN = 0;
    LED_EN = 0;
    // DigitalTube_DisplaySingle(0, num_code[9]);
    // while(1){
    //     Delay_1MS(5);
    //     DigitalTube_DisplaySingle(0, num_code[1]);
    //     Delay_1MS(5);
    //     DigitalTube_DisplaySingle(1, num_code[2]);
    //     Delay_1MS(5);
    //     DigitalTube_DisplaySingle(2, num_code[3]);
    // }

    DigitalTube_DisplayNum(12345678);
}