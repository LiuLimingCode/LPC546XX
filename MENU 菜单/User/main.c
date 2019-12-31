#include "headfile.h"

int16 int16_1 = 10, int16_2 = 12, int16_3 = 20, int16_4 = 30, int16_5 = 40;
float float_1 = 2.1, float_2 = -2.1, float_3 = 99.9, float_4 = 44.1, float_5 = 11.1;
uint8 uint8_1 = 2, uint8_2 = 3, uint8_3 = 4, uint8_4 = 3, uint8_5 = 6;

#define KC			MENU_BUTTON_CONFIRM
#define KR			MENU_BUTTON_RIGHT
#define KL			MENU_BUTTON_LEFT
#define KD			MENU_BUTTON_DOWN
#define KU			MENU_BUTTON_UP


int main(void)
{
	DisableInterrupts;
	get_clk();//获取时钟频率  务必保留
	
	OLED_Init();
	gpio_init(KC, GPI, 1, PULLUP);
	gpio_init(KR, GPI, 1, PULLUP);
	gpio_init(KL, GPI, 1, PULLUP);
	gpio_init(KD, GPI, 1, PULLUP);
	gpio_init(KU, GPI, 1, PULLUP);
	eeprom_init();
	Menu menu = {0};
	EnableInterrupts;
	
	menu[0].UintTitle = "0123";
	menu[0].VariableAddr[0] = &int16_1;
	menu[0].VariableName[0] = "int16_1";
	menu[0].VariableType[0] = VariableType_Int16;
	menu[0].VariableAddr[1] = &uint8_2;
	menu[0].VariableName[1] = "uint8_2";
	menu[0].VariableType[1] = VariableType_Uint8;
	menu[0].VariableAddr[2] = &int16_3;
	menu[0].VariableName[2] = "int16_3";
	menu[0].VariableType[2] = VariableType_Int16;
	menu[0].VariableAddr[3] = &float_1;
	menu[0].VariableName[3] = "float_1";
	menu[0].VariableType[3] = VariableType_Float;
	
	menu[1].UintTitle = "02";
	menu[1].VariableAddr[0] = &int16_2;
	menu[1].VariableName[0] = "int16_2";
	menu[1].VariableType[0] = VariableType_Int16;
	menu[1].VariableAddr[2] = &float_2;
	menu[1].VariableName[2] = "float_2";
	menu[1].VariableType[2] = VariableType_Float;
	
	menu[3].UintTitle = "void";
	
	menu[8].UintTitle = "13";
	menu[8].VariableAddr[1] = &uint8_1;
	menu[8].VariableName[1] = "uint8_1";
	menu[8].VariableType[1] = VariableType_Uint8;
	menu[8].VariableAddr[3] = &float_3;
	menu[8].VariableName[3] = "float_3";
	menu[8].VariableType[3] = VariableType_Float;
	
	Menu_Init(menu);                              //初始化菜单,在调用该函数前,请确保外部资源(GPIO,外部存储器,外部显示器)的初始化
	while(!Menu_Work()) systick_delay_ms(200);    //菜单每200ms工作一次，并根据是否按下“关闭菜单”选项后（函数返回0）结束死循环
	
	while(1);
}

