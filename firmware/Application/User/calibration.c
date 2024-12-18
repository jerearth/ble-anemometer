/*
 * Projekt 25 Zive - IT projekty, JER - konverzia projektu ST-Microelectronics example - BLUENRG
 *
 * calibration.c
 *
 *  Created on: Dec 18, 2024
 *      Author: Radoslav Jizdny
 *
 */


#include <stdint.h>
#include "calibration.h"

//degrees
static Calibration_value_t calibration_table_direction[] =
{
		{0xABC,0xABC, 0},
		{0xABC,0xABC, 30},
		{0xABC,0xABC, 60},
		{0xABC,0xABC, 90},
		{0xABC,0xABC, 120},
		{0xABC,0xABC, 150},
		{0xABC,0xABC, 180},
		{0xABC,0xABC, 210},
		{0xABC,0xABC, 240},
		{0xABC,0xABC, 270},
		{0xABC,0xABC, 300},
		{0xABC,0xABC, 330}
};

//input hall frequency period to wind m/s
static uint16_t calibration_table_speed[][2] =
{
		{0xABC, 15},
		{0xABC, 25},
		{0xABC, 35},
		{0xABC, 45},
		{0xABC, 55}
};

//linear interpolation function  adc12_angle, dutycycle2speed
uint8_t anemometer_adc2angle(float adc1, float adc2) // converted adcvolt
{

	//1 bit = 360/256
	return (uint8_t)(0xFF*calibration_table_direction[0].angle)/360;
}

uint8_t anemometer_period2speed(uint16_t period)
{

   uint8_t findedRow = 0;
	return (uint8_t)(calibration_table_speed[findedRow][1]);
}

