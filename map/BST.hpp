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
        typedef ft::pair<const key_type, mapped_type>   value_type;

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
                    // key_type    key;
                    // mapped_type value;

                    node & operator++()
                    {
                        node    *incr;

                        incr = this;
                        if (incr->right)
                        {
                            incr = incr->right;
                            while (incr->left)
                                incr = incr->left;
                        }   
                        else
                        {
                            while (!incr->is_left)
                                incr = incr->parent;
                            incr = incr->parent;
                        }
                        return *incr;
                    }
            };

        public:

            node                    *_root;
            std::allocator<node>    _allocator;
            size_t                  _size;
            key_compare             comp;


            node    *r_insert(key_type new_key, mapped_type new_value, node *node, ft::pair<BST::node* ,bool> *pair_address_bool)
            {
                if (node == NULL)
                {
                    node = _allocator.allocate(1);
                    node->pair.first = new_key;
                    node->pair.second = new_value;
                    node->left = NULL;
                    node->right = NULL;
                    node->parent = NULL;
                    node->is_left = 0;
                    pair_address_bool->first = node;
                    pair_address_bool->second = true;
                    this->_size++;
                }
                else if (!comp(new_key, node->pair.first)
                            && !comp(node->pair.first, new_key))  // compare equal
                {
                    node->pair.second = new_value;
                    pair_address_bool->first = node;
                    pair_address_bool->second = false;
                }
                else if (comp(new_key, node->pair.first))   // element goes to the left
                {
                    node->left = r_insert(new_key, new_value, node->left, pair_address_bool);
                    node->left->is_left = 1;
                    node->left->parent = node;
                }
                else if (!comp(new_key, node->pair.first))  // element goes to the right
                {
                    node->right = r_insert(new_key, new_value, node->right, pair_address_bool);
                    node->right->is_left = 0;
                    node->right->parent = node;
                }
                return node;
            }

            void    print_tree_sorted(node *node)
            {
                if (node == NULL)
                    return ;
                print_tree_sorted(node->left);
                std::string str = (node->is_left == 1) ? "Left node" : "Right node";
                std::cout << str << " - " << "key: " << node->pair.first << ", value: " << node->pair.second << std::endl;
                print_tree_sorted(node->right);
            }

            void    deep_copy(node* node_to_copy)
            {
                if (node_to_copy == NULL)
                    return ;
                // whatever the order, insert adds automatically in the right order
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
            void    insert(key_type key, mapped_type value,
                            ft::pair<node*, bool> *pair_address_bool)
            {
                _root = r_insert(key, value, _root, pair_address_bool);
            }

            // erase an element (or a range of elements ???)

            // find an element

            // clear the tree

            // find minimum element (for iterator begin)
            node    *minimum()
            {
                node    *current;

                current = this->_root;
                while (current->left)
                    current = current->left;
                return (current);
            }

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