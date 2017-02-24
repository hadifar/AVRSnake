int seed=2,i;
int sss;

int pos=1,status=1,snake[63],wm_sz=3,off,i,u,score=0;

void offstate()// FUNCTION TO MAKE DISPLAY OFF
	{
	//light off
	PORTC=0X00;
	PORTB=0X00;
	_delay_ms(1);
	}


/******FUNCTION THAT DEFINES 1 TO 64 POSITIONS OF SNAKE*******
*******(PORTC AND D VALUE IS ASSIGNED FOR EACH VALUES.)*******
*******PORT VALUES IS SELECTED ACCORDING WITH EACH INPUT******/
void position() 
{
	//light up 
	switch(snake[i])
	{
		case 1:PORTC=0x01,PORTB=0xFE;break;
		case 2:PORTC=0x02,PORTB=0xFE;break;
		case 3:PORTC=0x04,PORTB=0xFE;break;
		case 4:PORTC=0x08,PORTB=0xFE;break;
		case 5:PORTC=0x10,PORTB=0xFE;break;
		case 6:PORTC=0x20,PORTB=0xFE;break;
		case 7:PORTC=0x40,PORTB=0xFE;break;
		case 8:PORTC=0x80,PORTB=0xFE;break;
		
		case 9:PORTC=0x01,PORTB=0xFD;break;
		case 10:PORTC=0x02,PORTB=0xFD;break;
		case 11:PORTC=0x04,PORTB=0xFD;break;
		case 12:PORTC=0x08,PORTB=0xFD;break;
		case 13:PORTC=0x10,PORTB=0xFD;break;
		case 14:PORTC=0x20,PORTB=0xFD;break;
		case 15:PORTC=0x40,PORTB=0xFD;break;
		case 16:PORTC=0x80,PORTB=0xFD;break;
		
		case 17:PORTC=0x01,PORTB=0xFB;break;
		case 18:PORTC=0x02,PORTB=0xFB;break;
		case 19:PORTC=0x04,PORTB=0xFB;break;
		case 20:PORTC=0x08,PORTB=0xFB;break;
		case 21:PORTC=0x10,PORTB=0xFB;break;
		case 22:PORTC=0x20,PORTB=0xFB;break;
		case 23:PORTC=0x40,PORTB=0xFB;break;
		case 24:PORTC=0x80,PORTB=0xFB;break;
		
		case 25:PORTC=0x01,PORTB=0xF7;break;
		case 26:PORTC=0x02,PORTB=0xF7;break;
		case 27:PORTC=0x04,PORTB=0xF7;break;
		case 28:PORTC=0x08,PORTB=0xF7;break;
		case 29:PORTC=0x10,PORTB=0xF7;break;
		case 30:PORTC=0x20,PORTB=0xF7;break;
		case 31:PORTC=0x40,PORTB=0xF7;break;
		case 32:PORTC=0x80,PORTB=0xF7;break;
		
		case 33:PORTC=0x01,PORTB=0xEF;break;
		case 34:PORTC=0x02,PORTB=0xEF;break;
		case 35:PORTC=0x04,PORTB=0xEF;break;
		case 36:PORTC=0x08,PORTB=0xEF;break;
		case 37:PORTC=0x10,PORTB=0xEF;break;
		case 38:PORTC=0x20,PORTB=0xEF;break;
		case 39:PORTC=0x40,PORTB=0xEF;break;
		case 40:PORTC=0x80,PORTB=0xEF;break;
		
		case 41:PORTC=0x01,PORTB=0xDF;break;
		case 42:PORTC=0x02,PORTB=0xDF;break;
		case 43:PORTC=0x04,PORTB=0xDF;break;
		case 44:PORTC=0x08,PORTB=0xDF;break;
		case 45:PORTC=0x10,PORTB=0xDF;break;
		case 46:PORTC=0x20,PORTB=0xDF;break;
		case 47:PORTC=0x40,PORTB=0xDF;break;
		case 48:PORTC=0x80,PORTB=0xDF;break;
		
		case 49:PORTC=0x01,PORTB=0xBF;break;
		case 50:PORTC=0x02,PORTB=0xBF;break;
		case 51:PORTC=0x04,PORTB=0xBF;break;
		case 52:PORTC=0x08,PORTB=0xBF;break;
		case 53:PORTC=0x10,PORTB=0xBF;break;
		case 54:PORTC=0x20,PORTB=0xBF;break;
		case 55:PORTC=0x40,PORTB=0xBF;break;
		case 56:PORTC=0x80,PORTB=0xBF;break;
		
		case 57:PORTC=0x01,PORTB=0x7F;break;
		case 58:PORTC=0x02,PORTB=0x7F;break;
		case 59:PORTC=0x04,PORTB=0x7F;break;
		case 60:PORTC=0x08,PORTB=0x7F;break;
		case 61:PORTC=0x10,PORTB=0x7F;break;
		case 62:PORTC=0x20,PORTB=0x7F;break;
		case 63:PORTC=0x40,PORTB=0x7F;break;
		case 64:PORTC=0x80,PORTB=0x7F;break;
	}
	_delay_ms(1);
	offstate(); 
}	


