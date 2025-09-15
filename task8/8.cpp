#include <FastLED.h>  // подключаем библиотеку для управления светодиодами

#define NUM_LEDS 64   // количество светодиодов в ленте
#define DATA_PIN 3    // пин arduino, к которому подключена лента

CRGB leds[NUM_LEDS]; // массив для хранения цвета каждого светодиода

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS); // настраиваем ленту
  FastLED.setBrightness(100); // устанавливаем яркость (0-255)
}

void loop() {
  rainbowCycle(10); // запускаем эффект радуги с задержкой 10 мс
}

void rainbowCycle(uint8_t wait) {
  static uint8_t hue = 0; // переменная цвета, которая будет меняться

  // проходим по всем светодиодам
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i * 256 / NUM_LEDS), 255, 255); // устанавливаем цвет светодиода
  }
  
  FastLED.show(); // обновляем цвета на ленте
  delay(wait);    // ждём указанное время
  hue++;          // сдвигаем цвета, чтобы создать движение радуги
}
