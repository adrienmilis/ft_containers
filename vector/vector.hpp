#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <algorithm>
#include "../utils.hpp"

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

                    pointer ptr;

                public:

                    // COPLIEN
                    iterator() : ptr(NULL) {}
                    
                    iterator(pointer ptr) : ptr(ptr) {}
                    
                    iterator(iterator const & src) {
                        *this = src;
                    }
                    iterator & operator=(iterator const & rhs) {
                        this->ptr = rhs.ptr;
                        return *this;
                    }
                    ~iterator() {}

                    // OVERLOADS
                    reference   operator*() const {
                        return (*(this->ptr));
                    }
                    pointer operator->() const {
                        return (this->ptr);
                    }
                    iterator & operator++() {
                        ++this->ptr;
                        return *this;
                    }
                    iterator operator++(int) {
                        iterator tmp = *this;
                        ++(*this);
                        return (tmp);
                    }
                    iterator & operator--() {
                        this->ptr--;
                        return (*this);
                    }
                    iterator operator--(int) {
                        iterator tmp = *this;
                        --(*this);
                        return tmp;
                    }
                    // substract two iterators
                    difference_type operator-(iterator const & rhs) const {
                        return (this->ptr - rhs.ptr);
                    }
                    // add or substract iterator with an integer value
                    friend iterator operator+(iterator const & it, difference_type n) {
                        iterator    new_it;

                        new_it.ptr = it.ptr + n;
                        return (new_it);
                    }
                    iterator operator-(difference_type n) const {
                        iterator    new_it;

                        new_it.ptr = this->ptr - n;
                        return (new_it);
                    }
                    friend bool    operator==(iterator const & lhs, iterator const & rhs) {
                        return (lhs.ptr == rhs.ptr);
                    }
                    friend bool    operator!=(iterator const & lhs, iterator const & rhs) {
                        return (lhs.ptr != rhs.ptr);
                    }
                    friend bool operator<(iterator const & lhs, iterator const & rhs) {
                        return (lhs.ptr < rhs.ptr);
                    }
                    friend bool operator>(iterator const & lhs, iterator const & rhs) {
                        return (lhs.ptr > rhs.ptr);
                    }
                    friend bool operator<=(iterator const & lhs, iterator const & rhs) {
                        return (lhs.ptr <= rhs.ptr);
                    }
                    friend bool operator>=(iterator const & lhs, iterator const & rhs) {
                        return (lhs.ptr >= rhs.ptr);
                    }
                    iterator & operator+=(difference_type n) {
                        *this = *this + n;
                        return (*this);
                    }
                    iterator & operator-=(difference_type n) {
                        *this = *this - n;
                        return (*this);
                    }
                    value_type operator[](difference_type n) const {
                        return (*(this->ptr + n));
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

                    pointer ptr;

                public:

                    // COPLIEN
                    const_iterator() : ptr(NULL) {

                    }
                    const_iterator(const pointer ptr) : ptr(ptr) {

                    }
                    const_iterator(const_iterator const & src) {
                        *this = src;
                    }
                    const_iterator(iterator const & src) {
                        *this = src;
                    }
                    const_iterator & operator=(const_iterator const & rhs) {
                        this->ptr = rhs.ptr;
                        return *this;
                    }
                    // we can do (const_it = it) but not the opposite for obvious reasons
                    const_iterator & operator=(iterator const & rhs) {
                        this->ptr = rhs.ptr;
                        return *this;
                    }
                    ~const_iterator() {}

                    // OVERLOADS
                    const reference   operator*() const {
                        return (*(this->ptr));
                    }
                    const pointer operator->() const {
                        return (this->ptr);
                    }
                    const_iterator & operator++() {
                        this->ptr++;
                        return *this;
                    }
                    const_iterator operator++(int) {
                        const_iterator tmp = *this;
                        ++(*this);
                        return (tmp);
                    }
                    const_iterator & operator--() {
                        this->ptr--;
                        return (*this);
                    }
                    const_iterator operator--(int) {
                        const_iterator tmp = *this;
                        --(*this);
                        return tmp;
                    }
                    // substract two iterators
                    difference_type operator-(const_iterator const & rhs) const {
                        return (this->ptr - rhs.ptr);
                    }
                    // add or substract const_iterator with an integer value
                    friend const_iterator operator+(const_iterator const & it, difference_type n) {
                        const_iterator    new_it;

                        new_it.ptr = it.ptr + n;
                        return (new_it);
                    }
                    const_iterator operator-(difference_type n) const {
                        const_iterator    new_it;

                        new_it.ptr = this->ptr - n;
                        return (new_it);
                    }
                    friend bool    operator==(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs.ptr == rhs.ptr);
                    }
                    friend bool    operator!=(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs.ptr != rhs.ptr);
                    }
                    friend bool operator<(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs.ptr < rhs.ptr);
                    }
                    friend bool operator>(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs.ptr > rhs.ptr);
                    }
                    friend bool operator<=(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs.ptr <= rhs.ptr);
                    }
                    friend bool operator>=(const_iterator const & lhs, const_iterator const & rhs) {
                        return (lhs.ptr >= rhs.ptr);
                    }
                    const_iterator & operator+=(difference_type n) {
                        *this = *this + n;
                        return (*this);
                    }
                    const_iterator & operator-=(difference_type n) {
                        *this = *this - n;
                        return (*this);
                    }
                    value_type operator[](difference_type n) const {
                        return (*(this->ptr + n));
                    }
            };

        private:

            pointer         _data;          // points to the first element
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
            explicit vector(const allocator_type & alloc = allocator_type())
                : _allocator(alloc)
            {
                this->_data = this->_allocator.allocate(0);
                this->_capacity = 0;
                this->_size = 0;
            }

            // 2. fill
            explicit vector(size_type n, const value_type & val = value_type(),
                            const allocator_type & alloc = allocator_type())
                        : _allocator(alloc)
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
                    const allocator_type & alloc = allocator_type(),
				    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
                : _allocator(alloc)
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

                this->_allocator = x._allocator;
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

            // we construct a reverse_iterator from an iterator
            reverse_iterator rbegin() {
                iterator tmp(this->_data + this->_size - 1);
                return (reverse_iterator(tmp));
            }

            const_reverse_iterator rbegin() const {
                iterator tmp(this->_data + this->_size - 1);
                return (const_reverse_iterator(tmp));
            }

            reverse_iterator rend() {
                iterator tmp(this->_data - 1);
                return (reverse_iterator(tmp));
            }

            const_reverse_iterator rend() const {
                iterator tmp(this->_data - 1);
                return (const_reverse_iterator(tmp));
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
                    pointer new_data = this->_allocator.allocate(this->_capacity * 2);
                    
                    for (size_type i = 0; i < this->_size; i++)
                        this->_allocator.construct(new_data + i, this->_data[i]);
                    this->_allocator.construct(new_data + this->_size, val);
                    for (size_type i = 0; i < this->_size ; i++)
                        this->_allocator.destroy(this->_data + i);
                    this->_allocator.deallocate(this->_data, this->_capacity);
                    this->_capacity *= 2;
                    this->_data = new_data;
                }
                this->_size++;
            }

            void    pop_back()
            {
                this->_allocator.destroy(this->_data + this->_size - 1);
                this->_size--;
            }

            // insert: single element
            iterator insert(iterator position, const value_type & val)
            {
                size_type   position_index = position - this->begin();
                if (this->_size == this->_capacity)
                {
                    pointer new_data = this->_allocator.allocate(this->_capacity * 2);
                    typename ft::vector<value_type>::iterator   it = this->begin();
                    int i = 0;
                    typename ft::vector<value_type>::iterator   ite = this->end();

                    while (it != position)
                    {
                        this->_allocator.construct(new_data + i, *it);
                        ++i;
                        ++it;
                    }

                    this->_allocator.construct(new_data + i, val);
                    i++;
                    while (it != ite)
                    {
                        this->_allocator.construct(new_data + i, *it);
                        ++i;
                        ++it;
                    }
                    for (size_type i = 0; i < this->_size ; i++)
                        this->_allocator.destroy(this->_data + i);
                    this->_allocator.deallocate(this->_data, this->_capacity);
                    this->_data = new_data;
                    this->_size++;
                    this->_capacity *= 2;
                }
                else
                {
                    size_type   idx = this->_size;
                    while (idx != position_index) {
                        this->_data[idx] = this->_data[idx - 1];
                        --idx;
                    }
                    this->_allocator.construct(this->_data + idx, val);
                    this->_size++;
                }
                return (this->begin() + position_index);
            }

            // insert: fill
            void insert(iterator position, size_type n, const value_type & val)
            {
                size_type   construct_to;
                if (this->_size + n >= this->_capacity)
                {
                    size_type   old_capacity = this->_capacity;
                    pointer new_data;
                    if (this->_capacity * 2 >= this->_size + n) {
                        new_data = this->_allocator.allocate(this->_capacity * 2);
                        this->_capacity *= 2;
                    }
                    else {
                        new_data = this->_allocator.allocate(this->_capacity * 2 + n);
                        this->_capacity = this->_capacity * 2 + n;
                    }
                    typename ft::vector<value_type>::iterator   it = this->begin();
                    typename ft::vector<value_type>::iterator   ite = this->end();
                    size_type i = 0;

                    while (it != position) {
                        this->_allocator.construct(new_data + i, *it);
                        ++i;
                        ++it;
                    }
                    construct_to = n + i;
                    while (i < construct_to) {
                        this->_allocator.construct(new_data + i, val);
                        ++i;
                    }
                    while (it != ite) {
                        this->_allocator.construct(new_data + i, *it);
                        ++i;
                        ++it;
                    }
                    for (size_type i = 0; i < this->_size ; i++)
                        this->_allocator.destroy(this->_data + i);
                    this->_allocator.deallocate(this->_data, old_capacity);
                    this->_data = new_data;
                }
                else
                {
                    size_type   idx = this->_size - 1 + n;
                    size_type   position_index = position - this->begin();
                    while (idx != position_index) {
                        this->_data[idx] = this->_data[idx - n];
                        --idx;
                    }
                    construct_to = idx + n;
                    while (idx < construct_to) {
                        this->_allocator.construct(this->_data + idx, val);
                        ++idx;
                    }
                }
                this->_size += n;
            }

            // insert: range
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last, 
                typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
            {
                size_type   n = std::distance(first, last);
                if (this->_size + n >= this->_capacity)
                {
                    pointer new_data;
                    size_type   old_capacity = this->_capacity;
                    if (this->_capacity * 2 >= this->_size + n) {
                        new_data = this->_allocator.allocate(this->_capacity * 2);
                        this->_capacity *= 2;
                    }
                    else {
                        new_data = this->_allocator.allocate(this->_capacity * 2 + n);
                        this->_capacity = this->_capacity * 2 + n;
                    }
                    typename ft::vector<value_type>::iterator   it = this->begin();
                    typename ft::vector<value_type>::iterator   ite = this->end();
                    size_type i = 0;

                    while (it != position) {
                        this->_allocator.construct(new_data + i, *it);
                        ++i;
                        ++it;
                    }
                    while (first != last) {
                        this->_allocator.construct(new_data + i, *first);
                        ++i;
                        ++first;
                    }
                    while (it != ite) {
                        this->_allocator.construct(new_data + i, *it);
                        ++i;
                        ++it;
                    }
                    for (size_type i = 0; i < this->_size ; i++)
                        this->_allocator.destroy(this->_data + i);
                    this->_allocator.deallocate(this->_data, old_capacity);
                    this->_data = new_data;
                }
                else
                {
                    size_type   idx = this->_size - 1 + n;
                    size_type   position_index = position - this->begin();
                    while (idx - n >= position_index) {
                        this->_data[idx] = this->_data[idx - n];
                        --idx;
                    }
                    idx = position_index;
                    while (first != last) {
                        this->_allocator.construct(this->_data + idx, *first);
                        ++idx;
                        ++first;
                    }
                }
                this->_size += n;
            }

            // erase: single element
            iterator erase(iterator position)
            {
                typename ft::vector<value_type>::iterator   it = this->begin();
                typename ft::vector<value_type>::iterator   ite = this->end();

                if (position == ite - 1)
                {
                    this->_size--;
                    return (this->end());
                }
                else if (position == it)
                {
                    ++this->_data;
                    return (this->begin());
                }
                else
                {
                    size_type   i = 0;
                    pointer new_data = this->_allocator.allocate(this->_size - 1);
                    while (it != ite) {
                        if (it != position) {
                            this->_allocator.construct(new_data + i, *it);
                            ++i;
                        }
                        ++it;
                    }
                    for (size_type i = 0; i < this->_size ; i++)
                        this->_allocator.destroy(this->_data + i);
                    this->_allocator.deallocate(this->_data, this->_capacity);
                    this->_data = new_data;
                    this->_size--;
                    this->_capacity = this->_size;
                }
                return (this->begin() + (position - this->begin()));
            }

            // erase: range
            iterator erase(iterator first, iterator last)
            {
                typename ft::vector<value_type>::iterator   it = this->begin();
                typename ft::vector<value_type>::iterator   ite = this->end();
                typename ft::vector<value_type>::iterator   tmp = first;
                size_type   distance = last - first;

                // end : do not reallocate
                if (last == ite) {
                    this->_size -= distance;
                    return (this->end());
                }
                else if (first == this->begin())
                {
                    this->_data += distance;
                    this->_size -= distance;
                    return (this->begin());
                }
                // other than end: reallocate
                else
                {
                    size_type   i = 0;
                    pointer new_data = this->_allocator.allocate(this->_size - distance);
                    while (it != ite) {
                        if (it != first) {
                            this->_allocator.construct(new_data + i, *it);
                            ++i;
                        }
                        else if (first != last - 1)
                            ++first;
                        ++it;
                    }
                    for (size_type i = 0; i < this->_size ; i++)
                        this->_allocator.destroy(this->_data + i);
                    this->_allocator.deallocate(this->_data, this->_capacity);
                    this->_data = new_data;
                    this->_size -= distance;
                    this->_capacity = this->_size;
                }
                return (tmp);
            }

            void    swap(vector & x)
            {
                pointer     tmp;
                size_type   tmp_size;
                size_type   tmp_capacity;

                tmp = this->_data;
                tmp_size = this->_size;
                tmp_capacity = this->_capacity;

                this->_data = x._data;
                this->_size = x._size;
                this->_capacity = x._capacity;

                x._data = tmp;
                x._size = tmp_size;
                x._capacity = tmp_capacity;

            }

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

    // std::swap (vector)
    template <class T, class Alloc>
    void    swap(vector <T, Alloc> & x, vector<T, Alloc> & y)
    {
        x.swap(y);
    }

    // std::relational operators (vector)
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() == rhs.size())
            return false;
        return !(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs == rhs)
            return true;
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs == rhs)
            return true;
        return !(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

}

#endif