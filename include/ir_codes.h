#pragma once

#include <stdint.h>

// Коды кнопок ИК-пульта (протокол NEC, поле Cmd).
// Узнать код кнопки: нажать её и посмотреть в Serial Monitor строку
// "IR command: 0x.." (или Cmd на сканере).
//
// TODO: переименовать, когда станет ясно, какая это кнопка
//       (например IR_BTN_POWER, IR_BTN_1).
const uint16_t IR_BTN_A = 0x12;
const uint16_t IR_BTN_B = 0x03;
