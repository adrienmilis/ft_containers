#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "utils.hpp"

/*
    std::allocator : its methods are used for
        - allocating memory
        - deallocating memory
        - constructing objects ( gives a value (p2) to the pointer (p1) )

    random-access iterator
*/

namespace ft
{

    template< class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:

            typedef T       value_type;
            typedef Alloc   allocator_type;
            typedef size_t  size_type;

            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;

            struct  iterator;
            struct  const_iterator;
            typedef typename ft::reverse_iterator<iterator>                reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>                 const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;

        // iterators a ajouter
        // note sur les overloads friend:
        //      utile pour ne pas se soucier de l'ordre de l'operation (si le membre est a droite ou a gauche)
        //      et dans les cas de conversion. si aucun overload n'est possible avant conversion, mais 
        //      possible après, alors il faut utiliser friend sinon ca ne marchera pas
        // NOTE:
        //      ici, on n'a pas souvent besoin de friend parce que le pointeur est public !
        public:
            struct iterator
                : public ft::iterator< std::random_access_iterator_tag, value_type >
            {
                typedef typename ft::iterator< std::random_access_iterator_tag, value_type > base_iterator;

                typedef typename base_iterator::value_type           value_type;
                typedef typename base_iterator::difference_type      difference_type;
                typedef typename base_iterator::pointer              pointer;
                typedef typename base_iterator::reference            reference;
                typedef typename base_iterator::iterator_category    iterator_category;

                public:

                    pointer _ptr;

                public:

                    // COPLIEN
                    iterator() : _ptr(NULL) {

                    }
                    iterator(pointer ptr) : _ptr(ptr) {

                    }
                    iterator(iterator const & src) {
                        *this = src;
                    }
                    iterator & operator=(iterator const & rhs) {
                        this->_ptr = rhs._ptr;
                        return *this;
                    }
                    ~iterator() {}

                    // OVERLOADS
                    reference   operator*() const {
                        return (*(this->_ptr));
                    }
                    pointer operator->() const {
                        return (this->_ptr);
                    }
                    iterator & operator++() {
                        this->_ptr++;
                        return *this;
                    }
                    iterator operator++(int) {
                        iterator tmp = *this;
                        ++(*this);
                        return (tmp);
                    }
                    iterator & operator--() {
                        this->_ptr--;
                        return (*this);
                    }
                    iterator operator--(int) {
                        iterator tmp = *this;
                        --(*this);
                        return tmp;
                    }
                    // substract two iterators
                    difference_type operator-(iterator const & rhs) const {
                        return (this->_ptr - rhs._ptr);
                    }
                    // add or substract iterator with an integer value
                    friend iterator operator+(iterator const & it, difference_type n) {
                        iterator    new_it;

                        new_it._ptr = it._ptr + n;
                        return (new_it);
                    }
                    iterator operator-(difference_type n) {
                        iterator    new_it;

                        new_it._ptr = this->_ptr - n;
                        return (new_it);
                    }
                    friend bool    operator==(iterator const & lhs, iterator const & rhs) {
                        return (lhs._ptr == rhs._ptr);
                    }
                    friend bool    operator!=(iterator const & lhs, iterator const & rhs) {
                        return (lhs._ptr != rhs._ptr);
                    }
                    friend bool operator<(iterator const & lhs, iterator const & rhs) {
                        return (lhs._ptr < rhs._ptr);
                    }
                    friend bool operator>(iterator const & lhs, iterator const & rhs) {
                        return (lhs._ptr > rhs._ptr);
                    }
                    friend bool operator<=(iterator const & lhs, iterator const & rhs) {
                        return (lhs._ptr <= rhs._ptr);
                    }
                    friend bool operator>=(iterator const & lhs, iterator const & rhs) {
                        return (lhs._ptr >= rhs._ptr);
                    }
                    iterator & operator+=(difference_type n) {
                        *this = *this + n;
                        return (*this);
                    }
                    iterator & operator-=(difference_type n) {
                        *this = *this - n;
                        return (*this);
                    }
                    value_type operator[](difference_type n) {
                        return (*(this->_ptr + n));
                    }
            };

