#include "headfile.h"

float pitch, roll, yaw;
int16 gyroX, gyroY, gyroZ;

void MRT0_DriverIRQHandler(void)
{
	if(MRT_FLAG_READ(MRT_CH0))
	{
		MRT_FLAG_CLR(MRT_CH0);
		MPU6050_DMPGetData(&pitch, &roll, &yaw);
		MPU6050_ReadData(MPU6050_GYRO_X, &gyroX);
		MPU6050_ReadData(MPU6050_GYRO_Y, &gyroY);
		MPU6050_ReadData(MPU6050_GYRO_Z, &gyroZ);
		
		OLED_P6x8Flo(0, 0, pitch, -3);
		OLED_P6x8Flo(0, 1, roll, -3);
		OLED_P6x8Flo(0, 2, yaw, -3);
		
		OLED_P6x8Int(0, 5, gyroX, 4);
		OLED_P6x8Int(0, 6, gyroY, 4);
		OLED_P6x8Int(0, 7, gyroZ, 4);
	}
}

int main(void)
{
	DisableInterrupts;
	get_clk();//��ȡʱ��Ƶ��  ��ر���
	
	OLED_Init();
	while(MPU6050_DMPInit());
	//MPU6050_Init();
	mrt_pit_init_ms(MRT_CH0, 10);
	set_irq_priority(MRT0_IRQn,0);
	
	
	//���ж������
	EnableInterrupts;
	while (1)
	{
		//�˴���д��Ҫѭ��ִ�еĴ���
		
		
		
	}
}

