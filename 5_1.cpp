#include <iostream>
#include <windows.h>
#include <map>
#include <string>
    
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string array;
    int maxCount = 0;

    cout << "Введите строку : ";
    getline(cin, array);

    map <char, int> symbols;
    map <char, int> symbolsErase;

    for (int i = 0; i < array.size(); i++)
    {
        symbols[array[i]] += 1;

        if (maxCount < symbols[array[i]])
        {
            maxCount = symbols[array[i]];
        }
    }

    int count = maxCount;
    for (int i = 0; i < symbols.size(); i++)
    {
        for (const auto& element : symbols)
        {
            if (element.second >= count)
            {
                cout << element.first << " : " << element.second << endl;
                symbolsErase[element.first];
                //symbols.erase(element.first);
            }
        }
        for (const auto& element : symbolsErase)
        {
            symbols.erase(element.first);
        }
        count--;
    }

    return 0;
}