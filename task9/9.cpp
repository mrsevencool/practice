// пины подключения светодиодов и фоторезистора
#define RED_LED 9       // красный светодиод - двери закрыты
#define GREEN_LED 5     // зеленый светодиод - двери открыты
#define LDR A0          // фоторезистор на аналоговый пин

#define THRESHOLD 512   // порог, при котором дверь открывается
#define OPEN_TIME 3000  // минимальное время, на которое дверь остаётся открытой (мс)

bool doorIsOpen = false;       // дверь сейчас открыта или закрыта
unsigned long openTimer = 0;   // таймер для минимального времени открытия

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(LDR, INPUT);

  // по умолчанию дверь закрыта
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);

  Serial.begin(9600);
  Serial.println("автоматические двери запущены");
}

void loop() {
  int lightValue = analogRead(LDR);  // считываем значение освещенности

  // если Lux больше порога и дверь закрыта, открываем дверь
  if (lightValue > THRESHOLD && !doorIsOpen) {
    doorIsOpen = true;
    openTimer = millis();           // запускаем таймер
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    Serial.println("дверь открывается!");
  }

  // если дверь открыта
  if (doorIsOpen) {
    // проверяем, прошло ли минимальное время OPEN_TIME
    if (millis() - openTimer >= OPEN_TIME) {
      // если человек ушёл, закрываем дверь сразу
      if (lightValue <= THRESHOLD) {
        doorIsOpen = false;
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);
        Serial.println("дверь закрыта");
      }
      // иначе, оставляем дверь открытой и таймер не сбрасываем, чтобы минимальное время уже прошло
    }
  }

  delay(50); // пауза для стабильной работы
}
