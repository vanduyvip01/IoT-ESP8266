#define BLYNK_TEMPLATE_ID "TMPL6dL5rPNTo"
#define BLYNK_TEMPLATE_NAME "robot hihi"
#define BLYNK_AUTH_TOKEN    "eWqsFEUJ-SwvcdHmS6PjfcmbS-TMJus_"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char ssid[] = "shinvjp001";
char pass[] = "taoduyday1";
int Tien, Trai, Phai, Lui;
BLYNK_WRITE(V0)
{
  Tien = param.asInt();
}
BLYNK_WRITE(V1)
{
  Trai = param.asInt();
}
BLYNK_WRITE(V2)
{
  Phai = param.asInt();
}
BLYNK_WRITE(V3)
{
  Lui = param.asInt();
}

void setup()
{
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);S
  pinMode(D2,OUTPUT);
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}
void loop()
{
  Blynk.run();
  if(Tien==1){
    digitalWrite(D0,0);
    digitalWrite(D1,1);
    digitalWrite(D2,0);
  }
  else if(Trai==1){
    digitalWrite(D0,1);
    digitalWrite(D1,0);
    digitalWrite(D2,0);
  }
  else if(Phai==1){
    digitalWrite(D0,0);
    digitalWrite(D1,0);
    digitalWrite(D2,1);
  }
  else if(Lui==1){
    digitalWrite(D0,0);
    digitalWrite(D1,0);
    digitalWrite(D2,0);
  } else {
    digitalWrite(D0,1);
    digitalWrite(D1,1);
    digitalWrite(D2,1);    
  }
}
