/*
 * calibration.h
 *
 *  Created on: Dec 18, 2024
 *      Author: Radoslav Jizdny
 */

#ifndef APPLICATION_USER_CALIBRATION_H_
#define APPLICATION_USER_CALIBRATION_H_

typedef struct
{
	uint16_t hall_adc1;
	uint16_t hall_adc2;
	uint16_t angle;

}Calibration_value_t;


uint8_t anemometer_period2speed(uint16_t period);
uint8_t anemometer_adc2angle(float adc1, float adc2);



#endif /* APPLICATION_USER_CALIBRATION_H_ */
