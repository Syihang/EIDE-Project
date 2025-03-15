#include <STC89C5xRC.H>
#include "Dri_UART.h"

static bit s_is_sending = 0;

void Dri_UART_Init(void)
{
    // 1.串口工作模式
    SM0 = 0;
    SM1 = 1;

    // 2.波特率
    // 2.1 SMOD
    PCON &= 0x7F;
    // 2.2 定时器1
    // 2.2.1 工作模式
    TMOD &= 0x0F;
    TMOD |= 0x20;
    // 2.2.2 初始值
    TL1 = 253;
    TH1 = 253;
    // 2.2.3 启动定时器
    TR1 = 1;

    // 3.接收数据相关配置
    REN = 1;
    SM2 = 0;

    // 4.串口中断相关配置
    EA = 1;
    ES = 1;
    RI = 0;
    TI = 0;
}

void Dri_UART_SendChar(char c)
{
    while (s_is_sending == 1);
    s_is_sending = 1;

    SBUF = c;
}

void Dri_UART_SentStr(char *str)
{
    while (*str != '\0') {
        Dri_UART_SendChar(*str);
        str++;
    }
}

void Dri_UART_Handle(void) interrupt 4
{
    if (RI == 1) // 接收中断
    {
        if (SBUF == 'A') {
            P0 = 0x00;
            Dri_UART_SentStr("OK: LED is NO");
        } else if (SBUF == 'B') {
            P0 = 0xFF;
            Dri_UART_SentStr("OK: LED is YES");
        } else {
            Dri_UART_SentStr("ERROR: Invalid command");
        }
        RI = 0; // 清接收中断标志
    }
    if (TI == 1) // 发送中断
    {
        s_is_sending = 0;
        TI           = 0; // 清发送中断标志
    }
}