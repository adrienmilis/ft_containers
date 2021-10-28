#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include "../utils/utils.hpp"

#define RED     1
#define BLACK   0

/* All operations except insertion and deletion are the same as in an ordinary binary saerch tree */

namespace ft
{
    template <class key_type, class mapped_type, class key_compare>
    class RBT
    {
        public:

            typedef ft::pair<const key_type, mapped_type>   value_type;
            typedef std::allocator<value_type>              allocator_type;

            struct node
            {
                value_type  value;
                node        *parent;
                node        *left;
                node        *right;
                int         color;

                node(value_type value) :
                    value(value), parent(NULL),
                    left(NULL), right(NULL),
                    color(BLACK) {}
            };


        private:
            
            node                    *_root;
            node                    *NULLNODE;
            std::allocator<node>    _allocator;
            size_t                  _size;
            key_compare             comp;

            // recursive print
            void printHelper(node *root, std::string indent, bool right) const
            {
		        // print the tree structure on the screen
	   	        if (root != NULLNODE) {
		           std::cout << indent;
		           if (right) {
		              std::cout << "R----";
		              indent += "     ";
		           } else {
		              std::cout << "L----";
		              indent += "|    ";
		           }

                   std::string sColor = root->color ? "RED" : "BLACK";
		           std::cout << "[" << root->value.first << "]" << " (" << sColor << ")" << std::endl;
		           printHelper(root->left, indent, false);
		           printHelper(root->right, indent, true);
		        }
		    }   

            // recursive search
            node    *recursive_search(node *current_node, key_type key_to_find)
            {
                if (current_node == NULLNODE || current_node->value.first == key_to_find)
                    return (current_node);
                if (comp(key_to_find, current_node->value.first))
                    return recursive_search(current_node->left, key_to_find);
                else
                    return recursive_search(current_node->right, key_to_find);
            }

            // min and max from a certain node
            // (can be other than root)
            node    *min(node *current) const
            {
                while (current->left != NULLNODE)
                    current = current->left;

                return (current);
            }

            node    *max(node *current) const
            {
                while (current->right != NULLNODE)
                    current = current->right;
                return (current);
            }   

            void fix_delete(node* x)
            {
        		node    *s;
        		while (x != this->_root && x->color == BLACK)
                {
        			if (x == x->parent->left)
                    {
        				s = x->parent->right; 
        				if (s->color == RED)
                        {
        					// case 3.1
        					s->color = BLACK;
        					x->parent->color = RED;
        					left_rotate(x->parent);
        					s = x->parent->right;
        				}

        				if (s->left->color == BLACK && s->right->color == BLACK)
                        {
        					// case 3.2
        					s->color = RED;
        					x = x->parent;
        				}
                        else
                        {
        					if (s->right->color == BLACK && s->left->color == RED)
                            {
        						// case 3.3
        						s->left->color = BLACK;
        						s->color = RED;
        						right_rotate(s);
        						s = x->parent->right;
        					} 

        					// case 3.4
        					s->color = x->parent->color;
        					x->parent->color = BLACK;
        					s->right->color = BLACK;
        					left_rotate(x->parent);
        					x = this->_root;
        				}
        			}
                    else
                    {
        				s = x->parent->left;
        				if (s->color == RED)
                        {
        					// case 3.1
        					s->color = BLACK;
        					x->parent->color = RED;
        					right_rotate(x->parent);
        					s = x->parent->left;
        				}

        				if (s->right->color == BLACK && s->left->color == BLACK)
                        {
        					// case 3.2
        					s->color = RED;
        					x = x->parent;
        				}
                        else
                        {
        					if (s->left->color == BLACK && s->right->color == RED)
                            {
        						// case 3.3
        						s->right->color = BLACK;
        						s->color = RED;
        						left_rotate(s);
        						s = x->parent->left;
        					} 

        					// case 3.4
        					s->color = x->parent->color;
        					x->parent->color = BLACK;
        					s->left->color = BLACK;
        					right_rotate(x->parent);
        					x = this->_root;
        				}
        			} 
        		}
        		x->color = BLACK;
    	    }

