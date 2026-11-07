#pragma once

#include <stdint.h>

#include "colors.h"

// Режимы работы. MODE_COUNT — не режим, а их количество (для перебора по кругу).
enum Mode : uint8_t
{
  MODE_FLOW2,
  MODE_FLOW,
  MODE_OFF,
  MODE_COLOR, // постоянный цвет из state.color
  MODE_COUNT
};

// Всё, чем управляет пользователь, — в одном месте.
// Сюда же потом добавим яркость.
struct State
{
  Mode mode = MODE_FLOW2;
  Color color = COLOR_VIOLET; // цвет для MODE_COLOR
};

// Одно общее состояние на всю программу. Создаётся в state.cpp.
extern State state;
