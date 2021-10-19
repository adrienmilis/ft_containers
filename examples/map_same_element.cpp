#include <map>
#include <iostream>

int main() {

    std::map<char,int> first;

    first['a'] = 1;
    first['a'] = 2;
    std::cout << first['a'] << std::endl;
    return (0);
}