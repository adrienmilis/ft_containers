#include <iostream>
#include <sys/time.h>

#if STL==1
    #include <stack>
    #include <vector>
    #include <list>
    namespace ft=std;

#else
    #include "../stack.hpp"
    #include "../utils.hpp"
    #include "../vector.hpp"
    #include <list>

#endif

void test_stack_cppcom()
{
    std::cout << "----------CONSTRUCTORS-----------" << std::endl;
    {
    	ft::vector<int> myvector (2,200);        // vector with 2 elements
        ft::stack<int> first;                    // empty stack
        ft::stack<int,ft::vector<int> > third;  // empty stack using vector
        ft::stack<int,ft::vector<int> > fourth (myvector);
        std::cout << "size of first: " << first.size() << std::endl;
        std::cout << "size of third: " << third.size() << std::endl;
        std::cout << "size of fourth: " << fourth.size() << std::endl;
    }
    std::cout << "----------SIZE-----------" << std::endl;
    {
    	ft::stack<int> myints;
        std::cout << "0. size: " << myints.size() << std::endl;

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << std::endl;

        myints.pop();
        std::cout << "2. size: " << myints.size() << std::endl;
    }
    std::cout << "----------EMPTY-----------" << std::endl;
    {
    	ft::stack<int> mystack;
        int sum (0);

        for (int i=1;i<=1000000;i++) mystack.push(i);

        while (!mystack.empty())
        {
           sum += mystack.top();
           mystack.pop();
        }

        std::cout << "total: " << sum << std::endl;
    }
    std::cout << "----------TOP-----------" << std::endl;
    {
        ft::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << std::endl;
    }
    std::cout << "----------PUSH_POP-----------" << std::endl;
    {
    	ft::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
           std::cout << ' ' << mystack.top();
           mystack.pop();
        }
        std::cout << std::endl;

    }
    std::cout << "------------REL_OPERATOR--------" << std::endl;
    {
        std::list<int> a;
        a.push_back(10);
        a.push_back(20);
        a.push_back(30);
        std::list<int> b;
        b.push_back(10);
        b.push_back(20);
        b.push_back(30);
        std::list<int> c;
        c.push_back(30);
        c.push_back(20);
        c.push_back(10);
        ft::stack<int, std::list<int> > d(a);
        ft::stack<int, std::list<int> > e(b);
        ft::stack<int, std::list<int> > f(c);
        if (d==e) std::cout << "a and b are equal" << std::endl;
        if (e!=f) std::cout << "b and c are not equal" << std::endl;
        if (e<f) std::cout << "b is less than c" << std::endl;
        if (f>e) std::cout << "c is greater than b" << std::endl;
        if (d<=e) std::cout << "a is less than or equal to b" << std::endl;
        if (d>=e) std::cout << "a is greater than or equal to b" << std::endl;
    }
}

int main(void)
{
    struct timeval  time;
    gettimeofday(&time, NULL);
    long totalTime = (time.tv_sec * 1000000) + (time.tv_usec);

    test_stack_cppcom();

    gettimeofday(&time, NULL);
    totalTime = ((time.tv_sec * 1000000) + (time.tv_usec) - totalTime);
    std::cout << totalTime << std::endl;
    return (0);
}