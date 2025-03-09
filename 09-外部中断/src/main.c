#include <STC89C5xRC.H>
#include "Com_Util.h"
#define LED1 P00

void INT0_Init()
{
    // �����ж�
    EA  = 1;
    EX0 = 1;

    // ������ʽ���½��ش�����
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