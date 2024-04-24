int sensorPin = 2;
int sensorVol = 2;
volatile long pulse;
volatile long pluse;
float volume;
float lastTime;
float flowrate;


void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);
  attachInterrupt(digitalPinToInterrupt(sensorVol), increase, RISING);
  pinMode(4, INPUT);

}

void loop() {
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
  delay(500);

    /// press button rest
  if (digitalRead(4)) {
    pluse = 0;
  }
}

void increase(){
  pulse++;
  pluse++;
}