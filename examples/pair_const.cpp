#include <iostream>
#include <utility>
#include "../utils/utils.hpp"

template <typename T>
class test
{
    public:

        std::pair <const T, int> pair;
};

int main(void)
{
    test<int>   salut;

    salut.pair = std::make_pair(10, 10);
    return (0);
}