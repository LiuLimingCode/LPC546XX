/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		����
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴LPC546XX_config.h�ļ��ڰ汾�궨��
 * @Software 		IAR 7.8 or MDK 5.24a
 * @Target core		LPC54606J512BD100
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2018-05-24
 ********************************************************************************************************************/


#include "common.h"
#include "assert.h"
#include "LPC546XX_config.h"
#include "LPC546XX_pll.h"
#include "LPC546XX_config.h"
#include "LPC546XX_uart.h"
#include "SYSTEM_LPC54606.h"

//��ɵ�LPC�ײ���������˺ܶ໨�ڵ��쳣��������,�Ҷ��ⲿ�����˵��޸�
//assert.c�е�assert_failed�����ǵ��ײ����ʱ,����Ĳ�������ʱ�Զ�����
//system_LPC54606.c�е�HardFault_Handler�ж�һ���ǳ�������Խ��,����ָ���������ʱ�Զ�����
//��LPC546XX_config.h����������Ҫ�ĺ��Ӱ���������,����˽�һ��
//��PRINTF����������ô��ڴ�ӡ������Ϣ��ð������д0.����ײ���ڿ�����ʱ���ʼ��DEBUG_UART����,��Դ��ڵ�����ʹ�����Ӱ��
//��DEBUG_ASSERT�������Ҫ�ײ����������Ƿ���ȷ��ð������д0,������΢��΢�ӿ����������ٶ�
//���⵱ϵͳ���������ʱ��,�ײ����������while(1);����,��ʵ��������̫��,����ǵ����Ĺ�����,������ռ�ձȳ��ȥ
//�����Ҽ�����SystemFailed()����,���������е�assert_failed������HardFault_Handler������ʱ,���Զ�����SystemFailed()����
void SystemFailed(void)
{
	//ϵͳ������������,�������Լ��Ľ������,���罫��������PWMռ�ձ�ȫ����Ϊ0
	while(1);
}

void assert_failed(int8 *file, int32 line)
{
#if(1 == PRINTF)
	//����ԭ����ɵײ���MPU6050DMP�ײ��г�ͻ,�ʰ�assert_failed�ĳɼ򻯰�
	uart_putstr(DEBUG_UART, (uint8*)"����ʧ�ܷ����� ");
	uart_putstr(DEBUG_UART, (uint8*)file);
	uart_putstr(DEBUG_UART, (uint8*)" ����ĵ� ");
	uart_putchar(DEBUG_UART, (line % 1000000) / 100000 + '0');
	uart_putchar(DEBUG_UART, (line % 100000) / 10000 + '0');
	uart_putchar(DEBUG_UART, (line % 10000) / 1000 + '0');
	uart_putchar(DEBUG_UART, (line % 1000) / 100 + '0');
	uart_putchar(DEBUG_UART, (line % 100) / 10 + '0');
	uart_putchar(DEBUG_UART, (line % 10) / 1 + '0');
	uart_putstr(DEBUG_UART, (uint8*)" �У�����������Χ��\n");
#endif
    
	SystemFailed();
    //����ʧ�ܣ�ʹ�ô������ֲ鿴��ʾ��Ϣ
}
