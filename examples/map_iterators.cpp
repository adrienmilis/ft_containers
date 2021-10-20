#include <map>
#include <iostream>

int main()
{
    std::map<char, int> m;

    m['c'] = 1;
    m['y'] = 4;
    m['b'] = 7;

    std::map<char, int>::iterator   it = m.begin();
    std::map<char, int>::iterator   ite = m.end();

    while (it != ite)
    {
        std::cout << it->first << ", " << it->second << std::endl;
        // std::cout << *it << std::endl;   // does not compile
        ++it;
    }
}