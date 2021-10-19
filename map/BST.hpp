#ifndef BST_HPP
# define BST_HPP

#include <memory>
#include <functional>   // std::less
#include <iostream>     // std::cout 

/*
    - note : proteger contre 2 clefs qui sont les memes ?? ex dans insert : si c'est = on a un probleme je pense
*/

namespace ft
{
    // Compare(a, b): a goes before b (to its left)
    template <class key_type, class mapped_type, class key_compare>
    class BST
    {
        class node
        { 
            public:

                key_type    key;
                mapped_type value;
                node        *left;
                node        *right;
        };

        private:

            node            *_root;
            std::allocator  _allocator;
            size_t          _size;

            node    *r_insert(key_type new_key, mapped_type new_value, node *node)
            {
                if (node == NULL)
                {
                    node = _allocator.allocate(1);
                    node->key = new_key;
                    node->value = new_value;
                    node->left = NULL;
                    node->right = NULL;
                    this->_size++;
                }
                else if (!key_compare(new_key, node->key)
                            && !key_compare(node->key, new_key))  // compare equal
                    node->value = new_value;
                else if (key_compare(new_key, node->key))   // element goes to the left
                    node->left = insert(new_key, new_value, node->left);
                else if (!key_compare(new_key, node->key))  // element goes to the right
                    node->right = insert(new_key, new_value, node->right);
                return node;
            }

            void    print_tree_sorted(node *node)
            {
                if (node == NULL)
                    return ;
                print_tree_sorted(node->left);
                std::cout << "key: " << node->key << ", value: " << node->value;
                print_tree_sorted(node->right);
            }

        public: 

            BST() : _root(NULL) {}

            ~BST() {
                make_empty(_root);
            }

            // insert a new element in the tree
            void    insert(key_type key, mapped_type value)
            {
                _root = r_insert(key, value, _root);
            }

            // erase an element (or a range of elements ???)

            // find an element

            // clear the tree

            // find minimum element (for iterator begin)

            // find last element (for iterator end)

            // iterate over BST from lowest element to biggest element

            // return BST size
            size_t  size() const
            {
                return this->_size;
            }

            // overload operator= !!

            // print tree in order
            void    print_tree_sorted()
            {
                print_tree_sorted(root);
            }
    };

}

#endif