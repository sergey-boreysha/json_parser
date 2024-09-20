#pragma once

#define DEBUG_PRINT_GET_VALUE NO

unsigned int parser_json_packages(vector<string>& string_from_file,vector<vector<string>>& json_packages);
string json_get_value(string temp);
unsigned int json_get_value_by_field(string&str, string&field_name, string&value);