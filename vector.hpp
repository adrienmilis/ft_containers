#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <stdexcept>

/*
    std::allocator : its methods are used for
        - allocating memory
        - deallocating memory
        - constructing objects ( gives a value (p2) to the pointer (p1) )
*/

template< class T, class Alloc = std::allocator<T> >
class vector
{
    typedef T       value_type;
    typedef Alloc   allocator_type;
    typedef size_t  size_type;

    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;
    
    // iterators a ajouter


    private:

        T *                                 _data;          // points to the first element
        typename allocator_type::size_type  _capacity;      // maximum capacity
        typename allocator_type::size_type  _size;          // current size
        allocator_type                      _allocator;     // allocator object used to allocate memory

    public:
    
        /* --- CONSTRUCTORS --- */
        // 1. default
        explicit vector()
        {
           this->_data = _allocator.allocate(0);
           this->_capacity = 0;
           this->_size = 0; 
        }

        // 2. fill
        explicit vector(size_type n, const value_type & val = value_type())
        {
            this->_data = _allocator.allocate(n);
            this->_capacity = n;
            this->_size = 0;
            for (size_type i = 0; i < n ; i++)
                this->_allocator.construct(_data + i, val);
        }

        // 3. range (TO DO)
        // 4. copy  (TO DO)

        vector(const vector & x)
        {

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
            return (*(this->_data) + n);
        }

        const_reference at (size_type n) const
        {
            if (n >= this->_size || n < 0)
                throw std::out_of_range("Exception: out of range access of container");
            return (*(this->_data) + n);
        }
};

#endif