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
    // template <class T> struct is_integral;
    // struct is_integral<>
} 

#endif