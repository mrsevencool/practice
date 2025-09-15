#include <iostream>

int main() {
  std::string word;
  std::cout << "Введите строку из шести символов: ";
  std::cin >> word; // считываем строку из 6 символов

  // проверяем, соответствует ли строка формату номера:
  // первая буква, потом три цифры, потом две буквы
  std::cout << "Результат: ";
  if (std::isalpha(word[0]) && std::isdigit(word[1]) &&
      std::isdigit(word[2]) && std::isdigit(word[3]) &&
      std::isalpha(word[4]) && std::isalpha(word[5])) {
    std::cout << "Yes"; // все ок
  } else {
    std::cout << "No"; // не ок
  }

  return 0;
}