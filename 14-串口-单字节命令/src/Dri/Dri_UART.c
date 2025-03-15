#include <STC89C5xRC.H>
#include "Dri_UART.h"

static bit s_is_sending = 0;

void Dri_UART_Init(void)
{
    // 1.���ڹ���ģʽ
    SM0 = 0;
    SM1 = 1;

    // 2.������
    // 2.1 SMOD
    PCON &= 0x7F;
    // 2.2 ��ʱ��1
    // 2.2.1 ����ģʽ
    TMOD &= 0x0F;
    TMOD |= 0x20;
    // 2.2.2 ��ʼֵ
    TL1 = 253;
    TH1 = 253;
    // 2.2.3 ������ʱ��
    TR1 = 1;

    // 3.���������������
    REN = 1;
    SM2 = 0;

    // 4.�����ж��������
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
    if (RI == 1) // �����ж�
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
        RI = 0; // ������жϱ�־
    }
    if (TI == 1) // �����ж�
    {
        s_is_sending = 0;
        TI           = 0; // �巢���жϱ�־
    }
}