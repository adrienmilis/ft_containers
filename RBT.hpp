#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include "utils.hpp"

#define RED     1
#define BLACK   0

/* All operations except insertion and deletion are the same as in an ordinary binary saerch tree */

namespace ft
{
    template <class key_type, class mapped_type, class key_compare>
    class RBT
    {
        public:

            typedef pair<key_type, mapped_type>   value_type;

            struct node
            {
                    value_type  value;
                    node        *parent;
                    node        *left;
                    node        *right;
                    int         color;
            };

        private:
            
            node                    *_root;
            std::allocator<node>    _allocator;
            size_t                  size;
            key_compare             comp;

            // recursive print
            void printHelper(node *root, std::string indent, bool right)
            {
		        // print the tree structure on the screen
	   	        if (root != NULL) {
		           std::cout << indent;
		           if (right) {
		              std::cout << "R----";
		              indent += "     ";
		           } else {
		              std::cout << "L----";
		              indent += "|    ";
		           }

                   std::string sColor = root->color ? "RED" : "BLACK";
		           std::cout << root->value.first << ":" << root->value.second << "(" << sColor << ")" << std::endl;
		           printHelper(root->left, indent, false);
		           printHelper(root->right, indent, true);
		        }
		    }   

            // recursive search
            node    *recursive_search(node *current_node, key_type key_to_find)
            {
                if (current_node == NULL || current_node->value.first == key_to_find)
                    return (current_node);
                if (comp(key_to_find, current_node->value.first))
                    return recursive_search(current_node->left, key_to_find);
                else
                    return recursive_search(current_node->right, key_to_find);
            }

            // min and max from a certain node
            // (can be other than root)
            node    *min(node *current)
            {
                while (current->left != NULL)
                    current = current->left;
                return (current);
            }

            node    *max(node *current)
            {
                while (current->right != NULL)
                    current = current->right;
                return (current);
            }

            node    *recursive_delete(node *current_node, key_type key_to_delete)
            {
                node    *tmp;

                if (current_node == NULL)
                    return (current_node);
                else if (comp(key_to_delete, current_node->value.first))
                    current_node->left = recursive_delete(current_node->left, key_to_delete);
                else if (comp(current_node->value.first, key_to_delete))
                    current_node->right = recursive_delete(current_node->right, key_to_delete);
                else
                {
                    if (current_node->left == NULL && current_node->right == NULL) {
                        this->_allocator.deallocate(current_node, 1);
                        current_node = NULL;
                    }
                    else if (current_node->left == NULL) {
                        tmp = current_node;
                        current_node = current_node->right;
                        current_node->parent = tmp->parent;
                        this->_allocator.deallocate(tmp, 1);
                    }
                    else if (current_node->right == NULL) {
                        tmp = current_node;
                        current_node = current_node->left;
                        current_node->parent = tmp->parent;
                        this->_allocator.deallocate(tmp, 1);
                    }
                    else {
                        tmp = min(current_node->right);
                        current_node->value = tmp->value;
                        current_node->right = recursive_delete(current_node->right, tmp->value.first);
                    }
                }
                return (current_node);
            }
            
            void    left_rotate(node *x)
            {
                node    *y = x->right;

                y->parent = x->parent;
                if (x->parent == NULL)
                    this->_root = y;
                else if (x->parent->left == x)
                    x->parent->left = y;
                else
                    x->parent->right = y;
                y->left = x;
                x->right = y->left;
                if (y->left)
                    x->left->parent = x;
                x->parent = y;
            }

            void    right_rotate(node *x)
            {
                node    *y = x->left;

                y->parent = x->parent;
                x->left = y->right;
                if (y->right)
                    y->right->parent = x;
                if (x->parent == NULL)
                    this->_root = y;
                else if (x->parent->left == x)
                    x->parent->left = y;
                else
                    x->parent->right = y;
                y->right = x;
                x->parent = y;
            }

            void    fix_insert(node *k)
            {
                node    *uncle;
                while (k->parent->color == RED)
                {
                    if (k->parent == k->parent->parent->right)   // P is right child
                    {
                        uncle = k->parent->parent->left;
                        if (uncle->color == RED)
                        {
                            k->parent->color = BLACK;
                            uncle->color = BLACK;
                            k->parent->parent->color = RED;
                            k = k->parent->parent;              // we prepare for the next loop (fixing changes going up the tree)
                        }
                        else
                        {
                            if (k == k->parent->left)       // K is left child
                            {
                                k = k->parent;
                                right_rotate(k);    // right rotation at P
                            }
                            k->parent->color = BLACK;
                            k->parent->parent->color = RED;
                            left_rotate(k->parent->parent);     // left rotation at G
                        }
                    }
                    else
                    {
                        uncle = k->parent->parent->left;
                        if (uncle->color == RED)
                        {
                            k->parent->color = BLACK;
                            uncle->color = BLACK;
                            k->parent->parent->color = RED;
                            k = k->parent->parent;
                        }
                        else
                        {
                            if (k == k->parent->right)
                            {
                                k = k->parent;
                                left_rotate(k);
                            }
                            k->parent->color = BLACK;
                            k->parent->parent->color = RED;
                            right_rotate(k->parent->parent);
                        }
                    }
                    if (k == _root)
                        break;
                }
            }

        public:

            RBT() : _root(NULL), _allocator(), comp() {}

            // ~RBT() {
            //     _root = clear(_root);
            // }

            void    insert(value_type new_pair)
            {
                node    *node_down = this->_root;
                node    *parent_node = NULL;
                node    *new_node;

                while (node_down != NULL)
                {
                    parent_node = node_down;
                    if (!comp(new_pair.first, node_down->value.first) &&            // new key == current key
                            !comp(node_down->value.first, new_pair.first))
                    {
                        node_down->value.second = new_pair.second;
                        return ;
                    }
                    else if (comp(new_pair.first, node_down->value.first))          // new key < current key
                        node_down = node_down->left;
                    else                                                            // new key > current key
                        node_down = node_down->right;
                }
                new_node = _allocator.allocate(1);
                new_node->value = new_pair;
                new_node->parent = parent_node;
                new_node->left = NULL;
                new_node->right = NULL;
                new_node->color = (new_node->parent) ? RED : BLACK;
                if (parent_node == NULL)
                    this->_root = new_node;
                else if (comp(new_node->value.first, parent_node->value.first))
                    parent_node->left = new_node;
                else
                    parent_node->right = new_node;

                if (!new_node->parent || !new_node->parent->parent)
                    return ;

                fix_insert(new_node);   
            }

            node    *search(key_type key_to_find)
            {
                return (recursive_search(this->_root, key_to_find));
            }

            void prettyPrint()
            {
	            if (this->_root)
    	    	    printHelper(this->_root, "", true);
	        }

            node    *successor(node *curr)
            {
                node    *parent;

                if (curr->right)
                    return (min(curr->right));
                parent = curr->parent;
                // here, we stop when curr is a left child of parent
                // either curr is already a left child and we return parent,
                // or we stop when we find a left child by going up the tree
                while (parent != NULL && curr == parent->right)
                {
                    curr = parent;
                    parent = parent->parent;
                }
                return parent;
            }

            node    *predecessor(node *curr)
            {
                node    *parent;

                if (curr->left)
                    return (max(curr->left));
                parent = curr->parent;
                while (parent != NULL && curr == parent->left)
                {
                    curr = parent;
                    parent = parent->parent;
                }
                return parent;
            }

            void    delete_node(key_type key_to_delete)
            {
                _root = recursive_delete(_root, key_to_delete);
            }
    };
}

#endif