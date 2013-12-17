/* /* Glenn's Insectbot
   DC Robotics Arduino and Electronics Workshop Dec 2013
   This insectbot uses 2 servos, 1 LED, 1 button, 1 Piezo, designed by Glenn Mossy, Maryland.

/***********************************************************
The Servo walking code is derived from code by ABDUL SATTAR,08ES25, MEHRAN UET, PAKISTAN
ARDUINO AND SERVO BASED WALKING ROBOT
MADE BY: ABDUL SATTAR,08ES25, MEHRAN UET, PAKISTAN
THIS IS ARDUINO CODE... FEEL FREE TO USE; BUT DONOT FORGET ACCREDITE IT TO ME.
FOUND AT: HOTRESISTOR.BLOGSPOT.COM
http://www.mediafire.com/download/aae1bcaqatokac4/_3_SERVO_ROBOT_V3+CODE.zip
*************************************************************/

#include <Servo.h>

Servo servoBottom;    // The bottom servo
Servo servoFront;     // The front servo

#define  frontmidPoint  55   // default 52   changes the midpoint position of both legs/servos, range(41,60)
#define  BottommidPoint  90  // default 85   changes the midpoint position of both legs/servos, range(65,90)
#define   angle    11        // default 11  larger number makes wide strokes on front servo, range (5,17)
#define   angle2   20        // default 20   larger numbers makes wider strokes bottom servo, range (15,28)
#define   servowait 40       // default 30  1 makes it shake crazy, larger numbers makes the stroke slow way down, range(10,50)

 int bottom_servo =     BottommidPoint;
 int front_servo = frontmidPoint;

 int first_run=0;

 // initialize the LED and Piezo
 int blueledPin = 13;            // initialize the pin that the led is on
 int heartbeat = 300;            // initialize a heartbeat rate
 int piezeoPin = 2;              // initialize the pin that the piezo is on

// initialize the HC_SR04 code derived from LED range indicator sketch.
int echoPin = 7;            // Echo Pin
int trigPin = 8;            // Trigger Pin
int maximumRange = 400;   // Maximum range needed
int minimumRange = 15;    // Minimum range needed, 2cm the spec min limit
long distance;            // Duration used to calculate distance

void setup()
{
    Serial.begin(9600);              // initialize the serial monitor for debugging!
    
  // setup the pins for the LEDs and Sound
  pinMode(blueledPin, OUTPUT);     // initialize the pin as output for the blue led
  pinMode(piezeoPin, OUTPUT);      //  initialize the pin as output for the piezeo
  
  // setup the pins for the ultrasonic distance sensor
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
 
  // setup both servos
  
 // servoLeft.attach(8);
 servoFront.attach(10);   // pin 10 is my front servo
 servoBottom.attach(9);  // pin 9 is the bottom servo

  // initialize the servo legs to the middle starting positions
 servoFront.write(frontmidPoint);       // The front servo
 // servoLeft.write(midPoint);
 servoBottom.write(BottommidPoint);      // right is my bottom servo
 
 //pinMode(13,OUTPUT); 
 //pinMode(2,INPUT);
 // while(digitalRead(2)==0){}; ///////// WAIT FOR PIN 2  TO BE HIGH
 //digitalWrite(13,HIGH);
 //delay(1500);
 //digitalWrite(13,LOW);
 }

void loop()
 {
   

 //if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
// Serial.println("-1");
 digitalWrite(blueledPin, HIGH); 
 
 digitalWrite(piezeoPin, HIGH);   //turn the speaker on
 delay(500);                       //wait for half a second
 digitalWrite(piezeoPin, LOW);    //turn the speaker off
 delay(500);                       //wait for half a second
// }
// else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 digitalWrite(blueledPin, LOW);  
   walk_forward();         // make the insectbot walk forward
 
 //}
 
 
  
  // Sound and Lights!
  pulse_blue(heartbeat);          // Turn on the blue LED
  //piezeo_churp();               // churp the piezeo
  delay(heartbeat);
  
 }


 void walk_forward()
 {

  Serial.println("Move bottom servo with angle2 from 0 to it's midpoint, and increment");
  for(int i=0; i< angle2; i++)     // Move bottom servo with angle2 from 0 to it's midpoint
  {
    bottom_servo++;                 // increment the bottom servo position
    servoBottom.write(bottom_servo);
    delay(servowait);        // wait
  }
  
  Serial.println("Move front servo with angle1 from 0 to it's midpoint and increment");
  for(int i=0; i< angle; i++)     // Move front servo with angle1 from 0 to it's midpoint
  {
    front_servo++;                // increment the front servo position
    servoFront.write(front_servo);
    delay(servowait);              // wait
  }
 
  Serial.println("repeat"); 
  for(int i=0; i< angle; i++)      // Move front servo with angle1 from 0 to it's midpoint
  {
    front_servo++;                 // increment the front servo position       
    servoFront.write(front_servo);
    delay(servowait);               // wait
  }
    
  Serial.println("Move bottom servo with angle2 from 0 to it's midpoint, and decrement");
  for(int i=0;i< angle2; i++)         // Move bottom servo with angle2 from 0 to it's midpoint
  {
    bottom_servo--;                   // decrement the bottom servo position
    servoBottom.write(bottom_servo);
    delay(servowait);                 // wait
  }
  Serial.println("repeat"); 
  for(int i=0; i< angle2; i++)         // Move bottom servo with angle2 from 0 to it's midpoint
  { 
    bottom_servo--;                    // decrement the bottom servo position
    servoBottom.write(bottom_servo);
    delay(servowait);                  // wait
  } 
  
  Serial.println("Move front servo with angle1 from 0 to it's midpoint and deccrement");
  for(int i=0; i < angle; i++)           // Move front servo with angle1 from 0 to it's midpoint
  {
    front_servo--;                       // decrement the front servo position
    servoFront.write(front_servo);
    delay(servowait);                    // wait
  }  
  
  Serial.println("repeat");
  for(int i=0;i< angle; i++)               // Move front servo with angle1 from 0 to it's midpoint
  { 
    front_servo--;                         // decrement the front servo position
    servoFront.write(front_servo);
    delay(servowait);                       // wait
  }  
  
   Serial.println("Move bottom servo with angle2 from 0 to it's midpoint, and increment");
   for(int i=0; i< angle2; i++)               // Move bottom servo with angle2 from 0 to it's midpoint
  {
    bottom_servo++;                           // increment the bottom servo position
    servoBottom.write(bottom_servo);
    delay(servowait);                         // wait
  }

 }

 
long geteyes(long distance)
 {
 
long duration; // Duration used to calculate distance
   
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 return distance;
 }
 
void pulse_blue(int heartbeat)
{
  digitalWrite(blueledPin, HIGH);
  delay(heartbeat);
  digitalWrite(blueledPin, LOW);
  delay(heartbeat);
} 


void piezeo_churp()
{
   int x = 25;
  for (x= 25; x < 35; x++) {
  digitalWrite(piezeoPin, HIGH);
  delay(x+25);
  digitalWrite(piezeoPin, LOW);
  delay(x);
  }

}
