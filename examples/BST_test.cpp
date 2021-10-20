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
    tree.insert('y', 30);
    tree.insert('m', 30);
    
    // ft::BST<char, int, std::less<char> >    new_tree;
    // new_tree = tree;
    tree.print_tree_sorted();
    // std::cout << std::endl;
    // new_tree.print_tree_sorted();
    std::cout << tree._root->pair.first << std::endl;
    std::cout << tree._root->left->pair.first << std::endl; 
    std::cout << tree._root->right->pair.first << std::endl;
    std::cout << tree._root->right->right->pair.first << std::endl;

    return (0);
}