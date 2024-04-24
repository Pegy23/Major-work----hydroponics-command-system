int sensorPin = 2;
volatile long pulse;
float volume;
float lastTime;


void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);
}

void loop() {
  volume = 3.509 * pulse;

  if (millis() - lastTime > 1000) {
    pulse = 0;
    lastTime = millis();
  }

  Serial.print(volume);
  Serial.println(" mL/s");
}

void increase(){
  pulse++;
}