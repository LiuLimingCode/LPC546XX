# LPC546XX底层

Cortex-M4内核，时钟频率可达220 MHz，12位模数转换器（ADC），30通道DMA，五个定时器/计数器，其中四个支持PWM等功能

---

#### 更新日志
+ 2019年12月
	+ 基于逐飞底层，修改了assert、LPC546XX_spi、LPC546XX_eeprom程序，使得底层更加实用
	+ 重写 Menu ：
		+ 1.菜单由原来用32位内存保存变量，改为15位，在相同的存储空间上能存储更多的变量。
		+ 2.将程序中需要使用外部资源（存储器、显示器、GPIO）的函数独立封装，方便程序的移植和修改。
		+ 3.重写程序，并增加很多注释，使程序更逻辑、更能读懂。
		+ 4.菜单操作界面和操作方法不变。
	+ 新增 myspi，同时修改所有基于spi通讯的器件,包括OLED，数字电位器MCP41：
		+ 1.统一硬件SPI和软件SPI的实现函数。
		+ 2.解决了之前更改硬件SPI和软件SPI需要更改.c.h文件来实现的问题，现在只需要更改一个宏定义就可以达到一样效果。
		+ 3.增加代码注释增强可读性，增加宏定义实现不同的预编译功能。
	+ 重写 myiic，同时修改所有基于iic通讯的器件,包括MPU6050,FXAS2100,FXOS8700：
		+ 1.解决了之前同一个工程只能控制一个iic器件的尴尬问题。
		+ 2.增加代码注释增强可读性，增加宏定义实现不同的预编译功能。
	+ 考虑到以后移植的复杂性，总转风摄像头改用逐飞底层，并综合目前所有的图像处理函数到ImageProcess，希望以后摄像组队员能不断总结，并以这个文件传承图像处理函数。