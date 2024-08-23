#include <vector>
#include <string>

using namespace std;

#include "parcer.hpp"

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