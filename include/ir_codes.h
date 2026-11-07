#pragma once

#include <stdint.h>

// Коды кнопок ИК-пульта (протокол NEC, поле Cmd).
// Узнать код кнопки: нажать её и посмотреть в Serial Monitor строку
// "IR command: 0x.." (или Cmd на сканере).
//
// TODO: переименовать, когда станет ясно, какая это кнопка
//       (например IR_BTN_POWER, IR_BTN_1).
const uint16_t IR_BTN_ON = 0x12;
const uint16_t IR_BTN_B = 0x03;
const uint16_t IR_BTN_OFF = 0x1A;
const uint16_t IR_BTN_LIGHTNESS = 0x1E;
const uint16_t IR_BTN_4H = 0x1;
const uint16_t IR_BTN_8H = 0x2;
const uint16_t IR_BTN_MC = 0x3;
const uint16_t IR_BTN_RED = 0x4;
const uint16_t IR_BTN_GREEN = 0x5;
const uint16_t IR_BTN_DARK_BLUE = 0x6;
const uint16_t IR_BTN_ORANGE = 0x7;
const uint16_t IR_BTN_LIME = 0x8;
const uint16_t IR_BTN_BLUE = 0x9;
const uint16_t IR_BTN_DARK_YELLOW = 0xA;
const uint16_t IR_BTN_LIGHT_BLUE = 0x1B;
const uint16_t IR_BTN_VIOLET = 0x1F;
const uint16_t IR_BTN_YELLOW = 0xC;
const uint16_t IR_BTN_CYAN = 0xD;
const uint16_t IR_BTN_PURPURE = 0xE;
