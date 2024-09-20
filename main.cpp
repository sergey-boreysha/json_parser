#include <iostream>
#include <sstream>  
#include <string>  
#include <fstream>
#include <vector>
#include <map>


/* 
#include <string>
#include <cstring>

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
    __argument_Handler(argc, argv);

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
    read_string_from_file(fin,string_from_file); //----------------------нужно ли вернуть чего??????

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

    map<string,map<string,vector<vector<string>>>> json_sorted;

    /*
    *   сортировка по получателю
    */

    /*
    *   сортировка по длинне пакета
    */

    /*
    *   анализ отличий
    */






    /*
    *   командный блок...
    */
    while(1)
    {
        //ввод строки с клавиатуры  
		std::string input;  
		std::cout << ">>> ";  
		std::getline(std::cin, input);  

		//создаем поток для разбора строки  
		std::istringstream stream(input);  
		std::string word;  
		std::vector<std::string> words;  

		//парсим строку и сохраняем слова в вектор  
		while (stream >> word)
		{  
			words.push_back(word);  
		}  

		//проверяем был ли ввод
		if(words.size()==0)
		{
			continue;
		}

        if(words[0]=="exit" && words.size()==1) exit(0);

        if(words[0]=="getval" && words.size()==2) //отладочная версия!!!
        {
            string ret_value;
            unsigned int json_number = 1;

            for(string temp : json_packages[0]) //временно один json
            {
                unsigned int ret = json_get_value_by_field(temp, words[1], ret_value);

                if(ret)
                {
                    cout << "json #" << json_number << " -> \"" << words[1] << "\"" <<" = " <<  "\"" << ret_value << "\"" << endl;
                }
            }
        } 

    }

    /*
    *   закрываем файл...
    */
    fin.close();
}
