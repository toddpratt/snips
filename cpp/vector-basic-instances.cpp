#include <iostream>
#include <vector>

using namespace std;

class Junk {

private:
    int x;

public:
    Junk();
    void set_x(int);
    void print_x();

};

Junk::Junk() {
}

void Junk::set_x(int new_x) {
    x = new_x;
}

void Junk::print_x() {
    cout << "x = " << x << endl;
}

int main() {
    Junk* njunk;
    vector<Junk> stuff;
    int i;
    for(i=0; i<10; i++) {
        njunk = new Junk();
        njunk->set_x(i*-11);
        stuff.push_back(*njunk);
        stuff[i].print_x();
    }
    while(stuff.size()) {
        stuff.back().print_x();
        stuff.pop_back();
    }
    return 0;
}


