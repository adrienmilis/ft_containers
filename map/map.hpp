#ifndef MAP_HPP
# define MAP_HPP

#include <functional>   // std::less
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
            typedef typename allocator_type::const_reference    const_reference
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef size_t                                      size_type;

        // typedef iterator
        // typedef const_iterator
        // typedef reverse_iterator
        // typedef const_reverse_iterator
        // typedef difference_type
    
        private:

            BST             _bst;
            allocator_type  _allocator;

        public:

             /*  
                ================
                MEMBER FUNCTIONS
                ================
            */

            /* --- CONSTRUCTORS --- */
            // 1. default
            explicit map() : _BST() {}

            // // 2. range (insert value by value)
            // template <class InputIterator>
            // map (InputIterator first, InputIterator last)
            // {
            //     while (first != last)
            //     {
            //         ++first;
            //     }
            // }

            // 3. copy
            map(const map & x)
            {
                this->_bst = x._bst;
            }
    };
}


#endif