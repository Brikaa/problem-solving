#include <cmath>
#include <iostream>

int main()
{
  long long n;
  while (true)
  {
    std::cin >> n;
    if (n == 0)
      break;

    for (long long i = 31; i >= 1; i--)
    {
      long long x = std::round(std::pow(std::abs(n), 1.0 / i));
      if (std::pow(x, i) == std::abs(n) && !(i % 2 == 0 && n < 0))
      {
        std::cout << i << '\n';
        break;
      }
    }
  }
  return 0;
}
