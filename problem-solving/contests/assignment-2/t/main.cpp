#include <cstdio>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;
const ui N = 305;
long long divisors[N];

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    ull n;
    scanf("%llu", &n);
    for (ui i = 0; i < n; ++i)
      scanf("%lld", divisors + i);
    std::sort(divisors, divisors + n);
    long long number = divisors[0] * divisors[n - 1];
    for (ui i = 1; i <= n / 2 && number != -1; ++i)
      if (divisors[i] * divisors[n - i - 1] != number)
        number = -1;
    ull no_divisors = 0;
    for (long long i = 2; i * i <= number; ++i)
    {
      if (number % i == 0)
      {
        ++no_divisors;
        if (i * i != number)
          ++no_divisors;
      }
    }
    if (no_divisors != n)
      number = -1;
    printf("%lld\n", number);
  }
  return 0;
}
