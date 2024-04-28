// defines pins numbers
const int stepPin = 5; 
const int dirPin = 4;

/*
hw134	
      g	    dir
	    vcc	  step
	    1E	  sleep
	    1A	  reset
	    2A	  S3
	    2E	  S2
	    g	    S1
	    vmot	E
*/

const int delayMicros = 100;
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {

  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 3200 pulses for making one full cycle rotation 1/16 microstepping
  for(long int x = 0; x < 6400; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(delayMicros); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(delayMicros); 
  }
  delay(1); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(long int x = 0; x < 6400; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(delayMicros);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(delayMicros);
  }
  delay(1);
}