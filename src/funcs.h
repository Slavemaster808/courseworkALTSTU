#ifndef FUNCS_H
#define FUNCS_H
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Car {
 private:
  int serial_num;
  int stats;
  std::string name;
  std::string owner;

 public:
  Car();
  void print();
  void setNum(int num);
  void setStats(int stats_to_set);
  void setName(std::string name_to_set);
  void setOwner(std::string owner_to_set);
  std::string getName();
  std::string getOwner();
  int getSerialNum();
  int getStats();
};

void viaFile(std::vector<Car> &obj_vec, std::string filename);

void storeInMap(std::vector<Car> &obj_vec);

void viaKeyboard(std::vector<Car> &obj_vec, std::string filename);

void writeInFile(std::vector<Car> &obj_vec, std::string filename);

void addLineInFile(std::vector<Car> &obj_vec, std::string filename);

void printLines(std::vector<Car> &obj_vec);

void printFile(std::string filename);

void deleteLines(std::string filename);

void changeFile(std::string filename);

#endif