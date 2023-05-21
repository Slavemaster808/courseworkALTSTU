#include "funcs.h"

int main(void) {
  setlocale(LC_ALL, "Russian");
  std::vector<Car> obj_vec;
  std::string filename;
  int choose;
  int check = 1;

  while (check) {
    std::cout << "1. Ввод с помощью клавиатуры." << '\n'
              << "2. Ввод с помощью файла." << '\n'
              << "3. Добавить данные." << '\n'
              << "4. Удалить данные." << '\n'
              << "5. Изменить марку автомобиля." << '\n'
              << "6. Выход." << '\n';
    std::cin >> choose;
    if (choose > 0 && choose < 6) {
      std::cout << "Введите название файла: ";
      getline(std::cin, filename);
      getline(std::cin, filename);
    }
    switch (choose) {
      case 1:
        viaKeyboard(obj_vec, filename);
        break;
      case 2:
        viaFile(obj_vec, filename);
        break;
      case 3:
        addLineInFile(obj_vec, filename);
        break;
      case 4:
        deleteLines(filename);
        break;
      case 5:
        changeFile(filename);
        break;
      case 6:
        check = 0;
        break;
      default:
        std::cout << "Такой опции не существует." << '\n';
        break;
    }
  }

  return 0;
}