#include "../vector/vector.hpp"
#include <iostream>

int main()
{
    ft::vector<int>    v(10, 10);

    ft::vector<int>::iterator it = v.begin();
    ft::vector<int>::const_iterator ite = v.begin();

    if (it == ite)
        std::cout << "ok" << std::endl;
    return (0);
}