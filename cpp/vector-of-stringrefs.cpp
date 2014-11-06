
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::endl;
using std::string;

int main (int argc, char *argv[]) {
    vector<string *> v;
    for (int i=1; i<argc; i++) {
        string *argument = new string(argv[i]);
        v.push_back(argument);
    }
}

