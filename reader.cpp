#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include "reader.hpp"

void read_string_from_file(ifstream& fin,vector<string>& string_from_file)
{
    while(!fin.eof())
    {
        string strtmp = "";
        getline(fin,strtmp);
        string_from_file.push_back(strtmp);
    }
}