// Requires:
// export CPPFLAGS=-std=c++11
//
#include <iostream>
#include <functional>

int add4(int n) {
  return n + 4;
}

int add7(int n) {
  return n + 7;
}

void cout5plus(std::function<int(int n)> adder) {
  std::cout << "Adding some number to 5: " << adder(5) << std::endl;
}

// A class for demonstrating passing member functions.
class Foo
{

public:
  void do_test() {
    print105plusn(std::bind(&Foo::add2, this, std::placeholders::_1));
    print105plusn(std::bind(&Foo::add9, this, std::placeholders::_1));
  }

private:
  int add2(int n) {
    return n + 2;
  }

  int add9(int n) {
    return n + 9;
  }

  void print105plusn(std::function<int(int n)> adder) {
    std::cout << "Adding some number to 5: " << adder(105) << std::endl;
  }
};

int main(int argc, const char *argv[])
{
  cout5plus(&add4);
  cout5plus(&add7);

  // Throw in a lambda example.
  cout5plus(
      [] (int n) {
        return n + 11;
      });

  // Example of passing methods around.
  Foo foo;
  foo.do_test();

  return 0;
}
