/*
 * Projekt 25 Zive - IT projekty , JER - konverzia projektu ST-Microelectronics example - BLUENRG
 *
 * */
   
#include "rf_driver_ll_adc.h"
#include "rf_driver_ll_rcc.h"
#include "rf_driver_ll_bus.h"
#include "rf_driver_ll_system.h"
#include "rf_driver_ll_exti.h"
#include "rf_driver_ll_cortex.h"
#include "rf_driver_ll_utils.h"
#include "rf_driver_ll_pwr.h"
#include "rf_driver_ll_dma.h"
#include "rf_driver_ll_gpio.h"
#if defined(CONFIG_DEVICE_BLUENRG_LP) || defined(CONFIG_DEVICE_BLUENRG_LPS)
#include "bluenrg_lpx.h"
#include "bluenrg_lp_evb_config.h"
#endif
#if defined(USE_FULL_ASSERT)
#include "rf_driver_assert.h"
#endif /* USE_FULL_ASSERT */

#include "calibration.h"
#include "ble_anemometer.h"


/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#if defined(CONFIG_DEVICE_BLUENRG_LP)
#define USER_SAMPLERATE       (LL_ADC_SAMPLE_RATE_28)
#endif
#if defined(CONFIG_DEVICE_BLUENRG_LPS)
#define USER_SAMPLERATE_MSB       (LL_ADC_SAMPLE_RATE_MSB_4)
#define USER_SAMPLERATE           (LL_ADC_SAMPLE_RATE_0)
#endif

#define USER_DATAWIDTH        (LL_ADC_DS_DATA_WIDTH_16_BIT)
#define USER_RATIO            (LL_ADC_DS_RATIO_128)

#define BUFFER_SIZE           (5)

/* Private macro -------------------------------------------------------------*/
#define PRINT_INT(x)    ((int)(x))
#define PRINT_FLOAT(x)  (x>0)? ((int) (((x) - PRINT_INT(x)) * 1000)) : (-1*(((int) (((x) - PRINT_INT(x)) * 1000))))



/* Private variables ---------------------------------------------------------*/
static uint16_t aDST_Buffer[BUFFER_SIZE];
int8_t offset_vinp0 = 0;
int8_t offset_vinm0 = 0;

BLE_Anemometer_data_t anemodata = {};



/* Private function prototypes -----------------------------------------------*/
static void APP_ADC_Init(void);
static void APP_DMA_Init(void);
static void APP_GPIO_Init(void);

/* Private user code ---------------------------------------------------------*/


void APP_Init(void)
{
	float adcValue = 0.0;



	  /* BSP Init */
	 APP_GPIO_Init();

	  /* Set systick to 1ms using system clock frequency */
	 // LL_Init1msTick(SystemCoreClock);

	  /* Initialize all configured peripherals */
	  APP_ADC_Init();
	  APP_DMA_Init();

	  /* Set DMA transfer addresses of source and destination */
	  LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_1,
	                         LL_ADC_GetOutputDataRegDS(ADC),
	                         (uint32_t)&aDST_Buffer,
	                         LL_DMA_DIRECTION_PERIPH_TO_MEMORY);

	  /* Set DMA transfer size */
	 // LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, BUFFER_SIZE);

	  /* Enable DMA transfer complete/error interrupts */
	  LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_1);

	  /* Start the DMA transfer */
	  LL_ADC_DMAModeDSEnable(ADC);
	 // LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);

	  // LL_ADC_StartConversion(ADC);

}

void APP_Reload(void)
{

}

