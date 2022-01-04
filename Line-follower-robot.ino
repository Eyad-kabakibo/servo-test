#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enA 10
#define enB 5

int M1_Speed = 200; 
int M2_Speed = 200;
int LeftRotationSpeed = 150;
int RightRotationSpeed = 150;

 
 void setup() {
  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  
  pinMode(A0, INPUT); 
  pinMode(A1, INPUT); 

}
 
void loop() {
 
 int LEFT_SENSOR = digitalRead(A0);
 int RIGHT_SENSOR = digitalRead(A1);
 obstacul_detect();
if(RIGHT_SENSOR==0 && LEFT_SENSOR==0) {
  forward();
}
 
 else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1) {
  right(); 
 }
 
 else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0) {
  left(); 
}
 
 else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1) {
  Stop(); 
 }
}
 
 
 
void forward()
{
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
     
      analogWrite(enA, M1_Speed);
      analogWrite(enB, M2_Speed);
}
  
void backward()
{
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);       
      analogWrite(enA, M1_Speed);
      analogWrite(enB, M2_Speed);
}
  
void right()
{
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enB, RightRotationSpeed);
}
  
void left()
{
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enA, LeftRotationSpeed);
}
  
void Stop()
{
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
}
void obstacul_detect(){
  if (distance() <= 6){
    Stop();
    delay(100);
    right();
    delay(350);
    forward();
    delay(150);
    left();
    delay(180);
    forward();
    delay(100);
    left();
    delay(280);
    forward();
    delay(150);

    }
   
  }
int distance()
{
  long duration; 
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  return distance;
  }
