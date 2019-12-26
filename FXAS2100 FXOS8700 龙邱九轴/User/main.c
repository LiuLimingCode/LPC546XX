#include "headfile.h"

int16 GZ_Data, AX_Data;

int main(void)
{
	DisableInterrupts;
	get_clk();//��ȡʱ��Ƶ��  ��ر���
	
	OLED_Init();
	FXOS8700_Init();
	FXAS2100_Init();
	
	
	//���ж������
	EnableInterrupts;
	while (1)
	{
		//�˴���д��Ҫѭ��ִ�еĴ���
		
		FXAS2100_ReadData(FXAS2100_DATA_Z_GYRO, &GZ_Data);
		FXOS8700_ReadData(FXOS8700_DATA_X_ACCEL, &AX_Data);
		OLED_P6x8Int(0, 0, GZ_Data, -5);
		OLED_P6x8Int(0, 0, AX_Data, -5);
		
		systick_delay_ms(10);
		
	}
}

