#pragma once

#include <stdint.h>

// Цвет: яркость каждого канала 0..255
struct Color
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

// Готовые цвета. Значения подобраны «на глаз» —
// у RGB-светодиода зелёный обычно ярче, поэтому его часто приходится уменьшать.
const Color COLOR_RED         = {255, 0, 0};
const Color COLOR_ORANGE      = {255, 60, 0};
const Color COLOR_DARK_YELLOW = {255, 120, 0};
const Color COLOR_YELLOW      = {255, 200, 0};
const Color COLOR_LIME        = {150, 255, 0};
const Color COLOR_GREEN       = {0, 255, 0};
const Color COLOR_CYAN        = {0, 255, 255};
const Color COLOR_LIGHT_BLUE  = {0, 150, 255};
const Color COLOR_BLUE        = {0, 60, 255};
const Color COLOR_DARK_BLUE   = {0, 0, 255};
const Color COLOR_PURPLE      = {120, 0, 255};
const Color COLOR_VIOLET      = {255, 0, 255};
