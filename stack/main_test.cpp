#include <iostream>
#include "stack.hpp"

int main(void)
{
    ft::stack<int>  s;
    ft::stack<int>  s2;

    std::cout << s.size() << std::endl;
    std::cout << (s != s2) << std::endl;
    return (0);
}