#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
int sensorPin = 2;
int sensorVol = 2;
volatile long pulse;
volatile long pluse;
float volume;
float lastTime;
float flowrate;

 
dht DHT;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);
  attachInterrupt(digitalPinToInterrupt(sensorVol), increase, RISING);
  pinMode(4, INPUT);
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");

  flowrate = 3.509 * pulse;
  volume = 3.509 * pluse;

  if (millis() - lastTime > 1000) {
    pulse = 0;
    lastTime = millis();
  }

  Serial.print(flowrate);
  Serial.println(" mL/s");
  Serial.print(volume);
  Serial.print(" mL");

    /// press button rest
  if (digitalRead(4)) {
    pluse = 0;
  }
    
    delay(500);//Wait 5 seconds before accessing sensor again.
 
  
} //Fastest should be once every two seconds.

  void increase(){
  pulse++;
  pluse++;
}
 