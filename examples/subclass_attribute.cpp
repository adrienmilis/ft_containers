#include <iostream>

class A
{
    private:

        int i;

    struct B
    {
        void    print() {
            std::cout << i << std::endl;
        }
    };
};

int main()
{
    A::B    test;

    test.print();
    return (0);
}