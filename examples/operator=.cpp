#include <vector>
#include <iostream>

template<typename T>
void    display_vector(std::vector<T> & v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << std::endl;
    }
}

int main(void)
{
    std::vector<int>    v(30, 15);
    std::vector<int>    v2(10,10);

    std::cout << v2.capacity() << std::endl;
    v2.push_back(10);
    std::cout << v2.capacity() << std::endl;
    v = v2;
    std::cout << "v capacity " << v.capacity() << std::endl;
    display_vector(v);
}