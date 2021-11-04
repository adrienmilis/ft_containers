#include <vector>
#include <iostream>

int main(void)
{
    std::vector<int> v(5, 100);

    std::vector<int>::reverse_iterator  rit = v.rbegin();
    std::vector<int>::iterator          it = v.begin();

    while (rit != it)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    return (0);
}