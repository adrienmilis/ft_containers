#include <iostream>
#include <functional>
#include "RBT.hpp"
#include "utils.hpp"


int main()
{
    typedef ft::RBT<char, int, std::less<char> > RBT_char_int;

    RBT_char_int    tree;

    tree.insert(ft::make_pair('g', 10));
    tree.insert(ft::make_pair('g', 20));
    tree.insert(ft::make_pair('z', 15));
    tree.insert(ft::make_pair('m', 35));
    tree.insert(ft::make_pair('b', 35));
    tree.insert(ft::make_pair('c', 4));
    tree.prettyPrint();

    RBT_char_int::node *find = tree.search('b');
    if (find)
    {
        RBT_char_int::node *succ = tree.successor(find);
        if (succ)
            std::cout << "successor of " << find->value.first << " is " << succ->value.first << std::endl;
        else
            std::cout << "could not find successor" << std::endl;

        RBT_char_int::node *pred = tree.predecessor(find);
        if (pred)
            std::cout << "predecessor of " << find->value.first << " is " << pred->value.first << std::endl;
        else
            std::cout << "could not find predecessor" << std::endl;
    }
    else
        std::cout << "could not find key" << std::endl;

    tree.delete_node('b');
    tree.prettyPrint();
    
    return (0);
}