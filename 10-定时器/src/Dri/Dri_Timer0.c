#include "Dri_Timer0.h"
#include "Com_Util.h"
#include <STC89C5xRC.H>
#define LED P00

void DRI_Timer0_Init()
{
    // 1. 启用中断
    EA  = 1;
    ET0 = 1;

    // 2. 工作模式 C/T:0 , M1:0, M0:1
    TMOD &= 0xF0;
    TMOD |= 0x01;

    // 3. 定时初值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 4. 启动定时器
    TR0 = 1;
}

void Dir_Timer0_Hander() interrupt 1
{
    static u16 count = 0;
    // 1. 定时初值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 2. LED 闪烁
    count++;
    if (count >= 500) {
        count = 0;
        LED   = ~LED;
    }
}