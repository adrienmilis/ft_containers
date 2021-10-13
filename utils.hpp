#ifndef UTILS_HPP
# define UTILS_HPP

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
    // 1. enable_if
    template<bool Cond, class T = void>
    struct enable_if {};
    
    template<class T>
    struct enable_if<true, T>
    { typedef T type; };

    // 2. is_integral
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



} 

#endif