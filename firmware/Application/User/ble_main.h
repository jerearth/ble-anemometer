/*
 * ble_main.h
 *
 *  Created on: Dec 18, 2024
 *      Author: radoslav
 */

#ifndef APPLICATION_USER_BLE_MAIN_H_
#define APPLICATION_USER_BLE_MAIN_H_

#include "bluenrg_lp_stack.h"
#include "stack_user_cfg.h"



#ifndef _POWER_CONSUMPTION_TEST_PARAMETERS_H_
#define _POWER_CONSUMPTION_TEST_PARAMETERS_H_

#include "system_BlueNRG_LP.h"

/* ********************* System and Bluetooth LE clocks configuration ***************/

/* System initialization function. Set the clocks combination with the lowest
   power consumption:
   Sys_CLK = SYSCLK_DIRECT_HSE (system clock frequency is 32 MHz DIRECT HSE with
             HSI OFF);
   BLE_CLK = BLE_SYSCLK_16M (Bluetooth LE system clock frequency is 16 MHz).

   NOTE: This configuration is the lowest power consumption, since the HSI clock
         is disabled during the ACTIVE mode  and the PLL is off.
*/

/* System clock: direct HSE */
#define POWER_CONSUMPTION_DEMO_SYSTEM_CLOCK (SYSCLK_DIRECT_HSE)
/* Bluetoooth LE clock: 16MHz */
#define POWER_CONSUMPTION_DEMO_BLE_CLOCK    (BLE_SYSCLK_16M)

/* ********************* HSE Startup time *******************************************/

/* The High Speed Cystal start up time depends on temperature and voltage levels.
   The recommended value 780 us (320) is covering all the possible conditions
   in terms of temperatures variations and voltage variations [1.7V - 3.3V].

   WARNING: User can potentially reduce this value in order to improve
            power consumption performances for this specific demo case.

*/
#define HS_STARTUP_TIME 210 // [320: 780us];   [210: 512 us]

/* ********************* LSE oscillator drive capability ****************************/

/* LSE oscillator drive capability is set on system_BlueNRG_LP.c.
   LSConfigLSE() function using the LL_RCC_LSE_SetDriveCapability API.

   The recommended value is high drive value (LL_RCC_LSEDRIVE_HIGH):
	LL_RCC_LSE_SetDriveCapability(LL_RCC_LSEDRIVE_HIGH).

   WARNING: User can potentially reduce this value from high to low
            (LL_RCC_LSEDRIVE_MEDIUMHIGH, LL_RCC_LSEDRIVE_MEDIUMLOW, LL_RCC_LSEDRIVE_LOW)
            in order to improve power consumption values, but this change is not recommended
            since it could severely impact the proper device functionality.
*/

#endif // _POWER_CONSUMPTION_TEST_PARAMETERS_H_

/* This file contains all the information needed to init the BlueNRG-1 stack.
 * These constants and variables are used from the BlueNRG-1 stack to reserve RAM and FLASH
 * according the application requests
 */

/* Number of services requests from the micro sleep demo */
#define NUM_APP_GATT_SERVICES_CONF 0

/* Number of attributes requests from the micro sleep demo */
#define NUM_APP_GATT_ATTRIBUTES_CONF 0

/* Number of links needed for the demo: 1
 * Only 1 the default
 */
#define NUM_LINKS                                    (CONFIG_NUM_MAX_LINKS)

#define NUM_ADV_SETS_CONF                            (2U)
#define NUM_AUX_SCAN_SLOTS_CONF                      (2U)
#define NUM_SYNC_SLOTS_CONF                          (0U)
#define WHITE_LIST_SIZE_LOG2_CONF                    (3U)
#define L2CAP_MPS_CONF                               (247U)
#define NUM_L2CAP_COCS_CONF                          (0U)
#define MAX_NUM_CTE_ANTENNA_IDS                 (0U)
#define MAX_NUM_CTE_IQ_SAMPLES                  (0U)

#define ISR0_FIFO_SIZE   (256)
#define ISR1_FIFO_SIZE   (768)
#define USER_FIFO_SIZE   (1024)

/* Number of GATT attributes needed for the micro sleep demo. */
#define NUM_GATT_ATTRIBUTES     (NUM_APP_GATT_SERVICES_CONF + NUM_APP_GATT_ATTRIBUTES_CONF)

/* Set supported max value for ATT_MTU enabled by the application. Allowed values in range: [23:158] [New parameter added on BLE stack v2.x] */
#define MAX_ATT_MTU_CONF             (BLE_STACK_DEFAULT_ATT_MTU)

