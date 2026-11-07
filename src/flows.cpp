#include <Arduino.h>

#include "flows.h"
#include "pins.h"
#include "timing.h"

// Все эффекты устроены одинаково:
//   - в начале выставляют свой стартовый цвет;
//   - вместо delay() используют wait(): если нажали кнопку пульта,
//     эффект сразу выходит (return), и loop() запускает новый режим.

void setColor(int r, int g, int b)
{
  analogWrite(R, r);
  analogWrite(G, g);
  analogWrite(B, b);
}

void flow()
{
  setColor(0, 0, 0); // стартовый цвет: выключено

  for (int i = 0; i < 256; i++)
  {
    analogWrite(R, i);
    if (wait(50)) return;
  }
  for (int i = 0; i < 256; i++)
  {
    analogWrite(G, i);
    if (wait(50)) return;
  }
  for (int i = 0; i < 256; i++)
  {
    analogWrite(B, i);
    if (wait(50)) return;
  }
}

void flow2(int time)
{
  // Стартовый цвет: violet. Им же эффект и заканчивается,
  // поэтому при повторе по кругу рывка нет.
  setColor(255, 0, 255);

  for (int i = 255; i > -1; i--)
  {
    analogWrite(R, i); // blue
    if (wait(time)) return;
  }
  for (int i = 0; i < 256; i++)
  {
    analogWrite(G, i); // verdejo
    if (wait(time)) return;
  }
  for (int i = 255; i > -1; i--)
  {
    analogWrite(B, i); // verde
    if (wait(time)) return;
  }
  for (int i = 0; i < 256; i++)
  {
    analogWrite(R, i); // amarillo y naranja
    if (wait(time)) return;
  }
  for (int i = 255; i > -1; i--)
  {
    analogWrite(G, i); // rojo
    if (wait(time)) return;
  }
  for (int i = 0; i < 70; i++)
  {
    analogWrite(G, i); // pink
    analogWrite(B, i);
    if (wait(time)) return;
  }
  for (int i = 69; i > -1; i--)
  {
    analogWrite(G, i); // violetejo
    if (wait(time)) return;
  }
  for (int i = 69; i < 256; i++)
  {
    analogWrite(B, i); // violeta
    if (wait(time)) return;
  }
}
