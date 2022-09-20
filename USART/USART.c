#include <xc.h>
#include "Config.h"
#include "USART.h"


void USART_Init(long BAUD){
    // Pines TX y RX 
    TRISCbits.RC6 = 0; // Pin TX -> Salida
    TRISCbits.RC7 = 1; // Pin RX -> Entrada
    // Baudios
    SPBRG = (unsigned char)(((_XTAL_FREQ/BAUD)/64)-1);
    // Configuración
    TXSTAbits.BRGH = 0; // Low speed
    TXSTAbits.SYNC = 0; // Asincrono
    RCSTAbits.SPEN = 1; // Habilitar el TX y RX
    
    // Transmisión
    TXSTAbits.TX9 = 0; // Comunicación de 8bits
    TXSTAbits.TXEN = 1; // Activar transimisión 

    // Recepción
    RCSTAbits.RC9 = 0; // Comunicación de 8bits
    RCSTAbits.CREN = 1; // Activar recepción
}

void USART_Tx(char data){
    TXREG = data;
}

void USART_write(unsigned char *data){
    while(*data != 0x00){
        USART_Tx(*data);
        data++;
    }
}

char USART_Rx(){
    if(PIR1bits.RCIF == 1){
        return RCREG;
    }
    else{
        return 0
    }
}