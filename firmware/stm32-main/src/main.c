#include "main.h"
#include "debug.h"

USBD_HandleTypeDef hUSBDDevice;

static void SystemClock_Config(void);

int main(void)
{
    HAL_Init();

    SystemClock_Config();

    BSP_LED_Init(LED3);
    BSP_LED_Init(LED4);
    BSP_LED_Init(LED5);
    BSP_LED_Init(LED6);

    /* SysTick end of count event each 10ms */
    SystemCoreClock = HAL_RCC_GetHCLKFreq();
    SysTick_Config(SystemCoreClock / 100);

    #ifdef _DEBUG
    BSP_LED_On(LED3);
    BSP_LED_On(LED6);
        HAL_Delay(100);
    BSP_LED_Off(LED3);
    BSP_LED_Off(LED6);
    #endif

        debug("Starting USB Demo\n");

    USBD_Init(&hUSBDDevice, &HID_Desc,0);

        debug("\tUSB_Init() finished\n");

    USBD_RegisterClass(&hUSBDDevice, &USBD_CUSTOM_HID);

        debug("\tUSBD_RegisterClass() finished\n");

    /* Add Custom HID callbacks */
    USBD_CUSTOM_HID_RegisterInterface(&hUSBDDevice, &USBD_CustomHID_fops);

        debug("\tUSBD_CUSTOM_HID_RegisterInterface() finished\n");

    USBD_Start(&hUSBDDevice);

        debug("USB Demo started\n");
    //USBD_Stop(&hUSBDDevice);
    //USBD_DeInit(&hUSBDDevice);

  while(1)
  {

  }
}


//User send data to host
void HAL_SYSTICK_Callback(void){
    //uint8_t buf[64];
    //buf[0]=0x0;
    //buf[1]=0x1;
    //USBD_CUSTOM_HID_SendReport(&hUSBDDevice,buf,64);

}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 336
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void){
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

  /* STM32F405x/407x/415x/417x Revision Z devices: prefetch is supported  */
  if (HAL_GetREVID() == 0x1001)
  {
    /* Enable the Flash prefetch */
    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
  }
}

void Error_Handler(void){
    BSP_LED_On(LED4);
        debug ("Unrecoverable ERROR occured\n");
    while(1){
        BSP_LED_Toggle(LED4);
        HAL_Delay(100);
    }
}


