#include "main.h"
#include "GM6020.hpp"

GM6020 motors[7] = {1, 2, 3, 4, 5, 6, 7};   /*定义全局变量motors，用来存放各个电机的状态*/


uint32_t GM6020::txId(void)
{
    return 0x1FE;   /*使用电流控制，表头为0x1FE*/
}

uint32_t GM6020::rxId(void)
{
    return 0x204 + id_;   /*电机id设置为1*/
}

void GM6020::setInput(float current)
{
  input_ = current;
  if(current > 3)
    input_ = 3;     /*电机最大转矩电流为3A*/
  else if (current < -3)
    input_ = -3;
  
}

bool GM6020::encode(uint8_t *data) 
{
  /*电流范围: -3A ~ +3A → CAN数据: -16384 ~ +16384*/
  int16_t current_can = static_cast<int16_t>(input_ * (16384.0f / 3.0f));
    
  /*拆分数据*/
  uint8_t high_byte = (current_can >> 8) & 0xFF;
  uint8_t low_byte = current_can & 0xFF;
    
  /*确定数组中的位置*/
  int position = (id_ - 1) % 4;  
  int byte_offset = position * 2;   
    
  data[byte_offset] = high_byte;
  data[byte_offset + 1] = low_byte;
    
  return true;
}

bool GM6020::decode(uint8_t *data) 
{

  /*解码角度*/
  uint16_t raw_angle = (data[0] << 8) | data[1];
  angle_ = (raw_angle * 2.0f * 3.1415926) / 8191.0f;
    
  /*解码速度*/
  int16_t raw_vel = (data[2] << 8) | data[3];
  vel_ = static_cast<float>(raw_vel);
    
  /*解码电流*/ 
  int16_t raw_current = (data[4] << 8) | data[5];
  current_ = raw_current * (3.0f / 16384.0f);
    
  /*解析温度*/
  temp_ = static_cast<float>(data[6]);
    
  return true;
}