void APP_Tick(void)
{



	LL_DMA_SetMemoryAddress(DMA1, LL_DMA_CHANNEL_1, (uint32_t)&aDST_Buffer);
	LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, BUFFER_SIZE);
	LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);


	LL_ADC_StartConversion(ADC);

	while(!LL_ADC_IsActiveFlag_EOS(ADC));
	LL_ADC_ClearFlag_EOS(ADC);

	/*if( LL_ADC_IsActiveFlag_EOS(ADC) == 1) {
	  LL_ADC_ClearFlag_EOS(ADC);
	}*/

	BSP_COM_Init(NULL);
	/* Check the DMA flag Transfer Complete on channel 1 */
	if( LL_DMA_IsActiveFlag_TC1(DMA1) == 1) {
	  LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_1);


	  /**
	   * Nacitanie hodnot adc , urcit z ADC pin 1, pin 2 uhol na zaklade kalibracnej tabulky
	   * */

	  float adc1 = (float)LL_ADC_GetADCConvertedValueSingle(ADC, aDST_Buffer[0], LL_ADC_VIN_RANGE_3V6, USER_DATAWIDTH, offset_vinp0);
	  float adc2 = (float)LL_ADC_GetADCConvertedValueSingle(ADC, aDST_Buffer[1], LL_ADC_VIN_RANGE_3V6, USER_DATAWIDTH, offset_vinm0);
	  float temp =  LL_ADC_GetADCConvertedValueTemp(ADC, aDST_Buffer[4], USER_DATAWIDTH)/100.0;
	  float batt = LL_ADC_GetADCConvertedValueBatt(ADC, aDST_Buffer[3], USER_DATAWIDTH, 0);

	  anemodata.angle_deg = anemometer_adc2angle(adc1, adc2);
	  anemodata.speed_ms++;
	  anemodata.batt = (uint16_t)batt;
	  anemodata.temp = (uint16_t)temp;
	  /*
	  float

	  adcValue = (float)LL_ADC_GetADCConvertedValueSingle(ADC, aDST_Buffer[0], LL_ADC_VIN_RANGE_3V6, USER_DATAWIDTH, offset_vinp0);
	  printf("ADC pin 1 %d.%03d mV\r\n", PRINT_INT(adcValue),PRINT_FLOAT(adcValue));
	  adcValue = (float)LL_ADC_GetADCConvertedValueSingle(ADC, aDST_Buffer[1], LL_ADC_VIN_RANGE_3V6, USER_DATAWIDTH, offset_vinm0);
	  printf("ADC pin 2 %d.%03d mV\r\n", PRINT_INT(adcValue),PRINT_FLOAT(adcValue));
	  adcValue = (float)LL_ADC_GetADCConvertedValueDiff(ADC, aDST_Buffer[2], LL_ADC_VIN_RANGE_3V6, USER_DATAWIDTH, 0);
	  printf("ADC differential %d.%03d mV\r\n", PRINT_INT(adcValue),PRINT_FLOAT(adcValue));
	  anemodata.batt = adcValue = (float)LL_ADC_GetADCConvertedValueBatt(ADC, aDST_Buffer[3], USER_DATAWIDTH, 0);
	  printf("Battery voltage %d.%03d mV\r\n", PRINT_INT(adcValue),PRINT_FLOAT(adcValue));
	  anemodata.batt = adcValue = LL_ADC_GetADCConvertedValueTemp(ADC, aDST_Buffer[4], USER_DATAWIDTH)/100.0;
	  printf("Temperature %d.%02d %cC\r\n\n", PRINT_INT(adcValue),PRINT_FLOAT(adcValue), 248);
*/
	  /* Clear the DMA flag Transfer Complete on channel 1 */
	  LL_DMA_ClearFlag_TC1(DMA1);

	  /* Toggle the conversion/activity LED */
	  //BSP_LED_Toggle(BSP_LED2);



	}

	/* Check the ADC flag overrun of Down Sampler */
	if( LL_ADC_IsActiveFlag_OVRDS(ADC) == 1) {

	  /* Clear the ADC flag overrun of Down Sampler */
	  LL_ADC_ClearFlag_OVRDS(ADC);

	  /* Turn on the LED2 if overrun occurs */
	  BSP_LED_On(BSP_LED3);
	}

	/* Check the DMA flag Transfer Error on channel 1 */
	if( LL_DMA_IsActiveFlag_TE1(DMA1) == 1) {

	  /* Clear the DMA flag Transfer Error on channel 1 */
	  LL_ADC_ClearFlag_OVRDS(ADC);

	  /* Turn on the LED2 if transfer error occurs */
	  BSP_LED_On(BSP_LED3);
	}
}




