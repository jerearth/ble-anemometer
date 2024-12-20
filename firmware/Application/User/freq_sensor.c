
/******************** (C) COPYRIGHT 2022 STMicroelectronics ********************
* File Name          : TIM_Input_main.c
* Author             : RF Application Team
* Version            : 1.0.0
* Date               : 04-March-2019
* Description        : Code demonstrating the TIM functionality
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/**
 * @file  TIM_Input/TIM_Input_main.c
 * @brief Use of the TIM peripheral to measure a periodic signal frequency
 * provided either by an external signal generator or by
 * another timer instance.
 *

* \section KEIL_project KEIL project
  To use the project with KEIL uVision 5 for ARM, please follow the instructions below:
  -# Open the KEIL uVision 5 for ARM and select Project->Open Project menu.
  -# Open the KEIL project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\LL\\TIM\\TIM_Input\\MDK-ARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\TIM_Input.uvprojx</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild all target files. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download to download the related binary image.
  -# Alternatively, open the BlueNRG-LP Flasher utility and download the built binary image.

* \section IAR_project IAR project
  To use the project with IAR Embedded Workbench for ARM, please follow the instructions below:
  -# Open the Embedded Workbench for ARM and select File->Open->Workspace menu.
  -# Open the IAR project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\LL\\TIM\\TIM_Input\\EWARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\TIM_Input.eww</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild All. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download and Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \section WISE_project WiSE-Studio project
  To use the project with WiSE-Studio IDE (GCC toolchain), please follow the instructions below:
  -# Open the WiSE-Studio IDE
  -# Select File, Import, Existing Projects into Workspace
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\LL\\TIM\\TIM_Input\\WiSE-Studio\\{STEVAL-IDB011V1|STEVAL-IDB012V1}</tt>
  -# Select desired configuration to build
  -# Select Project->Build Project. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Run->Run/Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \subsection Project_configurations Project configurations
- \c Release - Release configuration


* \section Board_supported Boards supported
- \c STEVAL-IDB010V1
- \c STEVAL-IDB011V1
- \c STEVAL-IDB011V2
- \c STEVAL-IDB012V1
- \c STEVAL-IDB013V1



* \section Power_settings Power configuration settings
@table

==========================================================================================================
|                                         STEVAL-IDB01xV1                                                |
----------------------------------------------------------------------------------------------------------
| Jumper name | Description                                                                |
| JP2         |                                                                            |
----------------------------------------------------------------------------------------------------------
| USB         | USB supply power                                                            |
| BAT         | The supply voltage must be provided through battery pins.                   |


@endtable

* \section Jumper_settings Jumper settings
@table

========================================================================================================================================================================================
|                                                                             STEVAL-IDB01xV1                                                                                          |
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
| Jumper name |                                                                Description                                                                                             |
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
| JP1         | It provides the voltage to the BlueNRG-LP circuit. It must be fitted. It can be used for current measurements of the BlueNRG-LP device.                                |
| JP2         | It is a switch between two power domains. BAT position: to provide power from battery holder; USB position: to provide power from USB connector.                       |
| JP3         | It connects the BLE_SWCLK pin of the BlueNRG-LP with the SWCLK pin of the USB_CMSISDAP. It must be fitted.                                                             |
| JP4         | It connects the BLE_SWDIO pin of the BlueNRG-LP with the SWDIO pin of the USB_CMSISDAP. It must be fitted.                                                             |
| JP5         | It connects the BLE_RSTN pin of the BlueNRG-LP with the rest of the board (the USB_CMSISDAP and RESET push button). It must be fitted.                                 |


@endtable

* \section Pin_settings Pin settings
@table
|  PIN name  | STEVAL-IDB011V{1-2} | STEVAL-IDB012V1|
--------------------------------------------------------
|     A1     |       Not Used      |      USART TX      |
|     A11    |       Not Used      |      Not Used      |
|     A12    |       Not Used      |        N.A.        |
|     A13    |       Not Used      |        N.A.        |
|     A14    |       Not Used      |        N.A.        |
|     A15    |       Not Used      |        N.A.        |
|     A4     |       TIM1 CH1      |        N.A.        |
|     A5     |       Not Used      |        N.A.        |
|     A6     |       Not Used      |        N.A.        |
|     A7     |       Not Used      |        N.A.        |
|     A8     |       USART TX      |      Not Used      |
|     A9     |       USART RX      |      Not Used      |
|     B0     |       Not Used      |      USART RX      |
|     B14    |       Not Used      |      Not Used      |
|     B2     |       Not Used      |      Not Used      |
|     B3     |       Not Used      |      TIM17 CH1     |
|     B4     |       Not Used      |        DL2         |
|     B5     |       Not Used      |      Not Used      |
|     B7     |       Not Used      |      Not Used      |
|     B8     |         DL2         |        N.A.        |
|     B9     |       Not Used      |        N.A.        |
|     A0     |         N.A.        |      Not Used      |
|     A10    |         N.A.        |      Not Used      |
|     B1     |         N.A.        |      Not Used      |
|     B6     |         N.A.        |      Not Used      |
|     B15    |         N.A.        |      Not Used      |
|     GND    |       Not Used      |      Not Used      |
|     RST    |       Not Used      |      Not Used      |
|    VBAT    |       Not Used      |      Not Used      |
@endtable


* \section LEDs_description LEDs description
@table
|  LED name  |     STEVAL-IDB010V1    |     STEVAL-IDB011V1    |     STEVAL-IDB011V2    |     STEVAL-IDB012V1    |     STEVAL-IDB013V1    |
------------------------------------------------------------------------------------------------------------------------------------------------
|     DL1    |        Not Used        |        Not Used        |        Not Used        |        Not Used        |        Not Used        |
|     DL2    |  Slow blinking: error  |  Slow blinking: error  |  Slow blinking: error  |  Slow blinking: error  |  Slow blinking: error  |
|     DL3    |        Not Used        |        Not Used        |        Not Used        |        Not Used        |        Not Used        |
|     DL4    |        Not Used        |        Not Used        |        Not Used        |        Not Used        |        Not Used        |
|     U5     |        Not Used        |        Not Used        |        Not Used        |        Not Used        |        Not Used        |

@endtable


* \section Buttons_description Buttons description
@table
|   BUTTON name  |   STEVAL-IDB010V1  |   STEVAL-IDB011V1  |   STEVAL-IDB011V2  |    STEVAL-IDB012V1   |    STEVAL-IDB013V1   |
------------------------------------------------------------------------------------------------------------------------------------
|      PUSH1     |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |
|      PUSH2     |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |
|      RESET     |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |   Reset BlueNRG-LPS  |   Reset BlueNRG-LPS  |

@endtable

* \section Usage Usage

Use of the TIM peripheral to measure a periodic signal frequency provided either by an external signal generator or by another timer instance.
This example is based on the BLUENRG_LP TIM LL API.
The peripheral initialization uses LL unitary service functions for optimization purposes (performance and size).

TIM1_CH1 is configured in input capture mode. The TIM1CLK frequency is set to its maximum value (Prescaler is /2 * 2 = 1) in order to get the best possible resolution.

The "uwMeasuredFrequency" variable contains the measured signal frequency.
It is calculated within the capture/compare 1 interrupt service routine.

The minimum frequency value to measure is TIM1 counter clock / TIMx_CCR1 MAX
                                              = 64 MHz / 65535

Due to TIM1 interrupt routine processing time (around 1us), the maximum frequency value to measure is around 1 MHz.

BlueNRG_LP-EVB Set-up
- TIM1_CH1   PA4  the external signal must be connected to TIM1 Channel1 used as input pin.
Connect USART1 TX/RX to respectively RX and TX pins of PC UART (could be done through a USB to UART adapter) :
- Connect BlueNRG_LP board USART1 TX pin to PC COM port RX signal
- Connect BlueNRG_LP board USART1 RX pin to PC COM port TX signal
- Connect BlueNRG_LP board GND to PC COM port GND signal

Launch serial communication SW on PC (as HyperTerminal or TeraTerm) with proper configuration :
- 115200 bauds
- 8 bits data
- 1 start bit
- 1 stop bit
- no parity
- no HW flow control
**/

