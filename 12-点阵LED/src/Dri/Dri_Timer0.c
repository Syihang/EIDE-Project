#include "Dri_Timer0.h"
#include <STC89C5xRC.H>
#include <Com_Util.h>
#include <STDIO.H>

#define MAX_CALLBACK_COUNT 4
static Timer0_Callback s_callback[4];
u8 i;
void Dri_Timer0_Init()
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

    // 5. ��ʼ������ָ������
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        s_callback[i] = NULL;
    }
}

bit Dri_Timer0_RegisterCallback(Timer0_Callback callback)
{
    // ȷ�������ظ�ע��
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        // �������ѱ�ע��,�򷵻سɹ�
        if (s_callback[i] == callback) return 1;
    }

    // Ѱ�ҿ�λ
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        // ������ָ�������п�λ,��ע��
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

// ��ʱ��0�жϷ�����
void Dri_Timer0_Handler() interrupt 1
{
    // ����װ�س�ֵ
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 2.��Ѳ����ָ������
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_callback[i] != NULL) {
            s_callback[i]();
        }
    }
}