#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;
//using namespace ofstream;

unsigned char hstob(char data)
{
    if(data>=48 && data<=57)
        return (unsigned char)(data-48);
    if(data>=65 && data<=70)
        return (unsigned char)(data-55);
    if(data>=97 && data<=102)
        return (unsigned char)(data-87);

    return 0;
}

int main()
{
    //открываем файл
    string path = "log.json";
    ifstream fin;
    fin.open(path);

    vector<string> json_str;
    vector<string> payload_str;
    vector<vector<unsigned char>> payload_hex;

    //вычитываем строки из файла в вектор 
    while(!fin.eof())
    {
        string strtmp = "";
        getline(fin,strtmp);
        json_str.push_back(strtmp);
    }

    cout << "lines readed " << json_str.size() << "..."<< endl;

    int index = 0;

    //чистим строки
    for(string strtmp : json_str)
    {
        if(strtmp.find("udp.payload")!=string::npos)
        {
            index++;
            strtmp.erase(0,26);

            for(auto i=strtmp.begin();i!=strtmp.end();i++)
                if(*i==':') strtmp.erase(i);

            payload_str.push_back(strtmp);
            //cout << strtmp << endl << endl;
        }
    }

    cout << "find " << index << " string..." << endl;

    //конвертирование hex строки в число...
    index = 0;
    for(string strtmp : payload_str)
    {
        index++;
        vector<unsigned char> temp;

        for(size_t i=0;i<strtmp.size();i+=2)
        {
            unsigned char _hex = hstob(strtmp[i])*16 + hstob(strtmp[i+1]);
            temp.push_back(_hex);
        }
        
        payload_hex.push_back(temp);
    }

    cout << "convert " << index << " string..." << endl;

    //сортировка
    map<unsigned int, unsigned int> pltype;

    for(vector<unsigned char> strtmp : payload_hex)
    {
        unsigned int size = (unsigned int)strtmp.size();

        if(pltype.count(size))
        {
            pltype[size] += 1;
        }
        else
            {
                pltype.insert(make_pair(size,1));
            }
    }

    cout << "sorted " << pltype.size() << " uniq elements..." << endl;

     for(pair tmppr : pltype)
    {
        cout << "find " << tmppr.second << " pkg whis payload size " << tmppr.first << endl;
    }




    //закрываем файл
    fin.close();
}
        /* for(unsigned char c : temp)
        {
            printf("%2x ",(unsigned char)c);
        }
        cout << endl; */