#include <vector>
#include <iostream>

template<typename T>
void    display_vector(const std::vector<T> & v)
{
    if (v.size() == 0)
    {
        std::cout << "Empty vector" << std::endl;
        return ;
    }
    for (size_t i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    std::vector<int> v(3, 100);

    v.insert(v.begin(), 5, 19);
    std::cout << v.capacity() << std::endl;
    display_vector(v);
}