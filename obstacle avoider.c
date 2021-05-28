#include<avr/io.h>
#include<util/delay.h>

void main()
{ 
 DDRD=0b00000000;           //setting part D as an input part
 DDRB=0b11111111;           //setting part B as an output part
 PORTD=0b11111111;          //pulling up all the pins of part D
 int c;
 while(1)
{
c=PIND;
 if(c==0b11111111)         //no obstacle move forward
   PORTB=0b00001010;        
   
 if(c==0b11111110)         // obstacle to right
   PORTB=0b00000110;       // turn left  
   
 if(c==0b11111101)         // obstacle at the centre
   {PORTB=0b00000101;      // go back and turn right
   
   _delay_ms(3000);
   PORTB=0b00001001;
   _delay_ms(2000);
   }
   
   if(c==0b11111100)       // obstacle at the centre and right
   
   {
    PORTB=0b00000101;       //go back and turn left
	
	_delay_ms(3000);
	PORTB=0b00000110;
	_delay_ms(2000);
}	
	if(c==0b11111011)     // obstacle to the left
	   PORTB=0b00001001;   // turn right
	
	if(c==0b11111010)      // obstacles on both sides of robot
	  { 
	    PORTB=0b0000101;    // go back and turn right
		_delay_ms(3000);
		PORTB=0b00001001;
		_delay_ms(2000);
	   }
	   
	   if(c==0b11111001)    // obstacle on centre and left
	    {
		   PORTB=0b00000101;   //go back and turn right
		   _delay_ms(3000);
		   PORTB=0b00001001;
		   _delay_ms(2000);
		 }
		 if(c==0b11111000)    //obstacle on all sides
		 
		 {
		    PORTB=0b00000101;  //u turn
			_delay_ms(3000);
			PORTB=0b00001001;
			_delay_ms(5000);
		 }
	  }}