static void APP_GPIO_Init(void)
{
  
  LL_GPIO_InitTypeDef  gpioinitstruct = {0};
  LL_GPIO_StructInit(&gpioinitstruct);
  /* Initialization of the ADC pins */
  LL_AHB_EnableClock(LL_AHB_PERIPH_GPIOB);
  gpioinitstruct.Pin = LL_GPIO_PIN_2 | LL_GPIO_PIN_3;
  gpioinitstruct.Mode = LL_GPIO_MODE_ANALOG;
  gpioinitstruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
  gpioinitstruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;  
  gpioinitstruct.Pull = LL_GPIO_PULL_NO;  
  LL_GPIO_Init(GPIOB, &gpioinitstruct);
  
}


/**
  * @brief ADC Initialization Function
  * @param None
  * @retval None
  */
static void APP_ADC_Init(void)
{
  /* Peripheral clock enable */
  LL_APB1_EnableClock(LL_APB1_PERIPH_ADCDIG | LL_APB1_PERIPH_ADCANA);

  /* This function must not be called on QFN32 package */
#if defined(CONFIG_DEVICE_BLUENRG_LP) || defined(CONFIG_DEVICE_BLUENRG_LPS)
  LL_ADC_LDOEnable(ADC);
#endif

  /* Enable the ADC */
  LL_ADC_Enable(ADC);

  /* Configure the sample rate */
#if defined(CONFIG_DEVICE_BLUENRG_LP)
  LL_ADC_SetSampleRate(ADC, USER_SAMPLERATE);
#endif
#if defined(CONFIG_DEVICE_BLUENRG_LPS)
  LL_ADC_SetSampleRate(ADC, USER_SAMPLERATE_MSB, USER_SAMPLERATE);
#endif

  /* Configure the Down Sampler data width and ratio */
  LL_ADC_ConfigureDSDataOutput(ADC, USER_DATAWIDTH, USER_RATIO);

  /* Configure the operation mode as ADC mode (static/low frequency signal) */
  LL_ADC_SetADCMode(ADC, LL_ADC_OP_MODE_ADC);

  /* Start the sampling at end of previous sample */
  LL_ADC_InputSamplingMode(ADC, LL_ADC_SAMPLING_AT_END);

  /* Set the length of the conversion sequence as 5 */
  LL_ADC_SetSequenceLength(ADC, LL_ADC_SEQ_LEN_05);
  
  /* Set the 1st entry of the input sequence as VINP0 */
  LL_ADC_SetChannelSeq0(ADC, LL_ADC_CH_VINP0_TO_SINGLE_POSITIVE_INPUT);
  LL_ADC_SetVoltageRangeSingleVinp0(ADC, LL_ADC_VIN_RANGE_3V6);
  if(LL_ADC_GET_CALIB_GAIN_FOR_VINPX_3V6() != 0xFFF) {
    LL_ADC_SetCalibPoint1Gain(ADC, LL_ADC_GET_CALIB_GAIN_FOR_VINPX_3V6() );
  
    offset_vinp0 = LL_ADC_GET_CALIB_OFFSET_FOR_VINPX_3V6();
#ifdef CONFIG_DEVICE_BLUENRG_LP
    if(offset_vinp0 < -64 || offset_vinp0 > 63) {
      LL_ADC_SetCalibPoint1Offset(ADC, 0);
    }
    else
#endif
    {
      LL_ADC_SetCalibPoint1Offset(ADC, offset_vinp0);
      offset_vinp0 = 0;
    }
  }
  else {
    LL_ADC_SetCalibPoint1Gain(ADC, LL_ADC_DEFAULT_RANGE_VALUE_3V6);
  }
  LL_ADC_SetCalibPointForSinglePos3V6(ADC, LL_ADC_CALIB_POINT_1);

  /* Set the 2nd entry of the input sequence as VINM0 */
  LL_ADC_SetChannelSeq1(ADC, LL_ADC_CH_VINM0_TO_SINGLE_NEGATIVE_INPUT);
  LL_ADC_SetVoltageRangeSingleVinm0(ADC, LL_ADC_VIN_RANGE_3V6);
  if(LL_ADC_GET_CALIB_GAIN_FOR_VINMX_3V6() != 0xFFF) {
    LL_ADC_SetCalibPoint2Gain(ADC, LL_ADC_GET_CALIB_GAIN_FOR_VINMX_3V6() );

    offset_vinm0 = LL_ADC_GET_CALIB_OFFSET_FOR_VINMX_3V6();
#ifdef CONFIG_DEVICE_BLUENRG_LP
    if(offset_vinm0 < -64 || offset_vinm0 > 63) {
      LL_ADC_SetCalibPoint2Offset(ADC, 0);
    }
    else
#endif
    {
      LL_ADC_SetCalibPoint2Offset(ADC, offset_vinm0);
      offset_vinm0 = 0;
    }
  }
  else {
    LL_ADC_SetCalibPoint2Gain(ADC, LL_ADC_DEFAULT_RANGE_VALUE_3V6);
  }
  LL_ADC_SetCalibPointForSingleNeg3V6(ADC, LL_ADC_CALIB_POINT_2);
  
  /* Set the 3rd entry of the input sequence as differential (VINP0-VINM0) */
  LL_ADC_SetChannelSeq2(ADC, LL_ADC_CH_VINP0_VINM0_TO_DIFF_INPUT);
  LL_ADC_SetVoltageRangeDiffVinp0Vinm0(ADC, LL_ADC_VIN_RANGE_3V6);
  if(LL_ADC_GET_CALIB_GAIN_FOR_VINDIFF_3V6() != 0xFFF) {
    LL_ADC_SetCalibPoint3Gain(ADC, LL_ADC_GET_CALIB_GAIN_FOR_VINDIFF_3V6() );
    LL_ADC_SetCalibPoint3Offset(ADC, LL_ADC_GET_CALIB_OFFSET_FOR_VINDIFF_3V6() );
  }
  else {
    LL_ADC_SetCalibPoint3Gain(ADC, LL_ADC_DEFAULT_RANGE_VALUE_3V6);
  }
  LL_ADC_SetCalibPointForDiff3V6(ADC, LL_ADC_CALIB_POINT_3);
  
  /* Set the 4th entry of the input sequence as battery level detector */
  LL_ADC_SetChannelSeq3(ADC, LL_ADC_CH_BATTERY_LEVEL_DETECTOR);
  
  /* Set the 5th entry of the input sequence as temperature sensor */
  LL_ADC_SetChannelSeq4(ADC, LL_ADC_CH_TEMPERATURE_SENSOR);
  
#ifdef CONFIG_DEVICE_BLUENRG_LP
  /* Enable the temperature sensor */
  LL_PWR_EnableTempSens();
  
  if(LL_ADC_GET_CALIB_GAIN_FOR_VINPX_1V2() != 0xFFF) {
    LL_ADC_SetCalibPoint4Gain(ADC, LL_ADC_GET_CALIB_GAIN_FOR_VINPX_1V2() );
  }
  else {
    LL_ADC_SetCalibPoint4Gain(ADC, LL_ADC_DEFAULT_RANGE_VALUE_1V2);
  }
#endif
#if defined(CONFIG_DEVICE_BLUENRG_LPS)
    LL_ADC_SetCalibPoint4Gain(ADC, LL_ADC_DEFAULT_RANGE_VALUE_1V2);
#endif
  
  LL_ADC_SetCalibPointForSinglePos1V2(ADC, LL_ADC_CALIB_POINT_4);
}