            // a const_iterator points to an element of a constant type,
            // which means the the pointed element can't be modified
            // --> can be used for access only
            struct const_iterator
                : public ft::iterator< std::random_access_iterator_tag, value_type >
            {
                typedef typename ft::iterator< std::random_access_iterator_tag, value_type > base_iterator;

                typedef typename base_iterator::value_type           value_type;
                typedef typename base_iterator::difference_type      difference_type;
                typedef typename base_iterator::pointer              pointer;
                typedef typename base_iterator::reference            reference;
                typedef typename base_iterator::iterator_category    iterator_category;

                public:

                    pointer _ptr;

                public:

                    // COPLIEN
                    const_iterator() : _ptr(NULL) {

                    }
                    const_iterator(const pointer ptr) : _ptr(ptr) {

                    }
                    const_iterator(const_iterator const & src) {
                        *this = src;
                    }
                    const_iterator(iterator const & src) {
                        *this = src;
                    }
                    const_iterator & operator=(const_iterator const & rhs) {
                        this->_ptr = rhs._ptr;
                        return *this;
                    }
                    // we can do (const_it = it) but not the opposite for obvious reasons
                    const_iterator & operator=(iterator const & rhs) {
                        this->_ptr = rhs._ptr;
                        return *this;
                    }
                    ~const_iterator() {}

                    // OVERLOADS
                    const reference   operator*() const {
                        return (*(this->_ptr));
                    }
                    const pointer operator->() const {
                        return (this->ptr);
                    }
                    const_iterator & operator++() {
                        this->_ptr++;
                        return *this;
                    }
                    const_iterator operator++(int) {
                        const_iterator tmp = *this;
                        ++(*this);
                        return (tmp);
                    }
                    const_iterator & operator--() {
                        this->_ptr--;
                        return (*this);
                    }
                    const_iterator operator--(int) {
                        const_iterator tmp = *this;
                        --(*this);
                        return tmp;
                    }
                    // substract two iterators
                    difference_type operator-(const_iterator const & rhs) const {
                        return (this->_ptr - rhs._ptr);
                    }
                    // add or substract const_iterator with an integer value
                    friend const_iterator operator+(const_iterator const & it, difference_type n) {
                        const_iterator    new_it;

                        new_it._ptr = it._ptr + n;
                        return (new_it);
                    }
                    const_iterator operator-(difference_type n) {
                        const_iterator    new_it;

                        new_it._ptr = this->_ptr - n;
                        return (new_it);
                    }
                    friend bool    operator==(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs._ptr == rhs._ptr);
                    }
                    friend bool    operator!=(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs._ptr != rhs._ptr);
                    }
                    friend bool operator<(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs._ptr < rhs._ptr);
                    }
                    friend bool operator>(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs._ptr > rhs._ptr);
                    }
                    friend bool operator<=(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs._ptr <= rhs._ptr);
                    }
                    friend bool operator>=(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs._ptr >= rhs._ptr);
                    }
                    const_iterator & operator+=(difference_type n) {
                        *this = *this + n;
                        return (*this);
                    }
                    const_iterator & operator-=(difference_type n) {
                        *this = *this - n;
                        return (*this);
                    }
                    value_type operator[](difference_type n) {
                        return (*(this->_ptr + n));
                    }
            };

        private:

            value_type *    _data;          // points to the first element
            size_type       _capacity;      // maximum capacity
            size_type       _size;          // current size
            allocator_type  _allocator;     // allocator object used to allocate memory

        public:
            /*  
                ================
                MEMBER FUNCTIONS
                ================
            */

            /* --- CONSTRUCTORS --- */
            // 1. default
            explicit vector()
            {
                this->_data = this->_allocator.allocate(0);
                this->_capacity = 0;
                this->_size = 0;
            }

            // 2. fill
            explicit vector(size_type n, const value_type & val = value_type())
            {
                this->_data = this->_allocator.allocate(n);
                this->_capacity = n;
                this->_size = n;
                for (size_type i = 0; i < n ; i++)
                    this->_allocator.construct(_data + i, val);
            }

            // 3. range
            // if ft::enable_if<>::type is not defined (if InputIterator is an integral type), then
            // the template is not valid and the program will know to use the -FILL constructor-
            template < class InputIterator >
            vector(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
            {
                long    distance = std::distance(first, last);
                int     i;

                this->_data = this->_allocator.allocate(distance);
                this->_capacity = distance;
                this->_size = distance;
                i = 0;
                while (first != last)
                {
                    this->_allocator.construct(this->_data + i, *first);
                    first++;
                    i++;
                }
            }     

            // 4. copy
            vector(const vector & x)
            {
                size_type   x_size = x.size();

                this->_data = this->_allocator.allocate(x_size);
                this->_capacity = x_size;
                this->_size = x_size;
                for (size_type i = 0 ; i < x_size ; i++)
                {
                    this->_allocator.construct(this->_data + i, x[i]);
                }
            }

            /* --- DESTRUCTOR --- */
            ~vector()
            {
                this->clear();
                this->_allocator.deallocate(this->_data, this->_capacity);
            }

            /* --- OPERATOR= --- */
            vector & operator=(const vector & x)
            {
                // this->_capacity = x.size(), not x.capacity() if x.size() > this->_size
                if (x.size() > this->_capacity)
                {
                    this->clear();
                    this->_allocator.deallocate(this->_data, this->_capacity);
                    this->_data = this->_allocator.allocate(x.size());
                    this->_capacity = x.size();
                }
                this->_size = x.size();
                for (size_type i = 0; i < x.size() ; i++)
                {
                    this->_allocator.construct(this->_data + i, x[i]);
                }
                return (*this);
            }

            /* --- ITERATORS --- */
            iterator begin() {
                return (iterator(this->_data));
            }
            
            const_iterator begin() const {
                return (const_iterator(this->_data));
            }

            iterator end() {
                return (iterator(this->_data + this->_size));
            }

            const_iterator end() const {
                return (const_iterator(this->_data + this->_size));
            }

            reverse_iterator rbegin() {
                return (reverse_iterator(this->_data + this->_size - 1));
            }

            const_reverse_iterator rbegin() const {
                return (const_reverse_iterator(this->_data + this->_size - 1));
            }

            reverse_iterator rend() {
                return (reverse_iterator(this->_data - 1));
            }

            const_reverse_iterator rend() const {
                return (const_reverse_iterator(this->_data - 1));
            }
            /* --- CAPACITY --- */
            size_type size() const
            {
                return (this->_size);
            }

            size_type max_size() const
            {
                return (this->_allocator.max_size());
            }

            void resize(size_type n, value_type val = value_type())
            {
                if (n < this->_size)
                {
                    // remove & destroy elements after n (not deallocate)
                    for (size_type i = n ; i < this->_size ; i++)
                        this->_allocator.destroy(this->_data + i);
                    this->_size = n;
                }
                else if (n <= this->_capacity && n > this->_size)
                {
                    // insert at the end elements
                    for (size_type i = this->_size; i < n; i++)
                        this->_allocator.construct(this->_data + i, val);
                    this->_size = n;
                }
                else if (n > this->_capacity && n > this->_size)
                {
                    // reallocate new array
                    value_type  *new_array = this->_allocator.allocate(n);
                    // copy contents
                    for (size_type i = 0; i < this->_size; i++)
                        this->_allocator.construct(new_array + i, this->_data[i]);
                    // insert new elements
                    for (size_type i = this->_size; i < n; i++)
                        this->_allocator.construct(new_array + i, val);
                    // destroy old array
                    this->clear();
                    // deallocate old array
                    this->_allocator.deallocate(this->_data, this->_size);
                    this->_data = new_array;
                    // change current size and capacity
                    this->_size = n;
                    this->_capacity = n;
                }
            }

            size_type capacity() const
            {
                return (this->_capacity);
            }

            bool empty() const
            {
                return (this->_size == 0);
            }

            void reserve(size_type n)
            {
                if (n > this->_capacity)
                {
                    value_type  *new_array = this->_allocator.allocate(n);

                    for (size_type i = 0; i < this->_size; i++)
                        this->_allocator.construct(new_array + i, this->_data[i]);
                    for (size_type i = 0; i < this->_size ; i++)
                        this->_allocator.destroy(this->_data + i);
                    this->_allocator.deallocate(this->_data, this->_size);
                    this->_data = new_array;
                    this->_capacity = n;
                }
            }

            /* --- ELEMENT ACCESS --- */
            // 1. operator[]
            reference operator[] (size_type n)
            {
                return (*(this->_data + n));
            }

            const_reference operator[] (size_type n) const
            {
                return (*(this->_data + n));
            }

            // 2. at
            reference at(size_type n)
            {
                if (n >= this->_size || n < 0)
                    throw std::out_of_range("Exception: out of range access of container");
                return (*(this->_data + n));
            }

            const_reference at (size_type n) const
            {
                if (n >= this->_size || n < 0)
                    throw std::out_of_range("Exception: out of range access of container");
                return (*(this->_data + n));
            }

            // 3. front
            reference front()
            {
                return (*(this->_data));
            }

            const_reference front() const
            {
                return (*(this->_data));
            }

            // 4. back
            reference back()
            {
                return (*(this->_data + (this->_size - 1)));
            }

            const_reference back() const
            {
                return (*(this->_data + (this->_size - 1)));
            }

            /* --- MODIFIERS --- */
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last)
            {
                long    distance = std::distance(first, last);
                int     i;

                this->clear();
                // reallocation only if new vector size > current vector capacity
                if (static_cast<size_type>(distance) > this->_capacity)
                {
                    this->_allocator.deallocate(this->_data, this->_capacity);
                    this->_data = this->_allocator.allocate(distance);
                    this->_capacity = distance;
                }
                // Remplacer (construire)
                i = 0;
                while (first != last)
                {
                    this->_allocator.construct(this->_data + i, *first);
                    first++;
                    i++;
                }
                this->_size = distance;
            }

            void    push_back(const value_type & val)
            {
                /* 
                    - if enough capacity : simply add value at the end
                    - else, reallocate at twice the capacity, copy then add value
                */
                if (this->_size < this->_capacity)
                    this->_allocator.construct(this->_data + this->_size, val);
                else
                {
                    value_type  *new_data = this->_allocator.allocate(this->_capacity * 2);
                    
                    for (size_type i = 0; i < this->_size; i++)
                        this->_allocator.construct(new_data + i, this->_data[i]);
                    this->_allocator.construct(new_data + this->_size, val);
                    for (size_type i = 0; i < this->_size ; i++)
                        this->_allocator.destroy(this->_data + i);
                    this->_allocator.deallocate(this->_data, this->_capacity);
                    this->_capacity *= 2;
                    this->_data = new_data;
                }
                (this->_size) += 1;
            }

            void    pop_back()
            {
                this->_allocator.destroy(this->_data + this->_size - 1);
                this->_size--;
            }

            // void    swap(vector & x)
            // {
            //     // all iterators, references and pointers remain valid
            //     // donc concretement les adresses restent les memes
            //     ft::vector<value_type>  tmp(*this);

            //     // copy x in this
            //     // ASSIGN with iterators


            // }

            void    clear()
            {
                for (size_type i = 0; i < this->_size ; i++)
                    this->_allocator.destroy(this->_data + i);
                this->_size = 0;
            }

            /* --- ALLOCATOR --- */
            allocator_type  get_allocator() const
            {
                return (this->_allocator);
            }
    };
}

#endif