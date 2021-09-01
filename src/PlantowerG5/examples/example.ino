#include <G5.h>

G5 g5(13);

void setup() {
  Serial.begin(115200);
  g5.begin();
}

void loop() {
  g5.update();
  Serial.println();
  Serial.println(g5.pm1_0CF1);  // PM1.0 浓度（CF=1，标准颗粒物）单位μ g/m3
  Serial.println(g5.pm2_5CF1);  // PM2.5 浓度（CF=1，标准颗粒物）单位μ g/m3
  Serial.println(g5.pm10_CF1);  // PM10  浓度（CF=1，标准颗粒物）单位μ g/m3
  Serial.println(g5.pm1_0ATM);  // PM1.0 浓度（大气环境下）单位μ g/m3 
  Serial.println(g5.pm2_5ATM);  // PM2.5 浓度（大气环境下）单位μ g/m3
  Serial.println(g5.pm10_ATM);  // PM10  浓度（大气环境下）单位μ g/m3
  Serial.println(g5.pm0_3QTY);  // 0.1 升空气中直径在 0.3um 以上颗粒物个数
  Serial.println(g5.pm0_5QTY);  // 0.1 升空气中直径在 0.5um 以上颗粒物个数
  Serial.println(g5.pm1_0QTY);  // 0.1 升空气中直径在 1.0um 以上颗粒物个数
  Serial.println(g5.pm2_5QTY);  // 0.1 升空气中直径在 2.5um 以上颗粒物个数
  Serial.println(g5.pm5_0QTY);  // 0.1 升空气中直径在 5.0um 以上颗粒物个数
  Serial.println(g5.pm10_QTY);  // 0.1 升空气中直径在  10um 以上颗粒物个数
  Serial.println(g5.version);   // 版本号
  Serial.println(g5.error);     // 错误代码
  Serial.println("-----------------------");
  delay(500);
}
