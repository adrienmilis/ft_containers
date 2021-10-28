#include "../utils/utils.hpp"
#include "map.hpp"


// int main(void)
// {
//     std::cout << "============" << std::endl;
//     std::cout << "CONSTRUCTORS" << std::endl;
//     std::cout << "============" << std::endl << std::endl;

//     std::cout << std::endl;
//     std::cout << "=========" << std::endl;
//     std::cout << "OPERATOR=" << std::endl;
//     std::cout << "=========" << std::endl << std::endl;

//     std::cout << std::endl;
//     std::cout << "========" << std::endl;
//     std::cout << "CAPACITY" << std::endl;
//     std::cout << "========" << std::endl << std::endl;
    
//     std::cout << std::endl;
//     std::cout << "==============" << std::endl;
//     std::cout << "ELEMENT ACCESS" << std::endl;
//     std::cout << "==============" << std::endl << std::endl;

//     std::cout << std::endl;
//     std::cout << "=========" << std::endl;
//     std::cout << "MODIFIERS" << std::endl;
//     std::cout << "=========" << std::endl << std::endl;

//     std::cout << std::endl;
//     std::cout << "=========" << std::endl;
//     std::cout << "OBSERVERS" << std::endl;
//     std::cout << "=========" << std::endl << std::endl;

//     std::cout << std::endl;
//     std::cout << "==========" << std::endl;
//     std::cout << "OPERATIONS" << std::endl;
//     std::cout << "==========" << std::endl << std::endl;

//     std::cout << std::endl;
//     std::cout << "=========" << std::endl;
//     std::cout << "ITERATORS" << std::endl;
//     std::cout << "=========" << std::endl << std::endl;

//     std::cout << std::endl;
//     std::cout << "=================" << std::endl;
//     std::cout << "REVERSE_ITERATORS" << std::endl;
//     std::cout << "=================" << std::endl << std::endl;

// }

int main(void)
{
    ft::map<char, int>  m;

    m.insert(ft::make_pair('z', 4));
    m.insert(ft::make_pair('z', 10));
    m.insert(ft::make_pair('h', 3));
    m.insert(ft::make_pair('a', 1));

    ft::map<char, int>::iterator    it = m.begin();
    std::cout << it->first << ", " << it->second << std::endl;
    ++it;
    std::cout << it->first << ", " << it->second << std::endl;
    ++it;
    std::cout << it->first << ", " << it->second << std::endl;

    return (0);
}