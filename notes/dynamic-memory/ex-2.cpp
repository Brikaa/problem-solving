#include <iostream>

int main()
{
  double x = 6.125;
  /*
  Floating point sizes:
  1 11 52

  .125 = 2 ^ -3
  6.125 = 110.001
        = 1.10001 * 2^2
        = 0 (00000000010 + 1023) 1000100...
        = 0 10000000001 1000100000000000000000000000000000000000000000000000
        = 0100000000011000100000000000000000000000000000000000000000000000
  */
  long long &y = *((long long *)&x);
  for (int i = 63; ~i; --i)
  {
    std::cout << ((y >> i) & 1);
  }
  std::cout << '\n';
  for (int i = 0; i < 64; ++i)
  {
    std::cout << ((y >> i) & 1);
  }
  std::cout << "\n";
  return 0;
}