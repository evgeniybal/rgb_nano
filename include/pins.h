#pragma once

// Пины RGB-светодиода (ШИМ-выходы Arduino Nano).
// Пины 3 и 11 не используем: их ШИМ работает от Timer2,
// а Timer2 занимает библиотека IRremote.
const int R = 9;
const int G = 10;
const int B = 6;

// Сигнальный вывод (S) ИК-приёмника
const int IR_PIN = 2;
