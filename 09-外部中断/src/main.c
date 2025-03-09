#include <STC89C5xRC.H>
#include "Com_Util.h"
#define LED1 P00

void INT0_Init()
{
    // 启用中断
    EA  = 1;
    EX0 = 1;

    // 触发方式（下降沿触发）
    IT0 = 1;
}

void main()
{
    INT0_Init();
    while (1);
}

void INT0_Handler() interrupt 0
{
    Com_Util_Delay_1MS(10);
    if (P32 == 0) {
        LED1 = ~LED1;
    }
}