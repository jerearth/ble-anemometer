/*
 * freq_sensor.h
 *
 *  Created on: Dec 19, 2024
 *      Author: radoslav
 */

#ifndef APPLICATION_USER_FREQ_SENSOR_H_
#define APPLICATION_USER_FREQ_SENSOR_H_

/*

#define  HALL_SPEED_GPIO_PORT  GPIOB
#define  HALL_SPEED_PIN  LL_GPIO_PIN_5
#define  HALL_SPEED_EXTI_LINE LL_EXTI_LINE_PB5
#define	 HALL_TRIGGER_EDGE LL_EXTI_TRIGGER_BOTH_EDGE
#define  HALL_EXTI_TYPE LL_EXTI_TYPE_EDGE
#define HALL_EXTI_IRQn GPIOB_IRQn
*/

#define HALL_SPEED_PIN                         LL_GPIO_PIN_10
#define HALL_SPEED_GPIO_PORT                   GPIOA
#define HALL_GPIO_CLK_ENABLE()           LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOA)
#define HALL_SYSCFG_CLK_ENABLE()         LL_APB0_EnableClock(LL_APB0_PERIPH_SYSCFG)
#define HALL_SPEED_EXTI_LINE             LL_EXTI_LINE_PA10
#define HALL_EXTI_IRQn                   GPIOA_IRQn


#define HALL_EXTI_LINE_ENABLE()          LL_EXTI_EnableIT(HALL_EXTI_IRQn)
#define HALL_EXTI_RISING_TRIG_ENABLE()   LL_EXTI_SetTrigger(LL_EXTI_TRIGGER_RISING_EDGE, HALL_SPEED_EXTI_LINE)
#define HALL_EXTI_BOTH_TRIG_ENABLE()   LL_EXTI_SetTrigger(LL_EXTI_TRIGGER_BOTH_EDGE, HALL_SPEED_EXTI_LINE)

#define LED_BLINK_FAST  200
#define LED_BLINK_SLOW  500
#define LED_BLINK_ERROR 1000

/**
  * @brief  TIMx_ARR register maximum value
  */
#define TIMx_ARR_MAX (uint32_t)0xFFFF

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* TIMx interrupt processing */
void TimerCaptureCompare_Callback(void);

#define LED2_PIN                                LL_GPIO_PIN_4
#define LED2_GPIO_PORT                          GPIOB
#define LED2_GPIO_CLK_ENABLE()                  LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOB)



#define TIMx                                                    TIM17
#define LL_EnableClock_TIMx()                                   LL_APB0_EnableClock(LL_APB0_PERIPH_TIM17)
#define LL_EnableClock_TIMx_CH1()                               LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOA)
#define TIMx_IRQHandler                                         TIM17_IRQHandler
#define TIMx_IRQn                                               TIM17_IRQn

  /**TIM GPIO Configuration
  PB3 / AF2   ------> TIM17_CH1
  */

#define TIMx_CH1_PIN                                            LL_GPIO_PIN_3
#define TIMx_CH1_AF                                             LL_GPIO_AF_2
#define TIMx_CH1_PORT                                           GPIOB
#define LL_GPIO_SetAFPin_TIMx_CH1()                             LL_GPIO_SetAFPin_0_7(TIMx_CH1_PORT, TIMx_CH1_PIN, TIMx_CH1_AF);

void freq_sensor_init(void);
void freq_measure_task(void);
void HallSpeed_Callback(uint32_t ticks);
void HALLSpeed_RestCounter(void);



#endif /* APPLICATION_USER_FREQ_SENSOR_H_ */
