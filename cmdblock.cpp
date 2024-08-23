/* cmd.clear();
        getline(cin, cmd);

        sscanf(cmd.c_str(),"%s %s",arg1.data(),arg2.data());
        unsigned int key = (unsigned int)atoi(arg2.c_str());

        //печать группы пакетов...    
        if(!memcmp(arg1.c_str(),"printg",6)||!memcmp(arg1.c_str(),"pg",2))
        {
            if(key>0)
            {
                if(payload_sort.count(key))
                {
                    print_group(payload_sort,(unsigned char)key);
                    continue;
                }
                else
                    {
                        cout << ">>>> illegal key!" << endl;
                        continue;
                    }
            }
        }

        //анализ группы пакетов...    
        if(!memcmp(arg1.c_str(),"analitic",8)||!memcmp(arg1.c_str(),"al",2))
        {
            analitic(payload_sort,(unsigned char)key);
            continue;
        }

        //печать списка сортировки...
        if(cmd=="prints"||cmd=="ps")
        {
            print_sort(payload_sort);
            continue;
        }

        //очистка консоли...
        if(cmd=="clear"||cmd=="cls")
        {
            system("cls");
            continue;
        }


        //пустая комманда...
        if(cmd=="")
        {
            continue;
        }

        //выход...
        if(cmd=="quit"||cmd=="q")
        {
            break;
        }

        cout << ">>>> illegal cmd!" << endl; */