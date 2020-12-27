// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include <Student.hpp>
#include <fstream>
#include <Json.hpp>

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(File_path, true_file_path) {
std::string file_path = "../file_json/main.json";
Table table;
table.parsing_file(file_path);
std::stringstream out;
out << table << std::endl;
std::cout << table.print_string_all() << std::endl;
EXPECT_TRUE(true);

}

TEST(Table_output, table_test) {
std::string file_path = "../file_json/main.json";
Table table;
table.parsing_file(file_path);
std::stringstream out;
out << table << std::endl;
std:: string true_table =
    "|name | group|  avg | debt | \n"
    "| Ivanov Petr | 1 | 4.25 | null | \n"
    "| Sidorov Ivan | 31 | 4 | C++ | \n"
    "| Pertov Nikita | IU8-31 | 3.5 | 3 | \n\n";
EXPECT_EQ(out.str(), true_table);
}


TEST(File_path, mistake_file_path) {
std::string error1;
std::string check =
    "Wrong path of json file: ../file_json/mainnn.json";
try {
std::string file_path = "../file_json/mainnn.json";
Table table;
table.parsing_file(file_path);
std::stringstream out;
out << table << std::endl;
} catch (std::string ERROR){
error1 = ERROR;
std::cout << "mistake is here: " << ERROR << std::endl;
}
EXPECT_EQ(error1,check);
}

TEST(Value_input, test_debt) {
std::string error1;
std::string check =
    "Debt is wrong (not null, string or array)\n";
try {
std::string file_path = "../file_json/debt_test.json";
Table table;
table.parsing_file(file_path);
std::stringstream out;
out << table << std::endl;
} catch (std::string ERROR){
error1 = ERROR;
std::cout << "mistake is here: " << ERROR << std::endl;
}
EXPECT_EQ(error1, check);
}

TEST(Value_input, test_name) {
std::string error1;
std::string check =
    "Name is wrong (not string)\n";
try {
std::string file_path = "../file_json/name_test.json";
Table table;
table.parsing_file(file_path);
std::stringstream out;
out << table << std::endl;
} catch (std::string ERROR){
error1 = ERROR;
std::cout << "mistake is here: " << ERROR << std::endl;
}
EXPECT_EQ(error1,check);
}

TEST(Value_input, test_group) {
std::string error1;
std::string check =
    "Group is wrong (not string or int number)\n";
try {
std::string file_path = "../file_json/group_test.json";
Table table;
table.parsing_file(file_path);
std::stringstream out;
out << table << std::endl;
} catch (std::string ERROR){
error1 = ERROR;
std::cout << "mistake is here: " << ERROR << std::endl;
}
EXPECT_EQ(error1,check);
}

TEST(Value_input, test_avg) {
std::string error1;
std::string check =
    "Average is wrong (not null,string,float,int)\n";
try {
std::string file_path = "../file_json/avg_test.json";
Table table;
table.parsing_file(file_path);
std::stringstream out;
out << table << std::endl;
} catch (std::string ERROR){
error1 = ERROR;
std::cout << "mistake is here: " << ERROR << std::endl;
}
EXPECT_EQ(error1,check);
}

TEST(Value_input, test_meta) {
std::string error1;
std::string check =
    "Items don't equal meta\n";
try {
std::string file_path = "../file_json/meta_test.json";
Table table;
table.parsing_file(file_path);
std::stringstream out;
out << table << std::endl;
} catch (std::string ERROR){
error1 = ERROR;
std::cout << "mistake is here: " << ERROR << std::endl;
}
EXPECT_EQ(error1,check);
}

TEST(Value_input, test_items) {
std::string error1;
std::string check =
    "Items is not array\n";
try {
std::string file_path = "../file_json/items_test.json";
Table table;
table.parsing_file(file_path);
std::stringstream out;
out << table << std::endl;
} catch (std::string ERROR){
error1 = ERROR;
std::cout << "mistake is here: " << ERROR << std::endl;
}
EXPECT_EQ(error1,check);
}
