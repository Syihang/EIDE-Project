#include <STC89C5xRC.H>
#include "Int_Buzzer.h"
#include "Com_Util.h"

#define BUZZER P46

void Int_Buzzer_Buzz(u16 count, u16 ms) {
    while (count--) {
        BUZZER = ~BUZZER;
        Com_Util_Delay_1MS(ms);
    }
}