#ifndef UTILS_HPP
# define UTILS_HPP

#include <cstddef>  // ptrdiff_t
/*
    - iterator_traits
    - reverse_iterator
    - enable_if
    - is_integral
    - equal/lexicographical compare
    - std::pair
    - std::make_pair
*/

namespace ft
{
    /*  
        https://stackoverflow.com/a/25363479 --> great explanation of enable_if
        - type is only defined when bool Cond is true
        - so when type is a template parameter, the template is not defined if
            bool is not true, so it is possible to not use a template if a condition
            is not met!
    */
    /*  --- ENABLE_IF --- */

    template<bool Cond, class T = void>
    struct enable_if {};
    
    template<class T>
    struct enable_if<true, T>
    { typedef T type; };

    /* --- IS_INTEGRAL --- */
    template <class T, T v>
    struct integral_constant
    {
        static const T value = v;   // true or false vu qu'on passe un bool
        typedef T                       value_type;
        typedef integral_constant<T, v> type;
        operator T() { return v; }

    };

    template <class T>
    struct is_integral : public ft::integral_constant<bool, false> {};

    template<> struct is_integral<bool> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<char16_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<char32_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<wchar_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<signed char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<long long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned long long int> : public ft::integral_constant<bool, true> {};
    // const
    template<> struct is_integral<const bool> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const char16_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const char32_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const wchar_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const signed char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const long long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const unsigned char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const unsigned short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const unsigned int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const unsigned long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<const unsigned long long int> : public ft::integral_constant<bool, true> {};
    // volatile
    template<> struct is_integral<volatile bool> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile char16_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile char32_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile wchar_t> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile signed char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile long long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile unsigned char> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile unsigned short int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile unsigned int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile unsigned long int> : public ft::integral_constant<bool, true> {};
    template<> struct is_integral<volatile unsigned long long int> : public ft::integral_constant<bool, true> {};

    /* --- ITERATOR_TRAITS --- */
    // traits class defining properties of iterators

    // iterator_traits specializations take an iterator and define subtypes
    // used by standard algorithms to determine certain properties of the
    // iterators passed to them
    template <class Iterator>
    class iterator_traits
    {
        public:
            typedef typename Iterator::value_type          value_type;
            typedef typename Iterator::difference_type     difference_type;
            typedef typename Iterator::iterator_category   iterator_category;
            typedef typename Iterator::pointer             pointer;
            typedef typename Iterator::reference           reference;
    };

    template <class T>
    class iterator_traits<T*>
    {
        public:
            typedef ptrdiff_t                       difference_type;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    class iterator_traits<const T*>
    {
        public:
            typedef ptrdiff_t                       difference_type;
            typedef T                               value_type;
            typedef const T*                        pointer;
            typedef const T&                        reference;
            typedef std::random_access_iterator_tag iterator_category;
    };

    /* --- ITERATOR --- */

    /*
        - reimplement std::iterator (base class)
        - then in the vector class, inherit from that base iterator class
        - it just gives subtypes to use with all iterators without 
        - having to reimplement it always
    */

    // Category: iterator tag
    // T: type of elements pointed by the iterator
    // Distance: type to represent the difference between two iterators
    // Pointer: type to represent a pointer to an element pointed by the iterator
    // Reference: type to represent a reference to an element pointed by the iterator
    template    <class Category, class T, class Distance = ptrdiff_t,
                class Pointer = T*, class Reference = T&>
    struct iterator
    {
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
        typedef Category    iterator_category;
    };


    /* --- REVERSE_ITERATOR --- */
    template <class Iterator>
    class reverse_iterator
    {
        private:

            typedef Iterator                                                 iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category    iterator_category;
            typedef typename iterator_traits<Iterator>::value_type           value_type;
            typedef typename iterator_traits<Iterator>::difference_type      difference_type;
            typedef typename iterator_traits<Iterator>::pointer              pointer;
            typedef typename iterator_traits<Iterator>::reference            reference;


        private:

            Iterator    _base_iterator;

        public:

            // 1. Constructors
            reverse_iterator() : _base_iterator() {
                
            }

            explicit reverse_iterator(iterator_type it) : _base_iterator(it) {

            }
            template<class Iter>
            reverse_iterator(const reverse_iterator<Iter> & rev_it) : _base_iterator(rev_it._base_iterator) {

            }

            // 2. Base
            iterator_type base() const {
                return this->_base_iterator;
            }

            // 3. Overloads
            reference operator*() const {
                return (reverse_iterator(--_base_iterator));
            }
            reverse_iterator operator+(difference_type n) const {
                return (reverse_iterator(_base_iterator[-n-1]));
            }
            reverse_iterator & operator++() {
                --_base_iterator;
                return (*this);
            }
            reverse_iterator operator++(int) {
                reverse_iterator    tmp = *this;
                ++(*this);
                return (tmp);
            }
            reverse_iterator & operator+=(difference_type n) {
                _base_iterator -= n;
                return (*this);
            }
            reverse_iterator operator-(difference_type n) const {
                return (reverse_iterator(_base_iterator[n-1]));
            }
            reverse_iterator & operator--() {
                ++_base_iterator;
                return (*this);
            }
            reverse_iterator operator--(int) {
                reverse_iterator    tmp = *this;
                --(*this);
                return (tmp);
            }
            reverse_iterator & operator-=(difference_type n) {
                _base_iterator += n;
                return (*this);
            }
            pointer operator->() const {
                return (_base_iterator._ptr);
            }
            reference operator[] (difference_type n) const {
                return (_base_iterator[-n-1]);
            }
    };
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        return (lhs == rhs);
    }

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        return (lhs != rhs);
    }

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        return (lhs > rhs);
    }

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        return (lhs >= rhs);
    }

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        return (lhs < rhs);
    }

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
        return (lhs <= rhs);
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator> & rev_it) {
            return (rev_it + n);
        }
    
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (
        const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>& rhs) {
            return (lhs.base() - rhs.base());
        }
}

#endif