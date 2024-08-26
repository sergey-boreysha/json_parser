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

/* string get_value(vector<string> json_package,string search_value)
{
    for(string strtmp : json_package)
    {
        if(strtmp.find(search_value)!=string::npos)
        {

        }
    }
} */

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

    /*
    *   сортировка по отправителю
    */
    string temp = "          \"ip.checksum\": \"0xc9d0\",";
    //string temp = "          \"ip.dst_host\": \"172.16.203.101\",";

    size_t ret = temp.find(":"); 

    string substring;

    if(ret!=string::npos)
    {
        substring = temp.substr(ret+3, temp.size()-ret-5); 
    }
    cout << substring << endl;
    while(1);

    /*
    *   сортировка по получателю
    */

    /*
    *   сортировка по длинне пакета
    */

    /*
    *   анализ отличий
    */









    
    
    
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

    



        
    

    