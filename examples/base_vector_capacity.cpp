#include <vector>
#include <iostream>

int main(void)
{
    std::vector<int>    v;
    
    std::cout << v.capacity() << std::endl;
    v.push_back(1);
    std::cout << v.capacity() << std::endl;
    v.push_back(1);
    std::cout << v.capacity() << std::endl;
}