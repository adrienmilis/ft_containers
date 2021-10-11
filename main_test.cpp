#include "vector.hpp"
#include <iostream>

int main(void)
{
    vector<int>  v(3, 10);

    for (int i = 0; i < 4; i++)
        std::cout << v.at(i) << std::endl;
}