/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx_hal.h"

#include "spi.h"
#include "nRF24L01.h"
#include "nRF24L01_register_L.h"
#include "flash.h"
//#include "24l01.h"
#include "Eink.h"
//#include "EXTI.h"
#include "IIC.h"
#include "TPS65185.h"
#include "string.h"
void NRF_Init(void);

void SystemClock_Config(void);

const uint8_t addr[5] = {0x34,0x43,0x10,0x10,0x01};

const uint8_t start_flag[] = "A";
const uint8_t eof_flag[] = "EOF";

uint8_t Recivefile[120000];
uint32_t fpt = 0;

uint8_t rec_buff[33] = "";
uint32_t flag = 0;
#define __SEND while (nRF24L01_TxPack(&tpt) != _SET) { nRF24L01_Channel_Init(40); HAL_Delay(4);}

nRF24L01_TxStructure tpt = {
  .pSrc = 0,
  .Txnum = 0,
  .Rxnum = 0,
};

nRF24L01_RxStructure rpt = {
  .pRec = rec_buff
};


void cpy(void *des, void *src, uint32_t size) {
  uint8_t *dpt = (uint8_t *)des, *spt = (uint8_t *)src;
  while (--size) {
    *dpt = *spt;
    dpt++;
    spt++;
  }
}
int main(void)
{

  HAL_Init();
  /* Configure the system clock */
  SystemClock_Config();
  /* Initialize all configured peripherals */
	SYS_Init();
	NRF_Init();
  MX_SPI1_Init();
  TPS65185_Init();
  EPD_Init();
  make_wave_table();
  
  //nRF24L01 register init
  while (nRF24L01_Check() != _SET);
  nRF24L01_Init();
  nRF24L01_TxInit((uint8_t*)addr);
  nRF24L01_RxInit(P0, (uint8_t*)addr);
  nRF24L01_Channel_Init(40);
begin:
  while (1) {

    rpt.pRec = Recivefile;
    fpt = 0;
    flag = 0;
    
    while (fpt <= 120000) {
      
      nRF24L01_RxPack(&rpt, 0);
      
      /* Start flag */
      if (rpt.Rxnum == 1) {
				rpt.pRec[1] = 0;
				if (!strcmp((const char*)(rpt.pRec), (const char*)start_flag)){
					rpt.pRec = Recivefile;
					fpt = 0;
					flag = 1;
					continue;
				}
      }
      
      /* Eof flag */
      if (rpt.Rxnum == 3) {
				rpt.pRec[3] = 0;
				if (!strcmp((const char*)rpt.pRec, (const char*)eof_flag)) {
					if (!flag)
						goto begin;
					fpt = 0;
					flag = 0;
					break;
				}
      }
      
      if (rpt.Px != P0 || rpt.Rxnum != 32) {
        continue;
      }
      if (!flag)
				continue;
		
			//copy to ram buffer
			rpt.pRec += 32;
			
			//cpy(Recivefile + fpt, rpt.pRec, 32);
			fpt += 32;
    }
    //display
    EPD_Display_PIC(Recivefile);
    
  }
}

void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 240;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3);

  HAL_RCC_EnableCSS();

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */
void NRF_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __GPIOH_CLK_ENABLE();
  __GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
  /*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		
	GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
/* USER CODE END 4 */

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