/* Additional number of memory blocks  to be added to the minimum */
#define OPT_MBLOCKS_CONF		(6) /* 6:  for reaching the max throughput: ~220kbps (same as BLE stack 1.x) */

/* Number of EATT channels */
#define NUM_EATT_CHANNELS                           (0U)

/* Set the number of memory block for packet allocation */
#define MBLOCKS_COUNT            (BLE_STACK_MBLOCKS_CALC(MAX_ATT_MTU_CONF, NUM_LINKS, NUM_EATT_CHANNELS) + OPT_MBLOCKS_CONF)

#define NUM_OF_CONCURRENT_GATT_CLIENT_PROC_CONF         (0)

/* RAM reserved to manage all the data stack according the number of links,
 * number of services, number of attributes and attribute value length
 */
#define DYNAMIC_MEMORY_SIZE (BLE_STACK_TOTAL_BUFFER_SIZE(NUM_LINKS,NUM_EATT_CHANNELS,NUM_GATT_ATTRIBUTES,NUM_OF_CONCURRENT_GATT_CLIENT_PROC_CONF,MBLOCKS_COUNT,\
                                                         NUM_ADV_SETS_CONF,NUM_AUX_SCAN_SLOTS_CONF,WHITE_LIST_SIZE_LOG2_CONF,NUM_L2CAP_COCS_CONF,\
                                                         NUM_SYNC_SLOTS_CONF, MAX_NUM_CTE_ANTENNA_IDS, MAX_NUM_CTE_IQ_SAMPLES, \
                                                         ISR0_FIFO_SIZE, ISR1_FIFO_SIZE, USER_FIFO_SIZE))
/* Maximum duration of the connection event */
#define MAX_CONN_EVENT_LENGTH_CONF 0xFFFFFFFF

#define CALIBRATION_INTERVAL_CONF   10000

#if defined CONFIG_HW_LS_RO

/* Sleep clock accuracy. */
#define SLEEP_CLOCK_ACCURACY        500

/* Calibration must be done */
#define INITIAL_CALIBRATION         TRUE
#define CALIBRATION_INTERVAL        CALIBRATION_INTERVAL_CONF

#elif defined CONFIG_HW_LS_XTAL

/* Sleep clock accuracy. */
#define SLEEP_CLOCK_ACCURACY        100

/* No Calibration */
#define INITIAL_CALIBRATION         FALSE
#define CALIBRATION_INTERVAL        0

#endif

#ifndef HS_STARTUP_TIME
/* High Speed start up time */
#define HS_STARTUP_TIME 320 // 780 us
#endif

/* Radio Config Hot Table */
extern uint8_t hot_table_radio_config[];

/* This structure contains memory and low level hardware configuration data for the device */
#define BLE_STACK_INIT_PARAMETERS {                                             \
    .BLEStartRamAddress = (uint8_t*)dyn_alloc_a,                                \
    .TotalBufferSize = DYNAMIC_MEMORY_SIZE,                                     \
    .NumAttrRecords = NUM_GATT_ATTRIBUTES,                                      \
    .MaxNumOfClientProcs = NUM_OF_CONCURRENT_GATT_CLIENT_PROC_CONF,             \
    .NumOfLinks = NUM_LINKS,                                                    \
    .NumOfEATTChannels = NUM_EATT_CHANNELS,                                     \
    .NumBlockCount = MBLOCKS_COUNT,                                             \
    .ATT_MTU = MAX_ATT_MTU_CONF,                                                \
    .MaxConnEventLength = MAX_CONN_EVENT_LENGTH_CONF,                           \
    .SleepClockAccuracy = SLEEP_CLOCK_ACCURACY,                                 \
    .NumOfAdvDataSet = NUM_ADV_SETS_CONF,                                       \
    .NumOfAuxScanSlots = NUM_AUX_SCAN_SLOTS_CONF,                               \
    .WhiteListSizeLog2 = WHITE_LIST_SIZE_LOG2_CONF,                             \
    .L2CAP_MPS = L2CAP_MPS_CONF,                                                \
    .L2CAP_NumChannels = NUM_L2CAP_COCS_CONF,                                   \
    .NumOfSyncSlots = NUM_SYNC_SLOTS_CONF,                                      \
    .CTE_MaxNumAntennaIDs = MAX_NUM_CTE_ANTENNA_IDS,                            \
    .CTE_MaxNumIQSamples = MAX_NUM_CTE_IQ_SAMPLES, 		         	\
    .isr0_fifo_size = ISR0_FIFO_SIZE,                                           \
    .isr1_fifo_size = ISR1_FIFO_SIZE,                                           \
    .user_fifo_size = USER_FIFO_SIZE                                            \
}



#endif /* APPLICATION_USER_BLE_MAIN_H_ */
