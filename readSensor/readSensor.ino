#include <Encoder.h>

Encoder rail(2, 3);  // MicroView pins 11 and 12, both are interrupt pins 
// 2 -- BLUE
// 3 -- WHITE
// 5V - RED
// G -- BLACK
long encoder;  // Total range is somewhere above 170k (3.3" * 2.54 cm/" * 1/100 m/cm * 1/0.488e-6m) with 0.5 um encoder resolution.
long encoder_chk;


void setup() {
  pinMode(inPin, INPUT);  // sets the digital pin 7 as input
  pinMode(outPin, OUTPUT);  // sets the digital pin 7 as input
  pinMode(LED_BUILTIN, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(115200);  // initialize serial bus
  delay(500);
  encoder = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  // See if there's a new value
  encoder_chk = rail.read();
  if (encoder != encoder_chk) {
    // Track it
    encoder = encoder_chk;
  }
  digitalWrite(outPin,HIGH);   // read the input pin
  valRead = digitalRead(inPin);   // read the input pin
  if (valRead != 0) { digitalWrite(LED_BUILTIN, HIGH); }


  //Serial.print("Position in mm: ");
  Serial.println(encoder * 0.48828125 / 1000.0, 4);  // resolution to mm for displacement calculation
}
