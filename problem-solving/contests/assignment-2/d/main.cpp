/*
1 2
2 3
3 4
2 5

1 2
1 3/2
1 4/3
1 5/2

1 10

4 5
2 3
7 8
9 11
1 3

*/
#include <cstdio>

long long get_gcd(long long a, long long b)
{
  if (a == 0)
    return b;
  return get_gcd(b % a, a);
}

int main()
{
  while (true)
  {
    int n;
    scanf("%d", &n);
    if (n == -1)
      break;
    long long numerator = 1;
    long long denominator = 1;
    while (--n)
    {
      long long a, b;
      scanf("%lld%lld", &a, &b);
      numerator *= b;
      denominator *= a;
      if (numerator > 1e14)
      {
        long long gcd = get_gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
      }
    }
    long long gcd = get_gcd(numerator, denominator);
    printf("%lld %lld\n", denominator / gcd, numerator / gcd);
  }
  return 0;
}
