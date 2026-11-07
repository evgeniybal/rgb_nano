#include <Arduino.h>

// IRremote.hpp подключается только в ОДНОМ .cpp файле проекта —
// в нём не только объявления, но и сам код библиотеки.
#include <IRremote.hpp>

#include "colors.h"
#include "ir_codes.h"
#include "pins.h"
#include "remote.h"
#include "state.h"

// Какая кнопка пульта какой цвет включает.
// Чтобы добавить цвет — допиши строку.
struct ColorButton
{
  uint16_t button;
  Color color;
};

const ColorButton COLOR_BUTTONS[] = {
    {IR_BTN_RED, COLOR_RED},
    {IR_BTN_ORANGE, COLOR_ORANGE},
    {IR_BTN_DARK_YELLOW, COLOR_DARK_YELLOW},
    {IR_BTN_YELLOW, COLOR_YELLOW},
    {IR_BTN_LIME, COLOR_LIME},
    {IR_BTN_GREEN, COLOR_GREEN},
    {IR_BTN_CYAN, COLOR_CYAN},
    {IR_BTN_LIGHT_BLUE, COLOR_LIGHT_BLUE},
    {IR_BTN_BLUE, COLOR_BLUE},
    {IR_BTN_DARK_BLUE, COLOR_DARK_BLUE},
    {IR_BTN_PURPURE, COLOR_PURPLE},
    {IR_BTN_VIOLET, COLOR_VIOLET},
};

void remoteBegin()
{
  // ENABLE_LED_FEEDBACK — встроенный светодиод (D13) мигает при приёме сигнала
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
}

// Переключить режим. Возвращает true, если режим действительно сменился.
// Если режим тот же — false, и текущий эффект не перезапускается.
static bool setMode(Mode newMode)
{
  if (state.mode == newMode)
    return false;

  state.mode = newMode;
  return true;
}

// Включить постоянный цвет. Возвращает true, если что-то изменилось.
static bool showColor(const Color &c)
{
  const bool same = state.mode == MODE_COLOR &&
                    state.color.r == c.r &&
                    state.color.g == c.g &&
                    state.color.b == c.b;
  if (same)
    return false;

  state.mode = MODE_COLOR;
  state.color = c;
  return true;
}

// Что делать при нажатии кнопки.
// Возвращает true, если состояние изменилось (эффект нужно прервать).
// Неизвестные кнопки игнорируются.
static bool handleButton(uint16_t command)
{
  switch (command)
  {
  case IR_BTN_ON: // включить: радуга
    return setMode(MODE_FLOW2);

  case IR_BTN_OFF: // выключить
    return setMode(MODE_OFF);

  case IR_BTN_MC: // сменить эффект: flow2 <-> flow
    return setMode(state.mode == MODE_FLOW2 ? MODE_FLOW : MODE_FLOW2);

  default:
    break;
  }

  // Не режимная кнопка — может, это кнопка цвета?
  for (const ColorButton &cb : COLOR_BUTTONS)
  {
    if (cb.button == command)
      return showColor(cb.color);
  }

  return false; // неизвестная кнопка
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
    // Отладка: печать кода кнопки (раскомментируй вместе с Serial.begin в main.cpp)
    // Serial.print(F("IR command: 0x"));
    // Serial.println(data.command, HEX);
    changed = handleButton(data.command);
  }

  IrReceiver.resume(); // готовы принять следующий сигнал
  return changed;
}
