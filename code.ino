const int distance = 10;//ONLY CHANGE THIS NUMBER TO WHAT DISTANCE YOU WANT THE SENSOR TO DETECT ONJACTS(in inches)

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int buzzerPin = 9;//buzzer pin


void setup() {
  pinMode(buzzerPin, OUTPUT);//sets up buzzer pin
  pinMode(pingPin, OUTPUT);//sets up trigger pin of the sensor
  pinMode(echoPin, INPUT);//echo pin of the ultrasonic sensor
}

void loop() {
   scan();//runs the scan function
}

void scan() {
   //This function will scan the area for objects withn a certain distance of a sensor and beep. Code from https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm for this function and the one after it.
   long duration, inches, cm;//defines the length, inches, centimeters
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   if(inches<=distance){
    buzz();
   }
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

void buzz(){
  //This function controls the buzz.
  tone(buzzerPin, 1000, 500);//this function plays the sound,args:(buzzer pin, sound frequency, duration)
  delay(1000);//wait 1 second
}
