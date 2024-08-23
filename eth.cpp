#include <iostream>
#include <fstream>
#include <vector>

/* 
#include <string>
#include <cstring>

#include <map>
#include <iomanip>
#include <sstream> */

using namespace std;

#include "argument.hpp"
#include "reader.hpp"
#include "parcer.hpp"
#include "analitic.hpp"

int main(int argc, char* argv[])
{
    /*
    *   обработка аргументов
    */
    __argumentHandler(argc, argv);

    /*
    *   открываем файл
    */
    string path = argv[1];

    ifstream fin;
    fin.open(path);
    
    if(fin.is_open())
    {
        cout << "file " << path << " is open" << endl;
    }
    else
        {
            cout << "file " << path << " not exist" << endl;
            exit(-1);
        }

    /*
    *   вычитываем строки из файла в вектор
    */ 
    vector<string> string_from_file;
    readfile(fin,string_from_file);

    cout << "lines readed " << string_from_file.size() << "..."<< endl;

    /*
    *   ищем пакеты json
    */ 
    vector<vector<string>> json_packages;
    unsigned int founded_json_package = parser_json_packages(string_from_file,json_packages);

    cout << "founded " << founded_json_package << " json package..."<< endl;
    cout << "founded " << json_packages.size() << " json package..."<< endl;














    
    
    
    //int index = 0;
    
    /*
    *   командный блок...
    */
    /* string cmd;
    string arg1(10,'\0');
    string arg2(10,'\0'); */
    
    /* while(1)
    {

    } */

    /*
    *   закрываем файл...
    */
    fin.close();
}

    



        
    

    