#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int k = 0;
  
  std::cout << "Введите количество улиц и число запросов:";
  std::cin >> n >> k; // читаем количество улиц и запросов

  std::vector<int> snow(n + 1, 0); // массив для хранения количества снега на каждой улице

  std::cout << "Введите запросы: ";
  for (int i = 0; i < k; ++i) {
    int type = 0;
    std::cin >> type; // читаем тип события: 1 — добавить снег, 2 — запрос суммы

    if (type == 1) {
      int index = 0;
      int amount = 0;
      std::cin >> index >> amount;
      snow[index] += amount; // добавляем снег на улице index
    } else if (type == 2) {
      int l = 0;
      int r = 0;
      std::cin >> l >> r;
      int sum = 0;
      for (int j = l; j <= r; ++j) {
        sum += snow[j]; // считаем сумму снега от l до r включительно
      }
      std::cout << "Результат: " << sum << std::endl; // выводим результат запроса
    }
  }

  return 0;
}