            // replace x by y by changing pointers
            void    transplant(node *x, node *y)
            {
                if (x->parent == NULLNODE)
                    this->_root = y;
                else if (x == x->parent->left)
                    x->parent->left = y;
                else if (x == x->parent->right)
                    x->parent->right = y;
                y->parent = x->parent;
            }

            void delete_node(node *curr_node, int key)
            {
		        node    *z = NULLNODE;
		        node    *x;
                node    *y;

		        while (curr_node != NULLNODE)
                {
		        	if (curr_node->value.first == key) {
		        		z = curr_node;
		        	}
		        	if (curr_node->value.first <= key)
		        		curr_node = curr_node->right;
		        	else
		        		curr_node = curr_node->left;
		        }

		        if (z == NULLNODE)
		        	return;     // key not found so couldn't delete entry

		        y = z;
		        int y_original_color = y->color;
                // find the replacement x for y
		        if (z->left == NULLNODE) {
		        	x = z->right;               // x has replaced the node to delete (z). We'll have to fix from x afterwards
		        	transplant(z, z->right);    // if both children are null, the node is just deleted
                }
                else if (z->right == NULLNODE) {
		        	x = z->left;
		        	transplant(z, z->left);
		        }
                else
                {
                    // we replace the node to delete by y, the min of the right branch
                    // as in a BST deletion
		        	y = min(z->right);
		        	y_original_color = y->color;
		        	x = y->right;
		        	if (y->parent == z) // if y is a child of node to be deleted
		        		x->parent = y;
		        	else
                    {
		        		transplant(y, y->right);
		        		y->right = z->right;
		        		y->right->parent = y;
		        	}

		        	transplant(z, y);
		        	y->left = z->left;
		        	y->left->parent = y;
		        	y->color = z->color;
		        }
                // this->_allocator.deallocate(z, 1);
		        if (y_original_color == 0)
		        	fix_delete(x);
	        }

            void left_rotate(node * x)
            {
		        node    *y = x->right;

		        x->right = y->left;
		        if (y->left != NULLNODE)
		        	y->left->parent = x;
		        y->parent = x->parent;
		        if (x->parent == NULLNODE)
		        	this->_root = y;
		        else if (x == x->parent->left)
		        	x->parent->left = y;
		        else
		        	x->parent->right = y;
		        y->left = x;
		        x->parent = y;
	        }

	        // rotate right at node x
	        void right_rotate(node * x)
            {
	        	node    *y = x->left;

	        	x->left = y->right;
	        	if (y->right != NULLNODE)
	        		y->right->parent = x;
	        	y->parent = x->parent;
	        	if (x->parent == NULLNODE)
	        		this->_root = y;
	        	else if (x == x->parent->right)
	        		x->parent->right = y;
	        	else
	        		x->parent->left = y;
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
                        uncle = k->parent->parent->right;
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
                this->_root->color = BLACK;
            }

            void    deep_copy(node *node_to_copy, RBT const & rhs)
            {
                if (node_to_copy == rhs.NULLNODE)
                    return ;
                // whatever the order, insert adds automatically in the right order
                deep_copy(node_to_copy->left, rhs);
                deep_copy(node_to_copy->right, rhs);
                if (node_to_copy != rhs.NULLNODE)
                    insert(ft::make_pair(node_to_copy->value.first, node_to_copy->value.second));
            }

            void    print_tree_sorted(node  *curr_node) const
            {
                if (curr_node == NULLNODE)
                    return ;
                print_tree_sorted(curr_node->left);
                std::cout << "[" << curr_node->value.first << ":" << curr_node->value.second << "]" << " ";
                print_tree_sorted(curr_node->right);
            }

            RBT() {}

        public:


            RBT(allocator_type alloc) : _allocator(alloc), comp()
            {
                NULLNODE = this->_allocator.allocate(1);
                NULLNODE->parent = NULL;
                NULLNODE->left = NULL;
                NULLNODE->right = NULL;
                NULLNODE->color = BLACK;
                this->_root = NULLNODE;
                this->_size = 0;
            }

