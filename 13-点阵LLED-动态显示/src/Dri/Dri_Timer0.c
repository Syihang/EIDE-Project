#include "Dri_Timer0.h"
#include <STC89C5xRC.H>
#include <Com_Util.h>
#include <STDIO.H>

#define MAX_CALLBACK_COUNT 4
static Timer0_Callback s_callback[4];
u8 i;
void Dri_Timer0_Init()
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

    // 5. 初始化函数指针数组
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        s_callback[i] = NULL;
    }
}

bit Dri_Timer0_RegisterCallback(Timer0_Callback callback)
{
    // 确保不会重复注册
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        // 若函数已被注册,则返回成功
        if (s_callback[i] == callback) return 1;
    }

    // 寻找空位
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        // 若函数指针数组有空位,则注册
        if (s_callback[i] == NULL) {
            s_callback[i] = callback;
            return 1;
        }
    }
    return 0;
}

bit Dri_Timer0_DeregisterCallback(Timer0_Callback callback)
{
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callback[i] == callback) {
            s_callback[i] = NULL;
            return 1;
        }
    }
    return 0;
}

// 定时器0中断服务函数
void Dri_Timer0_Handler() interrupt 1
{
    // 重新装载初值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 2.轮巡函数指针数组
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callback[i] != NULL) {
            s_callback[i]();
        }
    }
}