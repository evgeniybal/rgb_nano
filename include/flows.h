#pragma once

// Установить цвет сразу (0..255 на канал)
void setColor(int r, int g, int b);

// Плавно зажечь R, затем G, затем B (шаг 50 мс)
void flow();

// Радуга: плавный переход по цветам, time — пауза между шагами в мс
void flow2(int time);
