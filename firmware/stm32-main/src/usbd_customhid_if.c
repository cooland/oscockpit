/**
  ******************************************************************************
  * @file    usbd_customhid_if_template.c
  * @author  MCD Application Team
  * @version V2.3.0
  * @date    04-November-2014
  * @brief   USB Device Custom HID interface file.
  *		     This template should be copied to the user folder, renamed and customized
  *          following user needs.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usbd_customhid_if.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

static int8_t CUSTOM_HID_Init     (void);
static int8_t CUSTOM_HID_DeInit   (void);
static int8_t CUSTOM_HID_OutEvent (uint8_t* state, uint16_t size);

/* Private variables ---------------------------------------------------------*/
extern USBD_HandleTypeDef USB_Device;

__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
/* //From HID descriptor tool
  0x05, 0x01,			//USAGE_PAGE (Generic Desktop)
  0x09, 0x00,			//USAGE (Undefined)
  0xA1, 0x01,			//COLLECTION (Application)
  0x15, 0x00,			//LOGICAL_MINIMUM (0)
  0x26, 0xFF, 0x00,		//LOGICAL_MAXIMUM (255)
  0x95, 0x3F,			//REPORT_COUNT (63)
  0x75, 0x08,			//REPORT_SIZE (8)
  0x85, 0x01,			//REPORT_ID (1)
  0x09, 0x00,			//USAGE (Undefined)
  0x91, 0x82,			//OUTPUT (Data, Var, Abs, Vol)
  0x85, 0x02,			//REPORT_ID (2)
  0x09, 0x00,			//USAGE (Undefined)
  0x81, 0x82,			//INPUT (Data, Var, Abs, Vol)
  0xC0					//END_COLLECTION
 */

    0x06, 0x00, 0xff, 	// USAGE_PAGE (Vendor defined)
    0x09, 0x00, 		// USAGE (Vendor Usage 0)
    0xa1, 0x01, 		// COLLECTION (Application)
    0x09, 0x01, 		// USAGE(Vendor Usage 1)
	//0x15, 0x00, 		// LOGICAL_MINIMUM (0)
    //0x26, 0xff, 0x00,	// LOGICAL_MAXIMUM (255)
    0x95, 0x3f, 		// REPORT_COUNT (63) 63 bytes
    0x75, 0x08, 		// REPORT_SIZE (8) 8 bits
    0x85, 0x01,			// REPORT_ID (1)
    0x91, 0x82, 		// OUTPUT (Data,Var,Abs,Vol)
    0x09, 0x01, 		// USAGE(Vendor Usage 1)
    0x81, 0x82, 		// INPUT (Data,Var,Abs,Vol)
    0xc0        // END_COLLECTION
    //22


};
//change USBD_CUSTOM_HID_REPORT_DESC_SIZE in usbd_conf.h too

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops =
{
  CUSTOM_HID_ReportDesc,
  CUSTOM_HID_Init,
  CUSTOM_HID_DeInit,
  CUSTOM_HID_OutEvent,
};

/* Private functions ---------------------------------------------------------*/
#ifdef _DEBUG
/*
void TextOut(const char *str)
{
  do {
    if(*str=='\n') ITM_SendChar('\r');
    ITM_SendChar(*str);
  } while(*str++);
}
*/
#endif

/**
  * @brief  CUSTOM_HID_Init
  *         Initializes the CUSTOM HID media low layer
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init(void)
{
return (0);

}

/**
  * @brief  CUSTOM_HID_DeInit
  *         DeInitializes the CUSTOM HID media low layer
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit(void)
{
  /*
     Add your deinitialization code here
  */

  return (0);

}


/**
  * @brief  CUSTOM_HID_Control
  *         Manage the CUSTOM HID class events
  * @param  event_idx: event index
  * @param  state: event state
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent  (uint8_t* state, uint16_t size)
{
    ReadUSBData(state,size);    //in main.c

  return USBD_OK;
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
