#include <iostream>

int main() {
  int x = 4, *y = &x, &z = x;
  *y = 8;
  std::cout << z << '\n';
  return 0;
}
