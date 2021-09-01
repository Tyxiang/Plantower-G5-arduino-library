#include <G5.h>

G5::G5(int pin)
{
  _rx_pin = pin;
  _tx_pin = pin;
}

void G5::begin()
{
  _SSerial.begin(9600, SWSERIAL_8N1, _rx_pin, _tx_pin, false, 64);
}

void G5::update()
{
  int s;
  byte array_length[2];
  int int_length;
  byte array_data[28];
  int int_cs_in_frame;
  int int_cs_calculated;
  for (int i = 0; i <= 99; i++) 
  { 
    // Serial.print("i:");
    // Serial.print(i);
    // Serial.print(" ");
    if (_SSerial.available() <= 0)
    {
      delay(100);
      //doService(100);
    }
    else
    {
      if (s == 0)
      {
        if (_SSerial.read() == 0x42)
        {
          s++;
        }
        else
        {
          s = 0;
        }
      }
      if (s == 1)
      {
        if (_SSerial.read() == 0x4d)
        {
          s++;
        }
        else
        {
          s = 0;
        }
      }
      if (s == 2)
      {
        array_length[0] = _SSerial.read();
        s++;
      }
      if (s == 3)
      {
        array_length[1] = _SSerial.read();
        int_length = array_length[0] * 256 + array_length[1];
        if (int_length == 28)
        {
          s++;
        }
        else
        {
          s = 0;
        }
      }
      if (s == 4)
      {
        for (int i = 0; i < 28; i++)
        {
          array_data[i] = _SSerial.read();
        }
        //cs
        int_cs_calculated = 0x42 + 0x4d + array_length[0] + array_length[1];
        for (int i = 0; i < 26; i++)
        {
          int_cs_calculated = int_cs_calculated + array_data[i];
        }
        int_cs_calculated = 0x0000FFFF & int_cs_calculated;
        //Serial.print("int_cs_calculated:");
        //Serial.println(int_cs_calculated);
        int_cs_in_frame = array_data[26] * 256 + array_data[27];
        //Serial.print("int_cs_in_frame:");
        //Serial.println(int_cs_in_frame);
        if (int_cs_in_frame == int_cs_calculated)
        {
          s++;
        }
        else
        {
          s = 0;
        }
      }
      if (s == 5)
      {
        pm1_0CF1 = array_data[0] * 256 + array_data[1];
        pm2_5CF1 = array_data[2] * 256 + array_data[3];
        pm10_CF1 = array_data[4] * 256 + array_data[5];

        pm1_0ATM = array_data[6] * 256 + array_data[7];
        pm2_5ATM = array_data[8] * 256 + array_data[9];
        pm10_ATM = array_data[10] * 256 + array_data[11];

        pm0_3QTY = array_data[12] * 256 + array_data[13];
        pm0_5QTY = array_data[14] * 256 + array_data[15];
        pm1_0QTY = array_data[16] * 256 + array_data[17];
        pm2_5QTY = array_data[18] * 256 + array_data[19];
        pm5_0QTY = array_data[20] * 256 + array_data[21];
        pm10_QTY = array_data[22] * 256 + array_data[23];

        version = array_data[24];
        error = array_data[25];
        break;
      }
    }
  }
}
