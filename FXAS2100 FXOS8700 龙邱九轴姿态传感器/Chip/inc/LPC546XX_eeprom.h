/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		EEPROM
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴LPC546XX_config.h�ļ��ڰ汾�궨��
 * @Software 		IAR 7.8 or MDK 5.24a
 * @Target core		LPC54606J512BD100
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2018-05-24
 ********************************************************************************************************************/


#ifndef _LPC546XX_eeprom_h
#define _LPC546XX_eeprom_h

#include "common.h"

#define EEPROM_BASE_ADDRESS         (0x40108000)                    //EEPROM ����ַ
#define EEPROM_SIZE                 (0x00004000)                    //EEPROM �ֽڴ�С(8λ)
#define EEPROM_PAGE_COUNT           (128)                           //EEPROM ҳ��
#define EEPROM_PAGE_SIZE            (EEPROM_SIZE/EEPROM_PAGE_COUNT) //EEPROM ҳ�ֽڴ�С(8λ)
#define EEPROM_OFFSET_MAX           (EEPROM_SIZE/4)            		//EEPROM ƫ�������ֵ(32λ)
#define EEPROM_PROGRAM_CMD          (6)                             //EEPROM ����
#define EEPROM_INTERNAL_FREQ        (1500000)                       //EEPROM Ƶ��



//-------------------------------------------------------------------------------------------------------------------
//  @brief      EEPROM��ȡһ����(4���ֽ�)
//  @param      pageNumber   д��EEPROM��ҳ һҳ��д32��uint32��������
//  @param      offset       д��EEPROM�ĵ�ַƫ����(32λ)
//  @param      tpye         ��ȡ���ݵ�����
//  @return     ��ȡ������
//  Sample usage:            uint32 test = EEPROM_READ_WORD(0, 0, uint32);  ��ȡƫ��0  ����Ϊuint32
//  @note                    
//-------------------------------------------------------------------------------------------------------------------
#define eeprom_read_word(pageNumber, offset, type)     (*(type *)((uint32)((EEPROM_BASE_ADDRESS + ((offset<EEPROM_OFFSET_MAX?offset:0)*4) + pageNumber*EEPROM_PAGE_SIZE))))

void eeprom_init(void);
void eeprom_write_word(uint16 pageNumber, int16 offset, uint32 data);
void eeprom_write_page(uint16 pagenum, uint32 *data);


#endif

