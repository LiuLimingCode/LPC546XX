/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴LPC546XX_config.h�ļ��ڰ汾�궨��
 * @Software 		IAR 7.8 or MDK 5.24a
 * @Target core		LPC54606J512BD100
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2018-05-24
 ********************************************************************************************************************/

/*
�ӿڶ��壺

����ͷ             ��Ƭ���ӿ�
D0-D7���ݿ�        B24 B25 B26 B27 B28 B29 B30 B31
SDA                A9   F5
SCL                A8
���ź�             A0
�����ź�           A1

�˷�
ͨ��1              A10
ͨ��2              A15
ͨ��3              A16
ͨ��4              A31
ͨ��5              B0
ͨ��6              A23

IIC                
SDA                A13 F1
SCL                A14

���PWM
PWM1               A18   T1
PWM2               A20
PWM3               B4   T2
PWM4               B5

������         
LSB1               A2   T0
DIR                A3
LSB2               A4  T3
DIR                A5


���   
PWM                A6 T4

OLED/TFT
SCK                B19
MOSI               B21
MISO               B20      Һ��û���������  ����SPI��ռ���������
CS                 B9 F4

DC                 B10
RES                B8
BL                 B7

UART                
RX                 A24
TX                 A25  

����   
B1 B2 B3 B23���⽻��  


���뿪��		
B17  B22���⽻��  

NRF
B15 B14 A29 A22 A21 A17	���⽻��  

*/


//���µĹ��̻��߹����ƶ���λ�����ִ�����²���
//��һ�� �ر��������д򿪵��ļ�
//�ڶ��� project  clean  �ȴ��·�����������

#include "headfile.h"

void All_Init(void);
void Menu_Set(void);

int main(void)
{   
	get_clk();//��һ�����Ҫд
	DisableInterrupts;

	All_Init();
	
	EnableInterrupts;	
	
	while(1)
	{
		if(mt9v032_finish_flag)
		{
			mt9v032_finish_flag = 0;
			Threshold_Value=OSTUThreshold((uint8 *)image, COL,ROW);//���ɷ������ֵ �Ѿ����Ż� ʱ��ԼΪ1ms
			GrayscaleToBinary((uint8 *)image, (uint8 *)CameraBinary,Threshold_Value, ROW*COL);//��ֵ��
					  
		}
		Oledshow();
		UI_Send();
	}
}

void All_Init(void)
{
		OLED_Init();
/*----------------------------����--------------------------------*/
	gpio_init(Button_Up, GPI, 1,PULLUP);
	gpio_init(Button_Down, GPI, 1,PULLUP);
 	gpio_init(Button_Left, GPI, 1,PULLUP);
	gpio_init(Button_Right, GPI, 1,PULLUP);  
	gpio_init(Button_Mid, GPI, 1,PULLUP);	
/*----------------------------��������ʼ��------------------------------*/
	ctimer_count_init(CODER_L);	
	ctimer_count_init(CODER_R);
	gpio_init(CODER_DIR_L, GPI, 0,PULLDOWN);
	gpio_init(CODER_DIR_R, GPI, 0,PULLDOWN);
  camera_init();  //��ʼ������ͷ  û������ͷһ��Ҫע�͵�
/*----------------------------�����ʼ��-------------------------------*/
	sct_pwm_init(PWM_CH_L_Z, 12500, 0);
	sct_pwm_init(PWM_CH_L_F, 12500, 0);
  sct_pwm_init(PWM_CH_R_Z, 12500, 0);
	sct_pwm_init(PWM_CH_R_F, 12500, 0); 
/*----------------------------�����ʼ��-------------------------------*/ 
	ctimer_pwm_init(Servo, 100, 500);
	
	eeprom_init();
	
	Menu_Set();
	
	Correct_Sensor();
	while(MPU6050_DMPInit());	//û��������һ��Ҫע�͵�
	
	/*---------------------------��ʱ���ж�--------------------------------*/
	mrt_pit_init_ms(MRT_CH0,10);  //�ص�ȥ����ʱ���жϷ�������Ķ���
	uart_init(USART_3, 115200, UART3_TX_A2, UART3_RX_A3);
	enable_irq(FLEXCOMM3_IRQn);
}

void Menu_Set(void)
{
	Menu menu = {0};
	
	menu[0].UintTitle = "MOTOR_L";
	menu[0].VariableAddr[0] = &Left_motor_pid.P;
	menu[0].VariableName[0] = "L_P";
	menu[0].VariableType[0] = VariableType_Float;
	menu[0].VariableAddr[1] = &Left_motor_pid.I;
	menu[0].VariableName[1] = "L_I";
	menu[0].VariableType[1] = VariableType_Float;

	menu[1].UintTitle = "MOTOR_R";
	menu[1].VariableAddr[0] = &Right_motor_pid.P;
	menu[1].VariableName[0] = "L_P";
	menu[1].VariableType[0] = VariableType_Float;
	menu[1].VariableAddr[1] = &Right_motor_pid.I;
	menu[1].VariableName[1] = "L_I";
	menu[1].VariableType[1] = VariableType_Float;
	
	
	Menu_Init(menu);                              //��ʼ���˵�,�ڵ��øú���ǰ,��ȷ���ⲿ��Դ(GPIO,�ⲿ�洢��,�ⲿ��ʾ��)�ĳ�ʼ��
	while(!Menu_Work()) systick_delay_ms(200);    //�˵�ÿ200ms����һ�Σ��������Ƿ��¡��رղ˵���ѡ��󣨺�������0��������ѭ��
}

