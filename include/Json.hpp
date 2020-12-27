//
// Created by zagig on 24.12.2020.
//

#ifndef TEMPLATE_JSON_HPP
#define TEMPLATE_JSON_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Student.hpp>
#include <ostream>
class Table {
 public:
  Table();
  void parsing_file(const std::string &path_file);
  std::string print_string_all();
  friend std::ostream& operator<<(std::ostream &out, const Table& t);
 private:
  std::vector<Student> students_all;

};


#endif  // TEMPLATE_JSON_HPP
