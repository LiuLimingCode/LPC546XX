 /*!
 * @�ļ�       mcp41.h
 * @����       mcp41���ֵ�λ������ʵ��
 * @����       ������
 * @���ʱ��   2019-12
 */
 
#ifndef __LPC546XX_MCP41_H
#define __LPC546XX_MCP41_H

#include "headfile.h"

/****************** SPI����ѡ�� ******************/
#define MCP41_SCL_Pin    A21
#define MCP41_SDA_Pin    A20

/****************** Ƭѡ����ѡ�� ******************/
#define MCP41_CS0       B23  
#define MCP41_CS1       B22
#define MCP41_CS2       B10
#define MCP41_CS3       B9
#define MCP41_CS4       B8
#define MCP41_CS5       0xff
#define MCP41_CS6       0xff
#define MCP41_CS7       0xff

/****************** ADCͨ��ѡ�� ******************/
#define MCP41_P0       ADC_CH6_B0
#define MCP41_P1       ADC_CH6_B0
#define MCP41_P2       ADC_CH6_B0
#define MCP41_P3       ADC_CH6_B0
#define MCP41_P4       ADC_CH6_B0
#define MCP41_P5       0xff
#define MCP41_P6       0xff
#define MCP41_P7       0xff

void MCP41_Init(void);
void MCP41_SetCmd(uint8 Set_Num ,uint8 data);
uint8 MCP41_SetValue(uint8 Set_Num, uint8 Ask_Value);

#endif
