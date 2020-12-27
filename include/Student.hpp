//
// Created by zagig on 24.12.2020.
//

#ifndef TEMPLATE_STUDENT_HPP
#define TEMPLATE_STUDENT_HPP

#include <iostream>
#include <any>
#include <string>
#include "nlohmann/json.hpp"

using namespace nlohmann;

class Student {
 public:
  void from_json(const json& j);
  auto get_name(const json& j) -> std::string;
  auto get_debt(const json& j) -> std::any;
  auto get_avg(const json& j) -> std::any;
  auto get_group(const json& j) -> std::any;
  std::string print_string() const;
  std::string group_string() const;
  std::string avg_string() const;
  std::string debt_string() const;
  friend std::ostream& operator<<(std::ostream &out, const Student& s);

  Student(const json &j);

 private:
  std::string name;
  std::any group;
  std::any avg;
  std::any debt;
};


#endif  // TEMPLATE_STUDENT_HPP
