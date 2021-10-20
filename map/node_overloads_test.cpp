#include <iostream>
#include "map.hpp"

int main()
{
    typedef ft::BST<char, int, std::less<char> >::node  node;
    
    // node    *node1, *node2;

    // node1 = new node();
    // node2 = new node();
    // node1->key = 'a';
    // node2->key = 'c';
    // std::cout << (*node1 == *node2) << std::endl;

    // delete node1;
    // delete node2;
    node    node1;
    node    node2;

    node1.pair.first = 'a';
    node1.pair.second = 1;

    node2.pair.first = 'b';
    node2.pair.second = 2;

    node & node1_ref = node1;
    node & node2_ref = node2;

    ++node1_ref;
}