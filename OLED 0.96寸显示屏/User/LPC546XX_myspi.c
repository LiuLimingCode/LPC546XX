/*!
 * @�ļ�       myspi.c
 * @����       Ӳ��SPI�����SPIͳһʵ��
 * @����       ������
 * @���ʱ��   2019-12
 */

#include "LPC546XX_myspi.h"

//----------------------------------------------------------------------
//  @����       Ӳ��SPI��ʼ��
//  @����       spi       ��Ҫʹ�õ�spiģ���
//  @����       baud      ���䲨����,��spi�����ٶ�
//  @ע��       ��ֱֲ�Ӹ��ĺ��������Ե���ʵ����ͬ���ܼ���,
//              ����������ֲ,ֱ�ӰѺ����������,�����ڲ�Ҫ���ü���
//----------------------------------------------------------------------
void SPI_InitHardware(SPIN_enum spi, SPI_PIN_enum sdaPin, SPI_PIN_enum sclPin, uint32 baud)
{
	spi_init(spi, SPI_CS_NOT_USE, sclPin, sdaPin, SPI_MISO_NOT_USE, 0, flexcomm_get_clk(FLEXCOMM_0));
}

//----------------------------------------------------------------------
//  @����       Ӳ��SPI����һ���ֽڵ�����
//  @����       spi       ��Ҫʹ�õ�spiģ���
//  @����       data      ��Ҫ���͵�����
//  @ע��       ��ֱֲ�Ӹ��ĺ��������Ե���ʵ����ͬ���ܼ���,
//              ����������ֲ,ֱ�ӰѺ����������,�����ڲ�Ҫ���ü���
//----------------------------------------------------------------------
void SPI_SendDataHardware(SPIN_enum spi, uint8 data)
{
	//spi_mosi(spi, SPI_CS_NOT_USE, &data, NULL, 1, 1); //�⺯���汾,���Ĵ����汾�����������,����øú����Ƚ�����
	
	//�Ĵ����汾�ķ��ͳ���,�����ٶȸ���,���ǲ�һ������
	while(!(SPIN[spi]->FIFOSTAT & SPI_FIFOSTAT_TXEMPTY_MASK));                        //�ȵ����ͻ���Ϊ��
    SPIN[spi]->FIFOWR = SPI_FIFOWR_TXDATA(data) | SPI_FIFOWR_EOT_MASK | SPI_FIFOWR_LEN(7); //��������   
    //while(!(SPIN[spi]->FIFOSTAT & SPI_FIFOSTAT_RXNOTEMPTY_MASK));                     //�ȴ����ջ��岻Ϊ��
    SPIN[spi]->FIFORD;
}

//----------------------------------------------------------------------
//  @����       ���SPI��ʼ��,����ʼ������GPIO����
//  @����       sdaPin    sda�����ź����ź�
//  @����       sclPin    sclʱ���ź����ź�
//  @ע��       ��ֱֲ�Ӹ��ĺ��������Ե���ʵ����ͬ���ܼ���
//----------------------------------------------------------------------
void SPI_InitSimulated(PIN_enum sdaPin, PIN_enum sclPin)
{
	gpio_init(sclPin, GPO, 1, NOPULL);
	gpio_init(sdaPin, GPO, 1, NOPULL);
}

//----------------------------------------------------------------------
//  @����       ���SPI����һ���ֽڵ�����,������GPIO��ƽ�任��ģ��SPIʱ��
//  @����       sdaPin    sda�����ź����ź�
//  @����       sclPin    sclʱ���ź����ź�
//  @����       data      ��Ҫ���͵�����
//  @ע��       ��ֱֲ�Ӹ��ĺ��������Ե���ʵ����ͬ���ܼ���
//----------------------------------------------------------------------
void SPI_SendDataSimulated(PIN_enum sdaPin, PIN_enum sclPin, uint8 data)
{
#define MYSPI_GPIO_SET_BITS(x)    gpio_set(x ,1) //Ϊ������ֲ,����ֱ�Ӹ��ĺ궨��ʵ����ͬ����
#define MYSPI_GPIO_RESET_BITS(x)  gpio_set(x, 0)
	uint8_t temp = 8;
	
	MYSPI_GPIO_RESET_BITS(sclPin);
	while (temp--)
	{
		if (data & 0x80) MYSPI_GPIO_SET_BITS(sdaPin);
		else MYSPI_GPIO_RESET_BITS(sdaPin); 
		MYSPI_GPIO_SET_BITS(sclPin);
		MYSPI_GPIO_RESET_BITS(sclPin);
		data <<= 1;
	}
}
