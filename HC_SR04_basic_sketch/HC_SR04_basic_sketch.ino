/*
 HC-SR04 Ping distance sensor Basic sketch
 
 Hardware Setup for HC-SR04 Ping distance sensor 
      VCC to arduino 5v 
      GND to arduino GND
      Echo to Arduino pin 7 
      Trig to Arduino pin 8
*/
const int echoPin = 7;               //configure the echo PIN 
const int trigPin = 8;               // configure the trigger PIN 

void setup()
{
  Serial.begin (9600);               // setup the serial monitor so we can see the distance 
  
  pinMode(trigPin, OUTPUT);          // the trigger pin will be an OUTPUT
  pinMode(echoPin, INPUT);           // the echo pin will be the return echo IN
  
}

void loop() {
  int duration, distance;             // integers for both duration and distance
  
  digitalWrite(trigPin, HIGH);        // send the trigger pulse
  delayMicroseconds(1000);            // let the pulse be 1 second
  digitalWrite(trigPin, LOW);         // end the trigger pulse
  
  duration = pulseIn(echoPin, HIGH);  // Get the the echo value from the echo pin and we are going to calulate the duration
  distance = (duration/2) / 29.1;     // microseconds per millimetre - sound travels 1 mm in ~2.9us
  
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");   // We want to be notified if the object is found to be out of range
  }
  else {
    Serial.print(distance);           // Object in range, print out the distance to the serial monitor
    Serial.println(" cm");            //  in centimeters
  } 
  delay(500);                         //  wait and loop
}


