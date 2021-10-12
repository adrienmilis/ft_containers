#include "vector.hpp"
#include <iostream>

template<typename T>
void    display_vector(vector<T> & v)
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
    std::cout << "============" << std::endl;
    std::cout << "CONSTRUCTORS" << std::endl;
    std::cout << "============" << std::endl << std::endl;
    std::cout << "--- 1. Default constructor ---" << std::endl;
    vector<int> v;
    display_vector(v);
    std::cout << "--- 2. Fill constructor ---" << std::endl;
    vector<int> v2(5, 10);
    display_vector(v2);
    std::cout << "--- 3. Range constructor ---" << std::endl; // TO DO
    std::cout << "--- 4. Copy constructor ---" << std::endl;
    vector<int> v4(v2);
    display_vector(v4);

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "OPERATOR=" << std::endl;
    std::cout << "=========" << std::endl << std::endl;
    v = v4;
    display_vector(v);

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "ITERATORS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;
    std::cout << std::endl;
    std::cout << "========" << std::endl;
    std::cout << "CAPACITY" << std::endl;
    std::cout << "========" << std::endl << std::endl;
    std::cout << "--- 1. Size ---" << std::endl;
    std::cout << "v size (should be 5): " << v.size() << std::endl;
    std::cout << "--- 2. Max_size ---" << std::endl;
    std::cout << "v max_size: " << v.max_size() << std::endl;
    std::cout << "--- 3. Resize ---" << std::endl;
    v.resize(2, 5);
    display_vector(v);
    std::cout << "v capacity: " << v.capacity() << std::endl;
    v.resize(5, 5);
    display_vector(v);
    v.resize(10, 5);
    display_vector(v);
    std::cout << "--- 4. Capacity ---" << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;
    // push_back, then look at capacity TO DO
    std::cout << "--- 5. Empty ---" << std::endl;
    std::cout << "Before clearing: " << v.empty() << std::endl; 
    v.clear();
    std::cout << "After clearing: " << v.empty() << std::endl; 
    std::cout << "--- 6. Reserve ---" << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;
    v.resize(5);
    std::cout << "v capacity (should not change): " << v.capacity() << std::endl;
    v.resize(20);
    std::cout << "v capacity: " << v.capacity() << std::endl;
    try {
        v.resize(v.max_size() + 1);
    }
    catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "ELEMENT ACCESS" << std::endl;
    std::cout << "==============" << std::endl << std::endl;

    
    /*std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "MODIFIERS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;
    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "ALLOCATOR" << std::endl;
    std::cout << "=========" << std::endl << std::endl;



    std::cout << "--- at ---" << std::endl;
    for (size_t i = 0; i < v.size() + 1; i++)
    {
        try {
            std::cout << v.at(i) << std::endl;
        }
        catch (const std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "--- [] operator ---" << std::endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        try {
            std::cout << v[i] << std::endl;
        }
        catch (const std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "--- display vector ---" << std::endl;
    display_vector(v);

    std::cout << "--- copy constructor ---" << std::endl;
    vector<int> v2(v);
    display_vector(v2);

    std::cout << "--- operator= ---" << std::endl;
    vector<int>    v3(30, 15);
    vector<int>    v4(3 ,10);

    std::cout << v4.capacity() << std::endl;
    v3 = v4;
    std::cout << "v capacity " << v3.capacity() << std::endl;
    display_vector(v3);
    std::cout << "---" << std::endl;
    vector<int>    v5(3 ,10);
    vector<int>    v6(30, 15);

    std::cout << v6.capacity() << std::endl;
    v5 = v6;
    std::cout << "v capacity " << v5.capacity() << std::endl;
    display_vector(v5); */

    return (0);
}