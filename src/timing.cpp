#include <Arduino.h>

#include "remote.h"
#include "timing.h"

bool wait(unsigned long ms)
{
  unsigned long start = millis();
  while (millis() - start < ms)
  {
    if (checkRemote())
      return true;
  }
  return false;
}
