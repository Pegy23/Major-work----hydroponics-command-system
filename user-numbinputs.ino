// C++ code

float b;
//
void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop()
{
  while (Serial.available() == 0) {} 
  b = Serial.parseFloat();
  Serial.print("I got ");
  Serial.println(b);
}