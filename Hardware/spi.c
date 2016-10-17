#include "spi.h"


/* SPI1 init function */


SPI_HandleTypeDef hspi1;

void MX_SPI1_Init(void)
{
	
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLED;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
  //hspi1.Init.CRCPolynomial = 10;
  HAL_SPI_Init(&hspi1);
}


//void SPIx_SetSpeed(u8 SpeedSet)
//{
//	SPI_InitStructure.SPI_BaudRatePrescaler = SpeedSet ;
//  SPI_Init(SPI1, &SPI_InitStructure);
//	SPI_Cmd(SPI1,ENABLE);
//} 

////SPIx 读写一个字节
////TxData:要写入的字节
////返回值:读取到的字节
uint8_t SPIx_ReadWriteByte(uint8_t TxData)
{		
	uint8_t RxData=0;	
	

	
	HAL_SPI_TransmitReceive(&hspi1,&TxData,&RxData,1,100);
					   
	return RxData;
}































