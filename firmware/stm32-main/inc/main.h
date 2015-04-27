#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "stm32f4xx_hal.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_customhid.h"
#include "stm32f4_discovery.h"


void ReadUSBData (uint8_t* state, uint16_t size);
void SendUSBData(uint8_t* state, uint16_t size);

#include "usbd_customhid_if.h"

#endif /* MAIN_H_INCLUDED */
