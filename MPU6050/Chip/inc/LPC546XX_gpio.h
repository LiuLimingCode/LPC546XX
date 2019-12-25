/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：179029047
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		GPIO
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看LPC546XX_config.h文件内版本宏定义
 * @Software 		IAR 7.8 or MDK 5.24a
 * @Target core		LPC54606J512BD100
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2018-05-24
 ********************************************************************************************************************/

#ifndef _LPC546XX_gpio_h
#define _LPC546XX_gpio_h

#include "common.h"

//-------------------------------------------------------------------------------------------------------------------
//  @brief                      定义输入输出位访问   使用方法与51类似，可以简单的操作IO口
//  @param      Y               Y取值范围 0-31
//  Sample usage:               P0(0) = 1;    P000输出高电平（前提P000设置为输出模式）      
//                              dat = P0(31); 获取P031电平（前提P031设置为输入模式）
//  @Note                       P000 = ~P000;这个操作是不能实现的  翻转IO请使用gpio_toggle函数
//-------------------------------------------------------------------------------------------------------------------  
#define P0(Y)             GPIO->B[0][Y]
#define P1(Y)             GPIO->B[1][Y]


//-------------------------------------------------------------------------------------------------------------------
//  @brief                      定义输入输出位访问   使用方法与51类似，可以简单的操作IO口
//  @param      X               X取值范围 0-1
//  @param      Y               Y取值范围 0-31
//  Sample usage:               P(0,1) = 1;   P001输出高电平（前提P001设置为输出模式）      
//                              dat = P(2,0); 获取P200电平（前提P200设置为输入模式）
//  @Note                       P000 = ~P000;这个操作是不能实现的  翻转IO请使用gpio_toggle函数
//------------------------------------------------------------------------------------------------------------------- 
#define P(X,Y)			  GPIO->B[X][Y]


//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO_PIN        定义输入输出寄存器8位(字节)地址
//  @param      X               X取值范围 0：P0   1：P1
//  @param      Y               Y取值范围 0：00-07引脚   1：08-15引脚
//                                        2：16-23引脚   3：24-31引脚
//  Sample usage:               GPIO_PIN(0,0) = 0XFF;   P000-P007八个引脚输出高电平 前提是IO设置为输出模式
//                              dat = GPIO_PIN(0,0);    获取P000-P007八个引脚电平   前提是IO设置为输入模式
//  @Note                       GPIO_PIN(0,0) = ~GPIO_PIN(0,0);这个操作是不能实现的  8位IO翻转请使用GPIO_NOT宏定义
//-------------------------------------------------------------------------------------------------------------------  
#define GPIO_PIN(X,Y)   (*((uint8 *)((uint32)(&(GPIO->PIN[X])) + Y)))



//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO_DIR        定义引脚方向寄存器8位(字节)地址
//  @param      X               X取值范围 0：P0   1：P1
//  @param      Y               Y取值范围 0：00-07引脚   1：08-15引脚
//                                        2：16-23引脚   3：24-31引脚
//  Sample usage:               GPIO_DIR(0,0) = 0XFF;    P000-P007设置为输出模式
//                              GPIO_DIR(0,0) = 0X00;    P000-P007设置为输入模式
//-------------------------------------------------------------------------------------------------------------------
#define GPIO_DIR(X,Y)   (*((uint8 *)((uint32)(&(GPIO->DIR[X])) + Y)))



//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO_SET        定义引脚置一寄存器8位(字节)地址
//  @param      X               X取值范围 0：P0   1：P1
//  @param      Y               Y取值范围 0：00-07引脚   1：08-15引脚
//                                        2：16-23引脚   3：24-31引脚
//  Sample usage:               GPIO_SET(0,0) = 0XFF;    P000-P007输出高电平 前提是IO设置为输出模式
//                              GPIO_SET(0,0) = 0X00;    无效
//-------------------------------------------------------------------------------------------------------------------
#define GPIO_SET(X,Y)   (*((uint8 *)((uint32)(&(GPIO->SET[X])) + Y)))



//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO_CLR        定义引脚清零寄存器8位(字节)地址
//  @param      X               X取值范围 0：P0   1：P1
//  @param      Y               Y取值范围 0：00-07引脚   1：08-15引脚
//                                        2：16-23引脚   3：24-31引脚
//  Sample usage:               GPIO_CLR(0,0) = 0XFF;    P000-P007输出低电平 前提是IO设置为输出模式
//                              GPIO_CLR(0,0) = 0X00;    无效
//-------------------------------------------------------------------------------------------------------------------
#define GPIO_CLR(X,Y)   (*((uint8 *)((uint32)(&(GPIO->CLR[X])) + Y)))



//-------------------------------------------------------------------------------------------------------------------
//  @brief      GPIO_NOT        定义引脚取反寄存器8位(字节)地址
//  @param      X               X取值范围 0：P0   1：P1
//  @param      Y               Y取值范围 0：00-07引脚   1：08-15引脚
//                                        2：16-23引脚   3：24-31引脚
//  Sample usage:               GPIO_NOT(0,0) = 0XFF;    P000-P007输出翻转 前提是IO设置为输出模式
//                              GPIO_NOT(0,0) = 0X00;    无效
//-------------------------------------------------------------------------------------------------------------------
#define GPIO_NOT(X,Y)   (*((uint8 *)((uint32)(&(GPIO->NOT[X])) + Y)))


void  gpio_init  (PIN_enum pin, GPIODIR_enum dir, uint8 dat, uint32 pull);
void  gpio_pull_set(PIN_enum pin, uint8 pull);
void  gpio_set   (PIN_enum pin, uint8 dat);
void  gpio_dir   (PIN_enum pin, GPIODIR_enum dir);
uint8 gpio_get   (PIN_enum pin);
void  gpio_toggle(PIN_enum pin);






#endif


