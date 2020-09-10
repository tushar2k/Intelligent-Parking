// defines pins numbers
#include <Servo.h> 
#include <LiquidCrystal.h>
const int trigPin = 7;
int pirState = LOW;
int val=0;
const int echoPin = 8;
int inputPin = 9;  
int servoPin = 10;
int servoPin2=13;
int counter=3;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  
// defines variables
float duration;
float distance;
Servo Servo1;
Servo Servo2;
void setup() {
  pinMode(inputPin, INPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("AVAILABLE:-");
  lcd.setCursor(0,1);
  lcd.print(counter);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Servo1.attach(servoPin);
Servo2.attach(servoPin2);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
  val = digitalRead(inputPin);
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
Serial.println(distance)  ;
//CONDITION STATEMENT
if (distance<8) {
  Servo1.write(0); 
   delay(5000);
  Servo1.write(90); 
   delay(1000);
   counter=counter-1;
   lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("available:-");
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(counter);
  
}
if (val == HIGH) {                            // check if the input is HIGH
    if (pirState == LOW and counter<3) {     
      Servo2.write(0); 
   delay(5000);
  Servo2.write(90); 
   delay(1000);// we have just turned on
  counter=counter+1;
  pirState = HIGH;
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("available:-");
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(counter);
    }
}
    else {
  if (pirState == HIGH){                   // we have just turned of
pirState = LOW;
}
    }
if (counter==0) {
  lcd.setCursor(0,0);
  lcd.print("NO SPACE  ");
  lcd.setCursor(0,1);
  lcd.print("AVAILABLE");
}  
// Prints the distance on the Serial Monitor
}
