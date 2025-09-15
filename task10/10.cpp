#include <Servo.h>

Servo myServo;          // объект для сервопривода
int currentAngle = 0;   // текущий угол сервопривода

void setup() {
  Serial.begin(9600);       // запускаем последовательный порт
  myServo.attach(3);        // подключаем сервопривод к пину 9
  myServo.write(currentAngle); // ставим начальный угол 0
  Serial.println("введите угол от 0 до 180:");
}

void loop() {
  // проверяем, есть ли данные в serial
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // считываем строку до перевода строки
    input.trim(); // убираем пробелы и символы переноса строки

    // проверяем, состоит ли ввод только из цифр
    bool isNumber = true;
    for (unsigned int i = 0; i < input.length(); i++) {
      if (!isDigit(input[i])) {
        isNumber = false;
        break;
      }
    }

    if (isNumber) {
      int angle = input.toInt(); // преобразуем строку в число

      if (angle >= 0 && angle <= 180) {
        // если угол отличается от текущего, плавно поворачиваем сервопривод
        if (angle != currentAngle) {
          Serial.print("поворот сервопривода в угол: ");
          Serial.println(angle);

          if (angle > currentAngle) {
            for (int a = currentAngle; a <= angle; a++) {
              myServo.write(a);
              delay(10); // скорость поворота (можно менять)
            }
          } else {
            for (int a = currentAngle; a >= angle; a--) {
              myServo.write(a);
              delay(10);
            }
          }

          currentAngle = angle; // обновляем текущий угол
        }
      } else {
        Serial.println("ошибка: угол должен быть от 0 до 180");
      }
    } else {
      Serial.println("ошибка: вводите только числа");
    }

    Serial.println("введите угол от 0 до 180:");
  }
}
