#define bande_rate 9600
#define MUBBR (F_CPU/(16UL*bande_rate))-1
char received[50];
int index=0;
void setup() {
UCSR0B=1<<RXCIE0|1<<RXEN0|1<<TXEN0;
UCSR0C=1<<UCSZ00|1<<UCSZ01;
UBRR0H=MUBBR>>8;
UBRR0L=MUBBR;
}
//ISR(USART_RX_vect)

//{
  //char received;
  //received=UDR0;
  //UDR0=received;
//}

ISR(USART_RX_vect)

{
  received[index]=UDR0;
  if(received[index]==13){
    for(int i=0;i<=index;i++){
      UDR0=received[i];
      delay(1);
    }
    index = 0;
  }else{
    index ++;
  }
}
void loop() {
}