            RBT(RBT const & src) : _allocator(src._allocator), comp()
            {
                NULLNODE = this->_allocator.allocate(1);
                NULLNODE->parent = NULL;
                NULLNODE->left = NULL;
                NULLNODE->right = NULL;
                NULLNODE->color = BLACK;
                _root = NULLNODE;
                *this = src;
            }

            ~RBT()
            {
                _root = clear(_root);
                this->_allocator.deallocate(this->NULLNODE, 1);
            }

            node    *clear(node *t)
            {
                if (t == NULLNODE)
                {
                    this->_size = 0;
                    return NULL;
                }
                clear(t->left);
                clear(t->right);
                this->_allocator.deallocate(t, 1);
                return (NULL);
            }

            RBT & operator=(RBT const & rhs)
            {
                this->clear(_root);
                this->_size = rhs._size;
                deep_copy(rhs._root, rhs);
                return (*this);
            }

            ft::pair<node*, bool>   insert(value_type new_pair)
            {
                node    *node_down = this->_root;
                node    *parent_node = NULLNODE;
                node    *new_node;

                while (node_down != NULLNODE)
                {
                    parent_node = node_down;
                    if (!comp(new_pair.first, node_down->value.first) &&            // new key == current key
                            !comp(node_down->value.first, new_pair.first))
                    {
                        // node_down->value.second = new_pair.second;               // no replacement of value if key already exists 
                        return (ft::make_pair(node_down, false));
                    }
                    else if (comp(new_pair.first, node_down->value.first))          // new key < current key
                        node_down = node_down->left;
                    else                                                            // new key > current key
                        node_down = node_down->right;
                }
                new_node = _allocator.allocate(1);
                _allocator.construct(new_node, new_pair);
                // new_node->value = new_pair;
                new_node->parent = parent_node;
                new_node->left = NULLNODE;
                new_node->right = NULLNODE;
                new_node->color = (new_node->parent == NULLNODE) ? BLACK : RED;
                if (parent_node == NULLNODE)
                    this->_root = new_node;
                else if (comp(new_node->value.first, parent_node->value.first))
                    parent_node->left = new_node;
                else
                    parent_node->right = new_node;

                ++this->_size;
                if (!new_node->parent) {
                    new_node->color = BLACK;
                    return (ft::make_pair(new_node, true));
                }
                if (!new_node->parent->parent)
                    return (ft::make_pair(new_node, true));
                fix_insert(new_node);
                return (ft::make_pair(new_node, true));
            }

            node    *search(key_type key_to_find) const
            {
                return (recursive_search(this->_root, key_to_find));
            }

            void    display_tree() const
            {
	            if (this->_root != NULLNODE)
    	    	    printHelper(this->_root, "", true);
	        }

            void    display_sorted() const
            {
                print_tree_sorted(_root);
                std::cout << std::endl;
            }

            node    *successor(node *curr) const
            {
                node    *parent;

                if (curr == this->max())   // returns address after end for end iterator
                    return curr + 1;
                if (curr == this->min() - 1)
                    return this->min();
                if (curr->right != NULLNODE)
                    return (min(curr->right));
                parent = curr->parent;
                // here, we stop when curr is a left child of parent
                // either curr is already a left child and we return parent,
                // or we stop when we find a left child by going up the tree
                while (parent != NULLNODE && curr == parent->right)
                {
                    curr = parent;
                    parent = parent->parent;
                }
                return parent;
            }

            node    *predecessor(node *curr) const
            {
                node    *parent;

                if (curr == this->max() + 1)
                    return this->max();
                if (curr == this->min())
                    return this->min() - 1;
                if (curr->left != NULLNODE)
                    return (max(curr->left));
                parent = curr->parent;
                while (parent != NULLNODE && curr == parent->left)
                {
                    curr = parent;
                    parent = parent->parent;
                }
                return parent;
            }

            void    delete_node(key_type key_to_delete)
            {
                delete_node(_root, key_to_delete);
                this->_size--;
            }

            node    *get_root() const
            {
                return this->_root;
            }

            node    *get_nullnode() const
            {
                return this->NULLNODE;
            }

            size_t  size() const
            {
                return this->_size;
            }

            node    *min() const
            {
                return min(this->_root);
            }

            node    *max() const
            {
                return max(this->_root);
            }
    };
}

#endif