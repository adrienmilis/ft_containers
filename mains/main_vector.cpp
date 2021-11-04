#include <iostream>
#include <sys/time.h>

#if STL==1
    #include <vector>
    namespace ft=std;

#else
    #include "../vector.hpp"
    #include "../utils.hpp"

#endif

template<typename T>
void    display_vector(const ft::vector<T> & v)
{
    if (v.empty())
    {
        std::cout << "Empty vector" << std::endl;
        return ;
    }
    for (size_t i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void    test_me()
{
    std::cout << "============" << std::endl;
    std::cout << "CONSTRUCTORS" << std::endl;
    std::cout << "============" << std::endl << std::endl;
    std::cout << "--- 1. Default constructor ---" << std::endl;
    ft::vector<int> v;
    display_vector(v);

    std::cout << std::endl;
    std::cout << "--- 2. Fill constructor ---" << std::endl;
    ft::vector<int> v2(5, 10);
    display_vector(v2);

    std::cout << std::endl;
    std::cout << "--- 3. Range constructor ---" << std::endl;
    int myints[] = {32, 47, 88};
    ft::vector<int> v3(myints, myints+3);
    display_vector(v3);

    ft::vector<int> ft_v0(10, 100);
    ft::vector<int>::iterator   it = ft_v0.begin();
    ft::vector<int>::iterator   ite = ft_v0.end();
    ft::vector<int>  v3_2(it, ite - 1);
    display_vector(v3_2);

    std::cout << std::endl;
    std::cout << "--- 4. Copy constructor ---" << std::endl;
    ft::vector<int> v4(v2);
    display_vector(v4);

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "OPERATOR=" << std::endl;
    std::cout << "=========" << std::endl << std::endl;
    v = v4;
    display_vector(v);

    std::cout << std::endl;
    std::cout << "========" << std::endl;
    std::cout << "CAPACITY" << std::endl;
    std::cout << "========" << std::endl << std::endl;
    std::cout << "--- 1. Size ---" << std::endl;
    std::cout << "v size (should be 5): " << v.size() << std::endl;
    std::cout << std::endl;
    std::cout << "--- 2. Max_size ---" << std::endl;
    std::cout << "v max_size: " << v.max_size() << std::endl;
    std::cout << std::endl;
    std::cout << "--- 3. Resize ---" << std::endl;
    v.resize(2, 5);
    display_vector(v);
    std::cout << "v capacity: " << v.capacity() << std::endl;
    v.resize(5, 5);
    display_vector(v);
    v.resize(10, 5);
    display_vector(v);
    std::cout << std::endl;
    std::cout << "--- 4. Capacity ---" << std::endl;
    std::cout << "v capacity: " << v.capacity() << std::endl;
    v.push_back(25);
    std::cout << "v capacity after push_back: " << v.capacity() << std::endl;
    
    std::cout << std::endl;
    std::cout << "--- 5. Empty ---" << std::endl;
    std::cout << "Before clearing: " << v4.empty() << std::endl; 
    v4.clear();
    std::cout << "After clearing: " << v4.empty() << std::endl; 
    std::cout << std::endl;
    std::cout << "--- 6. Reserve ---" << std::endl;
    display_vector(v);
    std::cout << "v capacity: " << v.capacity() << std::endl;
    v.resize(5);
    display_vector(v);
    std::cout << "v capacity (should not change): " << v.capacity() << std::endl;
    v.resize(20, 20);
    display_vector(v);
    std::cout << "v capacity: " << v.capacity() << std::endl;
    try {
        v.resize(v.max_size() + 1);
    }
    catch (const std::exception & e) {
        std::cout << "Exception" << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "ELEMENT ACCESS" << std::endl;
    std::cout << "==============" << std::endl << std::endl;

    std::cout << "--- 1. Operator[] ---" << std::endl;
    std::cout << "Full vector: ";
    display_vector(v);
    std::cout << "v[1]: " << v[1] << std::endl;
    std::cout << "v[2]: " << v[2] << std::endl;
    std::cout << "v[6]: " << v[6] << std::endl;
    v[1] = 50;
    std::cout << "v[1] changed: " << v[1] << std::endl;
    std::cout << std::endl;

    std::cout << "--- 2. at ---" << std::endl;
    const   ft::vector<int> const_v(5, 100);

    std::cout << "Const vector: ";
    display_vector(const_v);
    try {
        std::cout << "v.at(-1) - " << v.at(-1) << std::endl;
    }
    catch (const std::exception & e) {
        std::cout << "Exception" << std::endl;
    }
    try {
        std::cout << "v.at(v.size())] - " << v.at(v.size()) << std::endl;
    }
    catch (const std::exception & e) {
        std::cout << "Exception" << std::endl;
    }
    std::cout << "v.at(5): " << v.at(5) << std::endl;
    std::cout << "const_v.at(0): " << const_v.at(0) << std::endl;
    std::cout << std::endl;

    std::cout << "--- 3. front ---" << std::endl;
    std::cout << "v.front(): " << v.front() << std::endl;
    std::cout << "const_v.front(): " << const_v.front() << std::endl;
    std::cout << std::endl;

    std::cout << "--- 4. back ---" << std::endl;
    v[v.size() - 1] = 99;
    display_vector(v);
    std::cout << "v.back(): " << v.back() << std::endl;
    std::cout << "const_v.back(): " << const_v.back() << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "MODIFIERS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;
    
    std::cout << "--- 1. Assign ---" << std::endl;
    std::cout << "Before assign:" << std::endl;
    display_vector(v2);
    int myints2[] = {1, 2, 3};
    v2.assign(myints2, myints2 + 3);
    std::cout << "After assign:" << std::endl;
    display_vector(v2);
    ft::vector<int> std_v(10, 100);
    ft::vector<int>::iterator   it2 = std_v.begin();
    ft::vector<int>::iterator   ite2 = std_v.end();
    std::cout << "After assign with iterators: " << std::endl;
    v2.assign(it2, ite2 - 1);
    display_vector(v2);

    // TO DO: ASSIGN WITH OWN ITERATORS

    std::cout << std::endl;
    std::cout << "--- 2. Push_back ---" << std::endl;
    display_vector(v2);
    std::cout << "capacity: " << v2.capacity() << ", size: " << v2.size() << std::endl;
    std::cout << "push_back 5" << std::endl;
    v2.push_back(5);
    display_vector(v2);
    std::cout << "capacity: " << v2.capacity() << ", size: " << v2.size() << std::endl;
    v2.push_back(5);
    std::cout << "push_back 5" << std::endl;
    display_vector(v2);
    std::cout << "capacity: " << v2.capacity() << ", size: " << v2.size() << std::endl;

    std::cout << std::endl;
    std::cout << "--- 3. Pop_back ---" << std::endl;
    v2.pop_back();
    std::cout << "pop_back" << std::endl;
    display_vector(v2);
    v2.pop_back();
    std::cout << "pop_back" << std::endl;
    display_vector(v2);

    std::cout << std::endl;
    std::cout << "--- 4. Insert ---" << std::endl;
    std::cout << "* Single element: enough capacity *" << std::endl;
    std::cout << "v2.capacity(): " << v2.capacity() << std::endl;
    ft::vector<int>::iterator  insert_it = v2.begin() + 2;
    *insert_it = 19;
    display_vector(v2);
    v2.insert(insert_it, 25);
    display_vector(v2);
    std::cout << std::endl;
    std::cout << "* Single element: not enough capacity *" << std::endl;
    display_vector(v3);
    std::cout << "capacity: " << v3.capacity() << std::endl;
    ft::vector<int>::iterator  insert_it_v3 = v3.begin();
    v3.insert(insert_it_v3, 19);
    display_vector(v3);
    std::cout << "capacity: " << v3.capacity() << std::endl;

    std::cout << std::endl;
    std::cout << "* Fill: enough capacity *" << std::endl;
    display_vector(v2);
    std::cout << "capacity: " << v2.capacity() << std::endl;
    v2.insert(v2.begin() + 2, 3, 19);
    display_vector(v2);

    std::cout << std::endl;
    std::cout << "* Fill: not enough capacity *" << std::endl;
    display_vector(v3);
    std::cout << "capacity: " << v3.capacity() << std::endl;
    v3.insert(v3.begin() + 2, 3, 19);
    display_vector(v3);

    std::cout << std::endl;
    std::cout << "* Range: enough capacity *" << std::endl;
    display_vector(v3);
    std::cout << "capacity: " << v3.capacity() << std::endl;
    int myints3[] = {3, 3, 3, 3};
    v3.insert(v3.begin() + 1, myints3, myints3 + 3);
    display_vector(v3);

    std::cout << std::endl;
    std::cout << "* Range: not enough capacity *" << std::endl;
    display_vector(v);
    std::cout << "capacity: " << v.capacity() << std::endl;
    v.insert(v.begin() + 1, myints3, myints3 + 3);
    display_vector(v);
    
    std::cout << std::endl;
    std::cout << "--- 5. Erase ---" << std::endl;
    std::cout << "* Single element *" << std::endl;
    display_vector(v3);
    v3.erase(v3.end() - 1);
    std::cout << "  --> v3.erase(v3.end() - 1)" << std::endl;
    display_vector(v3);
    v3.erase(v3.begin() + 1);
    std::cout << "  --> v3.erase(v3.begin() + 1)" << std::endl;
    display_vector(v3);

    std::cout << std::endl;
    std::cout << "* Range *" << std::endl;
    display_vector(v3);
    v3.erase(v3.begin() + 1, v3.begin() + 3);
    std::cout << "erase from begin+1 to begin+3" << std::endl;
    display_vector(v3);
    v3.erase(v3.end() - 2, v3.end() - 1);
    std::cout << "erase from end-2 to end-1" << std::endl;
    display_vector(v3);

    std::cout << std::endl;
    std::cout << "--- 6. Swap ---" << std::endl;
    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (5,200);   // five ints with a value of 200    
    foo.swap(bar);  
    std::cout << "foo contains: ";
    display_vector(foo);
    std::cout << "bar contains: ";
    display_vector(bar);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "ITERATORS" << std::endl;
    std::cout << "=========" << std::endl << std::endl;

    int int_tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ft::vector<int> iterated_vector(int_tab, int_tab + 10);
    display_vector(iterated_vector);
    ft::vector<int>::iterator   ft_it = iterated_vector.begin();
    ft::vector<int>::iterator   ft_ite = iterated_vector.end();

    std::cout << "begin: " << *ft_it << std::endl;
    std::cout << "end: " << *(ft_ite - 1) << std::endl;

    std::cout << "--- Default constructor ---" << std::endl;
    // uninitialized, only good option is to = it to a valid iterator.
    ft::vector<int>::iterator   default_it;
    std::cout << "--- Copy constructor ---" << std::endl;
    ft::vector<int>::iterator   copy_it(ft_it);
    std::cout << "copy: same as begin: " << *copy_it << std::endl;
    std::cout << "--- Copy assignation ---" << std::endl;
    default_it = copy_it;
    std::cout << "assignation: now same as begin and copy: " << *default_it << std::endl;
    std::cout << "--- == and != operators ---" << std::endl;
    std::cout << "copy_it == default_it ? " << (copy_it == default_it) << std::endl;
    std::cout << "copy_it != default_it ? " << (copy_it != default_it) << std::endl;
    std::cout << "--- can be dereferenced with * ---" << std::endl;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    std::cout << "--- can be dereferenced and assigned with * ---" << std::endl;
    *(copy_it) = 3;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    *(copy_it) = 0;
    std::cout << "--- can be pre-incremented ---" << std::endl;
    std::cout << "*(copy_it): " << *(++copy_it) << std::endl;
    std::cout << "--- can be post incremented ---" << std::endl;
    std::cout << "*(copy_it): " << *(copy_it++) << std::endl;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    std::cout << "--- can be pre decremented ---" << std::endl;
    std::cout << "*(copy_it): " << *(--copy_it) << std::endl;
    std::cout << "--- can be pre decremented ---" << std::endl;
    std::cout << "*(copy_it): " << *(copy_it--) << std::endl;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    std::cout << "--- adding iterator and integer value ---" << std::endl;
    std::cout << *(copy_it + 2) << std::endl;
    std::cout << "--- substracting iterator and integer value ---" << std::endl;
    std::cout << *(copy_it + 5 - 2) << std::endl;
    std::cout << "--- substracting two iterators (gives distance) ---" << std::endl;
    ++ft_it;    // ft_it is now on index 1
    ++copy_it;
    ++copy_it; // copy_it is now on index 2
    std::cout << copy_it - ft_it << std::endl;
    std::cout << "--- relational operators <, >, <=, >= ---" << std::endl;
    std::cout << "copy_it > ft_it ? " << (copy_it > ft_it) << std::endl;
    std::cout << "copy_it < ft_it ? " << (copy_it < ft_it) << std::endl;
    std::cout << "copy_it >= ft_it ? " << (copy_it >= ft_it) << std::endl;
    std::cout << "copy_it < ft_it ? " << (copy_it <= ft_it) << std::endl;
    std::cout << "--- += and -= ---" << std::endl;
    copy_it += 3;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    copy_it -= 3;
    std::cout << "*(copy_it): " << *(copy_it) << std::endl;
    std::cout << "--- [] operator ---" << std::endl;
    std::cout << "copy_it[3]: " << copy_it[3] << std::endl;

    std::cout << std::endl;
    std::cout << "=================" << std::endl;
    std::cout << "REVERSE_ITERATORS" << std::endl;
    std::cout << "=================" << std::endl << std::endl;

    display_vector(iterated_vector);
    ft::vector<int>::reverse_iterator   rev_it = iterated_vector.rbegin();
    ft::vector<int>::reverse_iterator   rev_ite = iterated_vector.rend();

    --rev_ite;
    std::cout << "--- operator* ---" << std::endl;
    std::cout << "*(rev_it): " << *rev_it << std::endl;
    std::cout << "*(rev_ite): " << *(rev_ite) << std::endl;

    std::cout << "--- operator+ ---" << std::endl;
    std::cout << "*(rev_it + 2): " << *(rev_it + 2) << std::endl;

    std::cout << "--- operator++ ---" << std::endl;
    std::cout << "(*(++rev_it)): " << (*(++rev_it)) << std::endl;
    std::cout << "(*(rev_it++)): " << (*(rev_it++)) << std::endl;
    std::cout << "(*rev_it): " << (*rev_it) << std::endl;

    std::cout << "--- operator+= ---" << std::endl;
    rev_it += 3;
    std::cout << "rev_it += 3 --> *(rev_it): " << *(rev_it) << std::endl;

    std::cout << "--- operator- ---" << std::endl;
    std::cout << "*(rev_it - 3): " << *(rev_it - 3) << std::endl;

    std::cout << "--- operator-- ---" << std::endl;
    std::cout << "(*(--rev_it)): " << (*(--rev_it)) << std::endl;
    std::cout << "(*(rev_it--)): " << (*(rev_it--)) << std::endl;
    std::cout << "(*rev_it): " << (*rev_it) << std::endl;

    std::cout << "--- operator-= ---" << std::endl;
    rev_it -= 3;
    std::cout << "rev_it -= 3 --> *(rev_it): " << *(rev_it) << std::endl;

    std::cout << "--- operator[] ---" << std::endl;
    std::cout << "rev_it[3]: " << rev_it[3] << std::endl;

    std::cout << "*rev_ite: " << *rev_ite << std::endl;
    std::cout << "rev_ite[-3]: " << rev_ite[-3] << std::endl;

    std::cout << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "RELATIONAL OPERATORS" << std::endl;
    std::cout << "====================" << std::endl << std::endl;

    ft::vector<int> foo1 (3,100);   // three ints with a value of 100
    ft::vector<int> bar2 (2,200);   // two ints with a value of 200

    if (foo1==bar2) std::cout << "foo and bar are equal\n";
    if (foo1!=bar2) std::cout << "foo and bar are not equal\n";
    if (foo1< bar2) std::cout << "foo is less than bar\n";
    if (foo1> bar2) std::cout << "foo is greater than bar\n";
    if (foo1<=bar2) std::cout << "foo is less than or equal to bar\n";
    if (foo1>=bar2) std::cout << "foo is greater than or equal to bar\n";

    ft::vector<int> big_vector(1000, 1000);
    ft::vector<int> medium_vector(500, 500);

    big_vector.insert(big_vector.begin() + 500, medium_vector.begin(), medium_vector.end());
    big_vector.erase(big_vector.begin() + 10, big_vector.end() - 200);

}

void test_cppcom()
{
    std::cout << "----------CONSTRUCTORS-----------" << std::endl;
    {
    	// constructors used in the same order as described above:
        ft::vector<int> first;                                // empty vector of ints
        ft::vector<int> second (4,100);                       // four ints with value 100
        ft::vector<int> third (second.begin(),second.end());  // iterating through second
        ft::vector<int> fourth (second);                       // a copy of third

        // the iterator constructor can also be used to construct from arrays:
        int myints[] = {16,2,77,29};

        ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        std::cout << "The contents of fifth are:";
        for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "The contents of second are:";
        for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "The contents of third are:";
        for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    std::cout << "----------OPERATOR==-----------" << std::endl;
    {
    	ft::vector<int> foo (3,0);
        ft::vector<int> bar (5,0);

        bar = foo;
        foo = ft::vector<int>();

        std::cout << "Size of foo: " << int(foo.size()) << '\n';
        std::cout << "Size of bar: " << int(bar.size()) << '\n';
    }


    std::cout << "----------REND_RBEGIN-----------" << std::endl;
    {
    	ft::vector<int> myvector (5);  // 5 default-constructed ints

        int i=0;

        ft::vector<int>::reverse_iterator rit = myvector.rbegin();
        for (; rit!= myvector.rend(); ++rit)
          *rit = ++i;

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
    }

    std::cout << "----------SIZE-----------" << std::endl;
    {  
        ft::vector<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<10; i++) myints.push_back(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.insert (myints.end(),10,100);
        std::cout << "2. size: " << myints.size() << '\n';

        myints.pop_back();
        std::cout << "3. size: " << myints.size() << '\n';
    }

    std::cout << "----------PUSH__BACK-----------" << std::endl;
    {
        ft::vector<int> myvector;

        for (int i = 19; i <= 42; i++)
            myvector.push_back (i);

        std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
        std::cout << "vector contains:";
        for (ft::vector<int>::iterator it=myvector.begin(); it != myvector.end() ; it++)
        	std::cout << " " << *it;
        std::cout << std::endl;
    }

    std::cout << "----------INSERT-----------" << std::endl;
    {
        ft::vector<int> myvector (3,100);
        ft::vector<int>::iterator it;

        it = myvector.begin();
        it = myvector.insert ( it , 200 );
        myvector.insert (it,2,300);

        // "it" no longer valid, get a new one:
        it = myvector.begin();

        ft::vector<int> anothervector (2,400);
        myvector.insert(it+2,anothervector.begin(),anothervector.end());

        ft::vector<int> vec;
        vec.push_back(19);
        vec.push_back(21);
        vec.push_back(42);
        myvector.insert (myvector.begin(), vec.begin(), vec.end()-1);

        std::cout << "myvector contains:";
        for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
        std::cout << '\n';
    }

    std::cout << "----------IT_OP[]_OP+_OP-_OP+=_OP-=()-----------" << std::endl;
    {
    	ft::vector<int>v1;
    	v1.push_back(1); 
    	v1.push_back(2); 
    	v1.push_back(3); 
    	v1.push_back(4); 
    	v1.push_back(5); 
        int i; 
    
    	ft::vector<int>::iterator itx = v1.begin();
        for(i=0;i<5;++i) 
            std::cout << itx[i] << " "; 
    	std::cout << std::endl;
    	ft::vector<int>::iterator it = v1.begin() + 1;
    	std::cout << it[-1] << std::endl;
    	it = v1.end() - 1;
    	std::cout << it[-1] << std::endl;
    	it -= 4;
    	std::cout << it[0] << std::endl;
    	it += 2;
    	std::cout << it[0] << std::endl;

    }
    std::cout << "----------RESIZE-----------" << std::endl;
    { 
        ft::vector<int> myvector;
        // set some initial content:
        for (int i=1;i<10;i++) myvector.push_back(i);

        myvector.resize(5);
        myvector.resize(8,100);
        myvector.resize(12);

        std::cout << "myvector contains:";
        for (size_t i=0;i<myvector.size();i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }		

    std::cout << "----------OP[]-----------" << std::endl;
    {
    	ft::vector<int> myvector (10);   // 10 zero-initialized elements

    
        size_t sz = myvector.size();

        // assign some values:
        for (unsigned i=0; i<sz; i++) myvector[i]=i;

        // reverse vector using operator[]:
        for (unsigned i=0; i<sz/2; i++)
        {
          int temp;
          temp = myvector[sz-1-i];
          myvector[sz-1-i]=myvector[i];
          myvector[i]=temp;
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<sz; i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }

    std::cout << "----------EMPTY-----------" << std::endl;
    {
        ft::vector<int> myvector;
        int sum (0);

        for (int i=1;i<=10;i++) myvector.push_back(i);

        while (!myvector.empty())
        {
           sum += myvector.back();
           myvector.pop_back();
        }

        std::cout << "total: " << sum << '\n';
    }

    std::cout << "----------FRONT-----------" << std::endl;
    {
    	ft::vector<int> myvector;

        myvector.push_back(78);
        myvector.push_back(16);

        // now front equals 78, and back 16

        myvector.front() -= myvector.back();

        std::cout << "myvector.front() is now " << myvector.front() << '\n';

    }

    std::cout << "----------RESERVE-----------" << std::endl;
    {
        ft::vector<int> foo;
        foo.reserve(19);
        std::cout << foo.capacity() << std::endl;
        foo.reserve(42);
        std::cout << foo.capacity() << std::endl;
    }

    std::cout << "----------AT-----------" << std::endl;
    {
        ft::vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
          myvector.at(i)=i;

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector.at(i);
        std::cout << '\n';
    
    }

    std::cout << "----------ASSIGN-----------" << std::endl;
    {
        ft::vector<int> first;
        ft::vector<int> second;
        ft::vector<int> third;

        first.assign (7,100);             // 7 ints with a value of 100

        ft::vector<int>::iterator it;
        it=first.begin()+1;

        second.assign (it,first.end()-1); // the 5 central values of first

        int myints[] = {1776,7,4};
        third.assign (myints,myints+3);   // assigning from array.

        std::cout << "Size of first: " << int (first.size()) << '\n';
        std::cout << "Size of second: " << int (second.size()) << '\n';
        std::cout << "Size of third: " << int (third.size()) << '\n';
    }

    std::cout << "----------SWAP-----------" << std::endl;
    {
    	ft::vector<int> foo (3,100);   // three ints with a value of 100
        ft::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (unsigned i=0; i<foo.size(); i++)
          std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i=0; i<bar.size(); i++)
          std::cout << ' ' << bar[i];
        std::cout << '\n';
    }

    std::cout << "----------NMO_REL_OP-----------" << std::endl;
    {
        ft::vector<int> foo (3,100);   // three ints with a value of 100
        ft::vector<int> bar (2,200);   // two ints with a value of 200

        if (foo==bar) std::cout << "foo and bar are equal\n";
        if (foo!=bar) std::cout << "foo and bar are not equal\n";
        if (foo< bar) std::cout << "foo is less than bar\n";
        if (foo> bar) std::cout << "foo is greater than bar\n";
        if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
        if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

    }

    std::cout << "----------NMO_SWAP-----------" << std::endl;
    {
        ft::vector<int> foo (3,100);   // three ints with a value of 100
        ft::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "bar contains:";
        for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
    }
}

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
    int idx;
    char buff[BUFFER_SIZE];
};
#define COUNT (MAX_RAM / (int)sizeof(Buffer))

void    test42()
{
    srand(54554);
    ft::vector<int> vector_int;

    for (int i = 0; i < COUNT; i++)
    {
        vector_int.push_back(rand());
    }
    for (int i = 0; i < COUNT; i++)
    {
        const int idx = rand() % COUNT;
        vector_int[idx] = 5;
    }
    std::cout << vector_int[1523]<< std::endl;
}

int main(void)
{
    struct timeval  time;
    gettimeofday(&time, NULL);
    long totalTime = (time.tv_sec * 1000000) + (time.tv_usec);

    test_me();
    test_cppcom();
    test42();

    gettimeofday(&time, NULL);
    totalTime = ((time.tv_sec * 1000000) + (time.tv_usec) - totalTime);
    std::cout << totalTime << std::endl;
    return (0);
}