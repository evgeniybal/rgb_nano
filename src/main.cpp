#include <Arduino.h>

const int R = 9, G = 10, B = 11;

void setColor(int r, int g, int b) {
  analogWrite(R, r);
  analogWrite(G, g);
  analogWrite(B, b);
}

void flow() {
  for (int i = 0; i < 256; i++) {
    analogWrite(R, i);
    delay(50);
  }
  for (int i = 0; i < 256; i++) {
    analogWrite(G, i);
    delay(50);
  }
  for (int i = 0; i < 256; i++) {

    analogWrite(B, i);
    delay(50);
  }
}
void flow2(int time){
  for (int i = 255; i > -1; i--) {
    analogWrite(R, i);//blue
    delay(time);
  }
  for (int i = 0; i < 256; i++) {
    analogWrite(G, i);//verdejo
    delay(time);
  }
  for (int i = 255; i > -1; i--) {
    analogWrite(B, i);//verde
    delay(time);
  }
  for (int i = 0; i < 256; i++) {
    analogWrite(R, i);//amarillo y naranja
    delay(time);
  }
  for (int i = 255; i > -1; i--) {
    analogWrite(G, i);//rojo
    delay(time);
  }
  for (int i = 0; i < 70; i++) {
    analogWrite(G, i);//pink
    analogWrite(B, i);
    delay(time);
  }
  for (int i = 69; i > -1; i--) {
    analogWrite(G, i);//violetejo
    delay(time);
  }
  for (int i = 69; i < 256; i++) {
    analogWrite(B, i);//violeta
    delay(time);
  }
}
void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  for (int i = 0; i < 256; i++) {
    analogWrite(R, i);
    analogWrite(B, i);//violet
    delay(50);
  }
}
void loop() {
  flow2(20);
}
