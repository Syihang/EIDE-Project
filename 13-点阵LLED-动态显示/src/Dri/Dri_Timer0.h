#ifndef __DRI_TIMER0_H__
#define __DRI_TIMER0_H__
typedef (*Timer0_Callback)(void);

void Dri_Timer0_Init();

/**
 * @brief ע�ᶨʱ��0�жϻص�����
 *
 * @param callback ����ָ��
 * @return bit 1:ע��ɹ� 0:ע��ʧ��
 */
bit Dri_Timer0_RegisterCallback(Timer0_Callback callback);

/**
 * @brief ȡ��ע��ص�����
 *
 * @param callback ����ָ��
 * @return bit 1:ȡ���ɹ� 0:ȡ��ʧ��
 */
bit Dri_Timer0_DeregisterCallback(Timer0_Callback callback);

#endif /* __DRI_TIMER0_H__ */