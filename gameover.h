unsigned char data2[16]="0000000000000000";



void lcdout()
{
	unsigned char data1[32]="    SCORE";
	disp_commant(0x01);//CLEAR LCD	
	for(int i=0;i<16;i++)
	{
		disp_data(data1[i]);
	}

	disp_commant(0xC0);//2nd line
	for(int i=0;i<16;i++)
	{
		disp_data(data2[i]);
	}

}


void gameover()
{
	unsigned char data1[32]="       GAME               OVER";
	disp_commant(0x01);//CLEAR LCD	
	for(int i=0;i<16;i++)
	{
	
		disp_data(data1[i]);
	}

	disp_commant(0xC0);//2nd line
	for(int i=16;i<32;i++)
	{
	
		disp_data(data1[i]);
	}
}



void gameStart()
{
	unsigned char data1[32]="CLICK RIGHT KEY TO START GAME";
	disp_commant(0x01);//CLEAR LCD	
	for(int i=0;i<16;i++)
	{
	
		disp_data(data1[i]);
	}

	disp_commant(0xC0);//2nd line
	for(int i=16;i<32;i++)
	{
	
		disp_data(data1[i]);
	}	
}
