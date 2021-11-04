#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> v(5, 100);

    std::vector<int>::iterator  first = v.begin() + 1;
    std::vector<int>::iterator  last = v.end() - 1;

    std::cout << std::distance(first, last) << std::endl;
    std::cout << last - first << std::endl;
    return (0);
}