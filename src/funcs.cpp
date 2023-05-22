#include "funcs.h"

Car::Car() {
  name = "Test";
  owner = "Owner";
  serial_num = -1;
  stats = -1;
}

void Car::print() {
  std::cout << serial_num << '\n';
  std::cout << stats << '\n';
  std::cout << name << '\n';
  std::cout << owner << '\n';
}

void Car::setNum(int num) { serial_num = num; }
void Car::setStats(int stats_to_set) { stats = stats_to_set; }
void Car::setName(std::string name_to_set) { name = name_to_set; }
void Car::setOwner(std::string owner_to_set) { owner = owner_to_set; }

std::string Car::getName() { return name; }
std::string Car::getOwner() { return owner; }
int Car::getSerialNum() { return serial_num; }
int Car::getStats() { return stats; }

void viaFile(std::vector<Car> &obj_vec, std::string filename) {
  std::vector<std::string> vec;
  std::string line;
  Car car;
  int i = 0;

  std::ifstream fp(filename, std::ios::app);

  while (getline(fp, line)) {
    vec.push_back(line);
    std::cout << vec[i] << '\n';
    i++;
  }
  fp.close();

  int cnt = (i + 1) / 4;
  int j = 0;
  for (int i = 0; i < cnt; i++) {
    car.setNum(std::stoi(vec[j++]));
    car.setStats(std::stoi(vec[j++]));
    car.setName(vec[j++]);
    car.setOwner(vec[j++]);
    obj_vec.push_back(car);
  }
  storeInMap(obj_vec);
}

void storeInMap(std::vector<Car> &obj_vec) {
  std::map<std::string, int> mp;

  for (size_t i = 0; i < obj_vec.size(); i++) {
    mp[obj_vec[i].getName()] = mp[obj_vec[i].getName()] + 1;
  }

  for (size_t i = 0; i < mp.size(); i++) {
    std::cout << obj_vec[i].getName() << ":" << mp[obj_vec[i].getName()]
              << '\n';
  }
}

void viaKeyboard(std::vector<Car> &obj_vec, std::string filename) {
  Car car;
  int n, i = 0;
  int snumber, stat;
  std::string str;

  std::cout << "Введите количетсво владельцев: ";
  std::cin >> n;

  while (i < n) {
    std::cout << "Введите серийный номер " << i + 1 << " владельца: ";
    std::cin >> snumber;
    car.setNum(snumber);
    std::cout << "Введите характеристики автомобиля " << i + 1
              << " владельца: ";
    std::cin >> stat;
    car.setStats(stat);
    std::cout << "Введите название автомобиля " << i + 1 << " владельца: ";
    getline(std::cin, str);
    getline(std::cin, str);
    car.setName(str);
    std::cout << "Введите ФИО " << i + 1 << " владельца: ";
    getline(std::cin, str);
    car.setOwner(str);
    obj_vec.push_back(car);
    i++;
  }
  writeInFile(obj_vec, filename);
  printFile(filename);
  storeInMap(obj_vec);
}

void writeInFile(std::vector<Car> &obj_vec, std::string filename) {
  std::ofstream fp;
  fp.open(filename, std::ios::app);

  for (size_t i = 0; i < obj_vec.size(); i++) {
    fp << obj_vec[i].getSerialNum() << "\n";
    fp << obj_vec[i].getStats() << '\n';
    fp << obj_vec[i].getName() << '\n';
    fp << obj_vec[i].getOwner() << '\n';
  }
  fp.close();
}

void addLineInFile(std::vector<Car> &obj_vec, std::string filename) {
  std::string str1, str2;
  Car car;

  std::cout << "Введите название автомобиля: ";
  std::getline(std::cin, str1);
  //   std::getline(std::cin, str1);
  car.setName(str1);
  std::cout << "Введите ФИО владельца: ";
  std::getline(std::cin, str2);
  car.setOwner(str2);
  obj_vec.push_back(car);

  //   std::cout << "Название автомобиля: " << str1 << '\n';
  //   std::cout << "ФИО владельца: " << str2 << '\n';

  std::ofstream fp("log.txt", std::ios::app);
  fp << car.getName() << '\n' << car.getOwner() << '\n';
  fp.close();

  std::ofstream fptr(filename, std::ios::app);
  fptr << car.getSerialNum() << "\n";
  fptr << car.getStats() << '\n';
  fptr << car.getName() << '\n';
  fptr << car.getOwner() << '\n';
  fptr.close();

  printFile(filename);
  storeInMap(obj_vec);
}

void printLines(std::vector<Car> &obj_vec) {
  for (size_t i = 0; i < obj_vec.size(); i++) {
    std::cout << "Серийный номер " << i + 1
              << " владельца: " << obj_vec[i].getSerialNum() << "\n";
    std::cout << "Характеристики автомобиля " << i + 1
              << " владельца: " << obj_vec[i].getStats() << '\n';
    std::cout << "Название автомобиля " << i + 1
              << " владельца: " << obj_vec[i].getName() << '\n';
    std::cout << "ФИО " << i + 1 << " владельца: " << obj_vec[i].getOwner()
              << '\n';
  }
}

void printFile(std::string filename) {
  std::string str;
  std::ifstream fp;

  fp.open(filename);
  while (getline(fp, str)) {
    std::cout << str << '\n';
  }
  fp.close();
}

void deleteLines(std::string filename) {
  std::ofstream temp("temp.txt");
  std::ifstream fp(filename);
  std::string str, dline;
  std::vector<std::string> vec;

  std::cout << "Введите серийный номер автомобиля: ";
  getline(std::cin, dline);

  while (getline(fp, str)) {
    vec.push_back(str);
  }

  for (size_t i = 0; i < vec.size(); i = i + 4) {
    if (vec[i] == dline) {
      for (int j = i; j < i + 4; j++) {
        vec[j] = " ";
      }
    }
  }

  for (size_t i = 0; i < vec.size(); i++) {
    if (vec[i] != " ") {
      temp << vec[i] << '\n';
    }
  }
  fp.close();
  temp.close();
  remove(filename.c_str());
  rename("temp.txt", filename.c_str());
}

void changeFile(std::string filename) {
  std::ofstream temp("temp.txt");
  std::ifstream fp(filename);
  std::string str, dline, newname;
  std::vector<std::string> vec;

  std::cout << "Введите ФИО владельца: ";
  getline(std::cin, dline);
  std::cout << "Введи новое название автомобиля: ";
  getline(std::cin, newname);

  while (getline(fp, str)) {
    vec.push_back(str);
  }

  for (size_t i = 0; i < vec.size(); i++) {
    if (vec[i] == dline) {
      vec[i - 1] = newname;
    }
  }

  for (size_t i = 0; i < vec.size(); i++) {
    temp << vec[i] << '\n';
  }

  fp.close();
  temp.close();
  remove(filename.c_str());
  rename("temp.txt", filename.c_str());
}