/**
  * @brief DMA Initialization Function
  * @param None
  * @retval None
  */
static void APP_DMA_Init(void)
{
  /* Init with LL driver */
  /* DMA controller clock enable */
  LL_AHB_EnableClock(LL_AHB_PERIPH_DMA);

  /* Configure DMA request MEMTOMEM_DMA1_Channel1 */

  /* Set the DMA channel 1 with the ADC Down Sampler output */
  LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_1, LL_DMAMUX_REQ_ADC_DS);

  /* Set transfer direction from ADC DS peripheral to RAM memory */
  LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_1, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);

  /* Set priority level */
  LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PRIORITY_HIGH);

  /* Set DMA mode */
  LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MODE_NORMAL);

  /* Set peripheral increment mode to no increment */
  LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PERIPH_NOINCREMENT);

  /* Set memory increment mode to increment */
  LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MEMORY_INCREMENT);

  /* Set peripheral data width to 16-bit */
  LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_PDATAALIGN_HALFWORD);

  /* Set memory data width to 16-bit */
  LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_1, LL_DMA_MDATAALIGN_HALFWORD);

}


/******************************************************************************/
/*   USER IRQ HANDLER TREATMENT                                               */
/******************************************************************************/



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
     ex: printf("Wrong parameters value: file %s on line %d", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
