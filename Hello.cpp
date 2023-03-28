#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

    /*
    *   potrzeba:
    *       - pozycja litery
    *       - ilość powtórzeń
    *       - pozycja ostatniego powtórzenia
    */

int compare(std::string str, int pos)
{
    int wynik = pos;
    if (str.at(pos) == str.at(pos + 1))
    {
        wynik++;
        if (wynik >= str.size())    
            return wynik;
        wynik = compare(str, wynik);
    }
    return wynik;
}

void mod(std::string & str)
{
    int pozycjaLitery;
    int ilPowt;
    int ostPowt;
    for (size_t i{0}; i < str.size(); ++i)
    {
        if (str.at(i) == str.at(i + 1))
        {
            pozycjaLitery = i;
            ostPowt = compare(str, i);
        }
        else
        {
            continue;
        }
        str.insert(pozycjaLitery, std::to_string(ostPowt - pozycjaLitery));
        str.erase(str.begin() + pozycjaLitery + 1, str.begin() + ostPowt);
    }
}

int main()
{
    std::string str{"JRRRATAKKK"};
    //getline(std::cin, str);
    std::cout << "Normalna wersja: "<< str << '\n';
    mod(str);
    std::cout << "Zmieniona wersja: "<< str << '\n';
}