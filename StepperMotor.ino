#include <Stepper.h>

int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int motSpeed = 10;
int dt = 500;
int buttonPin = 7;
int buttonVal;
int buttonOldVal = 1;
int posState = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  buttonVal = digitalRead(buttonPin);
  Serial.println(buttonVal);
  
  if(buttonOldVal == 0 && buttonVal == 1)
  {
    if(posState == 0)
    {
      myStepper.step(stepsPerRevolution);
      posState = 1;
    }
    else
    {
      myStepper.step(-stepsPerRevolution);
      posState = 0;
    }
  }
  buttonOldVal = buttonVal;
}
