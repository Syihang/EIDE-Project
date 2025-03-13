#include "Int_Buzzer.h"
#include "Int_Key.h"

void Start_Buzzer();
void main()
{
    Start_Buzzer();
}

void Start_Buzzer()
{
    // ¿ØÖÆLED
    while (1) {
        if (Int_Key_IsSW1Pressed()) {
            Int_Buzzer_Buzz(50, 1);
        }
        if (Int_Key_IsSW2Pressed()) {
            Int_Buzzer_Buzz(100, 1);
        }
        if (Int_Key_IsSW3Pressed()) {
            Int_Buzzer_Buzz(200, 1);
        }
        if (Int_Key_IsSW4Pressed()) {
            Int_Buzzer_Buzz(200, 2);
        }
    }
}