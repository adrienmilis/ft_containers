#include "../map/BST.hpp"
#include <iostream>
#include <functional>

int main()
{
    ft::BST<char, int, std::less<char> >    tree;

    tree.insert('b', 2);
    tree.insert('a', 1);
    tree.insert('a', 17);
    tree.insert('c', 1);
    
    ft::BST<char, int, std::less<char> >    new_tree;
    new_tree = tree;
    tree.print_tree_sorted();
    std::cout << std::endl;
    new_tree.print_tree_sorted();

    return (0);
}