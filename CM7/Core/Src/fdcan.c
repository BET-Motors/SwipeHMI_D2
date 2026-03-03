/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    fdcan.c
  * @brief   This file provides code for the configuration
  *          of the FDCAN instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "fdcan.h"

/* USER CODE BEGIN 0 */
#include <stdio.h>
#include <string.h>
#include "cmsis_os2.h"

static DriverInputsTx_t internalLcpt;
static FuseboxCtrlTx_t internalFBRState;

/* USER CODE END 0 */

FDCAN_HandleTypeDef hfdcan1;
FDCAN_HandleTypeDef hfdcan2;

/* FDCAN1 init function */
void MX_FDCAN1_Init(void)
{

  /* USER CODE BEGIN FDCAN1_Init 0 */
  /* USER CODE END FDCAN1_Init 0 */

  /* USER CODE BEGIN FDCAN1_Init 1 */

  /* USER CODE END FDCAN1_Init 1 */
  hfdcan1.Instance = FDCAN1;
  hfdcan1.Init.FrameFormat = FDCAN_FRAME_FD_NO_BRS;
  hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan1.Init.AutoRetransmission = ENABLE;
  hfdcan1.Init.TransmitPause = DISABLE;
  hfdcan1.Init.ProtocolException = DISABLE;
  hfdcan1.Init.NominalPrescaler = 1;
  hfdcan1.Init.NominalSyncJumpWidth = 1;
  hfdcan1.Init.NominalTimeSeg1 = 41;
  hfdcan1.Init.NominalTimeSeg2 = 38;
  hfdcan1.Init.DataPrescaler = 1;
  hfdcan1.Init.DataSyncJumpWidth = 1;
  hfdcan1.Init.DataTimeSeg1 = 1;
  hfdcan1.Init.DataTimeSeg2 = 1;
  hfdcan1.Init.MessageRAMOffset = 0;
  hfdcan1.Init.StdFiltersNbr = 0;
  hfdcan1.Init.ExtFiltersNbr = 1;
  hfdcan1.Init.RxFifo0ElmtsNbr = 32;
  hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxFifo1ElmtsNbr = 0;
  hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxBuffersNbr = 0;
  hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.TxEventsNbr = 0;
  hfdcan1.Init.TxBuffersNbr = 0;
  hfdcan1.Init.TxFifoQueueElmtsNbr = 32;
  hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
  if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FDCAN1_Init 2 */
	  // --- FILTER CONFIGURATION ---
		// We use one optimized mask to catch all IDs in range 0x10000000 - 0x100000FF
		FDCAN_FilterTypeDef sFilterConfig = {0};

		sFilterConfig.IdType = FDCAN_EXTENDED_ID;
		sFilterConfig.FilterIndex = 0;
		sFilterConfig.FilterType = FDCAN_FILTER_MASK;
		sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;

		// The Base ID: Matches the prefix of your signals
		sFilterConfig.FilterID1 = 0x10000000;

		// The Mask: Check top 24 bits (0x100000...), ignore last 8 bits
		// This allows IDs 0x10000000 to 0x100000FF to pass.
		sFilterConfig.FilterID2 = 0x1FFFFF00;

		if (HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK)
		{
			Error_Handler();
		}

		// Optional: Reject all Standard Frames explicitly
		HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE);

		// --- START FDCAN ---
		if (HAL_FDCAN_Start(&hfdcan1) != HAL_OK)
		{
			Error_Handler();
		}

		// --- ENABLE INTERRUPTS ---
		// Trigger HAL_FDCAN_RxFifo0Callback when a new message arrives
		if (HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
		{
			Error_Handler();
		}
  /* USER CODE END FDCAN1_Init 2 */

}
/* FDCAN2 init function */
void MX_FDCAN2_Init(void)
{

  /* USER CODE BEGIN FDCAN2_Init 0 */

  /* USER CODE END FDCAN2_Init 0 */

  /* USER CODE BEGIN FDCAN2_Init 1 */

  /* USER CODE END FDCAN2_Init 1 */
  hfdcan2.Instance = FDCAN2;
  hfdcan2.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  hfdcan2.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan2.Init.AutoRetransmission = DISABLE;
  hfdcan2.Init.TransmitPause = DISABLE;
  hfdcan2.Init.ProtocolException = DISABLE;
  hfdcan2.Init.NominalPrescaler = 16;
  hfdcan2.Init.NominalSyncJumpWidth = 1;
  hfdcan2.Init.NominalTimeSeg1 = 1;
  hfdcan2.Init.NominalTimeSeg2 = 1;
  hfdcan2.Init.DataPrescaler = 1;
  hfdcan2.Init.DataSyncJumpWidth = 1;
  hfdcan2.Init.DataTimeSeg1 = 1;
  hfdcan2.Init.DataTimeSeg2 = 1;
  hfdcan2.Init.MessageRAMOffset = 0;
  hfdcan2.Init.StdFiltersNbr = 0;
  hfdcan2.Init.ExtFiltersNbr = 0;
  hfdcan2.Init.RxFifo0ElmtsNbr = 0;
  hfdcan2.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan2.Init.RxFifo1ElmtsNbr = 0;
  hfdcan2.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan2.Init.RxBuffersNbr = 0;
  hfdcan2.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
  hfdcan2.Init.TxEventsNbr = 0;
  hfdcan2.Init.TxBuffersNbr = 0;
  hfdcan2.Init.TxFifoQueueElmtsNbr = 0;
  hfdcan2.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  hfdcan2.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
  if (HAL_FDCAN_Init(&hfdcan2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FDCAN2_Init 2 */

  /* USER CODE END FDCAN2_Init 2 */

}

static uint32_t HAL_RCC_FDCAN_CLK_ENABLED=0;

void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspInit 0 */

  /* USER CODE END FDCAN1_MspInit 0 */
    /* FDCAN1 clock enable */
    HAL_RCC_FDCAN_CLK_ENABLED++;
    if(HAL_RCC_FDCAN_CLK_ENABLED==1){
      __HAL_RCC_FDCAN_CLK_ENABLE();
    }

    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**FDCAN1 GPIO Configuration
    PB9     ------> FDCAN1_TX
    PA11     ------> FDCAN1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* FDCAN1 interrupt Init */
    HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
    HAL_NVIC_SetPriority(FDCAN1_IT1_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN1_IT1_IRQn);
  /* USER CODE BEGIN FDCAN1_MspInit 1 */

  /* USER CODE END FDCAN1_MspInit 1 */
  }
  else if(fdcanHandle->Instance==FDCAN2)
  {
  /* USER CODE BEGIN FDCAN2_MspInit 0 */

  /* USER CODE END FDCAN2_MspInit 0 */
    /* FDCAN2 clock enable */
    HAL_RCC_FDCAN_CLK_ENABLED++;
    if(HAL_RCC_FDCAN_CLK_ENABLED==1){
      __HAL_RCC_FDCAN_CLK_ENABLE();
    }

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**FDCAN2 GPIO Configuration
    PB5     ------> FDCAN2_RX
    PB13     ------> FDCAN2_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN2;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* FDCAN2 interrupt Init */
    HAL_NVIC_SetPriority(FDCAN2_IT0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN2_IT0_IRQn);
    HAL_NVIC_SetPriority(FDCAN2_IT1_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN2_IT1_IRQn);
  /* USER CODE BEGIN FDCAN2_MspInit 1 */

  /* USER CODE END FDCAN2_MspInit 1 */
  }
}

