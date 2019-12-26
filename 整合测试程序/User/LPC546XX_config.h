/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：179029047
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		LPC546XX库配置文件
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看LPC546XX_config.h文件内版本宏定义
 * @Software 		IAR 7.8 or MDK 5.24a
 * @Target core		LPC54606J512BD100
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2018-05-24
 ********************************************************************************************************************/

#ifndef _LPC546XX_config_h
#define _LPC546XX_config_h

//-------------------------------------------------------------------------------------------------------------------
//  当前版本号
//  如果此处版本号与version.txt文件版本不一致，以version.txt文件为准
//-------------------------------------------------------------------------------------------------------------------
#define SEEKFREE_LPC546XX_VERSION   0X125


//-------------------------------------------------------------------------------------------------------------------
//  LPC546XX_CLOSE_ISP 为 0   不关闭ISP
//  LPC546XX_CLOSE_ISP 为 1   永久关闭ISP,只要运行一次程序则永久关闭，如果想要使用ISP就只能更换芯片
//-------------------------------------------------------------------------------------------------------------------
#define LPC546XX_CLOSE_ISP          0



//-------------------------------------------------------------------------------------------------------------------
//  LPC546XX_PLL_CLOCK_SOURCE 为 0   使用内部12M晶振
//  LPC546XX_PLL_CLOCK_SOURCE 为 1   使用外部12M晶振
//-------------------------------------------------------------------------------------------------------------------
#define LPC546XX_PLL_CLOCK_SOURCE   1
    
//-------------------------------------------------------------------------------------------------------------------
//  LPC546XX_MAIN_CLOCK 为 0         内核频率 180M  标准频率
//  LPC546XX_MAIN_CLOCK 为 1         内核频率 200M  超频有风险，需自行承担一切后果
//  LPC546XX_MAIN_CLOCK 为 2         内核频率 210M  超频有风险，需自行承担一切后果
//-------------------------------------------------------------------------------------------------------------------
#define LPC546XX_MAIN_CLOCK         0

//-------------------------------------------------------------------------------------------------------------------
//  CLK_OUT 为 0                     不通过P026输出main_clk/200时钟
//  CLK_OUT 为 1                     通过P026输出main_clk/200时钟，P026输出的频率乘200等于main_clk频率
//-------------------------------------------------------------------------------------------------------------------
#define CLK_OUT                     0


//-------------------------------------------------------------------------------------------------------------------
//  PRINTF 为 0                      不使用printf串口打印函数及不输出调试信息，则不会初始化相应串口
//  PRINTF 为 1                      使用printf串口打印函数及输出调试信息，则会初始化相应串口，切记定义为1，之后不要在手动初始化串口
//-------------------------------------------------------------------------------------------------------------------
#define PRINTF                      0


#if(1 == PRINTF)

//-------------------------------------------------------------------------------------------------------------------
//printf串口打印函数所使用的串口、串口波特率、串口引脚宏定义
//-------------------------------------------------------------------------------------------------------------------
#define DEBUG_UART                  USART_0
#define DEBUG_UART_BAUD             115200
#define DEBUG_UART_TX_PIN           UART0_TX_A25
#define DEBUG_UART_RX_PIN           UART0_RX_A24
#endif

//-------------------------------------------------------------------------------------------------------------------
//  DEBUG_ASSERT 为 0                不对底层函数的调用进行参数判断，可以挺高出现运行的效率
//  DEBUG_ASSERT 为 1                对底层函数的调用进行参数判断，若调用了错误的函数进入assert_failed函数 指出错误所在文件及所在行
//                                   错误信息需要PRINTF宏定义为1才能用串口输出
//-------------------------------------------------------------------------------------------------------------------
#define DEBUG_ASSERT                1




//----LED引脚----	 
#define  SET_OLED_SCL_PIN   SPI4_SCK_B19
#define  SET_OLED_SDA_PIN   SPI4_MOSI_B21
#define  SET_OLED_RST_PIN   B1
#define  SET_OLED_DC_PIN    B2
#define  SET_OLED_CS_PIN    SPI4_CS0_B9
#define  SET_OLED_SDA_IN    SPI4_MISO_B20
#define  SET_OLED_SPI       SPI_4

//----MPU6050模拟IIC引脚-----
#define SET_MPU6050_SCL_PIN      B12
#define SET_MPU6050_SDA_PIN      B3

//电感
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

//----按键----
#define Button_Up    A18
#define Button_Down  B4
#define Button_Left  B13
#define Button_Right B7
#define Button_Mid   B11

//----拨码开关----
#define Switch_1 B15	//无
#define Switch_2 B14	//无
#define Switch_3 A17	//无线调试使能
#define Switch_4 B17	//电磁校准

//----蜂鸣器----
#define Beep   A22

//舵机
#define Servo  TIMER4_PWMCH0_A6

//电机PWM

#define PWM_CH_L_Z			SCT0_OUT7_A28
#define PWM_CH_L_F			SCT0_OUT6_A27
#define PWM_CH_R_Z			SCT0_OUT8_A29
#define PWM_CH_R_F			SCT0_OUT5_A26



//编码器
#define CODER_L         TIMER3_COUNT0_A4
#define CODER_R         TIMER2_COUNT0_A24
#define CODER_DIR_L     A5
#define CODER_DIR_R     A25

//超声波
#define SONIC_Trig	B3
#define SONIC_Echo	B1

//串口
#define Bluetooth_UART     USART_3
#define Bluetooth_UART_TXD UART3_TX_A2
#define Bluetooth_UART_RXD UART3_RX_A3

#endif
