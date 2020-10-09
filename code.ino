const int distance = 10;//ONLY CHANGE THIS NUMBER TO WHAT DISTANCE YOU WANT THE SENSOR TO DETECT OBJECTS(in inches)

const int pingPin = 6; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 7; // Echo Pin of Ultrasonic Sensor
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
   digitalWrite(pingPin, HIGH);//starts emitting the wave
   delayMicroseconds(10);//wait
   digitalWrite(pingPin, LOW);//stops emitting the wave
   duration = pulseIn(echoPin, HIGH);//recives the wave back and gets a value
   inches = microsecondsToInches(duration);//converts the value above into inches
   if(inches<=distance){
    buzz();//if the distance is less than a certain  number, buzz
   }
   delay(100);//wait
}

long microsecondsToInches(long microseconds) {
   //converts a value recived by the ultrasonic sensor into inches
   return microseconds / 74 / 2;
}

void buzz(){
  //This function controls the buzz.
  tone(buzzerPin, 1000, 500);//this function plays the sound,args:(buzzer pin, sound frequency, duration)
  delay(1000);//wait 1 second
}
