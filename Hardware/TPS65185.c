#include "TPS65185.h"


void TPS65185_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
  /* GPIO Ports Clock Enable */
  __GPIOH_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();
  /*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	IIC_Init();//IIC≥ı ºªØ
}

uint8_t TPS65185_ReadOneByte(uint8_t ReadAddr)
{				  
	uint8_t temp=0;		  	    																 
  IIC_Start();  
	IIC_Send_Byte(TPS65185_Addr+REG_WRITE);     
	IIC_Wait_Ack(); 
  IIC_Send_Byte(ReadAddr);   
	IIC_Wait_Ack();	    
	IIC_Start();  	 	   
	IIC_Send_Byte(TPS65185_Addr+REG_READ);           	   
	IIC_Wait_Ack();	 
  temp=IIC_Read_Byte(0);
	IIC_Wait_Ack();		
  IIC_Stop();   
	return temp;
}

void TPS65185_WriteOneByte(uint8_t WriteAddr,uint8_t DataToWrite)
{				   	  	    																 
  IIC_Start();  
	IIC_Send_Byte(TPS65185_Addr+REG_WRITE);   
	IIC_Wait_Ack();	   
  IIC_Send_Byte(WriteAddr);  
	IIC_Wait_Ack(); 	 										  		   
	IIC_Send_Byte(DataToWrite);     							   
	IIC_Wait_Ack();  		    	   
  IIC_Stop();

}




