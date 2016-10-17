#ifndef __TPS65185_H_
#define __TPS65185_H_
#include "IIC.h"

#define TPS65185_Addr 0xD0
#define REG_WRITE			0x00
#define REG_READ			0x01

#define TMST_VALUE 0x00
#define ENABLE     0x01
#define VADJ       0x02
#define VCOM1      0x03
#define VCOM2      0x04
#define INT_EN1		 0x05
#define INT_EN2		 0x06
#define INT1			 0x07
#define INT2			 0x08
#define UPSEQ0		 0x09
#define UPSEQ1		 0x0A
#define DWNSEQ0		 0x0B
#define DWNSEQ1		 0x0C
#define TMST1			 0x0D
#define TMST2			 0x0E
#define PG				 0x0F
#define REVID			 0x10	

#define WAKUP_H            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,GPIO_PIN_SET)
#define WAKUP_L            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,GPIO_PIN_RESET)

#define PWRUP_H            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2,GPIO_PIN_SET)
#define PWRUP_L            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2,GPIO_PIN_RESET)

#define VCOMCTRL_H            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9,GPIO_PIN_SET)
#define VCOMCTRL_L            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9,GPIO_PIN_RESET)

void TPS65185_Init(void);
uint8_t TPS65185_ReadOneByte(uint8_t ReadAddr);							//指定地址读取一个字节
void TPS65185_WriteOneByte(uint8_t WriteAddr,uint8_t DataToWrite);		//指定地址写入一个字节




#endif


