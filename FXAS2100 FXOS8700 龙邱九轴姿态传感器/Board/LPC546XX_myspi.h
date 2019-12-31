/*!
 * @�ļ�       myspi.h
 * @����       Ӳ��SPI�����SPIͳһʵ��
 * @����       ������
 * @���ʱ��   2019-12
 */

#ifndef __LPC546XX_MYSPI_H
#define __LPC546XX_MYSPI_H

#include "headfile.h"

/****************** Ӳ��SPI�����SPI���� ******************
##SPI��ͨѶЭ��,����������������(SDA��������,SCLʱ������)����
  ���ķ�ʽ�ı��ƽ�ź�,�Ӷ����䲻ͬ������.
##Ӳ��SPIʹ�õ�Ƭ���ڲ���SPIģ�鴫������
  �ŵ㣺�����ٶȿ�,������ռ��CPU
  ȱ�㣺��Ƭ��������SPIģ��,���ұ����Ƶ�оƬ�ļĴ���,��ͬ�ͺ�
      �ĵ�Ƭ����̷�������ͬ,������ײ���ֲ.
##���SPIʹ�����ŵĸߵ͵�ƽ�仯����(GPIO)ģ���SPI��ʱ��
  ȱ�㣺�����ٶ���,�ڴ����������ҪCPU����,ռ��CPU
  �ŵ㣺���ڴ󲿷ֵ�Ƭ������GPIO����,�ײ���ֲ��
*********************************************************/

void SPI_InitHardware(SPIN_enum spi, SPI_PIN_enum sdaPin, SPI_PIN_enum sclPin, uint32 baud);
void SPI_SendDataHardware(SPIN_enum spi, uint8 data);
void SPI_InitSimulated(PIN_enum sdaPin, PIN_enum sclPin);
void SPI_SendDataSimulated(PIN_enum sdaPin, PIN_enum sclPin, uint8 data);

#endif
