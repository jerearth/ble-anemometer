/*
 * ble_anemometer.h
 *
 *  Created on: Dec 18, 2024
 *      Author: radoslav
 */

#ifndef APPLICATION_USER_BLE_ANEMOMETER_H_
#define APPLICATION_USER_BLE_ANEMOMETER_H_



typedef struct
{
	uint16_t batt;
	uint16_t temp;
	uint8_t angle_deg;
	uint8_t speed_ms;
	uint16_t reserved;

}BLE_Anemometer_data_t;

extern BLE_Anemometer_data_t anemodata;

void APP_Tick(void);
void APP_Init(void);


#endif /* APPLICATION_USER_BLE_ANEMOMETER_H_ */
