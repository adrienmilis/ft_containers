#ifndef MAP_HPP
# define MAP_HPP

#include <utility>      // remove, std::pair
#include <functional>   // std::less
#include <iterator>     // std::bidirectional_iterator_tag
#include "RBT.hpp"
#include "../utils/utils.hpp"

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

            struct iterator;
            struct const_iterator;
            typedef ft::reverse_iterator<iterator>                          reverse_iterator;     
            typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;

        private:

            typedef RBT<key_type, mapped_type, key_compare>    search_tree;
            typedef typename search_tree::node                  tree_node;
            

    
        public:
            search_tree     _rbt;
        private:
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
 
                typedef typename base_iterator::pointer             pointer;
                typedef typename base_iterator::reference           reference;

                typedef RBT<key_type, mapped_type, key_compare>     search_tree;
                typedef typename search_tree::node                  tree_node;

                public:

                    typename search_tree::node  *current_node;
                    search_tree                 *rbt;

                    // COPLIEN
                    iterator() : current_node(NULL), rbt(NULL) {}

                    iterator(iterator const & src) {
                        *this = src;
                    }

                    iterator(tree_node *node, search_tree *rbt) : current_node(node), rbt(rbt) {}

                    iterator & operator=(iterator const & rhs) {
                        this->rbt = rhs.rbt;
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
                    reference   operator*() const {
                        return (current_node->value);
                    }
                    pointer operator->() const {
                        return (&current_node->value);
                    }
                    // INCREMENT / DECREMENT
                    iterator & operator++() {
                        this->current_node = this->rbt->successor(this->current_node);
                        return (*this);
                    }
                    iterator operator++(int) {
                        iterator tmp = *this;
                        this->operator++();
                        return (tmp);
                    }
                    
                    iterator & operator--() {
                        this->current_node = this->rbt->predecessor(current_node);
                        return (*this);
                    }
                    iterator operator--(int) {
                        iterator tmp = *this;
                        this->operator--();
                        return (tmp);
                    }
            };

            struct const_iterator
                : public ft::iterator<std::bidirectional_iterator_tag, value_type>
            {
                typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>  base_iterator;
 
                typedef typename base_iterator::pointer             pointer;
                typedef typename base_iterator::reference           reference;

                typedef RBT<key_type, mapped_type, key_compare>     search_tree;
                typedef typename search_tree::node                  tree_node;

                public:

                    typename search_tree::node  *current_node;
                    search_tree                 *rbt;

                // COPLIEN
                const_iterator() : current_node(NULL), rbt(NULL) {}

                const_iterator(iterator const & src) {
                    *this = src;
                }

                const_iterator(const_iterator const & src) {
                    *this = src;
                }
                
                const_iterator(tree_node *node, search_tree *rbt) : current_node(node), rbt(rbt) {}

                const_iterator & operator=(iterator const & rhs) {
                    this->rbt = rhs.rbt;
                    this->current_node = rhs.current_node;
                    return *this;
                }

                const_iterator & operator=(const_iterator const & rhs) {
                    this->rbt = rhs.rbt;
                    this->current_node = rhs.current_node;
                    return *this;
                }

                ~const_iterator() {}

                // OVERLOADS
                friend bool operator==(const_iterator const & lhs, const_iterator const & rhs) {
                    return (lhs.current_node == rhs.current_node);
                }
                friend bool operator!=(const_iterator const & lhs, const_iterator const & rhs) {
                    std::cout << "TEST" << std::endl;
                    return (lhs.current_node != rhs.current_node);
                }
                const reference   operator*() const {
                    return (current_node->value);
                }
                const pointer operator->() const {
                    return (&current_node->value);
                }

                // INCREMENT / DECREMENT
                const_iterator & operator++() {
                    this->current_node = this->rbt->successor(this->current_node);
                    return (*this);
                }
                const_iterator operator++(int) {
                    const_iterator tmp = *this;
                    this->operator++();
                    return (tmp);
                }
                
                const_iterator & operator--() {
                    this->current_node = this->rbt->predecessor(current_node);
                    return (*this);
                }
                const_iterator operator--(int) {
                    const_iterator tmp = *this;
                    this->operator--();
                    return (tmp);
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
                : _rbt(alloc), _allocator(alloc), _comp(comp) {}

            // 2. range (insert value by value)
            template <class InputIterator>
            map (InputIterator first, InputIterator last,
                    const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type())
                : _rbt(alloc), _allocator(alloc), _comp(comp)
            {
                while (first != last)
                {
                    this->_rbt.insert(*first);
                    ++first;
                }
            }

            // 3. copy
            map(const map & x) :
                _rbt(x._rbt), _allocator(x._allocator), _comp(x._comp) {}

            /* --- DESTRUCTOR --- */
            ~map() {}

            /* --- OPERATOR= --- */
            // the container preserves its current allocator
            map & operator=(const map & x)
            {
                _rbt.clear(_rbt.get_root());
                this->_rbt = x._rbt;
                this->_comp = x._comp;
                return (*this);
            }

            /* --- ITERATORS --- */
            iterator    begin()
            {
                return (iterator(_rbt.min(), &this->_rbt));
            }

            const_iterator  begin() const
            {
                return (const_iterator(_rbt.min(), &this->_rbt));
            }

            iterator    end()
            {
                if (this->empty())
                    return this->begin();
                return (iterator(_rbt.max() + 1, &this->_rbt));
            }

            const_iterator  end() const
            {
                return (const_iterator(_rbt.max(), &this->_rbt));
            }

            reverse_iterator    rbegin()
            {
                iterator tmp = iterator(_rbt.max(), &this->_rbt);
                return (reverse_iterator(tmp));
            }

            const_reverse_iterator  rbegin() const
            {
                const_iterator tmp = const_iterator(_rbt.max(), &this->_rbt);
                return (const_reverse_iterator(tmp));
            }

            reverse_iterator    rend()
            {
                iterator    tmp = iterator(_rbt.min() - 1, &this->_rbt);
                return (reverse_iterator(tmp));
            }

            const_reverse_iterator  rend() const
            {
                const_iterator tmp = const_iterator(_rbt.min() - 1, &this->_rbt);
                return (const_reverse_iterator(tmp));
            }

            /* --- CAPACITY --- */
            bool    empty() const
            {
                return (_rbt.size() == 0);
            }

            size_type   size() const
            {
                return (_rbt.size());
            }

            size_type   max_size() const
            {
                return (this->_allocator.max_size());
            }
            /* --- ELEMENT ACCESS --- */

            /* --- MODIFIERS --- */
            // 1. insert: single element
            ft::pair<iterator, bool> insert(const value_type & val)
            {
                ft::pair<tree_node*, bool> pair = _rbt.insert(val);
                return (ft::make_pair(iterator(pair.first, &this->_rbt), pair.second));
            }
            // 2. insert: with hint
            // 3. insert: range
            /* --- OBSERVERS --- */
            /* --- OPERATIONS --- */
            /* --- ALLOCATOR --- */


    };
}


#endif