/*
 * sds011.h
 *
 *  Created on: 10.03.2019
 *      Author: Pathfinder
 */

#ifndef INC_SDS011_H_
#define INC_SDS011_H_

#include "stm32f4xx_hal.h"

typedef struct SDS_t {
  UART_HandleTypeDef* huart_sds;
  uint16_t pm_2_5;
  uint16_t  pm_10;
  uint8_t data_receive[19];
} SDS;

static const uint8_t Sds011_SleepCommand[] = {
		0xAA,
		0xB4,
		0x06,
		0x01,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0xFF,
		0xFF,
		0x05,
		0xAB
};

static const uint8_t Sds011_WorkingMode[] = {
		0xAA,
		0xB4,
		0x06,
		0x01,
		0x01,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0xFF,
		0xFF,
		0x06,
		0xAB
};

void sdsInit(SDS* sds, const UART_HandleTypeDef* huart_sds);
void sds_uart_RxCpltCallback(SDS* sds, UART_HandleTypeDef *huart);

int8_t sdsSend(SDS* sds, const uint8_t *data_buffer, const uint8_t length);

uint16_t sdsGetPm2_5(SDS* sds);
uint16_t sdsGetPm10(SDS* sds);

int8_t sdsWorkingMode(SDS* sds);
int8_t sdsSleepMode(SDS* sds);

uint8_t getCRC(uint8_t buff[]);

#endif /* SDS011_H_ */
