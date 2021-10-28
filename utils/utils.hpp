#ifndef UTILS_HPP
# define UTILS_HPP

#include <cstddef>  // ptrdiff_t
#include <iterator>

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
    struct enable_if<true, T> // enable_if<bool, var>
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
    // va toujours pointer 1 derriere, c'est au moment du dereferencement qu'on
    // recupere la bonne valeur
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

            iterator_type   _base_iterator;

        public:

            // 1. Constructors
            reverse_iterator() : _base_iterator() {}

            explicit reverse_iterator(iterator_type it) : _base_iterator(it) {}

            template<class Iter>
            reverse_iterator(const reverse_iterator<Iter> & rev_it) : _base_iterator(rev_it._base_iterator) {}

            // 2. Base
            iterator_type base() const {
                return this->_base_iterator;
            }

            // 3. Overloads
            reference operator*() const {
                return (*_base_iterator);
            }
            reverse_iterator operator+(difference_type n) const {
                return (reverse_iterator(_base_iterator - n));
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
                return (reverse_iterator(_base_iterator + n));
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
            reference operator[](difference_type n) const {
				return (*(_base_iterator - n));
            }
            // template <class Iterator>
            friend bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                return (lhs == rhs);
            }

            // template <class Iterator>
            friend bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                return (lhs._base_iterator != rhs._base_iterator);
            }

            // template <class Iterator>
            friend bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                return (lhs > rhs);
            }

            // template <class Iterator>
            friend bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                return (lhs >= rhs);
            }

            // template <class Iterator>
            friend bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                return (lhs < rhs);
            }

            // template <class Iterator>
            friend bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                return (lhs <= rhs);
            }
    };

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

    /* --- STD::EQUAL --- */
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    // pred: binary function that accepts two elements and return true if equal or false if not equal
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    /* --- STD::LEXICOGRAPHICAL_COMPARE --- */
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    // comp: binary function that accepts two elements of the type
    // pointed by the iterators and return true if equal or false if not equal
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2,
                                    Compare comp)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || comp(*first2, *first1))
                return false;
            else if (comp(*first1, *first2))
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    /* --- STD::PAIR --- */
    template <class T1, class T2>
    struct pair
    {
        typedef T1  first_type;
        typedef T2  second_type;

        public:

            first_type  first;
            second_type second;
        
        public:

            // CONSTRUCTORS
            pair() : first(), second() {}

            // U and V must be same types or implicitely convertible to
            // first_type and second_type
            template<class U, class V>
            pair(const pair<U, V> & pr) : first(pr.first), second(pr.second) {}

            pair(const first_type & a, const second_type & b) : first(a), second(b) {}
            
            pair & operator=(const pair & pr) {
                first = pr.first;
                second = pr.second;
                return *this;
            }

    };
    template <class T1, class T2>
    bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first==rhs.first && lhs.second==rhs.second; }
    template <class T1, class T2>
    bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs==rhs); }
    template <class T1, class T2>
    bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
    template <class T1, class T2>
    bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(rhs<lhs); }
    template <class T1, class T2>
    bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; }
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs<rhs); }

    /* --- STD::MAKE_PAIR --- */
    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (pair<T1, T2>(x, y));
    }
}

#endif