/**
******************************************************************************
* @file    rf_device_it.c
* @author  AMS RF Application Team
* @version V1.0.0
* @date    27-March-2019
* @brief   Main Interrupt Service Routines.
*          This file provides template for all exceptions handler and
*          peripherals interrupt service routine.
******************************************************************************
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "rf_device_it.h"
#include "ble_const.h"
#include "bluenrg_lp_stack.h"
#include "bluenrg_lp_evb_com.h"
#include "rf_driver_hal_vtimer.h"
#include "hal_miscutil.h"
#include "crash_handler.h"
#include "rf_driver_ll_tim.h"
#include "freq_sensor.h"


/** @addtogroup BlueNRG1_StdPeriph_Examples
* @{
*/

/** @addtogroup GPIO_Examples
* @{
*/

/** @addtogroup GPIO_IOToggle
* @{
*/

#define DEBOUNCE_RESET_VAL 0xFFFFFFFF
volatile uint32_t debounce_count = DEBOUNCE_RESET_VAL,debounce_last = 0;

#define DEBOUNCE_CNT 0
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M0 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  */
NOSTACK_FUNCTION(NORETURN_FUNCTION(void NMI_IRQHandler(void)))
{
  HAL_CrashHandler(__get_MSP(), NMI_SIGNATURE);
  /* Go to infinite loop when NMI exception occurs */
  while (1)
  {}
}

/**
* @brief  This function handles Hard Fault exception.
*/
NOSTACK_FUNCTION(NORETURN_FUNCTION(void HardFault_IRQHandler(void)))
{
  HAL_CrashHandler(__get_MSP(), HARD_FAULT_SIGNATURE);
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles SVCall exception.
  */
void SVC_IRQHandler(void)
{
}


/**
* @brief  This function handles SysTick Handler.
*/
void SysTick_IRQHandler(void)
{
	if(debounce_count != DEBOUNCE_RESET_VAL)
		debounce_count++;
}


/******************************************************************************/
/*                 BLUENRG_LP Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (EXTI), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_bluenrg_lp.s).                                               */
/******************************************************************************/
/**
* @brief  This function handles UART interrupt request.
* @param  None
* @retval None
*/

void USART1_IRQHandler(void)
{
  BSP_COM_IRQHandler();
}


/**
* @brief  This function handles DMA Handler.
*/
void DMA_IRQHandler(void)
{

}


/**
* @brief  This function handles GPIO interrupt request.
* @param  None
* @retval None
*/



void BLE_WKUP_IRQHandler(void)
{
  HAL_VTIMER_WakeUpCallback();
}

void CPU_WKUP_IRQHandler(void)
{
  HAL_VTIMER_TimeoutCallback();
}

void BLE_ERROR_IRQHandler(void)
{
  volatile uint32_t debug_cmd;

  BLUE->DEBUGCMDREG |= 1;

  /* If the device is configured with
     System clock = 64 MHz and BLE clock = 16 MHz
     a register read is necessary to end fine
     the clear interrupt register operation,
     due the AHB down converter latency */
  debug_cmd = BLUE->DEBUGCMDREG;
}

void BLE_TX_RX_IRQHandler(void)
{
  uint32_t blue_status = BLUE->STATUSREG;
  uint32_t blue_interrupt = BLUE->INTERRUPT1REG;

  /** clear all pending interrupts */
  BLUE->INTERRUPT1REG = blue_interrupt;

  HAL_VTIMER_EndOfRadioActivityIsr();
  BLE_STACK_RadioHandler(blue_status|blue_interrupt);
  HAL_VTIMER_RadioTimerIsr();

  /* If the device is configured with
     System clock = 64 MHz and BLE clock = 16 MHz
     a register read is necessary to end fine
     the clear interrupt register operation,
     due the AHB down converter latency */
  blue_interrupt = BLUE->INTERRUPT1REG;
}

void BLE_RXTX_SEQ_IRQHandler(void)
{
  HAL_RXTX_SEQ_IRQHandler();
}
/**
* @}
*/

/*
void TIMx_IRQHandler(void)
{
   if(LL_TIM_IsActiveFlag_CC1(TIMx) == 1)
  {
    LL_TIM_ClearFlag_CC1(TIMx);

   TimerCaptureCompare_Callback();
  }
}*/

void HALLSpeed_RestCounter(void)
{
	debounce_count = DEBOUNCE_RESET_VAL;
}
void HALL_IRQHandler(void)
{
	printf("\r\nEXTI HANDLER..\r\n");

	if(debounce_count == DEBOUNCE_RESET_VAL)
	{
		debounce_count = debounce_last = 0;
		return;
	}


	  if (LL_EXTI_IsInterruptPending(HALL_SPEED_EXTI_LINE) != RESET)
	  {
		LL_EXTI_ClearInterrupt(HALL_SPEED_EXTI_LINE);

		//if ( (debounce_count - debounce_last) >= DEBOUNCE_CNT )

		{
		  /* Add the SW no bounce */

		  /* Handle user button press in dedicated function */
		  HallSpeed_Callback(debounce_count - debounce_last);
		  debounce_last = debounce_count;
		}
	  }
}

void GPIOA_IRQHandler(void)
{
	HALL_IRQHandler();
}


void GPIOB_IRQHandler(void)
{
	HALL_IRQHandler();
}
/**
* @}
*/

/**
* @}
*/

/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
