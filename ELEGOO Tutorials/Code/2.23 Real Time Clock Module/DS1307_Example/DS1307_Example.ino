#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

void printZero(int num) {
  if(num < 10) Serial.print("0");
  Serial.print(num);
}

void setup() {
  Serial.begin(9600);
  
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  // 如果 RTC 没运行，设置时间（取消注释使用）
  // if (!rtc.isrunning()) {
  //   rtc.adjust(DateTime(2026, 7, 6, 10, 0, 0));
  // }
}

void loop() {
  DateTime now = rtc.now();
  
  Serial.print(now.year());
  Serial.print("-");
  printZero(now.month());
  Serial.print("-");
  printZero(now.day());
  Serial.print(" ");
  printZero(now.hour());
  Serial.print(":");
  printZero(now.minute());
  Serial.print(":");
  printZero(now.second());
  Serial.println();
  
  delay(1000);
}