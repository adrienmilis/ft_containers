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
    std::vector<int>    foo(3, 100);
    std::vector<int>    bar(5, 200);
    std::vector<int>::iterator  foo_it = foo.begin();

    foo.swap(bar);
    display_vector(foo);
    std::cout << *foo_it << std::endl;
    return (0);
}