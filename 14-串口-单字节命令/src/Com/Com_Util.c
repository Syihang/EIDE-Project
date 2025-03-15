#include "Com_Util.h"
#include "INTRINS.H"
void Com_Util_Delay_1MS(u16 count){
	unsigned char data i, j;
    while (count > 0) {
        count--;
        _nop_();
        i = 2;
        j = 199;
        do {
            while (--j);
        } while (--i);
    }
}