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

int main(int argc, const char *argv[])
{
  cout5plus(&add4);
  cout5plus(&add7);
  cout5plus(
      [] (int n) {
        return n + 11;
      });
  return 0;
}
