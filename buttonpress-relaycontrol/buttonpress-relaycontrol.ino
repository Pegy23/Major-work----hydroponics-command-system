

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(4, INPUT);

}

void loop() {

  if (digitalRead(4)) {
    digitalWrite(8, LOW);
    Serial.println("OFF");
    delay(100);
  }

  else {
    digitalWrite(8, HIGH);
    Serial.println("ON");

  }


}