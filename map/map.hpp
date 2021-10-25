#ifndef MAP_HPP
# define MAP_HPP

#include <functional>   // std::less
#include <iterator>     // std::bidirectional_iterator_tag
#include "BST.hpp"
#include "../utils.hpp"

namespace ft
{
    template <  class Key,                                              // map::key_type
                class T,                                                // map::mapped_type
                class Compare = std::less<Key>,                         // map::key_compare
                class Alloc = std::allocator<ft::pair<const Key, T> >   // map::allocator_type
             >
    class map
    {
        public:

            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef ft::pair<const key_type, mapped_type>       value_type;
            typedef Compare                                     key_compare;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef size_t                                      size_type;

        private:

            typedef BST <key_type, mapped_type, key_compare>    search_tree;
            typedef typename search_tree::node                  tree_node;
            

        // typedef iterator
        // typedef const_iterator
        // typedef reverse_iterator
        // typedef const_reverse_iterator
        // typedef difference_type
    
        private:

            search_tree     _bst;
            allocator_type  _allocator;
            Compare         _comp;

        public:

            /*  
                =========
                ITERATORS
                =========
            */

            struct iterator
                : public ft::iterator<std::bidirectional_iterator_tag, value_type>
            {
                typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>  base_iterator;
 
                typedef typename base_iterator::value_type          value_type;
                typedef typename base_iterator::difference_type     difference_type;
                typedef typename base_iterator::pointer             pointer;
                typedef typename base_iterator::reference           reference;

                public:

                    typename search_tree::node  *current_node;

                    // COPLIEN
                    iterator() : current_node(NULL) {}

                    iterator(iterator const & src) {
                        *this = src;
                    }

                    iterator(typename search_tree::node  *node) : current_node(node) {}

                    iterator & operator=(iterator const & rhs) {
                        this->current_node = rhs.current_node;
                        return *this;
                    }

                    ~iterator() {}

                    // OVERLOADS
                    friend bool operator==(iterator const & lhs, iterator const & rhs) {
                        return (lhs.current_node == rhs.current_node);
                    }
                    friend bool operator!=(iterator const & lhs, iterator const & rhs) {
                        return (lhs.current_node != rhs.current_node);
                    }
                    // TO DO verifier ces deux là
                    reference   operator*() const {
                        return (current_node->pair);
                    }
                    pointer operator->() const {
                        return (current_node->pair);
                    }
                    // INCREMENT / DECREMENT
                    iterator & operator++() {
                        current_node = &(++(*current_node));
                    }
            };

            /*  
                ================
                MEMBER FUNCTIONS
                ================
            */

            /* --- CONSTRUCTORS --- */
            // 1. default
            explicit map(const key_compare & comp = key_compare(),
                            const allocator_type& alloc = allocator_type())
                : _bst(), _allocator(alloc), _comp(comp) {}

            // // 2. range (insert value by value)
            // template <class InputIterator>
            // map (InputIterator first, InputIterator last,
            //         const key_compare& comp = key_compare(),
            //         const allocator_type& alloc = allocator_type())
            //     : _BST(), _comp(comp), _allocator(alloc)
            // {
            //     while (first != last)
            //     {
                    
            //     }
            // }

            // 3. copy
            map(const map & x)
            {
                this->_bst = x._bst;
                this->_allocator = x._allocator;
                this->_comp = x._comp;
            }

            /* --- DESTRUCTOR --- */
            ~map() {}

            /* --- OPERATOR= --- */
            // the container preserves its current allocator
            map & operator=(const map & x)
            {
                _bst.clear();
                this->_bst = x._bst;
                this->_comp = x._comp;
            }

            /* --- ITERATORS --- */
            iterator    begin()
            {
                return (iterator(_bst.minimum()));
            }

            /* --- CAPACITY --- */
            bool    empty() const
            {
                return (_bst.size() == 0);
            }

            size_type   size() const
            {
                return (_bst.size());
            }

            size_type   max_size() const
            {
                return (this->_allocator.max_size());
            }
            /* --- ELEMENT ACCESS --- */

            /* --- MODIFIERS --- */
            // 1. insert: single element
            pair<iterator, bool> insert(const value_type & val)
            {
                bool                           new_elem = false;
                tree_node                      *new_elem_address = NULL;
                ft::pair<tree_node*, bool>    pair_node_bool
                    = make_pair(new_elem_address, new_elem);

                _bst.insert(val.first, val.second, &pair_node_bool);
                ft::pair<iterator, bool>    pair_iterator_bool
                    = make_pair(iterator(pair_node_bool.first), pair_node_bool.second);
                return (pair_iterator_bool);
            }
            // 2. insert: with hint
            // 3. insert: range
            /* --- OBSERVERS --- */
            /* --- OPERATIONS --- */
            /* --- ALLOCATOR --- */


    };
}


#endif