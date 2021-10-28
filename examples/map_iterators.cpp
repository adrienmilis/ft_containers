#include <map>
#include <iostream>
#include "../map/map.hpp"
#include "../utils/utils.hpp"

int main()
{
    ft::map<char, int> m;

    m.insert(ft::make_pair('c', 1));
    m.insert(ft::make_pair('b', 7));
    m.insert(ft::make_pair('y', 4));
    // m['c'] = 1;
    // m['y'] = 4;
    // m['b'] = 7;

    ft::map<char, int>::iterator   it = m.begin();
    // ft::map<char, int>::iterator   ite = m.end();

    // while (it != ite)
    // {
        // std::cout << it->first << ", " << it->second << std::endl;
        std::cout << (*it).first << std::endl;
        ++it;
    // }
}