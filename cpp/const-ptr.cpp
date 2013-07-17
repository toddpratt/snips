
#include <iostream>

typedef struct j {
  int i;
} j;


void show_i (const j *l) {
  std::cout << l->i << std::endl;
}

int main (void) {
  j u;
  u.i = 373;
  show_i(&u);
  return 0;
}

