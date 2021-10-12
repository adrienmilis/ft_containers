#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <stdexcept>
#include <algorithm>

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

        // 3. range (TO DO)
        template <class InputIterator>
        
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
                this->clear();
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

        void    clear()
        {
            for (size_t i = 0; i < this->_size ; i++)
                this->_allocator.destroy(this->_data + i);
            this->_size = 0;
        }

        /* --- ALLOCATOR --- */

};

#endif