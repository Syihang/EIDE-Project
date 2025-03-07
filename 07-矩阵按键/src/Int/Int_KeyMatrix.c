#include <STC89C5xRC.H>
#include "Int_KeyMatrix.h"

u8 Int_keyMatrix_CheckSW(){

    // 检测第一行
    P2 = 0xFE;
    if (P24 == 0) {
        Com_Util_Delay_1MS(10);
        if(P24 == 0) {
            while(P24 == 0);
            return 5;
        }
    }

    if (P25 == 0) {
        Com_Util_Delay_1MS(10);
        if(P25 == 0) {
            while(P25 == 0);
            return 6;
        } 
    }

    if (P26 == 0) {
        Com_Util_Delay_1MS(10);
        if(P26 == 0) {
            while(P26 == 0);
            return 7;
        } 
    }

    if (P27 == 0) {
        Com_Util_Delay_1MS(10);
        if(P27 == 0) {
            while(P27 == 0);
            return 8; 
        }  
    }

    // 检测第二行
    P2 = 0xFD;
    if (P24 == 0) {
        Com_Util_Delay_1MS(10);
        if(P24 == 0) {
            while(P24 == 0);
            return 9;
        }
    }

    if (P25 == 0) {
        Com_Util_Delay_1MS(10);
        if(P25 == 0) {
            while(P25 == 0);
            return 10;
        }  
    }

    if (P26 == 0) {
        Com_Util_Delay_1MS(10);
        if(P26 == 0) {
            while(P26 == 0);
            return 11;
        } 
    }

    if (P27 == 0) {
        Com_Util_Delay_1MS(10);
        if(P27 == 0) {
            while(P27 == 0);
            return 12;
        } 
    }

    // 检测第三行
    P2 = 0xFB;
    if (P24 == 0) {
        Com_Util_Delay_1MS(10);
        if(P24 == 0) {
            while(P24 == 0);
            return 13;
        } 
    }

    if (P25 == 0) {
        Com_Util_Delay_1MS(10);
        if(P25 == 0) {
            while(P25 == 0);
            return 14;
        } 
    }

    if (P26 == 0) {
        Com_Util_Delay_1MS(10);
        if(P26 == 0) {
            while(P26 == 0);
            return 15;
        }  
    }

    if (P27 == 0) {
        Com_Util_Delay_1MS(10);
        if(P27 == 0) {
            while(P27 == 0);
            return 16;
        } 
    }

    // 检测第四行
    P2 = 0xF7;
    if (P24 == 0) {
        Com_Util_Delay_1MS(10);
        if(P24 == 0) {
            while(P24 == 0);
            return 17;
        }
    }

    if (P25 == 0) {
        Com_Util_Delay_1MS(10);
        if(P25 == 0) {
            while(P25 == 0);
            return 18;
        } 
    }

    if (P26 == 0) {
        Com_Util_Delay_1MS(10);
        if(P26 == 0) {
            while(P26 == 0);
            return 19;
        }  
    }

    if (P27 == 0) {
        Com_Util_Delay_1MS(10);
        if(P27 == 0) {
            while(P27 == 0);
            return 20;
        } 
    }

    return 0;

}