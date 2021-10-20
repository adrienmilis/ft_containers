#ifndef BST_HPP
# define BST_HPP

#include <memory>
#include <functional>   // std::less
#include <iostream>     // std::cout
#include "../utils.hpp"

namespace ft
{
    // Compare(a, b): a goes before b (to its left)
    template <class key_type, class mapped_type, class key_compare>
    class BST
    {
        public:

            typedef ft::pair<key_type, mapped_type> node_pair;

            class node
            {
                public:

                    node_pair   pair;
                    node        *parent;
                    node        *left;
                    node        *right;
                    int         is_left;
                    int         is_right;
                    // key_type    key;
                    // mapped_type value;

                    node & operator++() {
                        
                        return *this;
                    }
            };

        public:

            node                    *_root;
            std::allocator<node>    _allocator;
            size_t                  _size;
            key_compare             comp;


            node    *r_insert(key_type new_key, mapped_type new_value, node *node)
            {
                if (node == NULL)
                {
                    node = _allocator.allocate(1);
                    node->pair.first = new_key;
                    node->pair.second = new_value;
                    node->left = NULL;
                    node->right = NULL;
                    node->parent = NULL;
                    this->_size++;
                }
                else if (!comp(new_key, node->pair.first)
                            && !comp(node->pair.first, new_key))  // compare equal
                    node->pair.second = new_value;
                else if (comp(new_key, node->pair.first))   // element goes to the left
                {
                    node->left = r_insert(new_key, new_value, node->left);
                    node->left->parent = node;
                }
                else if (!comp(new_key, node->pair.first))  // element goes to the right
                {
                    node->right = r_insert(new_key, new_value, node->right);
                    node->right->parent = node;
                }
                return node;
            }

            void    print_tree_sorted(node *node)
            {
                if (node == NULL)
                    return ;
                print_tree_sorted(node->left);
                std::cout << "key: " << node->pair.first << ", value: " << node->pair.second << std::endl;
                print_tree_sorted(node->right);
            }

            void    deep_copy(node* node_to_copy)
            {
                if (node_to_copy == NULL)
                    return ;
                deep_copy(node_to_copy->left);
                deep_copy(node_to_copy->right);
                if (node_to_copy)
                    insert(node_to_copy->pair.first, node_to_copy->pair.second);
            }


        public: 

            BST() : _root(NULL), _allocator(), comp() {}

            ~BST() {
                _root = clear(_root);
            }

            // destroy & deallocate tree
            node    *clear(node *t)
            {
                if (t == NULL)
                    return NULL;
                clear(t->left);
                clear(t->right);
                this->_allocator.destroy(t);
                this->_allocator.deallocate(t, 1);
                return (NULL);
            }
            // overload operator= !!
            BST & operator=(BST const & rhs)
            {
                deep_copy(rhs._root);
                return (*this);
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

            // print tree in order
            void    print_tree_sorted()
            {
                print_tree_sorted(_root);
            }
    };
    // std::ostream & operator<<(std::ostream & o, const BST & rhs)
    // {
    //     rhs.print_tree_sorted();
    // }

}

#endif