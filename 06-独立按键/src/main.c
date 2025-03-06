#include <STC89C5xRC.H>
// #include <pthread.h>
#include "Int_DigitalTube.h"
#include "Com_Util.h"
#include "Int_Key.h"

#define SW1 P42
#define SW2 P43
#define SW3 P32
#define SW4 P33

#define LED1 P00
#define LED2 P01
#define LED3 P02
#define LED4 P03

void Start_LED();
void Start_SMG();
void main(){

    // Start_LED();
    Start_SMG();

}


void Start_LED(){
    // 控制LED
    while(1){
        if (Int_Key_IsSW1Pressed()){
            LED1 = ~LED1;
        }
        if (Int_Key_IsSW2Pressed()){
            LED2 = ~LED2;
        }
        if (Int_Key_IsSW3Pressed()){
            LED3 = ~LED3;
        }
        if (Int_Key_IsSW4Pressed()){
            LED4 = ~LED4;
        }
    }
}

void Start_SMG(){
    // 控制数码管
    u32 num = 0;
    Int_DigitalTube_Init();
    
    while(1){
        if (Int_Key_IsSW1Pressed()){
            num++;
        }
        if (Int_Key_IsSW2Pressed()){
            if(num > 0) num--;
        }
        if (Int_Key_IsSW3Pressed()){
            num *= 2;
        }
        if (Int_Key_IsSW4Pressed()){
            num /= 2;
        }
        Int_DigitalTube_DisplayNum(num);	
    }
}