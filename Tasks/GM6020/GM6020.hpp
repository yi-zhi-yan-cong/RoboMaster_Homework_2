#ifndef _GM6020_H_
#define _GM6020_H_

#include "main.h"




class GM6020 {
  public:
    GM6020(uint32_t id) { id_ = id; };
    ~GM6020() = default;
    uint32_t txId(void);
    uint32_t rxId(void);
    float angle(void){ return angle_; };
    float vel(void){ return vel_; };
    float current(void){ return current_; };
    float temp(void){ return temp_; };
    void setInput(float current);
    bool encode(uint8_t *data);
    bool decode(uint8_t *data);
  private:
    uint32_t id_;
    float input_;
    float angle_;
    float vel_;
    float current_;
    float temp_;
};





#endif