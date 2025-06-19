#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n; // читаем количество запросов

  std::vector<std::vector<int>> requests(n, std::vector<int>(4)); // создаём массив для хранения всех запросов

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      std::cin >> requests[i][j]; // считываем a, b, x, y для каждого запроса
    }
  }
  
  for (int i = 0; i < n; i++) {
    std::vector<int> request = requests[i];
    int a = request[0]; // количество контроллеров A
    int b = request[1]; // количество контроллеров B
    int x = request[2]; // количество модулей типа 1
    int y = request[3]; // количество модулей типа 2

    int max_b_pair = 0;

    // пытаемся подключить B только к модулям типа 1 (они совместимы)
    if (b >= x) {
      max_b_pair = x; // b хватит на все x
      x = 0; // все модули типа 1 ушли на B
    } else {
      max_b_pair = b; // b меньше x, значит используем всех B
      x -= b; // уменьшаем x на использованные
    }

    // теперь A можно подключить к оставшимся x и ко всем y
    int max_a_pair = std::min(a, x + y);

    std::cout << max_b_pair + max_a_pair << ' '; // выводим общее количество пар
  }

  return 0;
}
