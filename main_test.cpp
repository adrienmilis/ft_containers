#include "vector.hpp"
#include <iostream>

template<typename T>
void    display_vector(const vector<T> & v)
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
    std::cout << std::endl;
    std::cout << "--- 2. Fill constructor ---" << std::endl;
    vector<int> v2(5, 10);
    display_vector(v2);
    std::cout << std::endl;
    std::cout << "--- 3. Range constructor ---" << std::endl; // TO DO
    std::cout << std::endl;
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
    std::cout << std::endl;
    std::cout << "--- 2. Max_size ---" << std::endl;
    std::cout << "v max_size: " << v.max_size() << std::endl;
    std::cout << std::endl;
    std::cout << "--- 3. Resize ---" << std::endl;
    v.resize(2, 5);
    display_vector(v);
    std::cout << "v capacity: " << v.capacity() << std::endl;
    v.resize(5, 5);
    display_vector(v);
    v.resize(10, 5);
    display_vector(v);
    std::cout << std::endl;
    std::cout << "--- 4. Capacity ---" << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;
    // push_back, then look at capacity TO DO
    std::cout << std::endl;
    std::cout << "--- 5. Empty ---" << std::endl;
    std::cout << "Before clearing: " << v4.empty() << std::endl; 
    v4.clear();
    std::cout << "After clearing: " << v4.empty() << std::endl; 
    std::cout << std::endl;
    std::cout << "--- 6. Reserve ---" << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;
    v.resize(5);
    std::cout << "v capacity (should not change): " << v.capacity() << std::endl;
    v.resize(20, 20);
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

    std::cout << "--- 1. Operator[] ---" << std::endl;
    std::cout << "Full vector: ";
    display_vector(v);
    std::cout << "v[1]: " << v[1] << std::endl;
    std::cout << "v[2]: " << v[2] << std::endl;
    std::cout << "v[6]: " << v[6] << std::endl;
    v[1] = 50;
    std::cout << "v[1] changed: " << v[1] << std::endl;
    std::cout << std::endl;

    std::cout << "--- 2. at ---" << std::endl;
    const   vector<int> const_v(5, 100);

    std::cout << "Const vector: ";
    display_vector(const_v);
    try {
        std::cout << "v.at(-1) - " << v.at(-1) << std::endl;
    }
    catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "v.at(v.size())] - " << v.at(v.size()) << std::endl;
    }
    catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "v.at(5): " << v.at(5) << std::endl;
    std::cout << "const_v.at(0): " << const_v.at(0) << std::endl;
    std::cout << std::endl;

    std::cout << "--- 3. front ---" << std::endl;
    std::cout << "v.front(): " << v.front() << std::endl;
    std::cout << "const_v.front(): " << const_v.front() << std::endl;
    std::cout << std::endl;

    std::cout << "--- 4. back ---" << std::endl;
    v[v.size() - 1] = 99;
    display_vector(v);
    std::cout << "v.back(): " << v.back() << std::endl;
    std::cout << "const_v.back(): " << const_v.back() << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "MODIFIERS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;
    
    std::cout << "--- 1. Assign ---" << std::endl;
    std::cout << "Before assign:" << std::endl;
    display_vector(v2);
    int myints[] = {1, 2, 3};
    v2.assign(myints, myints + 3);
    std::cout << "After assign:" << std::endl;
    display_vector(v2);
    // TO DO: ASSIGN WITH OWN ITERATORS

    std::cout << std::endl;
    std::cout << "--- 2. Push_back ---" << std::endl;
    std::cout << std::endl;
    std::cout << "--- 3. Pop_back ---" << std::endl;
    std::cout << std::endl;
    std::cout << "--- 4. Insert ---" << std::endl;
    std::cout << std::endl;
    std::cout << "--- 5. Erase ---" << std::endl;
    std::cout << std::endl;
    std::cout << "--- 6. Swap ---" << std::endl;
    std::cout << std::endl;
    std::cout << "--- 7. Clear ---" << std::endl;
    
    /*std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "ALLOCATOR" << std::endl;
    std::cout << "=========" << std::endl << std::endl;*/

    return (0);
}