void seed1()
{
	switch(seed)
	{
		case 1:PORTC=0x01,PORTB=0xFE;break;
		case 2:PORTC=0x02,PORTB=0xFE;break;
		case 3:PORTC=0x04,PORTB=0xFE;break;
		case 4:PORTC=0x08,PORTB=0xFE;break;
		case 5:PORTC=0x10,PORTB=0xFE;break;
		case 6:PORTC=0x20,PORTB=0xFE;break;
		case 7:PORTC=0x40,PORTB=0xFE;break;
		case 8:PORTC=0x80,PORTB=0xFE;break;
		
		case 9:PORTC=0x01,PORTB=0xFD;break;
		case 10:PORTC=0x02,PORTB=0xFD;break;
		case 11:PORTC=0x04,PORTB=0xFD;break;
		case 12:PORTC=0x08,PORTB=0xFD;break;
		case 13:PORTC=0x10,PORTB=0xFD;break;
		case 14:PORTC=0x20,PORTB=0xFD;break;
		case 15:PORTC=0x40,PORTB=0xFD;break;
		case 16:PORTC=0x80,PORTB=0xFD;break;
		
		case 17:PORTC=0x01,PORTB=0xFB;break;
		case 18:PORTC=0x02,PORTB=0xFB;break;
		case 19:PORTC=0x04,PORTB=0xFB;break;
		case 20:PORTC=0x08,PORTB=0xFB;break;
		case 21:PORTC=0x10,PORTB=0xFB;break;
		case 22:PORTC=0x20,PORTB=0xFB;break;
		case 23:PORTC=0x40,PORTB=0xFB;break;
		case 24:PORTC=0x80,PORTB=0xFB;break;
		
		case 25:PORTC=0x01,PORTB=0xF7;break;
		case 26:PORTC=0x02,PORTB=0xF7;break;
		case 27:PORTC=0x04,PORTB=0xF7;break;
		case 28:PORTC=0x08,PORTB=0xF7;break;
		case 29:PORTC=0x10,PORTB=0xF7;break;
		case 30:PORTC=0x20,PORTB=0xF7;break;
		case 31:PORTC=0x40,PORTB=0xF7;break;
		case 32:PORTC=0x80,PORTB=0xF7;break;
		
		case 33:PORTC=0x01,PORTB=0xEF;break;
		case 34:PORTC=0x02,PORTB=0xEF;break;
		case 35:PORTC=0x04,PORTB=0xEF;break;
		case 36:PORTC=0x08,PORTB=0xEF;break;
		case 37:PORTC=0x10,PORTB=0xEF;break;
		case 38:PORTC=0x20,PORTB=0xEF;break;
		case 39:PORTC=0x40,PORTB=0xEF;break;
		case 40:PORTC=0x80,PORTB=0xEF;break;
		
		case 41:PORTC=0x01,PORTB=0xDF;break;
		case 42:PORTC=0x02,PORTB=0xDF;break;
		case 43:PORTC=0x04,PORTB=0xDF;break;
		case 44:PORTC=0x08,PORTB=0xDF;break;
		case 45:PORTC=0x10,PORTB=0xDF;break;
		case 46:PORTC=0x20,PORTB=0xDF;break;
		case 47:PORTC=0x40,PORTB=0xDF;break;
		case 48:PORTC=0x80,PORTB=0xDF;break;
		
		case 49:PORTC=0x01,PORTB=0xBF;break;
		case 50:PORTC=0x02,PORTB=0xBF;break;
		case 51:PORTC=0x04,PORTB=0xBF;break;
		case 52:PORTC=0x08,PORTB=0xBF;break;
		case 53:PORTC=0x10,PORTB=0xBF;break;
		case 54:PORTC=0x20,PORTB=0xBF;break;
		case 55:PORTC=0x40,PORTB=0xBF;break;
		case 56:PORTC=0x80,PORTB=0xBF;break;
		
		case 57:PORTC=0x01,PORTB=0x7F;break;
		case 58:PORTC=0x02,PORTB=0x7F;break;
		case 59:PORTC=0x04,PORTB=0x7F;break;
		case 60:PORTC=0x08,PORTB=0x7F;break;
		case 61:PORTC=0x10,PORTB=0x7F;break;
		case 62:PORTC=0x20,PORTB=0x7F;break;
		case 63:PORTC=0x40,PORTB=0x7F;break;
		case 64:PORTC=0x80,PORTB=0x7F;break;
		}
	_delay_ms(1);
	offstate(); 
}


