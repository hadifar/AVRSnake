#define F_CPU 1000000uL
#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#include<stdlib.h>
#include"offstate.h"
#include"gameover.h"
#include"lcd.h"
#include"directionchange.h"

int score;

void out()
	{
	gameover();
	offstate();
	PORTC=0xFF,PORTB=0xFF;
	_delay_ms(2000);
	WDTCR|=(1<<3);// WATCHDOG TIMER ENABLE
	}


void init_interrupts()
{
cli(); //Disable Global Interrupts
GICR =(1<<INT0); //Set Bit6 of GICR to unmask INT0 interrupt.  (turn on Interrupt0)
MCUCR =(3<<ISC00); //Configuring MCUCR for Rising Edge interrupt for INT0
sei(); //Enable Global Interrupts
}


int main()
{
	
	
	TCCR0=0X01;
	
	//Initialize our ports
 	DDRC=0XFF; 
	DDRB=0XFF;
	DDRD|=(1<<PD0)|(1<<PD1)|(1<<PD7); //for our LCD display set as hight for output
	DDRD&=~((1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5)|(1<<PD6)); //for our buttons set as low for input
	DDRA=0xFF;
	
	
	//this three line initialize our LCD to display some message
	
	disp_commant(0x38); //00111000
	disp_commant(0x0C);//00001100 to make display on cursor off
	disp_commant(0x01);//CLEAR LCD
	
	gameStart();//Use Port A to display Start Message



	while(~(~(1<<PIND3)|PIND))//TO HOLD TILL RIGHT KEY PRESS
	{
		//PIND3 right
		//PIND4 UP
		//PIND5 Left
		//PIND6 down
	}
	
	
	//ba port c roshan mikonim ye satro 
	//ba port b khamosh mikonim chizaee k lazem nadarim
	
	disp_commant(0x01); // clear LCD
	lcdout(); //clear LCD and write Score :
	pos=1;
	position(); //PORTB For row & PORTC for Col
	
	//down();
	
	
	while(1)
	{
		
		no_inp();
		init_interrupts();
	}	
	
	
	return 1905;
}




ISR (INT0_vect)//INTERRUPT SUBROUTINE....
{
	sss=0;
	if((PIND&(1<<PIND3))&& status!=3)
	{
		right();
		status=1;
	}
	else if((PIND&(1<<PIND4))&& status!=4)
	{	
		up();
		status=2;
	}
	else if((PIND&(1<<PIND5))&& status!=1)
	{
		left();
		status=3;
	}
	else if((PIND&(1<<PIND6))&& status!=2)
	{
		down();
		status=4;
	}
	else
	{
		no_inp();
	}
}

//-------------------------------direction change !---------------------------------
void no_inp()
{
	switch(status)
	{
		case 1:right();break;
		case 2:up();break;
		case 3:left();break;
		case 4:down();break;
	}
}


void shift()
{
	for(i=wm_sz-1;i>0;i--)
	{
		snake[i]=snake[i-1];
	}
	snake[0]=pos;
	for(i=2;i<wm_sz;i++) //check bit himself or not
	{
		if(snake[i]==pos)
		{
			out();
			_delay_ms(10000);
		}
	}
}

void seed_change()
{
	score=0;
	if(seed==pos)
	{
		int timervalue=TCNT0;
		timervalue=timervalue/4;
		seed=timervalue+1;
		wm_sz++;
		score++;
		if(score==1)
		{
			data1update();
		}
		i=0;
	}
}


void right()
{
	sss=1;
	
	while(sss==1)
	{	
		if(pos%8==0)  //CHECK WHETHER POSITION IS RIGHT EXTREMITY
		{
			pos=((((pos/8)-1)*8)+1);
			seed_change();
			shift();
			for(u=0;u<25;u++)
			{
				for(i=0;i<wm_sz;i++)
				{
					position();
					seed1();
				}
			}
			for(off=0;off<=15;off++)
			{
				offstate();
			}
		}
				
		else
		{
			pos=pos+1;
			seed_change();
			shift();
			for(u=0;u<25;u++)
			{
				for(i=0;i<wm_sz;i++)
				{
					position();
					seed1();
				}
			}
			for(off=0;off<=15;off++)
			{
				offstate();
			}
		}
		
		status=1;
		init_interrupts();
	}
}

void up()
{
	sss=1;
	
	while(sss==1)
	{
		if(pos>0&&pos<=8)//CHECK WHETHER POSITION IS UP EXTREMITY

		{
			pos=pos+56;
			seed_change();
			shift();
			for(u=0;u<25;u++)
			{
				for(i=0;i<wm_sz;i++)
				{
					position();
					seed1();
				}
			}
			for(off=0;off<=15;off++)
			{
				offstate();
			}	
		}	
		else
		{
			pos=pos-8;
			seed_change();
			shift();
			for(u=0;u<25;u++)
			{
				for(i=0;i<wm_sz;i++)
				{
					position();
					seed1();
				}
			}
			for(off=0;off<=15;off++)
			{
				offstate();
			}	
		}
		status=2;
		init_interrupts();
	}
} 


void left()
{
	sss=1;
	
	while(sss==1)
	{
		if(((pos+7)%8)==0)//CHECK WHETHER POSITION IS LEFT EXTREMITY

		{
			pos=pos+7;
			seed_change();
			shift();
			for(u=0;u<25;u++)		
			{
				for(i=0;i<wm_sz;i++)
				{
					position();
					seed1();
				}
			}
			for(off=0;off<=15;off++)
			{
				offstate();
			}		
		}
		else
		{
			pos=pos-1;
			seed_change();
			shift();
			for(u=0;u<25;u++)
			{
				for(i=0;i<wm_sz;i++)
				{
					position();
					seed1();
				}
			}
			for(off=0;off<=15;off++)
			{
				offstate();
			}	
		}
		
		status=3;
		init_interrupts();
	}
} 

void down()
{
	sss=1;
	
	while(sss==1)
	{
		if(pos>=57&&pos<=64)//CHECK WHETHER POSITION IS DOWN EXTREMITY

		{
			pos=pos-56;
			seed_change();
			shift();
			for(u=0;u<25;u++)
			{
				for(i=0;i<wm_sz;i++)
				{
					position();
					seed1();
				}
				for(off=0;off<=15;off++)
				{
					offstate();
				}
			}
				
		}
		else
		{
			pos=pos+8;
			seed_change();
			shift();
			for(u=0;u<25;u++)
			{
				for(i=0;i<wm_sz;i++)
				{
					position();
					seed1();
				}
			}
			for(off=0;off<=15;off++)
			{
				offstate();
			}	
		}
		status=4;
		init_interrupts();
	}
}
