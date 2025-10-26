#ifndef _PID_H_
#define _PID_H_

#include "main.h"

struct PidParams{
  float kp;
  float ki;
  float kd;
  float integral_limit;   // 新增：积分限幅
  float output_limit;     // 新增：输出限幅
};

struct PidData{
  float integral;
  float last_error;
};

class Pid {
  public:
    Pid(PidParams &params) { params_ = params; 
                             datas_.integral = datas_.last_error = 0;};
    ~Pid() = default;
    void setParams(PidParams &params);
    PidParams getParams(void);
    float pidCalc(const float ref, const float fdb, const float T);
  private:
    PidParams params_;
    PidData datas_;
    //PidData last_datas_;

};

#endif