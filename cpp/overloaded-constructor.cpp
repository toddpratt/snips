
#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    Person();
    Person(string newname);
    void next();
};

Person::Person()
{
    name = string("");
}

Person::Person(string newname)
{
    name = newname;
}

int main()
{
    Person p[3];
    return 0;
}

