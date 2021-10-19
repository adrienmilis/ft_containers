#include <iostream>
#include "../vector.hpp"
#include <sys/time.h>

int	get_elapsed(struct timeval begin, struct timeval end)   // nanoseconds
{
	int	elapsed;

	elapsed = (end.tv_sec - begin.tv_sec) * 1000000.0
		+ (end.tv_usec - begin.tv_usec);
	return (elapsed);
}

void func(void)
{
    ft::vector<int> v;
    ft::vector<int> v2(5, 10);
    int myints[] = {32, 47, 88};
    ft::vector<int> v3(myints, myints+3);

    ft::vector<int> ft_v0(10, 100);
    ft::vector<int>::iterator   it = ft_v0.begin();
    ft::vector<int>::iterator   ite = ft_v0.end();
    ft::vector<int>  v3_2(it, ite - 1);

    ft::vector<int> v4(v2);
    v = v4;
    v.resize(2, 5);
    v.resize(5, 5);
    v.resize(10, 5);
    v.push_back(25);
    v4.clear();
    v.resize(5);
    v.resize(20, 20);
    try {
        v.resize(v.max_size() + 1);
    }
    catch (const std::exception & e) {
    }
    
    v[1] = 50;
    const   ft::vector<int> const_v(5, 100);

    try {
    }
    catch (const std::exception & e) {
    }
    try {
    }
    catch (const std::exception & e) {
    }
    v[v.size() - 1] = 99;
    int myints2[] = {1, 2, 3};
    v2.assign(myints2, myints2 + 3);
    ft::vector<int> std_v(10, 100);
    ft::vector<int>::iterator   it2 = std_v.begin();
    ft::vector<int>::iterator   ite2 = std_v.end();
    v2.assign(it2, ite2 - 1);
    v2.push_back(5);
    v2.push_back(5);
    v2.pop_back();
    v2.pop_back();
    ft::vector<int>::iterator  insert_it = v2.begin() + 2;
    *insert_it = 19;
    v2.insert(insert_it, 25);
    ft::vector<int>::iterator  insert_it_v3 = v3.begin();
    v3.insert(insert_it_v3, 19);
    v2.insert(v2.begin() + 2, 3, 19);
    v3.insert(v3.begin() + 2, 3, 19);
    int myints3[] = {3, 3, 3, 3};
    v3.insert(v3.begin() + 1, myints3, myints3 + 3);
    v.insert(v.begin() + 1, myints3, myints3 + 3);
    v3.erase(v3.end() - 1);
    v3.erase(v3.begin() + 1);
    v3.erase(v3.begin() + 1, v3.begin() + 3);
    v3.erase(v3.end() - 2, v3.end() - 1);
    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (5,200);   // five ints with a value of 200    
    foo.swap(bar);  

    int int_tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ft::vector<int> iterated_vector(int_tab, int_tab + 10);
    ft::vector<int>::iterator   ft_it = iterated_vector.begin();
    ft::vector<int>::iterator   ft_ite = iterated_vector.end();

    ft::vector<int>::iterator   default_it;
    ft::vector<int>::iterator   copy_it(ft_it);
    default_it = copy_it;
    *(copy_it) = 3;
    *(copy_it) = 0;
    ++ft_it;    // ft_it is now on index 1
    ++copy_it;
    ++copy_it; // copy_it is now on index 2
    copy_it += 3;
    copy_it -= 3;
    ft::vector<int>::reverse_iterator   rev_it = iterated_vector.rbegin();
    ft::vector<int>::reverse_iterator   rev_ite = iterated_vector.rend();
    rev_it += 3;
    rev_it -= 3;
    ft::vector<int> foo1 (3,100);   // three ints with a value of 100
    ft::vector<int> bar2 (2,200);   // two ints with a value of 200

    ft::vector<int> big_vector(1000, 1000);
    ft::vector<int> medium_vector(500, 500);

    big_vector.insert(big_vector.begin() + 500, medium_vector.begin(), medium_vector.end());
    big_vector.erase(big_vector.begin() + 10, big_vector.end() - 200);
    
}

int main()
{
    struct timeval begin;
    struct timeval end;

    gettimeofday(&begin, NULL);
    for (int i=0 ; i<100; i++)
        func();
    gettimeofday(&end, NULL);
    std::cout << get_elapsed(begin, end) << std::endl;
    return (0);
}