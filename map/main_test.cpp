#include "../utils/utils.hpp"
#include "map.hpp"

int main(void)
{
    ft::map<char, int>  m;

    m.insert(ft::make_pair('z', 4));
    m.insert(ft::make_pair('h', 3));
    m.insert(ft::make_pair('a', 1));

    ft::map<char, int>::iterator    it = m.begin();
    std::cout << it->first << std::endl;
    ++it;
    std::cout << it->first << std::endl;

    return (0);
}