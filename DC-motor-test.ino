#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enA 10
#define enB 5
 
 
 int M1_Speed = 80; 
 int M2_Speed = 80; 
 int LeftRotationSpeed = 250; 
 int RightRotationSpeed = 250; 
 void setup() {
  
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT);
  
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
 
   pinMode(A0, INPUT); // initialize Left sensor as an input
   pinMode(A1, INPUT); // initialize Right sensor as an input
 
}
 
void loop() {

  forward();
  delay(5000);
  
  right();
  delay(5000);
 
  left();
  delay(5000);

 
  Stop();
  delay(5000);
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
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
       
        analogWrite(enA, LeftRotationSpeed);
        analogWrite(enB, RightRotationSpeed);
}
  
void left()
{
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
       
        analogWrite(enA, LeftRotationSpeed);
        analogWrite(enB, RightRotationSpeed);
}
  
void Stop()
{
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
}
