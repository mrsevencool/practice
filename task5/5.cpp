#include <iostream>
#include <vector>

int main() {
  int h = 0;
  int w = 0;
  std::cout << "Введите высоту и ширину матрицы: ";
  std::cin >> h >> w; // читаем размеры матрицы

  std::vector<std::vector<int>> matrix(h, std::vector<int>(w)); // создаём матрицу h×w

  std::cout << "Введите значения матрицы: ";
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      std::cin >> matrix[i][j]; // считываем значения в матрицу
    }
  }

  int min_i = h;  // минимальная строка, где встретилась 1
  int min_j = w;  // минимальный столбец, где встретилась 1
  int max_i = -1; // максимальная строка, где встретилась 1
  int max_j = -1; // максимальный столбец, где встретилась 1

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (matrix[i][j] == 1) {
        if (i < min_i) {
          min_i = i; // обновляем верхнюю границу
        }
        if (j < min_j) {
          min_j = j; // обновляем левую границу
        }
        if (i > max_i) {
          max_i = i; // обновляем нижнюю границу
        }
        if (j > max_j) {
          max_j = j; // обновляем правую границу
        }
      }
    }
  }

  std::cout << "Координаты прямоугольника: " << min_i - 1 << ' ' << min_j - 1 << ' ' << max_i + 1 << ' ' << max_j + 1; // выводим координаты прямоугольника
}