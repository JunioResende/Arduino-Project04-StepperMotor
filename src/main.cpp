#include <Arduino.h>

#include <Stepper.h>

const int stepsPerRevolution = 500;

int pinIN1 = 8;
int pinIN2 = 9;
int pinIN3 = 10;
int pinIN4 = 11;

int speedStepper = 60;

Stepper myStepper(stepsPerRevolution, pinIN1, pinIN2, pinIN3, pinIN4);

void setup()
{
  myStepper.setSpeed(speedStepper);
}

void loop()
{
  for (int i = 0; i <= 3; i++)
  {
    myStepper.step(-512);
    delay(2000);
  }

  // Gira o motor no sentido anti-horario a 120 graus
  for (int i = 0; i <= 2; i++)
  {
    myStepper.step(682);
    delay(2000);
  }

  // Gira o motor no sentido horario, aumentando a
  // velocidade gradativamente
  for (int i = 10; i <= 60; i = i + 10)
  {
    myStepper.setSpeed(i);
    myStepper.step(40 * i);
  }
  delay(2000);
}