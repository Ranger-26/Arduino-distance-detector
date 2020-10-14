#include <LiquidCrystal.h>//includes the library for the LCD which is used to display stuff on a screen

//These lines of code define the pin numbers for the arduino of each component used
const int distance = 10;//The proximity of the sensor of beeping

const int pingPin = 6; // Trigger pin of the Ultrasonic Sensor on the arduino
const int echoPin = 7; // Echo pin of the Ultrasonic Sensor on the arduino
const int buzzerPin = 9;//Positive pin of the buzzer on the arduino

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//initializes the LCD object and the connected pins

void setup() {
  pinMode(buzzerPin, OUTPUT);//sets up buzzer pin
  pinMode(pingPin, OUTPUT);//sets up trigger pin of the ultrasonic sensor
  pinMode(echoPin, INPUT);//echo pin of the ultrasonic sensor
  lcd.print("Welcome!");//displays "Welcome!" to the LCD 
  delay(1000);//waits one second
}

void loop() {
   //This function will scan the area for objects withn a certain distance of a sensor and beep and does that forever. Code from https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm for this function and the one after it.
   lcd.clear();//clears the LCD of the previous distance shown
   float inches = detectDistance();//calls the detect distance function to get the distance which will be a decimal
   lcd.print(int(inches));//prints distance to the LCD as an integer
   if(inches<=distance)//checks if the distance is less than the proximity distance defined in line 8{
    buzz();//if the distance is less than a certain  number, buzz
   }
   delay(100);//waits .1 of a second
}

void buzz(){
  //This function controls the buzz.
  tone(buzzerPin, 1000, 500);//this function plays the sound,args:(buzzer pin, sound frequency, duration)
  delay(1000);//wait 1 second
}

float detectDistance(){
   long duration;//defines a variable which will hold the detected distance
   digitalWrite(pingPin, HIGH);//starts emitting the wave 
   delayMicroseconds(10);//waits 10 microseconds
   digitalWrite(pingPin, LOW);//stops emitting the wave
   duration = pulseIn(echoPin, HIGH);//recives the wave back and gets a value
   return duration / 74 / 2;//converts a value recived by the ultrasonic sensor into inches and returns it
}

