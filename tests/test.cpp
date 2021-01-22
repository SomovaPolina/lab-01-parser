#include <gtest/gtest.h>
#include <Student.hpp>
#include <fstream>
#include <Json.hpp>
#include <cstring>
#include <vector>
#include <iostream>

TEST(Example, EmptyTest) {
  EXPECT_TRUE(true);
}

TEST(File_path, true_file_path) {
  std::string test_string =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Petrov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
  std::ofstream test_file;
  test_file.open("test_file.json", std::ios::out);
  test_file << test_string;
  test_file.close();
  std::string file_path = "test_file.json";
  Table table;
  table.parsing_file(file_path);
  std::stringstream out;
  out << table << std::endl;
  std::cout << table.print_string_all() << std::endl;
  EXPECT_TRUE(true);
}

TEST(File_path, mistake_file_path) {
  std::string error1;
  std::string check =
      "Wrong path of json file: ../json_files/maaainnn.json";
  try {
    std::string file_path = "../json_files/maaainnn.json";
    Table table;
    table.parsing_file(file_path);
    std::stringstream out;
    out << table << std::endl;
  } catch (std::string ERROR) {
    error1 = ERROR;
    std::cout << "mistake is here: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1,check);
}

TEST(Value_input, test_debt) {
std::string test_string =\
R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": 4
    },
    {
      "name": "Petrov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
std::ofstream test_file;
test_file.open("test_debt.json", std::ios::out);
test_file << test_string;
test_file.close();

std::string error1;
std::string check =
    "Debt is wrong (not null, string or array)\n";
try {
std::string file_path = "test_debt.json";
Table table;
table.parsing_file(file_path);
std::stringstream out;
out << table << std::endl;
} catch (std::string ERROR) {
error1 = ERROR;
std::cout << "mistake is here: " << ERROR << std::endl;
}
EXPECT_EQ(error1, check);
}


TEST(Value_input, test_group) {
  std::string test_string =\
 R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 3.1,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Petrov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
  std::ofstream test_file;
  test_file.open("test_group.json", std::ios::out);
  test_file << test_string;
  test_file.close();

  std::string error1;
  std::string check =
      "Group is wrong (not string or int number)\n";
  try {
    std::string file_path = "test_group.json";
    Table table;
    table.parsing_file(file_path);
    std::stringstream out;
    out << table << std::endl;
  } catch (std::string ERROR) {
    error1 = ERROR;
    std::cout << "mistake is here: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1,check);
}

TEST(Value_input, test_avg) {
  std::string test_string =\
 R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Petrov Nikita",
      "group": "IU8-31",
      "avg": [4],
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
  std::ofstream test_file;
  test_file.open("test_avg.json", std::ios::out);
  test_file << test_string;
  test_file.close();

  std::string error1;
  std::string check =
      "Average is wrong (not null,string,float,int)\n";
  try {
    std::string file_path = "test_avg.json";
    Table table;
    table.parsing_file(file_path);
    std::stringstream out;
    out << table << std::endl;
  } catch (std::string ERROR) {
    error1 = ERROR;
    std::cout << "mistake is here: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1,check);
}

TEST(Value_input, fail_count) {
  std::string test_string =\
 R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Petrov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 2
  }
})";
  std::ofstream test_file;
  test_file.open("test_fail_count.json", std::ios::out);
  test_file << test_string;
  test_file.close();

  std::string error1;
  std::string check =
      "Items don't equal meta\n";
  try {
    std::string file_path = "test_fail_count.json";
    Table table;
    table.parsing_file(file_path);
    std::stringstream out;
    out << table << std::endl;
  } catch (std::string ERROR) {
    error1 = ERROR;
    std::cout << "mistake is here: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1,check);
}