void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspDeInit 0 */

  /* USER CODE END FDCAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    HAL_RCC_FDCAN_CLK_ENABLED--;
    if(HAL_RCC_FDCAN_CLK_ENABLED==0){
      __HAL_RCC_FDCAN_CLK_DISABLE();
    }

    /**FDCAN1 GPIO Configuration
    PB9     ------> FDCAN1_TX
    PA11     ------> FDCAN1_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_9);

    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11);

    /* FDCAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(FDCAN1_IT0_IRQn);
    HAL_NVIC_DisableIRQ(FDCAN1_IT1_IRQn);
  /* USER CODE BEGIN FDCAN1_MspDeInit 1 */

  /* USER CODE END FDCAN1_MspDeInit 1 */
  }
  else if(fdcanHandle->Instance==FDCAN2)
  {
  /* USER CODE BEGIN FDCAN2_MspDeInit 0 */

  /* USER CODE END FDCAN2_MspDeInit 0 */
    /* Peripheral clock disable */
    HAL_RCC_FDCAN_CLK_ENABLED--;
    if(HAL_RCC_FDCAN_CLK_ENABLED==0){
      __HAL_RCC_FDCAN_CLK_DISABLE();
    }

    /**FDCAN2 GPIO Configuration
    PB5     ------> FDCAN2_RX
    PB13     ------> FDCAN2_TX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_5|GPIO_PIN_13);

    /* FDCAN2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(FDCAN2_IT0_IRQn);
    HAL_NVIC_DisableIRQ(FDCAN2_IT1_IRQn);
  /* USER CODE BEGIN FDCAN2_MspDeInit 1 */

  /* USER CODE END FDCAN2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

// Use this for your 8-byte messages
uint64_t UnpackSignal(const uint8_t* data, uint8_t start, uint8_t len) {
    uint64_t val = 0;
    memcpy(&val, data, 8); // Safe 8-byte copy
    val >>= start;
    uint64_t mask = (len >= 64) ? 0xFFFFFFFFFFFFFFFFULL : (1ULL << len) - 1;
    return val & mask;
}

void PackSignal(uint64_t* frame, uint32_t value, uint8_t startBit, uint8_t length) {
    uint64_t mask = (1ULL << length) - 1;
    value &= mask; // Ensure value doesn't exceed its bit-length
    *frame |= ((uint64_t)value << startBit);
}

void SafeQueuePut(CAN_Raw_Msg_t* msg) {
    // 1. Check if the queue is full
    // Replace 'osMessageQueueGetCount' with your specific driver call
    if (osMessageQueueGetSpace(guiMQHandle) == 0) {
        CAN_Raw_Msg_t dummy;
        // 2. Remove the oldest message (FIFO behavior)
        // This makes room so the next 'Put' won't block or fail
        osMessageQueueGet(guiMQHandle, &dummy, NULL, 0);
    }

    // 3. Insert the fresh message
    osMessageQueuePut(guiMQHandle, msg, 0, 0);
}

void CanRecvTask(void *argument) {
	FDCAN_RxHeaderTypeDef header;
    CAN_Raw_Msg_t rawMsg;
	const uint32_t taskPeriod = 10;
	uint32_t tick = osKernelGetTickCount();

	while(1)
	{
		tick += taskPeriod;
		osDelayUntil(tick);

		while (HAL_FDCAN_GetRxFifoFillLevel(&hfdcan1, FDCAN_RX_FIFO0) > 0)
		{
			if (HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &header, rawMsg.data) != HAL_OK)
				break;
            
      rawMsg.id = header.Identifier;
      osStatus_t status = osMessageQueuePut(guiMQHandle, &rawMsg, 0, 0);

			if(status != osErrorResource) {
				SafeQueuePut(&rawMsg);
			}

			// CAN_Dispatcher(header.Identifier, rawMsg.data);
		}
		if (HAL_FDCAN_GetRxFifoFillLevel(&hfdcan1, FDCAN_RX_FIFO0) > 0) {
		    osDelay(1);   // give time back deterministically
		}
	}
}

void FDCAN_TxFrame(uint8_t *txd, uint32_t fid, bool extended, uint32_t dlc)
{
    FDCAN_TxHeaderTypeDef txh = {0};
//    uint8_t txd[8] = {0};

    txh.Identifier = fid;
    txh.IdType = (extended == true ? FDCAN_EXTENDED_ID : FDCAN_STANDARD_ID);
    txh.TxFrameType = FDCAN_DATA_FRAME;
    txh.DataLength = dlc;
    txh.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    txh.BitRateSwitch = FDCAN_BRS_OFF;
    txh.FDFormat = FDCAN_CLASSIC_CAN;
    txh.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    txh.MessageMarker = 0;

    HAL_StatusTypeDef st = HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &txh, txd);

    if (st == HAL_OK) {
        HAL_GPIO_TogglePin(USR_LED_1_GPIO_Port, USR_LED_1_Pin); // queued OK
    } else {
        // queued failed (Tx FIFO full / not started / etc.)
    	HAL_GPIO_TogglePin(USR_LED_1_GPIO_Port, USR_LED_1_Pin);
    }
}

/**
 * @brief Serializes the packed struct into a CAN frame.
 * Bit mapping strictly follows driverRequests.csv.
 */
void serialize_DriverInputs(DriverInputsTx_t *s, uint8_t *buf) {
  memset(buf, 0, 8);

  // Byte 0
  buf[0] |= (s->Override_Request & 0x01) << 0;       // Bit 0
  buf[0] |= (s->Drive_Program_Sw & 0x07) << 1;       // Bits 1-3
  buf[0] |= (s->Gear_Actuator_Override & 0x07) << 4; // Bits 4-6
  buf[0] |= (s->DCDC_Request & 0x01) << 7;           // Bit 7

  // Byte 1
  buf[1] |= (s->Air_Sus_Level_Control_Override & 0x0F) << 0; // Bits 8-11
  buf[1] |= (s->Low_Beam_Req & 0x01) << 4;                   // Bit 12
  buf[1] |= (s->High_Beam_Req & 0x01) << 5;                  // Bit 13
  buf[1] |= (s->Position_Light_Req & 0x01) << 6;             // Bit 14
  buf[1] |= (s->Interior_Light_Req & 0x01) << 7;             // Bit 15

  // Byte 2
  buf[2] |= (s->HVHeater_Enable & 0x01) << 0;        // Bit 16
  buf[2] |= (s->HeatPump_Req & 0x01) << 1;           // Bit 17
  buf[2] |= (s->HeatFoil_Req & 0x01) << 2;           // Bit 18
  buf[2] |= (s->LVvalve1_Req & 0x01) << 3;           // Bit 19
  buf[2] |= (s->LVvalve2_Req & 0x01) << 4;           // Bit 20
  buf[2] |= (s->LVvalve3_Req & 0x01) << 5;           // Bit 21
  buf[2] |= (s->Chrg_STOP_Req & 0x01) << 6;          // Bit 22
  buf[2] |= (s->Chrg_PreCond_Req & 0x01) << 7;       // Bit 23

  // Byte 3
  buf[3] |= (s->AirCompressor_Req & 0x01) << 0;      // Bit 24
}

/* Implementation in fdcan.c */
void serialize_FuseboxControl(FuseboxCtrlTx_t *s, uint8_t *buf) {
    // Pack box1_req (Bytes 0-3) - Little Endian
    buf[0] = (uint8_t)(s->box1_req & 0xFF);
    buf[1] = (uint8_t)((s->box1_req >> 8) & 0xFF);
    buf[2] = (uint8_t)((s->box1_req >> 16) & 0xFF);
    buf[3] = (uint8_t)((s->box1_req >> 24) & 0xFF);

    // Pack box2_req (Bytes 4-7) - Little Endian
    buf[4] = (uint8_t)(s->box2_req & 0xFF);
    buf[5] = (uint8_t)((s->box2_req >> 8) & 0xFF);
    buf[6] = (uint8_t)((s->box2_req >> 16) & 0xFF);
    buf[7] = (uint8_t)((s->box2_req >> 24) & 0xFF);
}

void CanTxTask(void *arg)
{
	const uint32_t taskPeriod = 250;
	uint32_t tick = osKernelGetTickCount();
  uint8_t cycle = 0;
  uint8_t txData[8];

	while(1) {
		tick += taskPeriod;
		osDelayUntil(tick);
		if (HAL_FDCAN_GetTxFifoFreeLevel(&hfdcan1) > 0)
		{
      serialize_DriverInputs(&internalLcpt, txData);
			FDCAN_TxFrame(txData, ID_DRIVER_INPUTS_TX, true, FDCAN_DLC_BYTES_8);
		}
    if ((HAL_FDCAN_GetTxFifoFreeLevel(&hfdcan1) > 0) && (cycle % 2 == 0))
		{
      serialize_FuseboxControl(&internalFBRState, txData);
			FDCAN_TxFrame(txData, ID_RELAY_FUSEBOX_CONTROL, true, FDCAN_DLC_BYTES_8);
		}
    cycle = (cycle + 1) % 2;
	}
}

void updateDriverInputs(DriverInputsTx_t data) {
  uint32_t primask = __get_PRIMASK();
	__disable_irq();
  internalLcpt = data; // copy the data atomically
  __set_PRIMASK(primask);
}

void updateFuseBoxRelayControl(FuseboxCtrlTx_t data) {
  uint32_t primask = __get_PRIMASK();
	__disable_irq();
  internalFBRState = data; // copy the data atomically
  __set_PRIMASK(primask);
}
/* USER CODE END 1 */
