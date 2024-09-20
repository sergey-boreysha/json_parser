#include <vector>
#include <string>

using namespace std;

#include "castom-data-type.hpp"
#include "parcer.hpp"

/*
*   парсер JSON пакетов
*/
unsigned int parser_json_packages(vector<string>& string_from_file,vector<vector<string>>& json_packages)
{
    unsigned int opening_curly_braces = 0;
    unsigned int closing_curly_braces = 0;
    unsigned int founded_json_package = 0;

    vector<string> json_package;

    for(string strtmp : string_from_file)
    {
        for(char c_tmp : strtmp)
        {
            if(c_tmp == '{')
            {
                opening_curly_braces++;
            }

                if(c_tmp == '}')
                {
                    closing_curly_braces++;
                }

        }
            if(opening_curly_braces)
            {
                json_package.push_back(strtmp);

                if(opening_curly_braces==closing_curly_braces)
                {
                    opening_curly_braces = 0;
                    closing_curly_braces = 0;
                    founded_json_package++;

                    json_packages.push_back(json_package);
                    json_package.clear();
                }
            }
    }

    return founded_json_package;
}

/*
*   получение значения по имени поля
*/
string json_get_value(string temp)
{
    string substring;
    size_t ret = temp.find(":"); 

    if(ret!=string::npos)
    {
        substring = temp.substr(ret+3, temp.size()-ret-5); 
    }

    #if DEBUG_PRINT_GET_VALUE == YES
        cout << substring << endl;
    #endif

    return substring;
}

unsigned int json_get_value_by_field(string&str, string&field_name, string&value)
{
    size_t ret = str.find(field_name);

    if(ret!=string::npos)
    {
        value = json_get_value(str);
        return 1;
    }else
        {
            
            return 0;
        }
}