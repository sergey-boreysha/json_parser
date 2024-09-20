


#include <iostream>
#include <cstring>

using namespace std;

#include "castom-data-type.hpp"
#include "argument.hpp"

void print_help()
{
    cout << endl << "<<< JSON parser + sort + find differences >>>" << endl << endl;
    cout << "USING: parser <filename>" << endl << endl;
    cout << "COMMANDs:..." << endl;
    cout << "  prints | ps       - print result sort" << endl;
    cout << "  printg | pg <grp> - print group payload data lenght" << endl;
    cout << "analitic | al <grp> - analysis differences in group" << endl;
    cout << "   clear | cls      - clear console" << endl;
    cout << "    quit | q        - exit programm" << endl << endl;
}

void __argument_Handler(int argc, char* argv[])
{
    #if DEBUG_MODE_ARGUMENT == YES
        cout<<">>>>> WARNING!!! - ENABLE DEBUG MODE! <<<<<<"<<endl;
        argc = 3;
        char*path = new char[20];
        memset(path,0,20);
        memcpy(path,"idle.json",9);
        argv[1] = path;
    #endif

    if(!memcmp(argv[1],"--help",6))
    {
        print_help();
        exit(0);
    }

    if(argc<2)
    {
        print_help();
        exit(0);
    }
}