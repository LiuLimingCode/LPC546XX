/*!
 * @�ļ�       myiic.h
 * @����       ģ��IIC����ʵ��,����IIC�ײ���C++���Ա�д,��Ϊһ����,IIC�ĵײ���C���Ա�д���ڷ���
 *             һ����,�Ҿ�������һ���ܺõĻ���չʾһ�������C���Ժ�C++��ϱ���.
 * @����       ������
 * @���ʱ��   2019-12
 */
 
#ifndef __LPC546XX_MYIIC_H
#define __LPC546XX_MYIIC_H

#ifdef __cplusplus  //ע��C���Ժ�C++���
extern "C" {
#endif

#include "headfile.h"

/***************** ��Ҫ�궨�� *****************/
#define NOP()   for(int tempdely = 0; tempdely < 2; ++tempdely);//����IICͨѶ����ʱʱ�䣬����ȶ���

//Ϊ������ֲ,����ֱ�Ӹ��ĺ궨��ʵ����ͬ����
#define MYIIC_GPIO_SET_BITS(x)    gpio_set(x, 1)       //����������ߵ�ƽ
#define MYIIC_GPIO_RESET_BITS(x)  gpio_set(x, 0)       //����������͵�ƽ
#define MYIIC_GPIO_SET_OUT(x)     gpio_init(x, GPO, 0, NOPULL) //����������Ϊ���ģʽ,Ĭ������͵�ƽ
#define MYIIC_GPIO_SET_IN(x)      gpio_init(x, GPI, 1, PULLUP) //����������Ϊ����ģʽ,Ĭ������
#define MYIIC_GPIO_READ(x)        gpio_get(x)          //��ȡ���������ƽ

/****************** C���Է��ɵ��ú��� ******************/
void IIC_Init(PIN_enum sdaPin, PIN_enum sckPin);
uint8 IIC_WriteData(PIN_enum sdaPin, PIN_enum sckPin, uint8 slaveAddress, uint8 registerAddress, uint8 data);
uint8 IIC_WriteBuffer(PIN_enum sdaPin, PIN_enum sckPin, uint8 slaveAddress, uint8 registerAddress, uint8 len, uint8 *buffer);
uint8 IIC_ReadData(PIN_enum sdaPin, PIN_enum sckPin, uint8 slaveAddress, uint8 registerAddress, uint8 *data);
uint8 IIC_ReadBuffer(PIN_enum sdaPin, PIN_enum sckPin, uint8 slaveAddress, uint8 registerAddress, uint8 len, uint8 *buffer);

#ifdef __cplusplus  //ע��C���Ժ�C++���
}
#endif

#endif
