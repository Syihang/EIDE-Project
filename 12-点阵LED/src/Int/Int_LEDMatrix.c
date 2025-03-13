#include <STC89C5xRC.H>
#include "Int_LEDMatrix.h"
#define LED_MATRIX_EN P35
#define LED_EN        P34

#define SER           P10
#define SCK           P12
#define RCK           P11

static u8 s_buffer[8] = {0};

void Int_LEDMatrix_Init()
{
    LED_MATRIX_EN = 0;
    LED_EN        = 0;
}

void Int_LEDMatrix_SetPic(u8 *pic)
{
    u8 i;
    for (i = 0; i < 8; i++) {
        s_buffer[i] = pic[i];
    }
}

void Int_LEDMatrix_Refresh()
{
    u8 i;
    for (i = 0; i < 8; i++) {
        P0 = 0xFF;
        // 设置显示哪一行
        SER = i == 0;

        // SER = 0;

        SCK = 0;
        SCK = 1;

        RCK = 0;
        RCK = 1;
        // 设置显示的数据
        P0 = ~s_buffer[i];
        Com_Util_Delay_1MS(1);
    }
}
