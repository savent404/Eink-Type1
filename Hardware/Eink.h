#ifndef __EINK_H_
#define __EINK_H_
#include "stm32f2xx_hal.h"


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//EPD 接口定义
//#define EPD_XCE1_PORT       GPIOD
//#define EPD_XCE1            GPIO_PIN_8		//PA8			U1CE1  p31

#define EPD_CL_PORT					GPIOA
#define EPD_CL         			GPIO_PIN_10		//PB8				CL		P5    WR

#define EPD_OE_PORT					GPIOA
#define EPD_OE              GPIO_PIN_9		//PB9			OE    P7    OE

#define EPD_LE_PORT					GPIOB
#define EPD_LE              GPIO_PIN_10		//PB10    LE    P6    LE

#define EPD_SHR_PORT				GPIOB
#define EPD_SHR             GPIO_PIN_11		//PB11		SHR   P8

#define EPD_GMODE1_PORT     GPIOB
#define EPD_GMODE1          GPIO_PIN_13		//PB12		MODE1
//#define EPD_XCE2_PORT       GPIOB
//#define EPD_XCE2            GPIO_PIN_13		//PB13		U1CE2
#define EPD_GMODE2_PORT     GPIOC
#define EPD_GMODE2          GPIO_PIN_8		//PB14		MODE2
#define EPD_XRL_PORT		GPIOB
#define EPD_XRL             GPIO_PIN_15		//PB15		RL

#define EPD_DB_PORT         GPIOC
#define EPD_DB_0            GPIO_PIN_0		//PC0			DATA
#define EPD_DB_1            GPIO_PIN_1		//PC1
#define EPD_DB_2            GPIO_PIN_2		//PC2
#define EPD_DB_3            GPIO_PIN_3		//PC3
#define EPD_DB_4            GPIO_PIN_4		//PC4
#define EPD_DB_5            GPIO_PIN_5		//PC5
#define EPD_DB_6            GPIO_PIN_6		//PC6
#define EPD_DB_7            GPIO_PIN_7		//PC7

#define EPD_XSPV_PORT		GPIOB
#define EPD_XSPV            GPIO_PIN_12		//PC8		SPV
#define EPD_CLK_PORT		GPIOB
#define EPD_CLK             GPIO_PIN_14		//PC9		CPV
#define EPD_SPH_PORT		GPIOA
#define EPD_SPH             GPIO_PIN_8		//PC13	SPH

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//EPD 电源 控制定义
//#define VCOM_CTR_PORT      	GPIOB	
//#define VCOM_CTR           	GPIO_PIN_2		//PB1			4053 S2
//#define ASW1_CTR_PORT      	GPIOB	
//#define ASW1_CTR           	GPIO_PIN_2		//PB2			4053	S1
//#define ASW3_CTR_PORT      	GPIOB	
//#define ASW3_CTR           	GPIO_PIN_0		//PB0			4053	S3

//#define VNEGGVEE_CTR_PORT		GPIOA
//#define VNEGGVEE_CTR				GPIO_PIN_1		//PA1			AME5142
//#define VPOS15_CTR_PORT			GPIOA
//#define VPOS15_CTR					GPIO_PIN_2		//PA2			Q4
//#define GVDD22_CTR_PORT			GPIOA
//#define GVDD22_CTR					GPIO_PIN_3		//PA3			Q5

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//按键 LED 控制定义
//#define LED4_CTR_PORT       GPIOC
//#define LED4_CTR			GPIO_PIN_12     //PC12
//#define LED5_CTR_PORT       GPIOC
//#define LED5_CTR			GPIO_PIN_11     //PC11
//#define LED6_CTR_PORT       GPIOC
//#define LED6_CTR			GPIO_PIN_10     //PC10

//#define KEY1_CTR_PORT       GPIOB
//#define	KEY1_CTR			GPIO_PIN_5		//PB5
//#define KEY2_CTR_PORT       GPIOD
//#define	KEY2_CTR			GPIO_PIN_2		//PD2
//#define KEY3_CTR_PORT       GPIOA
//#define	KEY3_CTR			GPIO_PIN_0		//PA0

#define TEST_CTR_PORT       GPIOC
#define	TEST_CTR			GPIO_PIN_3		//PC3	
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define PORT_A_PIN_OUT  	 EPD_CL |EPD_OE | EPD_SPH //EPD_XCE1 |
#define PORT_B_PIN_OUT  	 EPD_LE | EPD_SHR | EPD_GMODE1  | EPD_XRL |EPD_CLK | EPD_XSPV
#define PORT_C_PIN_OUT  	EPD_XSPV | EPD_CLK | EPD_SPH  | EPD_DB_0 | EPD_DB_1 | EPD_DB_2 | EPD_DB_3 | EPD_DB_4 | EPD_DB_5 | EPD_DB_6 | EPD_DB_7 |EPD_GMODE2

//#define PORT_A_PIN_IN  		KEY3_CTR
//#define PORT_B_PIN_IN  		KEY1_CTR
#define PORT_C_PIN_IN 		TEST_CTR
//#define PORT_D_PIN_IN  		KEY2_CTR

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define RCC_GPIO_USE        RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD
#define GPIO_SPEED_EPD      GPIO_Speed_50MHz



//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//EPD端口宏定义 
#define EPD_CL_H            HAL_GPIO_WritePin(EPD_CL_PORT, EPD_CL,GPIO_PIN_SET)
#define EPD_CL_L            HAL_GPIO_WritePin(EPD_CL_PORT, EPD_CL,GPIO_PIN_RESET)

#define EPD_LE_H            HAL_GPIO_WritePin(EPD_LE_PORT, EPD_LE,GPIO_PIN_SET)
#define EPD_LE_L            HAL_GPIO_WritePin(EPD_LE_PORT, EPD_LE,GPIO_PIN_RESET)

#define EPD_OE_H            HAL_GPIO_WritePin(EPD_OE_PORT, EPD_OE,GPIO_PIN_SET)
#define EPD_OE_L            HAL_GPIO_WritePin(EPD_OE_PORT, EPD_OE,GPIO_PIN_RESET)

#define EPD_SPH_H           HAL_GPIO_WritePin(EPD_SPH_PORT, EPD_SPH,GPIO_PIN_SET)
#define EPD_SPH_L           HAL_GPIO_WritePin(EPD_SPH_PORT, EPD_SPH,GPIO_PIN_RESET)

#define EPD_XSPV_H          HAL_GPIO_WritePin(EPD_XSPV_PORT, EPD_XSPV,GPIO_PIN_SET)
#define EPD_XSPV_L          HAL_GPIO_WritePin(EPD_XSPV_PORT, EPD_XSPV,GPIO_PIN_RESET)

#define EPD_CLK_H           HAL_GPIO_WritePin(EPD_CLK_PORT, EPD_CLK,GPIO_PIN_SET)
#define EPD_CLK_L           HAL_GPIO_WritePin(EPD_CLK_PORT, EPD_CLK,GPIO_PIN_RESET)







void SYS_Init(void);

void make_wave_table(void);

void EPD_PowerOn(uint16_t Vcom);
void EPD_PowerOff(void);
void EPD_Init(void);
void EPD_Start_Scan(void);
void EPD_Send_Row_Data(uint8_t *pArray);
void EPD_Display_PIC(unsigned char *ptr);



#endif

