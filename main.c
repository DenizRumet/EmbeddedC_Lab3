#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
DDRB |= 0xFF;
DDRD &= ~0xFF;
PORTB=0x01;
int sPIND;
int sbPIND;

int32_t cnt=0;

while(1)
{



 sPIND=PIND;
 sbPIND=_BV(PIND1);




if( sPIND ==0x02){//

    if(PORTB<128){
        PORTB=PORTB*2;
}
    else{

       //_delay_us(0.75);

        PORTB=128;
        PORTB=128;
        PORTB=128;
        PORTB=128;
        PORTB=0x01;
    }

   //  _delay_ms(500);
}

else if( (sPIND && sbPIND ) == 0x00){//(PIND==0x00){

    if(PORTB>1){
        PORTB=PORTB/2;
    }
    else{
        PORTB=1;
        PORTB=1;
        PORTB=1;
        PORTB=1;
        PORTB=128;
    }

    // _delay_ms(500);

};



    while((sPIND==0x02 && cnt<105250)||(sPIND==0x00 && cnt<105250 ) ){
        sPIND=PIND;
        sbPIND=_BV(PIND1);
        cnt=cnt+1;
    };
    cnt=0;
   // _delay_ms(1);



};

return 0;
}

/* son while da eger sw0 basılı ve sw1 basılı degilse yani sPIND 2 ise ve cnt değerimiz belirlediğimiz sayının altında ise loop içerde oyalanıyor ve
250 ms sayıyor 250 ms dolunca şartlardan biri false oluyor ve while ın içinden çıkıyor. Sonra herşey tekrar başlıyor.  */





