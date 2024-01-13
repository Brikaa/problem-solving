/*
- The prime factors of N! = prime factors of 1 * prime factors of 2 * ... * prime factors of N
                          = prime factors of 1..N with exponents of common prime factors added

*/
#include <unordered_map>
#include <stdio.h>

int main()
{
  std::unordered_map<int, int> factors;
  int N;
  scanf("%d", &N);
  for (int j = 2; j <= N; ++j)
  {
    int i = 2;
    int n = j;
    while (i * i <= n)
    {
      if (n % i == 0)
      {
        factors[i]++;
        n /= i;
      }
      else
      {
        ++i;
      }
    }
    if (n != 1)
      factors[n]++;
  }
  int m = 1e9 + 7;
  long long divisors = 1;
  for (auto f_pair : factors)
    divisors = (divisors * (f_pair.second + 1)) % m;
  int divisors_int = divisors % m;
  printf("%d\n", divisors_int);
}
