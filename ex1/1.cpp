#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

// генерируем случайную пирамиду с n уровнями
std::vector<std::vector<int>> generatePyramid(int n) {
  int MAX_VAL = 100;
  std::vector<std::vector<int>> pyramid;
  for (int i = 0; i < n; ++i) {
    std::vector<int> vec;
    for (int j = 0; j <= i; ++j) {
      vec.push_back(std::rand() % MAX_VAL); // случайное число от 0 до 99
    }
    pyramid.push_back(vec);
  }
  return pyramid;
}

// выводим пирамиду на экран
void printPyramid(const std::vector<std::vector<int>>& pyramid) {
  for (const auto& row : pyramid) {
    for (int val : row) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  std::srand(std::time(nullptr));
  int N = 0;
  std::cout << "Высота: ";
  std::cin >> N;  // читаем высоту пирамиды
  auto pyramid = generatePyramid(N); // создаём пирамиду

  printPyramid(pyramid); // показываем пирамиду
  std::cout << std::endl;

  std::vector<std::vector<int>> dp = pyramid; // копируем для вычислений
  std::vector<std::vector<int>> path(N, std::vector<int>(N, -1)); // для восстановления пути

  // считаем минимальную сумму снизу вверх
  for (int i = N - 2; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      // выбираем лучший вариант из двух соседних на следующий уровень
      if (dp[i + 1][j] < dp[i + 1][j + 1]) {
        dp[i][j] += dp[i + 1][j];
        path[i][j] = j; // запоминаем путь
      } else {
        dp[i][j] += dp[i + 1][j + 1];
        path[i][j] = j + 1; // запоминаем путь
      }
    }
  }

  std::cout << "Минимальное время спуска: " << dp[0][0] << std::endl; // выводим минимальную сумму
  
  std::cout << "Путь: ";
  int col = 0;
  for (int i = 0; i < N; ++i) {
    std::cout << pyramid[i][col] << " "; // выводим элементы пути
    col = path[i][col]; // идём дальше по запомненному пути
  }
  std::cout << std::endl;

  return 0;
}
