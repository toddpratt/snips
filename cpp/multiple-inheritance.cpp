
#include <iostream>

class A
{
protected:
    A();
};

A::A()
{
    std::cout << "A::A()" << std::endl;
}

class B
{
protected:
    B();
};

B::B()
{
    std::cout << "B::B()" << std::endl;
}


class Z : B, A
{
public:
    Z();
};

Z::Z()
{
    std::cout << "Z::Z()" << std::endl;
}

int main()
{
    Z *z;
    z = new Z();
    return 0;
}
