#include "PID.hpp"

void Pid::setParams(PidParams &params)
{
  params_ = params;
}

PidParams Pid::getParams(void) 
{
  return params_;
}

float Pid::pidCalc(const float ref, const float fdb)
{
  float T = 1;      /*GM6020电机刷新频率为1kHz，这里时间间隔取1ms = 0.001s*/
  float error = ref - fdb;

  float i_error = datas_.integral + error;
  float d_error = error - datas_.last_error;

  float output = params_.kp * error 
                 + params_.ki * i_error * T
                 + params_.kd * d_error / T;

  datas_.integral = i_error;
  datas_.last_error = error;

  return output;
}