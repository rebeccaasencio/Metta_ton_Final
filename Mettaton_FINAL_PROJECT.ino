#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

// create and instance of the matrix library
Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();

//Servos
Servo myservo;
Servo myservo1;

//Pins
const int buzzerPin = 3;
const int soundPin = A0;
const int slidePin = 2;
const int buttonPin = 6;

const int led_one = 7;
const int led_two = 8;
const int led_three = 9;
const int led_four = 10;

//Value Variables
const int threshold = 510;
int soundVal;
int slideVal;
int buttonVal;

void setup() {
  // INPUTS
  pinMode(soundPin, INPUT);
  pinMode(slidePin, INPUT);
  pinMode(buttonPin, INPUT);

  //OUTPUTS
  pinMode(buzzerPin, OUTPUT);
  pinMode(led_one, OUTPUT);
  pinMode(led_two, OUTPUT);
  pinMode(led_three, OUTPUT);
  pinMode(led_four, OUTPUT);

  //Servos
  myservo.attach(4);
  myservo1.attach(5);

  //Serial Begin
  Serial.begin(9600);
    if (!matrix.begin()) {
      Serial.println("IS31 not found");
      while (1)
      ;
  }
  Serial.println("let's gooooooo");

}

void loop() {
  // First read value of slide switch
  slideVal = digitalRead(slidePin);
  if (slideVal == 0){
    Serial.println("Off");
    delay(100);
  }else{
    Serial.println("On");
    delay(100);
  }

  //if the slide switch equals 1, then the "power" is on
  if (slideVal == 1){
    //read button value
    buttonVal = digitalRead(buttonPin);
    Serial.println(buttonVal);
    delay(100);

    //read sound sensor value
    soundVal = analogRead(soundPin);
    Serial.print("sound: ");
    Serial.println(soundVal);
    delay(500);

    //if the sound sensor is above the threshold or the button is pressed, then activate these components.
    if (soundVal >= threshold || buttonVal == 1){
      //LED Matrix
      //First Animation Frame
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
      delay(500);

      //Turn on LEDS
      digitalWrite(led_one, HIGH);
      digitalWrite(led_two, HIGH);
      digitalWrite(led_three, HIGH);
      digitalWrite(led_four, HIGH);

      //Turn on Piezo Buzzer
      tone(buzzerPin, 500);
      delay(500);

      //Turn on Servos
      myservo.write(soundVal);
      myservo1.write(soundVal);
      delay(500);

      //Second Animation Frame
      matrix.clear();
      matrix.drawPixel(4,6,255);
      matrix.drawPixel(4,7,255);
      matrix.drawPixel(4,8,255);
      matrix.drawPixel(5,3,255);
      matrix.drawPixel(5,8,255);
      matrix.drawPixel(6,3,255);
      matrix.drawPixel(6,4,255);
      matrix.drawPixel(6,8,255);
      matrix.drawPixel(7,3,255);
      matrix.drawPixel(7,4,255);
      matrix.drawPixel(7,8,255);
      matrix.drawPixel(8,6,255);
      matrix.drawPixel(8,7,255); 
      matrix.drawPixel(9,8,255);
      matrix.drawPixel(10,8,255);
      matrix.drawPixel(11,3,255);
      matrix.drawPixel(11,8,255);
      matrix.drawPixel(12,3,255);
      matrix.drawPixel(12,4,255);
      matrix.drawPixel(12,7,255);
      matrix.drawPixel(12,8,255);
      matrix.drawPixel(13,3,255);
      matrix.drawPixel(13,4,255);
      delay(500);

      //Third Animation Frame
      matrix.clear();
      matrix.drawPixel(4,1,255);
      matrix.drawPixel(4,6,255);
      matrix.drawPixel(4,7,255);
      matrix.drawPixel(4,8,255);
      matrix.drawPixel(5,1,255);
      matrix.drawPixel(5,3,255);
      matrix.drawPixel(5,8,255);
      matrix.drawPixel(6,1,255);
      matrix.drawPixel(6,3,255);
      matrix.drawPixel(6,4,255);
      matrix.drawPixel(6,8,255);
      matrix.drawPixel(7,0,255);
      matrix.drawPixel(7,1,255);
      matrix.drawPixel(7,3,255);
      matrix.drawPixel(7,4,255);
      matrix.drawPixel(7,8,255);
      matrix.drawPixel(8,6,255);
      matrix.drawPixel(8,7,255); 
      matrix.drawPixel(9,0,255);
      matrix.drawPixel(9,8,255);
      matrix.drawPixel(10,1,255);
      matrix.drawPixel(10,8,255);
      matrix.drawPixel(11,1,255);
      matrix.drawPixel(11,3,255);
      matrix.drawPixel(11,8,255);
      matrix.drawPixel(12,1,255);
      matrix.drawPixel(12,3,255);
      matrix.drawPixel(12,4,255);
      matrix.drawPixel(12,7,255);
      matrix.drawPixel(12,8,255);
      matrix.drawPixel(13,1,255);
      matrix.drawPixel(13,3,255);
      matrix.drawPixel(13,4,255);
      matrix.drawPixel(14,1,255);
      delay(500);

      //Fourth Animation Frame
      matrix.clear();
      matrix.drawPixel(1,6,255);
      matrix.drawPixel(2,7,255);
      matrix.drawPixel(3,3,255);
      matrix.drawPixel(3,7,255);
      matrix.drawPixel(4,1,255); 
      matrix.drawPixel(4,3,255);
      matrix.drawPixel(4,5,255);
      matrix.drawPixel(4,7,255);
      matrix.drawPixel(5,1,255);
      matrix.drawPixel(5,3,255);
      matrix.drawPixel(5,4,255);
      matrix.drawPixel(5,5,255);
      matrix.drawPixel(5,8,255);
      matrix.drawPixel(6,1,255);
      matrix.drawPixel(6,3,255);
      matrix.drawPixel(6,4,255);
      matrix.drawPixel(6,5,255);
      matrix.drawPixel(6,8,255);
      matrix.drawPixel(7,0,255); 
      matrix.drawPixel(7,3,255);
      matrix.drawPixel(7,5,255);
      matrix.drawPixel(7,8,255);
      matrix.drawPixel(8,8,255);
      matrix.drawPixel(9,0,255);
      matrix.drawPixel(9,8,255);
      matrix.drawPixel(10,0,255);
      matrix.drawPixel(10,8,255);
      matrix.drawPixel(11,1,255);
      matrix.drawPixel(11,3,255); 
      matrix.drawPixel(11,5,255);
      matrix.drawPixel(11,8,255);
      matrix.drawPixel(12,1,255);
      matrix.drawPixel(12,3,255);
      matrix.drawPixel(12,4,255);
      matrix.drawPixel(12,5,255);
      matrix.drawPixel(12,8,255);
      matrix.drawPixel(13,1,255);
      matrix.drawPixel(13,3,255);
      matrix.drawPixel(13,4,255);
      matrix.drawPixel(13,5,255); 
      matrix.drawPixel(13,8,255);
      matrix.drawPixel(14,1,255);
      matrix.drawPixel(14,3,255);
      matrix.drawPixel(14,5,255);
      delay(500);

    }
    else{//if the sound sensor does not detect above threshold or the button is not pressed
      //Turn off LEDS
      digitalWrite(led_one, LOW);
      digitalWrite(led_two, LOW);
      digitalWrite(led_three, LOW);
      digitalWrite(led_four, LOW);
      
      //Turn off Piezo Buzzer
      noTone(buzzerPin);
      delay(1000);

      //Clears LED Matrix
      matrix.clear();
      delay(500);

      //Resets Servos to original position and stops moving
      myservo.writeMicroseconds(1500);
      myservo1.writeMicroseconds(1500);
      delay(500);
    }
  }
  else{//if the switch is 0, the "power" is off.
    //The LEDS are off
    digitalWrite(led_one, LOW);
    digitalWrite(led_two, LOW);
    digitalWrite(led_three, LOW);
    digitalWrite(led_four, LOW);

    //Piezo Buzzer is off
    noTone(buzzerPin);
    delay(1000);

    //LED Matrix is off
    matrix.clear();
    delay(500);

    //Servos stopped
    myservo.writeMicroseconds(1500);
    myservo1.writeMicroseconds(1500);
    delay(500);
  }

}
