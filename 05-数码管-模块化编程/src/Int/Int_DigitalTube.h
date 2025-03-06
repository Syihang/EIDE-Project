#ifndef _INT_DIGITALTUBE_H_
#define _INT_DIGITALTUBE_H_

#include "Com_Util.h"

#define SMG_EN P36
#define LED_EN P34

void Int_DigitalTube_Init();
void Int_DigitalTube_DisplayNum(u32 num);
// void Int_DigitalTube_Set_Pos_NUm(u8 pos, u8 num);
#endif //!_INT_DIGITALTUBE_H_ 