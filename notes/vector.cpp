#include <iostream>
#include <vector>

int main() {
  std::vector v = {3, 2, 5, 4};
  std::cout << v[0] << '\n';
  for (int i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  std::vector<int>::iterator b = v.begin();
  while (b != v.end()) {
    std::cout << *b << ' ';
    b++;
  }
  std::cout << '\n';
  for (std::vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i) {
    std::cout << *i << ' ';
  }
  std::cout << '\n';
  return 0;
}
