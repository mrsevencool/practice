#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int k = 0;
  std::cout << "Введите длину слова и количество перестановок: ";
  std::cin >> n >> k; // читаем длину слова и количество применений перестановки

  std::vector<int> permutation(n); // вектор для хранения перестановки
  std::string word;

  std::cout << "Введите перестановку: ";
  for (int i = 0; i < n; i++) {
    std::cin >> permutation[i]; // читаем перестановку
  }

  std::cout << "Введите зашифрованное слово: ";
  std::cin >> word; // читаем зашифрованное слово

  std::string word2 = word; // временное слово для следующей итерации

  for (int j = 0; j < k; j++) {
    for (int i = 0; i < n; i++) {
      word2[permutation[i] - 1] = word[i]; // по перестановке ставим буквы на нужные позиции
    }
    word = word2; // обновляем текущее слово
  }

  std::cout << "Восстановленное слово: ";
  std::cout << word; // выводим восстановленное слово

  return 0;
}