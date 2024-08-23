//конвертор hex байта string в unsigned char...
/* unsigned char hstob(char data)
{
    if(data>=48 && data<=57)
        return (unsigned char)(data-48);
    if(data>=65 && data<=70)
        return (unsigned char)(data-55);
    if(data>=97 && data<=102)
        return (unsigned char)(data-87);

    return 0;
}
 */
//распечатка сортировки...
/* void print_sort(map<unsigned int, vector<vector<unsigned char>>> & data)
{
    for(pair plspair : data)
    {
        cout << "size " << plspair.first << " | contains objects " << plspair.second.size() << endl;
    }
} */

//печать заголовка, нумерация байт...
/* void print_head(unsigned char key)
{
    for(int i=0;i<=key;i++)
        cout << setw(2) << std::setfill('0') << i << " ";
    cout << endl;

    for(int i=0;i<=((key+1)*2)+key;i++)
        cout << "-";
    cout << endl;
} */

//печать отсортированной группы по ключу...
/* void print_group(map<unsigned int, vector<vector<unsigned char>>> & data, unsigned char key)
{
    print_head(key);

    vector<vector<unsigned char>> & outer_vec = data[key];

    // Вывод элементов векторов  
    for (const auto & inner_vec : outer_vec) 
    {  
        for (unsigned char value : inner_vec) {  
            cout << hex << setw(2) <<static_cast<int>(value) << " " << dec;  
        }  
        cout << endl;  
    }
} */

/* void analitic(map<unsigned int, vector<vector<unsigned char>>> & data, unsigned char key)
{
    cout << ">>>> analitic..." << endl;

    vector<vector<unsigned char>> & outer_vec = data[key];

    //vector<unsigned int> differences;
    map<unsigned int,unsigned int> differences;

    //ищем несовпадения...
    for(unsigned int i=0;i<key;i++)
    {
        unsigned char temp = data[key][0][i];

        for(vector<unsigned char> & inner_vec : outer_vec) 
        {  
            if(temp!=inner_vec[i])
            {
                if(!differences.count(temp))
                {
                    differences.insert(make_pair(i,i));
                }
            }
        }
    }

        if(differences.size())
        {
            cout << "found " << differences.size() << " differences" << endl;
            cout << "are different ";

            for(pair tmp : differences)
            {
                cout << dec << tmp.first << " ";
            }

            cout << "bytes" << endl;
        }
        else
            {
                cout << ">>>> payload equial!" << endl;
            }
} */

/*
    *   чистим строки
    */
    /* for(string strtmp : json_str)
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
    } */

    //cout << "find " << index << " string..." << endl;

    /*
    *   конвертирование hex строки в число...
    */
    /* index = 0;
    for(string strtmp : payload_str)
    {
        index++;
        vector<unsigned char> temp;

        for(size_t i=0;i<strtmp.size();i+=2)
        {
            unsigned char _hex = (unsigned char)(hstob(strtmp[i])*16 + hstob(strtmp[i+1]));
            temp.push_back(_hex);
        }
        
        payload_hex.push_back(temp);
    }

    cout << "convert " << index << " string..." << endl; */

    /*
    *   сортировка...
    */
    /* map<unsigned int, vector<vector<unsigned char>>> payload_sort;

    for(vector<unsigned char> uchtmp : payload_hex)
    {
        unsigned int size = (unsigned int)uchtmp.size()-1;

        if(payload_sort.count(size))
        {
            payload_sort[size].push_back(uchtmp);
        }
        else
            {
                // Используем emplace для создания ключа и первоначального значения
                //без make_pair!
                payload_sort.emplace(size, vector<vector<unsigned char>>());  
    
                // Добавляем вектор в значение по ключу 1  
                payload_sort[size].push_back(uchtmp);  
            }
    }

    cout << "sorted " << payload_sort.size() << " uniq elements..." << endl; */