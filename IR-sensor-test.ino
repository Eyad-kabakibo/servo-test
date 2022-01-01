int IRSensor = 2;

void setup()
{
  pinMode (IRSensor, INPUT);
  Serial.begin(9600);
}

void loop()
{

  int statusSensor = digitalRead (IRSensor);  
  Serial.write(statusSensor);
  
  delay(1000);
}
