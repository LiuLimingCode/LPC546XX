#include "headfile.h"

uint8 Pit_flag = 0;

void MRT0_DriverIRQHandler(void)
{
	if(MRT_FLAG_READ(MRT_CH0))
	{
		MRT_FLAG_CLR(MRT_CH0);
		Pit_flag = 1;
	}
}

int main(void)
{
	int32 times1,times2,time,delay;
	DisableInterrupts;
	get_clk();//获取时钟频率  务必保留
	
	OLED_Init();
	mrt_pit_init_ms(MRT_CH0, 50);
	set_irq_priority(MRT0_IRQn,0);
	
	//总中断最后开启
	EnableInterrupts;
	
	while(1)
	{
		if(Pit_flag == 1)
		{
			Pit_flag = 0;
			delay = 0;
			times1 = MRT0->CHANNEL[MRT_CH0].TIMER;
			if(MRT0->CHANNEL[MRT_CH0].TIMER & MRT_CHANNEL_INTVAL_IVALUE_MASK)
				delay += 1;
			
			OLED_P6x8Int(0, 0, 121, 3);
			OLED_P6x8Int(0, 1, 12, 3);
			OLED_P6x8Int(0, 2, 0, 3);
			OLED_P6x8Int(0, 3, -121, 3);
			OLED_P6x8Int(0, 4, 121, -3);
			OLED_P6x8Flo(0, 5, -12222.22, -5);
			OLED_P6x8Flo(0, 6, 122222.22, 6);
			OLED_P6x8Int(64, 0, 121, 3);
			OLED_P6x8Int(64, 1, 12, 3);
			OLED_P6x8Int(64, 2, 1, 2);
			OLED_P6x8Int(64, 3, -1, 1);
			OLED_P6x8Int(64, 4, 0, 1);
			OLED_P6x8Int(64, 5, -21, 2);
			OLED_P6x8Int(64, 6, -123, 2);
			times2 = MRT0->CHANNEL[MRT_CH0].TIMER;
			if(MRT0->CHANNEL[MRT_CH0].TIMER & MRT_CHANNEL_INTVAL_IVALUE_MASK)
				delay += 1;
			time = times1 - times2;
			OLED_P6x8Flo(0, 7, (float)time/(100000 * main_clk_mhz) * 100, 2);
			OLED_P6x8Str(64, 7, "ms");
		}
	}
}

