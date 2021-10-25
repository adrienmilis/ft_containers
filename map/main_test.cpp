#include "../utils.hpp"
#include "map.hpp"

int main(void)
{
    ft::map<char, int>  m;

    m.insert(ft::make_pair('a', 1));
    m.insert(ft::make_pair('b', 2));
    m.insert(ft::make_pair('c', 3));
    m.insert(ft::make_pair('d', 4));

    ft::map<char, int>::iterator    it = m.begin();
    std::cout << it->first << std::endl;

    return (0);
}