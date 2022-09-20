


#include <xc.h>

void ADC_Init(void){
    ADCON1bits.PCFG = 0; //Todos los puertos analogicos
    ADCON1bits.VCFG = 0;
    ADCON0 = 0;
    ADCON2bits.ACQT = 3;
    ADCON2bits.ADCS = 5;
    ADCON2bits.ADFM = 1;
}

unsigned int ADC_Read(unsigned char ch){
    if(ch > 13){return 0;}
    ADCON0 = 0;
    ADCON0 = (ch<<2);
    ADCON0bits.ADON = 1;
    ADCON0bits.GO_DONE = 1;
    while(ADCON0bits.GO_DONE == 1);
    ADCON0bits.ADON = 0;
    return ADRES;
}