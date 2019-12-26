/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		LPC546XX�������ļ�
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴LPC546XX_config.h�ļ��ڰ汾�궨��
 * @Software 		IAR 7.8 or MDK 5.24a
 * @Target core		LPC54606J512BD100
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2018-05-24
 ********************************************************************************************************************/

#ifndef _LPC546XX_config_h
#define _LPC546XX_config_h

//-------------------------------------------------------------------------------------------------------------------
//  ��ǰ�汾��
//  ����˴��汾����version.txt�ļ��汾��һ�£���version.txt�ļ�Ϊ׼
//-------------------------------------------------------------------------------------------------------------------
#define SEEKFREE_LPC546XX_VERSION   0X125


//-------------------------------------------------------------------------------------------------------------------
//  LPC546XX_CLOSE_ISP Ϊ 0   ���ر�ISP
//  LPC546XX_CLOSE_ISP Ϊ 1   ���ùر�ISP,ֻҪ����һ�γ��������ùرգ������Ҫʹ��ISP��ֻ�ܸ���оƬ
//-------------------------------------------------------------------------------------------------------------------
#define LPC546XX_CLOSE_ISP          0



//-------------------------------------------------------------------------------------------------------------------
//  LPC546XX_PLL_CLOCK_SOURCE Ϊ 0   ʹ���ڲ�12M����
//  LPC546XX_PLL_CLOCK_SOURCE Ϊ 1   ʹ���ⲿ12M����
//-------------------------------------------------------------------------------------------------------------------
#define LPC546XX_PLL_CLOCK_SOURCE   1
    
//-------------------------------------------------------------------------------------------------------------------
//  LPC546XX_MAIN_CLOCK Ϊ 0         �ں�Ƶ�� 180M  ��׼Ƶ��
//  LPC546XX_MAIN_CLOCK Ϊ 1         �ں�Ƶ�� 200M  ��Ƶ�з��գ������ге�һ�к��
//  LPC546XX_MAIN_CLOCK Ϊ 2         �ں�Ƶ�� 210M  ��Ƶ�з��գ������ге�һ�к��
//-------------------------------------------------------------------------------------------------------------------
#define LPC546XX_MAIN_CLOCK         0

//-------------------------------------------------------------------------------------------------------------------
//  CLK_OUT Ϊ 0                     ��ͨ��P026���main_clk/200ʱ��
//  CLK_OUT Ϊ 1                     ͨ��P026���main_clk/200ʱ�ӣ�P026�����Ƶ�ʳ�200����main_clkƵ��
//-------------------------------------------------------------------------------------------------------------------
#define CLK_OUT                     0


//-------------------------------------------------------------------------------------------------------------------
//  PRINTF Ϊ 0                      ��ʹ��printf���ڴ�ӡ�����������������Ϣ���򲻻��ʼ����Ӧ����
//  PRINTF Ϊ 1                      ʹ��printf���ڴ�ӡ���������������Ϣ������ʼ����Ӧ���ڣ��мǶ���Ϊ1��֮��Ҫ���ֶ���ʼ������
//-------------------------------------------------------------------------------------------------------------------
#define PRINTF                      0


#if(1 == PRINTF)

//-------------------------------------------------------------------------------------------------------------------
//printf���ڴ�ӡ������ʹ�õĴ��ڡ����ڲ����ʡ��������ź궨��
//-------------------------------------------------------------------------------------------------------------------
#define DEBUG_UART                  USART_0
#define DEBUG_UART_BAUD             115200
#define DEBUG_UART_TX_PIN           UART0_TX_A25
#define DEBUG_UART_RX_PIN           UART0_RX_A24
#endif

//-------------------------------------------------------------------------------------------------------------------
//  DEBUG_ASSERT Ϊ 0                ���Եײ㺯���ĵ��ý��в����жϣ�����ͦ�߳������е�Ч��
//  DEBUG_ASSERT Ϊ 1                �Եײ㺯���ĵ��ý��в����жϣ��������˴���ĺ�������assert_failed���� ָ�����������ļ���������
//                                   ������Ϣ��ҪPRINTF�궨��Ϊ1�����ô������
//-------------------------------------------------------------------------------------------------------------------
#define DEBUG_ASSERT                1




//----LED����----	 
#define  SET_OLED_SCL_PIN   SPI4_SCK_B19
#define  SET_OLED_SDA_PIN   SPI4_MOSI_B21
#define  SET_OLED_RST_PIN   B1
#define  SET_OLED_DC_PIN    B2
#define  SET_OLED_CS_PIN    SPI4_CS0_B9
#define  SET_OLED_SDA_IN    SPI4_MISO_B20
#define  SET_OLED_SPI       SPI_4

//----MPU6050ģ��IIC����-----
#define SET_MPU6050_SCL_PIN      B12
#define SET_MPU6050_SDA_PIN      B3

//���
#define AD_CH_L_1				ADC_CH5_A31 
#define AD_CH_L__				ADC_CH6_B0    
#define AD_CH_M_1				ADC_CH3_A15   
#define AD_CH_R__               ADC_CH4_A16  
#define AD_CH_R_1				ADC_CH0_A10
  

#define SET_MCP41_CS0           B23  
#define SET_MCP41_CS1           B22
#define SET_MCP41_CS2           B10
#define SET_MCP41_CS3           B9
#define SET_MCP41_CS4           B8
#define SET_MCP41_CS5           0xff
#define SET_MCP41_CS6           0xff
#define SET_MCP41_CS7           0xff

#define SET_MCP41_P0           AD_CH_L_1
#define SET_MCP41_P1           AD_CH_L__
#define SET_MCP41_P2           AD_CH_M_1
#define SET_MCP41_P3           AD_CH_R__
#define SET_MCP41_P4           AD_CH_R_1
#define SET_MCP41_P5           0xff
#define SET_MCP41_P6           0xff
#define SET_MCP41_P7           0xff

//----����----
#define Button_Up    A18
#define Button_Down  B4
#define Button_Left  B13
#define Button_Right B7
#define Button_Mid   B11

//----���뿪��----
#define Switch_1 B15	//��
#define Switch_2 B14	//��
#define Switch_3 A17	//���ߵ���ʹ��
#define Switch_4 B17	//���У׼

//----������----
#define Beep   A22

//���
#define Servo  TIMER4_PWMCH0_A6

//���PWM

#define PWM_CH_L_Z			SCT0_OUT7_A28
#define PWM_CH_L_F			SCT0_OUT6_A27
#define PWM_CH_R_Z			SCT0_OUT8_A29
#define PWM_CH_R_F			SCT0_OUT5_A26



//������
#define CODER_L         TIMER3_COUNT0_A4
#define CODER_R         TIMER2_COUNT0_A24
#define CODER_DIR_L     A5
#define CODER_DIR_R     A25

//������
#define SONIC_Trig	B3
#define SONIC_Echo	B1

//����
#define Bluetooth_UART     USART_3
#define Bluetooth_UART_TXD UART3_TX_A2
#define Bluetooth_UART_RXD UART3_RX_A3

#endif
