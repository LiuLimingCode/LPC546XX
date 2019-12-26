/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：179029047
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		headfile
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看LPC546XX_config.h文件内版本宏定义
 * @Software 		IAR 7.8 or MDK 5.24a
 * @Target core		LPC54606J512BD100
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2018-05-24
 ********************************************************************************************************************/
#ifndef _headfile_h
#define _headfile_h

#include "isr.h"
#include "common.h"

#include "LPC546XX_flexcomm.h" 
#include "LPC546XX_pll.h"
#include "LPC546XX_iocon.h"
#include "LPC546XX_gpio.h"
#include "LPC546XX_uart.h"
#include "LPC546XX_systick.h"
#include "LPC546XX_gint.h"
#include "LPC546XX_adc.h"
#include "LPC546XX_pit.h"
#include "LPC546XX_ctimer.h"
#include "LPC546XX_pint.h"
#include "LPC546XX_sct.h"
#include "LPC546XX_dma.h"
#include "LPC546XX_spi.h"
#include "LPC546XX_iic.h"
#include "LPC546XX_eeprom.h"
#include "LPC546XX_mrt.h"

#include "LPC546XX_oled.h"
#include "LPC546XX_mcp41.h"
#include "LPC546XX_myspi.h"

#include "LPC546XX_mpu6050.h"
#include "LPC546XX_myiic.h"

#include "SEEKFREE_MT9V032.h"

#include "VCAN_computer.h"

#include "menu.h"
#include "ImageProcess.h"
#include "SelfBuild_control.h"
#include "SelfBuild_PID.h"
#include "SelfBuild_Electron_Calcu.h"
#include "SelfBuild_correct_sensor.h"
#endif
