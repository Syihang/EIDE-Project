#include "Dri_Timer0.h"
#include "Com_Util.h"
#include <STC89C5xRC.H>
#define LED P00

void DRI_Timer0_Init()
{
    // 1. �����ж�
    EA  = 1;
    ET0 = 1;

    // 2. ����ģʽ C/T:0 , M1:0, M0:1
    TMOD &= 0xF0;
    TMOD |= 0x01;

    // 3. ��ʱ��ֵ
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 4. ������ʱ��
    TR0 = 1;
}

void Dir_Timer0_Hander() interrupt 1
{
    static u16 count = 0;
    // 1. ��ʱ��ֵ
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 2. LED ��˸
    count++;
    if (count >= 500) {
        count = 0;
        LED   = ~LED;
    }
}