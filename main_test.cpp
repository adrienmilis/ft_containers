#include "vector.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>

template<typename T>
void    display_vector(const ft::vector<T> & v)
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
    ft::vector<int> v;
    display_vector(v);

    std::cout << std::endl;
    std::cout << "--- 2. Fill constructor ---" << std::endl;
    ft::vector<int> v2(5, 10);
    display_vector(v2);

    std::cout << std::endl;
    std::cout << "--- 3. Range constructor ---" << std::endl;
    int myints[] = {32, 47, 88};
    ft::vector<int> v3(myints, myints+3);
    display_vector(v3);

    ft::vector<int> ft_v0(10, 100);
    ft::vector<int>::iterator   it = ft_v0.begin();
    ft::vector<int>::iterator   ite = ft_v0.end();
    ft::vector<int>  v3_2(it, ite - 1);
    display_vector(v3_2);

    std::cout << std::endl;
    std::cout << "--- 4. Copy constructor ---" << std::endl;
    ft::vector<int> v4(v2);
    display_vector(v4);

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "OPERATOR=" << std::endl;
    std::cout << "=========" << std::endl << std::endl;
    v = v4;
    display_vector(v);

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
    v.push_back(25);
    std::cout << "v capacity after push_back: " << v.capacity() << std::endl;
    
    std::cout << std::endl;
    std::cout << "--- 5. Empty ---" << std::endl;
    std::cout << "Before clearing: " << v4.empty() << std::endl; 
    v4.clear();
    std::cout << "After clearing: " << v4.empty() << std::endl; 
    std::cout << std::endl;
    std::cout << "--- 6. Reserve ---" << std::endl;
    display_vector(v);
    std::cout << "v capacity: " << v.capacity() << std::endl;
    v.resize(5);
    display_vector(v);
    std::cout << "v capacity (should not change): " << v.capacity() << std::endl;
    v.resize(20, 20);
    display_vector(v);
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
    const   ft::vector<int> const_v(5, 100);

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
    int myints2[] = {1, 2, 3};
    v2.assign(myints2, myints2 + 3);
    std::cout << "After assign:" << std::endl;
    display_vector(v2);
    ft::vector<int> std_v(10, 100);
    ft::vector<int>::iterator   it2 = std_v.begin();
    ft::vector<int>::iterator   ite2 = std_v.end();
    std::cout << "After assign with iterators: " << std::endl;
    v2.assign(it2, ite2 - 1);
    display_vector(v2);

    // TO DO: ASSIGN WITH OWN ITERATORS

    std::cout << std::endl;
    std::cout << "--- 2. Push_back ---" << std::endl;
    display_vector(v2);
    std::cout << "capacity: " << v2.capacity() << ", size: " << v2.size() << std::endl;
    std::cout << "push_back 5" << std::endl;
    v2.push_back(5);
    display_vector(v2);
    std::cout << "capacity: " << v2.capacity() << ", size: " << v2.size() << std::endl;
    v2.push_back(5);
    std::cout << "push_back 5" << std::endl;
    display_vector(v2);
    std::cout << "capacity: " << v2.capacity() << ", size: " << v2.size() << std::endl;

    std::cout << std::endl;
    std::cout << "--- 3. Pop_back ---" << std::endl;
    v2.pop_back();
    std::cout << "pop_back" << std::endl;
    display_vector(v2);
    v2.pop_back();
    std::cout << "pop_back" << std::endl;
    display_vector(v2);

    std::cout << std::endl;
    std::cout << "--- 4. Insert ---" << std::endl;
    std::cout << "* Single element: enough capacity *" << std::endl;
    std::cout << "v2.capacity(): " << v2.capacity() << std::endl;
    ft::vector<int>::iterator  insert_it = v2.begin() + 2;
    *insert_it = 19;
    display_vector(v2);
    v2.insert(insert_it, 25);
    display_vector(v2);
    std::cout << std::endl;
    std::cout << "* Single element: not enough capacity *" << std::endl;
    display_vector(v3);
    std::cout << "capacity: " << v3.capacity() << std::endl;
    ft::vector<int>::iterator  insert_it_v3 = v3.begin();
    v3.insert(insert_it_v3, 19);
    display_vector(v3);
    std::cout << "capacity: " << v3.capacity() << std::endl;

    std::cout << std::endl;
    std::cout << "* Fill: enough capacity *" << std::endl;
    display_vector(v2);
    std::cout << "capacity: " << v2.capacity() << std::endl;
    v2.insert(v2.begin() + 2, 3, 19);
    display_vector(v2);

    std::cout << std::endl;
    std::cout << "* Fill: not enough capacity *" << std::endl;
    display_vector(v3);
    std::cout << "capacity: " << v3.capacity() << std::endl;
    v3.insert(v3.begin() + 2, 3, 19);
    display_vector(v3);

    std::cout << std::endl;
    std::cout << "* Range: enough capacity *" << std::endl;
    display_vector(v3);
    std::cout << "capacity: " << v3.capacity() << std::endl;
    int myints3[] = {3, 3, 3, 3};
    v3.insert(v3.begin() + 1, myints3, myints3 + 3);
    display_vector(v3);

    std::cout << std::endl;
    std::cout << "* Range: not enough capacity *" << std::endl;
    display_vector(v);
    std::cout << "capacity: " << v.capacity() << std::endl;
    v.insert(v.begin() + 1, myints3, myints3 + 3);
    display_vector(v);
    
    // std::cout << std::endl;
    // std::cout << "--- 5. Erase ---" << std::endl;
    // std::cout << std::endl;
    // std::cout << "--- 6. Swap ---" << std::endl;
    // std::cout << std::endl;

    /*std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "ITERATORS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;

    int int_tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ft::vector<int> iterated_vector(int_tab, int_tab + 10);
    display_vector(iterated_vector);
    ft::vector<int>::iterator   ft_it = iterated_vector.begin();
    ft::vector<int>::iterator   ft_ite = iterated_vector.end();

    std::cout << "begin: " << *ft_it << std::endl;
    std::cout << "end: " << *(ft_ite - 1) << std::endl;

    std::cout << "--- Default constructor ---" << std::endl;
    // uninitialized, only good option is to = it to a valid iterator.
    ft::vector<int>::iterator   default_it;
    std::cout << "--- Copy constructor ---" << std::endl;
    ft::vector<int>::iterator   copy_it(ft_it);
    std::cout << "copy: same as begin: " << *copy_it << std::endl;
    std::cout << "--- Copy assignation ---" << std::endl;
    default_it = copy_it;
    std::cout << "assignation: now same as begin and copy: " << *default_it << std::endl;
    std::cout << "--- == and != operators ---" << std::endl;
    std::cout << "copy_it == default_it ? " << (copy_it == default_it) << std::endl;
    std::cout << "copy_it != default_it ? " << (copy_it != default_it) << std::endl;
    std::cout << "--- can be dereferenced with * ---" << std::endl;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    std::cout << "--- can be dereferenced and assigned with * ---" << std::endl;
    *(copy_it) = 3;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    *(copy_it) = 0;
    std::cout << "--- can be pre-incremented ---" << std::endl;
    std::cout << "*(copy_it): " << *(++copy_it) << std::endl;
    std::cout << "--- can be post incremented ---" << std::endl;
    std::cout << "*(copy_it): " << *(copy_it++) << std::endl;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    std::cout << "--- can be pre decremented ---" << std::endl;
    std::cout << "*(copy_it): " << *(--copy_it) << std::endl;
    std::cout << "--- can be pre decremented ---" << std::endl;
    std::cout << "*(copy_it): " << *(copy_it--) << std::endl;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    std::cout << "--- adding iterator and integer value ---" << std::endl;
    std::cout << *(copy_it + 2) << std::endl;
    std::cout << "--- substracting iterator and integer value ---" << std::endl;
    std::cout << *(copy_it + 5 - 2) << std::endl;
    std::cout << "--- substracting two iterators (gives distance) ---" << std::endl;
    ++ft_it;    // ft_it is now on index 1
    ++copy_it;
    ++copy_it; // copy_it is now on index 2
    std::cout << copy_it - ft_it << std::endl;
    std::cout << "--- relational operators <, >, <=, >= ---" << std::endl;
    std::cout << "copy_it > ft_it ? " << (copy_it > ft_it) << std::endl;
    std::cout << "copy_it < ft_it ? " << (copy_it < ft_it) << std::endl;
    std::cout << "copy_it >= ft_it ? " << (copy_it >= ft_it) << std::endl;
    std::cout << "copy_it < ft_it ? " << (copy_it <= ft_it) << std::endl;
    std::cout << "--- += and -= ---" << std::endl;
    copy_it += 3;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    copy_it -= 3;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    std::cout << "--- [] operator ---" << std::endl;
    std::cout << "copy_it[3]: " << copy_it[3] << std::endl;

    std::cout << std::endl;
    std::cout << "=================" << std::endl;
    std::cout << "REVERSE_ITERATORS" << std::endl;
    std::cout << "=================" << std::endl << std::endl;

    display_vector(iterated_vector);
    ft::vector<int>::reverse_iterator   rev_it = iterated_vector.rbegin();
    ft::vector<int>::reverse_iterator   rev_ite = iterated_vector.rend();

    std::cout << "--- operator* ---" << std::endl;
    std::cout << "*(rev_it): " << *rev_it << std::endl;
    std::cout << "*(rev_ite): " << *rev_ite << std::endl;

    std::cout << "--- operator+ ---" << std::endl;
    std::cout << "*(rev_it + 2): " << *(rev_it + 2) << std::endl;

    std::cout << "--- operator++ ---" << std::endl;
    std::cout << "(*(++rev_it)): " << (*(++rev_it)) << std::endl;
    std::cout << "(*(rev_it++)): " << (*(rev_it++)) << std::endl;
    std::cout << "(*rev_it): " << (*rev_it) << std::endl;

    std::cout << "--- operator+= ---" << std::endl;
    rev_it += 3;
    std::cout << "rev_it += 3 --> *(rev_it): " << *(rev_it) << std::endl;

    std::cout << "--- operator- ---" << std::endl;
    std::cout << "*(rev_it - 3): " << *(rev_it - 3) << std::endl;

    std::cout << "--- operator-- ---" << std::endl;
    std::cout << "(*(--rev_it)): " << (*(--rev_it)) << std::endl;
    std::cout << "(*(rev_it--)): " << (*(rev_it--)) << std::endl;
    std::cout << "(*rev_it): " << (*rev_it) << std::endl;

    std::cout << "--- operator-= ---" << std::endl;
    rev_it -= 3;
    std::cout << "rev_it -= 3 --> *(rev_it): " << *(rev_it) << std::endl;

    std::cout << "--- operator[] ---" << std::endl;
    std::cout << "rev_it[3]: " << rev_it[3] << std::endl;

    std::cout << "*rev_ite: " << *rev_ite << std::endl;
    std::cout << "rev_ite[-3]: " << rev_ite[-3] << std::endl;*/

    return (0);
}