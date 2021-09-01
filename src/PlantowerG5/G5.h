#include "Arduino.h"
#include <SoftwareSerial.h>

class G5 {
  public:
    G5(int pin);
    void begin();
    void update();
    int pm1_0CF1 = 0;
    int pm2_5CF1 = 0;
    int pm10_CF1 = 0;
    //
    int pm1_0ATM = 0;
    int pm2_5ATM = 0;
    int pm10_ATM = 0;
    //
    int pm0_3QTY = 0;
    int pm0_5QTY = 0;
    int pm1_0QTY = 0;
    int pm2_5QTY = 0;
    int pm5_0QTY = 0;
    int pm10_QTY = 0;
    //
    int version = 0;
    int error = 9999;
  private:
    int _tx_pin;
    int _rx_pin;
	  SoftwareSerial _SSerial;
};

