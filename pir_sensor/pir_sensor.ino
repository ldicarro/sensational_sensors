/*
 * Uses a PIR sensor to turn on an LED
 * when motion is detected.
 */

// define variables for pins
const int ledPin = 13;
const int inputPin = 2;

// variables to store information
int pirState = LOW;
int val = 0;
int timeElapse = 0;
int currentMillis = 0;

void setup() {
  // define pin behaviors
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the value form the sensor,
  // it is going to be HIGH or LOW
  val = digitalRead(inputPin);
  
  // if it is HIGH and the state in not already HIGH,
  // turn on the LED and print out info
  if(val == HIGH)
  {
    digitalWrite(ledPin,HIGH);
    if(pirState == LOW)
    {
      Serial.print("Motion Detected! ");
      Serial.print(millis() - currentMillis);
      Serial.println("ms");
      currentMillis = millis();
      pirState = HIGH;
    }

  }
  else
  {
    // if the pin is LOW and the state was already HIGH,
    // turn the LED off and set the state to LOW
    digitalWrite(ledPin,LOW);
    if(pirState == HIGH)
    {
      timeElapse = millis() - currentMillis;
      currentMillis = millis();
      Serial.print("Motion Ended! ");
      Serial.print(timeElapse);
      Serial.println("ms");
      pirState = LOW;
    }
  }
}
