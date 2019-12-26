#ifndef _SELFBUILD_CONTROL_H_
#define _SELFBUILD_CONTROL_H_

#include "headfile.h"

 
#define FULL_duty  1000  
#define	OLED_SHOW(x)					(int16)(25.5 * (x - 1))

extern int16 g_nLeft_duty;
extern int16 g_nRight_duty;
extern int16 g_nSpeedLeft; 
extern int16 g_nSpeedRight;
extern int32 range_protect(int32 duty, int32 min, int32 max);
extern int16 g_nSpeedLeft_set;
extern int16 g_nSpeedRight_set;
extern float pitch, roll, yaw;//欧拉角
extern int16 fGyroY;//Y轴角速度
extern int16 fGyroZ;//Z轴角速度
extern int16 fGyroX;//x轴角速度
extern float g_fGyroYRead;
extern float g_fGyroZRead;
extern float g_fGyroXRead;
void PWM_OUT(int16 pwm_left,int16 pwm_right);
void Speed_read(void); 
void DataRead(void);
void Oledshow(void);
void UI_Send(void);
#endif


