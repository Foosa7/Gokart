#include <Arduino.h>
#include <stdint.h>

#include <Arduino.h>

#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#define TIMES_TO_LOOP 1000000

volatile uint16_t ux16, uy16, uresult16;
volatile uint32_t ux32, uy32, uresult32;
volatile uint64_t ux64, uy64, uresult64;

volatile int16_t x16, y16, result16;
volatile int32_t x32, y32, result32;
volatile int64_t x64, y64, result64;

volatile float xf, yf, resultf;

uint32_t x32n, y32n, result32n;

uint16_t seed16() {
  return random(0, 0xffff);
}

uint32_t seed32() {
  return random(0, 0xffffffff);
}

uint64_t seed64() {
  return seed32();
}

float seedfloat() {
  float x, y;

  x = seed32();
  y = seed32();

  return x / y;
}

void setup() {
  uint32_t i;
  uint64_t micros_start, micros_end;

  Serial.begin(115200);
  Serial.println("hello world");

  WiFi.mode( WIFI_OFF );

  delay(1000);

  x32n = seed32();
  y32n = seed32();

  micros_start = micros();
  for(i = 0; i < TIMES_TO_LOOP; i++)
    result32n = x32n * y32n;
  micros_end = micros();

  Serial.print("non-volatile uint32_t microseconds ");
  Serial.println(micros_end - micros_start);

  micros_start = micros();
  for(i = 0; i < TIMES_TO_LOOP; i++)
    result32n = 540000 * 15;
  micros_end = micros();

  Serial.print("constants uint32_t microseconds ");
  Serial.println(micros_end - micros_start);


  ux16 = seed16();
  uy16 = seed16();
  x16 = ux16;
  y16 = uy16;

  micros_start = micros();
  for(i = 0; i < TIMES_TO_LOOP; i++)
    uresult16 = ux16 * uy16;
  micros_end = micros();

  Serial.print("uint16_t microseconds ");
  Serial.println(micros_end - micros_start);
    
  ux32 = seed32();
  uy32 = seed32();
  x32 = ux32;
  y32 = uy32;

  micros_start = micros();
  for(i = 0; i < TIMES_TO_LOOP; i++)
    uresult32 = ux32 * uy32;
  micros_end = micros();

  Serial.print("uint32_t microseconds ");
  Serial.println(micros_end - micros_start);

  ux64 = seed64();
  uy64 = seed64();
  x64 = ux64;
  y64 = uy64;

  micros_start = micros();
  for(i = 0; i < TIMES_TO_LOOP; i++)
    uresult64 = ux64 * uy64;
  micros_end = micros();

  Serial.print("uint64_t microseconds ");
  Serial.println(micros_end - micros_start);

  micros_start = micros();
  for(i = 0; i < TIMES_TO_LOOP; i++)
    result16 = x16 * y16;
  micros_end = micros();

  Serial.print("int16_t microseconds ");
  Serial.println(micros_end - micros_start);
    
  micros_start = micros();
  for(i = 0; i < TIMES_TO_LOOP; i++)
    result32 = x32 * y32;
  micros_end = micros();

  Serial.print("int32_t microseconds ");
  Serial.println(micros_end - micros_start);

  micros_start = micros();
  for(i = 0; i < TIMES_TO_LOOP; i++)
    result64 = x64 * y64;
  micros_end = micros();

  Serial.print("int64_t microseconds ");
  Serial.println(micros_end - micros_start);

  xf = 28.353520; //seedfloat();
  yf = 77.533633; //seedfloat();

  micros_start = micros();
  for(i = 0; i < TIMES_TO_LOOP; i++)
    resultf = xf * yf;
  micros_end = micros();

  Serial.print("float  microseconds ");
  Serial.println(micros_end - micros_start);
}

void loop() 
{

}
