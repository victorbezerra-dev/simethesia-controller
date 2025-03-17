#include <Wire.h>
#include <Arduino.h>

float y = 0;
float u = 0;
float e = 0;
float r = 50;
float Kp = -1;
float Ti = 20;
float Ts = 0.025;
float eold = 0;
long tempo = 0;
double BIS;
#define enabl  9
#define dir1  10
#define dir2  11

void setup() {
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  tempo = millis();
  Wire.requestFrom(8, sizeof(float));
  byte data[4];
  int i = 0;
  while (Wire.available()) {
     data[i++] = Wire.read();
  } 
  Serial.print("BIS Received");
  BIS = *((float*)data);
  Serial.println(BIS);

  y = BIS;
  eold = e;
  e=r-y;
  u=u+Kp*e+(Ts*Kp/Ti -Kp)*eold;
  u=min(max(0,u),30);
  byte *infusao = (byte*)&u; 
  Wire.beginTransmission(8);
  Wire.write(infusao, sizeof(float));
  Wire.endTransmission();
  Serial.print("BIS: ");
  Serial.print(BIS);
  Serial.print(" | Infusão: ");
  Serial.println(u);
  while(millis()-tempo<=(Ts*1000)){}
}