#include <iostream>
#include <functional>
#include <cstdlib>  // exit
#include "map/RBT.hpp"
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
        if (succ != tree.get_nullnode())
            std::cout << "successor of " << find->value.first << " is " << succ->value.first << std::endl;
        else
            std::cout << "could not find successor" << std::endl;

        RBT_char_int::node *pred = tree.predecessor(find);
        if (pred != tree.get_nullnode())
            std::cout << "predecessor of " << find->value.first << " is " << pred->value.first << std::endl;
        else
            std::cout << "could not find predecessor" << std::endl;
    }
    else
        std::cout << "could not find key" << std::endl;

    tree.delete_node('b');
    tree.insert(ft::make_pair('x', 35));
    tree.insert(ft::make_pair('f', 35));
    tree.insert(ft::make_pair('y', 35));
    tree.insert(ft::make_pair('t', 35));
    tree.insert(ft::make_pair('d', 35));
    tree.insert(ft::make_pair('v', 35));
    tree.prettyPrint();
    tree.delete_node('m');
    tree.prettyPrint();
    exit(0);
    tree.delete_node('g');
    tree.delete_node('t');
    tree.delete_node('y');
    tree.delete_node('a');
    tree.prettyPrint();
    exit(0);
    
    return (0);
}