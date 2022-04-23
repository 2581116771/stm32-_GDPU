#include "main.h"


extern uint8_t Temp_byte1, Temp_byte2;
extern uint16_t TEMP;

extern float Temperature;
extern float Humidity;
extern uint8_t Presence;
//#define Set_Pin_Output() {GPIOB->CRL&=0XF0FFFFFF;GPIOB->CRL|=3<<24;}
//#define Set_Pin_Iuput() {GPIOB->CRL&=0XF0FFFFFF;GPIOB->CRL|=8<<24;}
void DS18B20(void);
void Set_Pin_Output(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void Set_Pin_Input(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
uint8_t DS18B20_Start (void);
void DS18B20_Write (uint8_t data);
uint8_t DS18B20_Read (void);
