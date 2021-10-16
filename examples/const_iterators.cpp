#include <vector>
#include <iostream>

int main(void)
{
    std::vector<int> v(3, 100);

    std::vector<int>::iterator          it = v.begin();
    std::vector<int>::const_iterator    cit = v.begin();

    if (it == cit)
    {
        std::cout << "true" << std::endl;
    }
    return (0);
}