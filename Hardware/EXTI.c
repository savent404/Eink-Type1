#include "EXTI.h"
#include "nRF24L01.h"

extern nRF24L01_RxStructure rpt;
//uint8_t ReciveBuf[120000];
//__IO uint16_t NRF24L01_RX_NUM=0;


void EXTI0_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __GPIOB_CLK_ENABLE();

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 1, 0);
  HAL_NVIC_DisableIRQ(EXTI0_IRQn);
}


void EXTI0_IRQHandler()
{
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == RESET) {
      nRF24L01_RxPack_NoBlock(&rpt, 0);	
    }
}
