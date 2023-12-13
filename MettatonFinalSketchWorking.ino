#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

// create and instance of the library
Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();

Servo myservo;
Servo myservo1;
const int buzzerPin = 3;
const int soundPin = A0;
const int threshold = 515;
int soundVal;
int slidePin = 2;
int slideVal;
int buttonPin = 6;
int buttonVal;

int led_one = 7;
int led_two = 8;
int led_three = 9;
int led_four = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(soundPin, INPUT);
  pinMode(slidePin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led_one, OUTPUT);
  pinMode(led_two, OUTPUT);
  pinMode(led_three, OUTPUT);
  pinMode(led_four, OUTPUT);


  myservo.attach(4);
  myservo1.attach(5);
  Serial.begin(9600);
      if (!matrix.begin()) {
    Serial.println("IS31 not found");
    while (1)
      ;
  }
  Serial.println("let's gooooooo");

}

void loop() {
  // put your main code here, to run repeatedly:
  slideVal = digitalRead(slidePin);
  if (slideVal == 0){
    Serial.println("Off");
    delay(100);
  }else{
    Serial.println("On");
    delay(100);
  }


if (slideVal == 1){
  buttonVal = digitalRead(buttonPin);
  Serial.println(buttonVal);
  delay(100);
  soundVal = analogRead(soundPin);
  Serial.print("sound: ");
  Serial.println(soundVal);
  delay(500);
  if (soundVal >= threshold || buttonVal == 1){
    matrix.clear();
    matrix.drawPixel(1,3,255);
    matrix.drawPixel(1,4,255);
    matrix.drawPixel(2,2,255);
    matrix.drawPixel(2,3,255);
    matrix.drawPixel(3,2,255);
    matrix.drawPixel(3,4,255);
    matrix.drawPixel(4,4,255);
    matrix.drawPixel(4,5,255);
    matrix.drawPixel(5,1,255);
    matrix.drawPixel(5,2,255);
    matrix.drawPixel(5,4,255);
    matrix.drawPixel(5,6,255);
    matrix.drawPixel(6,1,255);
    matrix.drawPixel(6,2,255);
    matrix.drawPixel(6,5,255);
    matrix.drawPixel(6,7,255);
    matrix.drawPixel(7,1,255);
    matrix.drawPixel(7,5,255);
    matrix.drawPixel(7,6,255);
    matrix.drawPixel(7,7,255);
    matrix.drawPixel(8,1,255);
    matrix.drawPixel(8,3,255);
    matrix.drawPixel(8,5,255);
    matrix.drawPixel(8,7,255);
    matrix.drawPixel(9,4,255);
    matrix.drawPixel(9,5,255);
    matrix.drawPixel(9,6,255);
    matrix.drawPixel(9,7,255);
    matrix.drawPixel(10,1,255);
    matrix.drawPixel(10,2,255);
    matrix.drawPixel(10,4,255);
    matrix.drawPixel(10,5,255);
    matrix.drawPixel(10,7,255);
    matrix.drawPixel(11,1,255);
    matrix.drawPixel(11,2,255);
    matrix.drawPixel(11,3,255);
    matrix.drawPixel(11,5,255);
    matrix.drawPixel(11,6,255);
    matrix.drawPixel(11,7,255);
    matrix.drawPixel(12,1,255);
    matrix.drawPixel(12,5,255);
    matrix.drawPixel(12,7,255);
    matrix.drawPixel(13,3,255);
    matrix.drawPixel(13,4,255);
    matrix.drawPixel(13,5,255);
    matrix.drawPixel(13,6,255);

  // delay
    delay(500);
    digitalWrite(led_one, HIGH);
    digitalWrite(led_two, HIGH);
    digitalWrite(led_three, HIGH);
    digitalWrite(led_four, HIGH);
    tone(buzzerPin, 500);
    delay(1000);
    myservo.write(soundVal);
    //delay(500);
    myservo1.write(soundVal);
    delay(500);
    myservo1.writeMicroseconds(1500);
    delay(1000);


  }
  else{
    digitalWrite(led_one, LOW);
    digitalWrite(led_two, LOW);
    digitalWrite(led_three, LOW);
    digitalWrite(led_four, LOW);
    noTone(buzzerPin);
    delay(1000);
    matrix.clear();
    delay(500);
  }
}
else{
  digitalWrite(led_one, LOW);
  digitalWrite(led_two, LOW);
  digitalWrite(led_three, LOW);
  digitalWrite(led_four, LOW);
  noTone(buzzerPin);
  delay(1000);
  matrix.clear();
  delay(500);
  myservo.writeMicroseconds(1500);
  myservo1.writeMicroseconds(1500);
  delay(500);
}

}
