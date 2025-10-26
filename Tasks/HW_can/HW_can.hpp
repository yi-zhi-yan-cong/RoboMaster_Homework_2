/**
 *******************************************************************************
 * @file      :HW_can.hpp
 * @brief     :
 * @history   :
 *  Version     Date            Author          Note
 *  V1.0.0      yyyy-mm-dd      <author>        1。<note>
 *******************************************************************************
 * @attention :
 *******************************************************************************
 *  Copyright (c) 2025 Hello World Team,Zhejiang University.
 *  All Rights Reserved.
 *******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _HW_CAN_H_
#define _HW_CAN_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "GM6020.hpp"
#include "can.h"
/* Exported macro ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
extern GM6020 motors[7];  //引入全局变量motors，方便接收函数更新

void CanFilter_Init(CAN_HandleTypeDef *hcan);

void CAN_Send_Msg(CAN_HandleTypeDef *hcan, uint8_t *msg, uint32_t id,
                  uint8_t len);



#endif /* _HW_CAN_H_ */
