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
    tree.insert(ft::make_pair('x', 35));
    tree.insert(ft::make_pair('f', 35));
    tree.insert(ft::make_pair('y', 35));
    tree.insert(ft::make_pair('t', 35));
    tree.insert(ft::make_pair('d', 35));
    tree.insert(ft::make_pair('v', 35));
    tree.insert(ft::make_pair('w', 10));
    tree.insert(ft::make_pair('s', 20));
    tree.insert(ft::make_pair('u', 15));
    tree.insert(ft::make_pair('i', 35));
    tree.insert(ft::make_pair('o', 35));
    tree.insert(ft::make_pair('p', 4));
    tree.insert(ft::make_pair('n', 35));
    tree.insert(ft::make_pair('g', 35));
    tree.insert(ft::make_pair('m', 35));
    tree.insert(ft::make_pair('e', 35));
    tree.insert(ft::make_pair('r', 35));
    tree.insert(ft::make_pair('y', 35));
    tree.prettyPrint();

}