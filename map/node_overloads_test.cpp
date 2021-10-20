#include "map.hpp"

int main()
{
    typedef ft::BST<char, int, std::less<char> >::node  node;
    
    node    *node1, *node2;

    node1 = new node();
    node2 = new node();
    node1->key = 'a';
    node2->key = 'c';
    std::cout << (*node1 == *node2) << std::endl;

    delete node1;
    delete node2;
}