#include "rf_driver_ll_utils.h"
#include "rf_driver_ll_tim.h"
#include "rf_driver_ll_gpio.h"
#include "bluenrg_lp_evb_com.h"
/* Includes ------------------------------------------------------------------*/
#include "freq_sensor.h"



/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Measured frequency */
__IO uint32_t uwMeasuredFrequency = 0;

/* Private function prototypes -----------------------------------------------*/


__STATIC_INLINE void LED_Blinking(uint32_t Period);

LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
LL_EXTI_InitTypeDef EXTI_InitStruct = {0};

/* Private user code ---------------------------------------------------------*/

/**
* @brief  The application entry point.
* @retval int
*/
void freq_sensor_init(void)
{


  /* Set systick to 1ms using system clock frequency */
  LL_Init1msTick(SystemCoreClock);
	//LL_InitTick(SystemCoreClock, 100);
  /* Initialize all configured peripherals */
  /* GPIO Ports Clock Enable */
    LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOA);
    LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOB);
    LL_APB0_EnableClock(LL_APB0_PERIPH_SYSCFG);
    //LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOA) ;



  	/* Configure GPIO for BUTTON */

    LL_GPIO_SetPinMode(HALL_SPEED_GPIO_PORT, HALL_SPEED_PIN, LL_GPIO_MODE_INPUT);
    //LL_GPIO_SetPinPull(HALL_SPEED_GPIO_PORT, HALL_SPEED_PIN, LL_GPIO_PULL_NO);
    LL_GPIO_SetPinPull(HALL_SPEED_GPIO_PORT, HALL_SPEED_PIN, LL_GPIO_PULL_UP);

    HALL_EXTI_BOTH_TRIG_ENABLE();
    //HALL_EXTI_LINE_ENABLE();

    LL_EXTI_EnableIT(HALL_SPEED_EXTI_LINE);

    /* Clear the event occurred on the interrupt line 10 port A. */
      if (LL_EXTI_IsInterruptPending(HALL_SPEED_EXTI_LINE) != RESET)
      {
        LL_EXTI_ClearInterrupt(HALL_SPEED_EXTI_LINE);
      }

      /* Configure NVIC for USER_BUTTON_EXTI_IRQn */
  	  NVIC_SetPriority(HALL_EXTI_IRQn, IRQ_LOW_PRIORITY );
  	  NVIC_EnableIRQ(HALL_EXTI_IRQn);

  	  /* Configure NVIC for SysTick_IRQn */
  	  //NVIC_SetPriority(SysTick_IRQn, IRQ_LOW_PRIORITY);


  /*
  	EXTI_InitStruct.Line = HALL_SPEED_EXTI_LINE;
  	EXTI_InitStruct.LineCommand = ENABLE;
  	EXTI_InitStruct.Type = HALL_EXTI_TYPE;
  	EXTI_InitStruct.Trigger = HALL_TRIGGER_EDGE;
  	LL_EXTI_Init(&EXTI_InitStruct);
  */
  	/*
  	NVIC_SetPriority(HALL_EXTI_IRQn, IRQ_LOW_PRIORITY );
  	NVIC_EnableIRQ(HALL_EXTI_IRQn);
  	*/

  	  printf("\r\nEXTI ENABLED..\r\n");

}

void freq_measure_task(void)
{
	HALLSpeed_RestCounter();
	LL_mDelay(200);
}




/**
* @brief  Set LED2 to Blinking mode for an infinite loop (toggle period based on value provided as input parameter).
* @param  Period : Period of time (in ms) between each toggling of LED
*   This parameter can be user defined values. Pre-defined values used in that example are :
*     @arg LED_BLINK_FAST : Fast Blinking
*     @arg LED_BLINK_SLOW : Slow Blinking
*     @arg LED_BLINK_ERROR : Error specific Blinking
* @retval None
*/
__STATIC_INLINE void LED_Blinking(uint32_t Period)
{
  /* Toggle IO in an infinite loop */
  while (1)
  {
    LL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
    LL_mDelay(Period*10);
  }
}

/******************************************************************************/
/*   USER IRQ HANDLER TREATMENT                                               */
/******************************************************************************/



/**
* @brief  This function is executed in case of error occurrence.
* @retval None
*/
void Error_Handler(void)
{
  /* User can add his own implementation to report the HAL error return state */
  LED_Blinking(LED_BLINK_ERROR);
}

#ifdef  USE_FULL_ASSERT
/**
* @brief  Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param  file: pointer to the source file name
* @param  line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
  tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/



