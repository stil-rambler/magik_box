#include <Servo.h>
#include "button.h"

Servo myservo1;
Servo myservo2;

// Состояния системы (используем bool для логических значений)
bool boxClosed = true;      // состояние вокса (true - закрыто)
bool akumClosed = true;     // состояние отсека аккумулятора
bool hasBox = true;         // наличие груза в воксе
bool hasAkum = true;        // наличие аккумулятора

// Константы для пинов
const int BUTTON_BOX_PIN = 7;
const int BUTTON_AKUM_PIN = 8;

// Флаги операций
bool operationInProgress1 = false;
bool operationInProgress2 = false;

button btn1(BUTTON_BOX_PIN);
button btn2(BUTTON_AKUM_PIN);

// Углы сервоприводов
const int OPEN_ANGLE = 0;
const int CLOSE_ANGLE = 90;

void setup() {
  Serial.begin(9600);
  myservo1.attach(3);
  myservo2.attach(10);
  
  // Инициализация в закрытом состоянии
  myservo1.write(CLOSE_ANGLE);
  myservo2.write(CLOSE_ANGLE);
}

void toggleServo(Servo &servo, bool &state, bool &operationFlag) {
  if (operationFlag) return;
  
  operationFlag = true;
  int angle = state ? OPEN_ANGLE : CLOSE_ANGLE;
  servo.write(angle);
  state = !state;
  operationFlag = false;
}

void loop() {
  if (btn1.click()) {
    Serial.println("Box button pressed");
    toggleServo(myservo1, hasBox, operationInProgress1);
  }
  
  if (btn2.click()) {
    Serial.println("Akum button pressed");
    toggleServo(myservo2, hasAkum, operationInProgress2);
  }
}
