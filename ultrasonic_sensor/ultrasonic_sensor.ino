/*
 * Uses a 4 pin HC-SR04 ultrasonic sensor to
 * find the distance between it and another
 * object in front of it. Calculates the distance
 * based on the echo time of the ping.
 */

// define variables for pins
const int trig = 8;
const int echo = 9;

void setup() {
  // set the pin modes
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  // so we can see the values in 
  // the serial monitor
  Serial.begin(9600);
}

void loop() {
  // setting up variables for calculations
  long duration,in,cm;

  // make a pulse for the sensor send out by 
  // turning the pin off then on then off __|^|__
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  // determine how long the echo took to get back
  duration = pulseIn(echo,HIGH);

  // calculating the distance in the
  // functions belows
  in = microSecondsToIn(duration);
  cm = microSecondsToCm(duration);

  // printing out the results
  Serial.print(in);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microSecondsToIn(long duration)
{
  return duration / 74 / 2;
}

long microSecondsToCm(long duration)
{
  return duration / 29 / 2;
}
