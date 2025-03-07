#include "Int_KeyMatrix.h"
#include "Int_DigitalTube.h"
void main(){
    Int_DigitalTube_Init();
    while(1){
        u8 key, num;
        key = Int_keyMatrix_CheckSW();
        if(key){
            num = key;
        }
        Int_DigitalTube_DisplayNum(num);            
    }
}