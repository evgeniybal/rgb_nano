#include <Arduino.h>

#include "flows.h"
#include "pins.h"

void setup()
{
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  setColor(255, 0, 255); // violet — стартовый цвет для flow2
}

void loop()
{
  flow2(20);
}
