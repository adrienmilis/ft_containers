#include <functional>
#include <iostream>

int main()
{
    std::less<char>  less;
    std::cout << less('a', 'b') << std::endl;
    return (0);
}