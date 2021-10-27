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
    // tree.insert(ft::make_pair('w', 10));
    // tree.insert(ft::make_pair('s', 20));
    // tree.insert(ft::make_pair('u', 15));
    // tree.insert(ft::make_pair('i', 35));
    // tree.insert(ft::make_pair('o', 35));
    // tree.insert(ft::make_pair('p', 4));
    // tree.insert(ft::make_pair('n', 35));
    // tree.insert(ft::make_pair('g', 35));
    // tree.insert(ft::make_pair('m', 35));
    // tree.insert(ft::make_pair('e', 35));
    // tree.insert(ft::make_pair('r', 35));
    // tree.insert(ft::make_pair('y', 35));
    tree.prettyPrint();

    RBT_char_int    new_tree = tree;

    tree.delete_node('g');  // debugger mtn le delete node !!
    tree.delete_node('g');
    tree.delete_node('z');
    tree.delete_node('m');
    tree.delete_node('b');
    tree.delete_node('c');
    tree.delete_node('x');
    tree.delete_node('f');
    tree.delete_node('y');
    tree.delete_node('t');
    tree.delete_node('d');
    tree.delete_node('v');
    tree.delete_node('w');
    tree.delete_node('s');
    tree.delete_node('u');
    tree.delete_node('i');
    tree.delete_node('o');
    tree.delete_node('p');
    tree.delete_node('n');
    tree.delete_node('g');
    tree.delete_node('m');
    tree.delete_node('e');
    tree.delete_node('r');
    tree.delete_node('y');
    // std::cout << tree.get_root() << std::endl;
    // std::cout << new_tree.get_root() << std::endl;
    new_tree.prettyPrint();

}