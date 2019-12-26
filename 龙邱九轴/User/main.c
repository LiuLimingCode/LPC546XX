#include "headfile.h"

int16 GZ_Data, AX_Data;

int main(void)
{
	DisableInterrupts;
	get_clk();//获取时钟频率  务必保留
	
	OLED_Init();
	FXOS8700_Init();
	FXAS2100_Init();
	
	
	//总中断最后开启
	EnableInterrupts;
	while (1)
	{
		//此处编写需要循环执行的代码
		
		FXAS2100_ReadData(FXAS2100_DATA_Z_GYRO, &GZ_Data);
		FXOS8700_ReadData(FXOS8700_DATA_X_ACCEL, &AX_Data);
		OLED_P6x8Int(0, 0, GZ_Data, -5);
		OLED_P6x8Int(0, 0, AX_Data, -5);
		
		systick_delay_ms(10);
		
	}
}

