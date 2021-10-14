#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int>            v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    std::vector<int>::iterator  it = v.begin();
    std::vector<int>::iterator  ite = v.end();
    std::vector<int>::iterator  new_it;

    std::cout << ite - it << std::endl;
    


    // std::cout << it[-2] << std::endl;

    // int tab[5] = {1,2,3,4,5};

    // int *ptr = tab;
    // int *ptr2 = tab + 4;

    // std::cout << (ptr2 > ptr) << std::endl;

}