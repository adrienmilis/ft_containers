#include <map>
#include <iostream>

int main()
{
    std::map<int, int>  m;

    std::map<int, int>::iterator it = m.begin();
    ++it;
}