#include <iostream>

const int N = 2e5 + 5;
char str[N];
int prefix[N];
int main()
{
  /*
    #..###
    010110
    001123

    #.
    00
  */
  std::cin >> str;
  prefix[0] = 0;
  for (int i = 1; str[i]; ++i)
  {
    prefix[i] = prefix[i - 1] + (str[i - 1] == str[i]);
  }
  int m;
  std::cin >> m;
  while (m--)
  {
    // needed = p[l + 1] + p[l + 2] +... + p[r]
    // p[l] = p[0] + p[1] + ... + p[l]
    // p[r] = p[0] + p[1] + ... + p[l - 1] + p[l] + p[l + 1] + ... + p[r]
    // p[r] - p[l] = p[l + 1] + p[l + 2] + ... + p[r]
    int l, r;
    std::cin >> l >> r;
    std::cout << prefix[r - 1] - prefix[l - 1] << '\n';
  }
  return 0;
}
