/*
 * This sketch uses a photoresistor to dim an led 
 * when light is blocked from it. It uses a voltage
 * divider to feed the analog pin values.
 * 
 */

// define variables for the pins.
// use const because the values do not change.
const int photo = A0;
const int led = 3;

void setup()
{
  // set the LED pin to output
  pinMode(led,OUTPUT);
  
  // uncomment this line to see the values in the serial monitor
  //Serial.begin(9600);
}

void loop() 
{
  // read in the value and map it to a value between 0 and 255
  int inVal = map(analogRead(photo),0,1024,0,255);

  // write the mapped value to the LED pin
  analogWrite(led,inVal);

  // uncomment this line to see the values in the serial monitor
  //Serial.println(inVal);

}
