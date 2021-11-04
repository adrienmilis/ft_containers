#ifndef MAP_HPP
# define MAP_HPP

#include <utility>      // remove, std::pair
#include <functional>   // std::less
#include <iterator>     // std::bidirectional_iterator_tag
#include "RBT.hpp"
#include "utils.hpp"

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
                =============
                VALUE_COMPARE
                =============
            */
            class value_compare : public std::binary_function<value_type, value_type, bool>
            {
                public:  // if protected, can map access it or does it have to be made public?
                    Compare comp;
                    value_compare(Compare c) : comp(c) {}   // we construct it with our key_compare
                
                    typedef std::binary_function<value_type, value_type, bool>  Base;
                    typedef typename Base::result_type          result_type;
                    typedef typename Base::first_argument_type  first_argument_type;
                    typedef typename Base::second_argument_type second_argument_type;

                    bool    operator()(const value_type & x, const value_type & y) const
                    {
                        return (comp(x.first, y.first));
                    }
            };

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
                    this->_rbt.insert(_rbt.get_root(), *first);
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
                _rbt.clear_tree();
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
            mapped_type & operator[](const key_type & k)
            {
                tree_node   *found_node = _rbt.search(k);

                if (found_node == _rbt.get_nullnode())
                {
                    ft::pair<key_type, mapped_type>  new_pair;
                    new_pair.first = k;
                    value_type  pair_to_insert = new_pair;
                    // reference to mapped type of inserted pair
                    return (_rbt.insert(_rbt.get_root(), pair_to_insert)).first->value.second;
                }
                else
                    return (found_node->value.second);
            }

            /* --- MODIFIERS --- */
            // 1.1 insert: single element
            ft::pair<iterator, bool> insert(const value_type & val)
            {
                ft::pair<tree_node*, bool> pair = _rbt.insert(_rbt.get_root(), val);
                return (ft::make_pair(iterator(pair.first, &this->_rbt), pair.second));
            }

            // 1.2 insert: with hint
            iterator insert(iterator position, const value_type & val)
            {
                tree_node    *elem_at_position = _rbt.search(position->first);
                tree_node    *next_elem = _rbt.successor(elem_at_position);
                ft::pair<tree_node*, bool>   insert_ret;

                if (_comp(position->first, val.first) && _comp(val.first, next_elem->value.first))
                {
                    insert_ret = _rbt.insert(position.current_node, val);
                    return (iterator(insert_ret.first, &this->_rbt));
                }
                else
                {
                    insert_ret = _rbt.insert(_rbt.get_root(), val);
                    return (iterator(insert_ret.first, &this->_rbt));
                }
                
            }

            // 1.3 insert: range
            template <class InputIterator>
            void    insert(InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    this->insert(*first);
                    ++first;
                }
            }

            // 2.1 Erase: position
            void    erase(iterator position)
            {
                _rbt.delete_node(position->first);
            }

            // 2.2 Erase: key
            size_type   erase(const key_type & k)
            {
                bool element_deleted = _rbt.delete_node(k);
                return (element_deleted) ? 1 : 0;
            }

            // 2.3 Erase: range
            void    erase(iterator first, iterator last)
            {
                while (first != last)
                    this->erase(first++);
            }

            // 3. Swap
            void    swap(map & x)
            {
                map tmp;
                
                tmp._allocator = this->_allocator;
                tmp._comp = this->_comp;
                tmp._rbt = this->_rbt;

                this->_allocator = x._allocator;
                this->_comp = x._comp;
                this->_rbt = x._rbt;

                x._allocator = tmp._allocator;
                x._comp = tmp._comp;
                x._rbt = tmp._rbt;
            }

            // 4. Clear
            void    clear()
            {
                this->_rbt.clear_tree();
            }

            /* --- OBSERVERS --- */
            // 1. Key_comp
            key_compare key_comp() const
            {
                return (this->_comp);
            }

            // 2. Value_comp
            value_compare   value_comp() const
            {
                value_compare   value_comp(this->_comp);
                return (value_comp);
            }

            /* --- OPERATIONS --- */
            // 1. Find
            iterator    find(const key_type & k)
            {
                tree_node   *found = _rbt.search(k);
                if (found == _rbt.get_nullnode())
                    return this->end();
                else
                    return iterator(found, &this->_rbt);
            }

            const_iterator  find(const key_type & k) const
            {
                tree_node   *found = _rbt.search(k);
                if (found == _rbt.get_nullnode())
                    return this->end();
                else
                    return const_iterator(found, &this->_rbt);
            }

            // 2. Count
            size_type   count(const key_type & k) const
            {
                return (_rbt.search(k) == _rbt.get_nullnode()) ? 0 : 1;
            }

            // 3. Lower_bound
            // returns either an iterator on k or on the key that goes right after
            iterator    lower_bound(const key_type & k)
            {
                map::iterator   it = this->begin();
                map::iterator   ite = this->end();

                while (it != ite && this->_comp(it->first, k))   // while current key < k
                    ++it;
                return (it);
            }

            const_iterator  lower_bound(const key_type & k) const
            {
                map::const_iterator   it = this->begin();
                map::const_iterator   ite = this->end();

                while (it != ite && this->_comp(it->first, k))   // while current key < k
                    ++it;
                return (it);
            }

            // 4. Upper_bound
            iterator    upper_bound(const key_type & k)
            {
                map::iterator   it = this->begin();
                map::iterator   ite = this->end();

                while (it != ite &&
                    (this->_comp(it->first, k) ||
                    (!_comp(it->first, k) && !_comp(k, it->first))))
                    ++it;
                return (it);
            }

            const_iterator  upper_bound(const key_type & k) const
            {
                map::const_iterator   it = this->begin();
                map::const_iterator   ite = this->end();

                while (it != ite &&
                    (this->_comp(it->first, k) ||
                    (!_comp(it->first, k) && !_comp(k, it->first))))
                    ++it;
                return (it);
            }
            // 5. Equal_range
            pair<iterator, iterator>    equal_range(const key_type & k)
            {
                pair<iterator, iterator>    pair;

                pair.first = this->lower_bound(k);
                pair.second = this->upper_bound(k);
                return (pair);
            }

            pair<const_iterator, const_iterator>    equal_range(const key_type & k) const
            {
                pair<const_iterator, const_iterator>    pair;

                pair.first = this->lower_bound(k);
                pair.second = this->upper_bound(k);
                return (pair);
            }

            /* --- ALLOCATOR --- */
            allocator_type  get_allocator() const
            {
                return (this->_allocator);
            }

    };
}


#endif