#ifndef __DRI_UART_H__
#define __DRI_UART_H__

void Dri_UART_Init(void);

void Dri_UART_SendChar(char c);

void Dri_UART_SentStr(char *str);
#endif /* __DRI_UART_H__ */