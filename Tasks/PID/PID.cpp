#include "PID.hpp"

void Pid::setParams(PidParams &params)
{
  params_ = params;
}

PidParams Pid::getParams(void) 
{
  return params_;
}


float Pid::pidCalc(const float ref, const float fdb, const float T)
{
  float error = ref - fdb;
  
  float last_error = datas_.last_error;
  float integral = datas_.integral + error * T;     
  float derivative = (error - datas_.last_error) / T;

  datas_.integral += integral;
  if (datas_.integral > params_.integral_limit) 
    datas_.integral = params_.integral_limit;
  else if (datas_.integral < -params_.integral_limit) 
    datas_.integral = -params_.integral_limit;
  

  float output = params_.kp * error 
                 + params_.ki * integral 
                 + params_.kd * derivative;
  datas_.last_error = error;


  if (output > params_.output_limit) 
    output = params_.output_limit;
  else if (output < -params_.output_limit) 
    output = -params_.output_limit;

  return output;
}