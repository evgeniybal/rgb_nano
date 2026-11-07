#include <Arduino.h>

#include "flows.h"
#include "pins.h"
#include "remote.h"
#include "state.h"
#include "timing.h"

void setup()
{
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  Serial.begin(9600);
  remoteBegin();
}

// Запускает эффект текущего режима.
// Если во время эффекта нажали кнопку — эффект прерывается,
// loop() начинается заново и запускает уже новый режим.
void loop()
{
  switch (state.mode)
  {
  case MODE_FLOW2:
    flow2(20);
    break;

  case MODE_FLOW:
    flow();
    break;

  case MODE_OFF:
    setColor(0, 0, 0);
    wait(100); // просто ждём кнопку
    break;

  default:
    break;
  }
}
