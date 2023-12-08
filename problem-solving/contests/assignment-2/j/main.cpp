/*
2 2 2
3 3 3
5 5 5 7

2 2
3 3 3 3
2*3*3 * 2*3*3

if the value is negative and the exponent is even, try to find a smaller exponent that is odd
*/
#include <cstdio>
#include <vector>

int main()
{
  while (true)
  {
    long long n;
    scanf("%lld", &n);
    if (n == 0)
      break;
    bool negative = false;
    if (n < 0)
    {
      negative = true;
      n = -n;
    }
    std::vector<int> exponents;
    long long m = 2;
    bool new_exp = true;
    while (m * m <= n)
    {
      if (n % m == 0)
      {
        if (new_exp)
          exponents.push_back(1);
        else
          ++exponents[exponents.size() - 1];
        n /= m;
        new_exp = false;
      }
      else
      {
        ++m;
        new_exp = true;
      }
    }
    if (n > 1)
    {
      if (new_exp)
        exponents.push_back(1);
      else
        ++exponents[exponents.size() - 1];
    }
    int exponent = exponents[0];
    bool ok = true;
    int s = exponents.size();
    for (int i = 1; i < s && ok; ++i)
      if (exponents[i] != exponent)
        ok = false;
    if (!ok)
      printf("1\n");
    else
    {
      if (negative && exponent % 2 == 0)
        while (exponent % 2 == 0)
          exponent /= 2;
      printf("%d\n", exponent);
    }
  }
  return 0;
}
