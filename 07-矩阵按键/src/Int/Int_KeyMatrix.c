#include <STC89C5xRC.H>
#include "Int_KeyMatrix.h"

u8 Int_keyMatrix_CheckSW()
{

    u8 i, j;
    u8 lines[] = {0xFE, 0xFD, 0xFB, 0xF7};
    for (i = 0; i < 4; i++) {
        P2 = lines[i];
        for (j = 0; j < 4; j++) {
            if ((P2 & (0x10 << j)) == 0x00) {
                Com_Util_Delay_1MS(10);
                if ((P2 & (0x10 << j)) == 0x00) {
                    while ((P2 & (0x10 << j)) == 0x00);
                    return 5 + j + 4 * i;
                }
            }
        }
    }

    //     // ¼ì²âµÚÒ»ÐÐ
    //     P2 = lines[i];
    //     if (P24 == 0) {
    //         Com_Util_Delay_1MS(10);
    //         if (P24 == 0) {
    //             while (P24 == 0);
    //             return 5 + 4 * i;
    //         }
    //     }

    //     if (P25 == 0) {
    //         Com_Util_Delay_1MS(10);
    //         if (P25 == 0) {
    //             while (P25 == 0);
    //             return 6 + 4 * i;
    //         }
    //     }

    //     if (P26 == 0) {
    //         Com_Util_Delay_1MS(10);
    //         if (P26 == 0) {
    //             while (P26 == 0);
    //             return 7 + 4 * i;
    //         }
    //     }

    //     if (P27 == 0) {
    //         Com_Util_Delay_1MS(10);
    //         if (P27 == 0) {
    //             while (P27 == 0);
    //             return 8 + 4 * i;
    //         }
    //     }
    // }

    return 0;
}