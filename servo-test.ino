#include <Servo.h> 
 Servo servoNesnesi; 
 void setup() { 
servoNesnesi.attach(9); 
} 
void loop() {
 servoNesnesi.write(100);  delay(1000); 
servoNesnesi.write(20); 
 delay(1000); 
}
