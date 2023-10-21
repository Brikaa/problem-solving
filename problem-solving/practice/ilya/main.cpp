#include <iostream>

const int N = 1e5;
char str[N];
int prefix[N];
int main() {
  /*
    ###..###
    01223345
  */
  std::cin >> str;
  prefix[0] = 0;
  for (int i = 1; str[i]; ++i) {
    prefix[i] = prefix[i - 1] + (str[i - 1] == str[i]);
  }
  int m;
  std::cin >> m;
  while (m--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << prefix[r - 1] - prefix[l - 1] << '\n';
  }
  return 0;
}
