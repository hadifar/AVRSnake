#define RS PD0 //for LCD 
#define RW PD1
#define EN PD7

#define dataport PORTA

int index=14;

void disp_commant(unsigned char commant)
{
	dataport=commant;
	PORTD&=~(1<<RS);//set bit number Rs low
	PORTD&=~(1<<RW);
	PORTD|=(1<<EN); //set bit number En high
	_delay_ms(1);
	PORTD&=~(1<<EN);
}
void disp_data(unsigned char data)
{
	//port A
	dataport=data;
	PORTD|=(1<<RS);
	PORTD&=~(1<<RW);
	PORTD|=(1<<EN);
	_delay_ms(1);
	PORTD&=~(1<<EN);
}

void data1update()
	{


		if(score==1)
		{
		data2[index]=data2[index]+1;
		lcdout();
		}
			if(data2[index]=='9')
			{
				data2[index-1]++;
				data2[index]='0';
				lcdout();
			}
		if(data2[index-1]=='9')
			{
				data2[index-2]++;
				data2[index-1]='0';
				lcdout();
			}
}
