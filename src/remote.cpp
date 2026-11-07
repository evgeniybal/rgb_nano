#include <Arduino.h>

// IRremote.hpp подключается только в ОДНОМ .cpp файле проекта —
// в нём не только объявления, но и сам код библиотеки.
#include <IRremote.hpp>

#include "ir_codes.h"
#include "pins.h"
#include "remote.h"
#include "state.h"

void remoteBegin()
{
  // ENABLE_LED_FEEDBACK — встроенный светодиод (D13) мигает при приёме сигнала
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
}

// Что делать при нажатии кнопки.
// Возвращает true, если состояние изменилось (эффект нужно прервать).
// Неизвестные кнопки игнорируются — их код всё равно печатается в Serial.
static bool handleButton(uint16_t command)
{
  switch (command)
  {
  case IR_BTN_A:
  case IR_BTN_B:
    // ВРЕМЕННО: обе известные кнопки — следующий режим
    state.mode = static_cast<Mode>((state.mode + 1) % MODE_COUNT);
    return true;

  default:
    return false;
  }
}

bool checkRemote()
{
  if (!IrReceiver.decode())
    return false;

  const IRData &data = IrReceiver.decodedIRData;
  const bool isRepeat = data.flags & IRDATA_FLAGS_IS_REPEAT;
  bool changed = false;

  // UNKNOWN — помехи, а не пульт. Повтор — кнопку держат зажатой.
  if (data.protocol != UNKNOWN && !isRepeat)
  {
    Serial.print(F("IR command: 0x"));
    Serial.println(data.command, HEX);
    changed = handleButton(data.command);
  }

  IrReceiver.resume(); // готовы принять следующий сигнал
  return changed;
}
