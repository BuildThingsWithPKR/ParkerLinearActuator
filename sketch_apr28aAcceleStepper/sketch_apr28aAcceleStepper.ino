#include <AccelStepper.h>
AccelStepper stepper(1, 5,4);  // pin 5 = step, pin 4 = direction

void setup()
{  
  stepper.setMaxSpeed(150);
  stepper.setAcceleration(100);
}
 
void loop()
{    
  stepper.moveTo(6400);
  while (stepper.currentPosition() != 5000) // Full speed up to 300
    stepper.run();
  stepper.runToNewPosition(0); // Cause an overshoot then back to 0
}