#include "Json.hpp"
#include <Student.hpp>
Table::Table() {}
void Table::parsing_file(const std::string& path_file) {
  std::ifstream file(path_file, std::ifstream::in);
  if (!file) {
    throw std::string("Wrong path of json file: " + path_file);
  }
  nlohmann::json data;
  file >> data;
  if (!data.at("items").is_array()) {
    throw std::string("Items is not array\n");
  }
  if (data.at("items").size() != data.at("_meta").at("count")) {
    throw std::string("Items don't equal meta\n");
  }

  for (auto i = data.at("items").cbegin();
       i < data.at("items").cend();
       i++)
  {
    students_all.push_back(Student(i.value()));
  }
}
std::string Table::print_string_all() {
  std::string string;
  string = "|name | group|  avg | debt | \n";
  for (auto i = students_all.cbegin(); i < students_all.cend(); i++) {
    string += i->print_string();
    string += "\n";
  }

  return string;

}
std::ostream& operator<<(std::ostream& out, const Table& t) {
  out << "|name | group|  avg | debt | " << std::endl;
  for (size_t i = 0; i < t.students_all.size(); i++) {
    out << t.students_all[i] << std::endl;
  }
  return out;
}