#include "Int_LEDMatrix.h"
#include "Dri_Timer0.h"
void main()
{
    u8 pic[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

    Dri_Timer0_Init();

    Int_LEDMatrix_Init();
    Int_LEDMatrix_SetPic(pic);
    while (1) {
        // Int_LEDMatrix_Refresh();
    }
}