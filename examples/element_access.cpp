#include <vector>
#include <iostream>

int main(void)
{
    std::vector<int> v(10, 10);

    std::cout << v.at(-1) << std::endl;
    return (0);
}