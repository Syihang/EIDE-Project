#include <STC89C5xRC.H>
#include <INTRINS.H>

#define LED_DP P0

typedef unsigned char u8;
typedef unsigned int u16;

// ÉùÃ÷ÑÓÊ±º¯Êý
void Delay_1MS(u16 count){
	  unsigned char data i, j;

    while (count > 0) {
        count--;
        _nop_();
        i = 2;
        j = 199;
        do {
            while (--j)
                ;
        } while (--i);
    }

}

void main(){
	u8 temp = 1;
	while(1) {
		LED_DP =~ temp;
		temp <<= 1;
		Delay_1MS(100);
		
		if(temp == 0) {
			temp = 1;
		}
	}
}