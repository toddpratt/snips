
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Base {
    public:
        Base(void);
        ~Base(void);
        Base(string name);
};

Base::Base(void) {
    cout << "Base::Base(void)" << endl;
}

Base::Base(string name) {
    cout << "Base::Base(string name)" << endl;
}

Base::~Base(void) {
    cout << "Base::~Base(void)" << endl;
}

class Derived : Base {
    public:
        ~Derived(void);
        Derived(string name);
};

Derived::Derived(string name) {
    cout << "Derived::Derived(string name)" << endl;
}

Derived::~Derived(void) {
    cout << "Derived::~Derived(void)" << endl;
}

int main(void) {
    Base *b;
    Derived *d;

    cout << "---constructing instance b of Base:" << endl;
    b = new Base("Base");
    cout << "---ok" << endl;

    cout << "---constructing instance d of Derived:" << endl;
    d = new Derived("Derived");
    cout << "---ok" << endl;

    cout << "---deleting b..." << endl;
    delete b;
    cout << "---ok" << endl;

    cout << "---deleting d..." << endl;
    delete d;
    cout << "---ok" << endl;

    return 0;
}

