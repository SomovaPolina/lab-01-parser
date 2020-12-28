#include <Student.hpp>
using nlohmann::json;

void Student::from_json(const json& j) {

  name = get_name(j.at("name"));
  group = get_group(j.at("group"));
  avg = get_avg(j.at("avg"));
  debt = get_debt(j.at("debt"));
}

auto Student::get_name(const json& j) -> std::string {
  if (j.is_string()) {
    return j.get<std::string>();
  }
  else throw (std::string("Name is wrong (not string)\n"));
}

auto Student::get_debt(const json& j) -> std::any {
  if (j.is_null())
    return nullptr;
  else if (j.is_string())
    return j.get<std::string>();
  else if (j.is_array())
    return j.get<std::vector<std::string> >();
  else throw (std::string("Debt is wrong (not null, string or array)\n"));
}

auto Student::get_avg(const json& j) -> std::any {
  if (j.is_null())
    return nullptr;
  else if (j.is_string())
    return j.get<std::string>();
  else if (j.is_number_float())
    return j.get<float>();
  else if (j.is_number_integer())
    return j.get<int>();
  else throw (std::string("Average is wrong (not null,string,float,int)\n"));
}

auto Student::get_group(const json& j) -> std::any {
  if (j.is_string())
    return j.get<std::string>();
  else if (j.is_number_integer())
    return j.get<int>();
  else throw (std::string("Group is wrong (not string or int number)\n"));
}


std::string Student::group_string() const
{
  if (group.type() == typeid(int))
    return std::to_string(std::any_cast<int>(group));
  else if (group.type() == typeid(float))
  {
    std::string tmp = std::to_string(std::any_cast<float>(group));
    while (tmp.at(tmp.size()-1) == '0')
      tmp.pop_back();
    return tmp;
  } else {
    return std::any_cast<std::string>(group);
  }
}
std::string Student::avg_string() const
{
  if (avg.type() == typeid(int))
    return std::to_string(std::any_cast<int>(avg));
  else if (avg.type() == typeid(float_t))
  {
    std::string tmp = std::to_string(std::any_cast<float>(avg));
    while (tmp.at(tmp.size()-1) == '0')
      tmp.pop_back();
    return tmp;
  } else {
    return std::any_cast<std::string>(avg);
  }
}
std::string Student::debt_string() const
{
  if (debt.type() == typeid(int))
    return std::to_string(std::any_cast<int>(debt));
  else if (debt.type() == typeid(std::vector<std::string>))
  {
    int size;
    size = std::any_cast<std::vector<std::string>>(debt).size();
    //  return "this debt is vector";
    return std::to_string(size);
  } else {
    if (debt.type() == typeid(std::nullptr_t))
    {
      return "null";
    } else {
      return std::any_cast<std::string>(debt);
    }
  }
}

std::string Student::print_string() const {
  std::string string;
  string = "| " + name +" | " + group_string() +" | "
           + avg_string() +" | " + debt_string() + " | ";
  return string;
}
Student::Student(const json& j) {
  from_json(j);
}
std::ostream& operator<<(std::ostream& out, const Student& s) {
  out << "| " << s.name <<" | " << s.group_string() <<" | "
      << s.avg_string() <<" | " << s.debt_string() << " | ";
  return out;
}