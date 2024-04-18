#include <Servo.h>

Servo servo;

int trigPin = 11;
int echoPin = 12;

long duration;
int distance;

void setup() {
  servo.attach(13);       // Attaches the servo on pin 13 to the servo object
  servo.write(180);       // Moves the servo to 180 degrees
  delay(2000);            // Delays for 2 seconds to allow the servo to reach the position

  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input

  Serial.begin(9600);        // Starts serial communication at 9600 baud rate
}

void loop() {
  digitalWrite(trigPin, LOW);  // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Sets the trigPin to HIGH state for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;    // Calculating the distance

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 25) {  // Change Distance according to Ultrasonic Sensor Placement
    servo.write(180);
    delay(3000);  // Wait for 3 seconds
  } else {
    servo.write(90);  // Move the servo to 90 degrees if no object within 25 cm
  }
}
