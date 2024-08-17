#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
//using namespace ofstream;

int main()
{
    //открываем файл
    string path = "log.json";
    ifstream fin;
    fin.open(path);

    vector<std::string> jsonstr;
    vector<std::string> payload;

    //вычитываем строки в вектор
    while(!fin.eof())
    {
        string strtmp = "";
        getline(fin,strtmp);
        jsonstr.push_back(strtmp);
    }

    cout << "lines readed " << jsonstr.size() << "..."<< endl;

    int index = 0;
    for(string strtmp : jsonstr)
    {
        if(strtmp.find("udp.payload")!=string::npos)
        {
            index++;
            strtmp.erase(0,25);
            payload.push_back(strtmp);
            cout << strtmp << endl << endl;
        }
    }

    /* cout << "find " << index << " elements..." << endl;

    map<unsigned int, unsigned int> pltype;

    for(string strtmp : payload)
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
    } */




    //закрываем файл
    fin.close();
}