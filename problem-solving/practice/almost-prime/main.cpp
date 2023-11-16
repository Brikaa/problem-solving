/*

*/
#include <stdio.h>
#include <unordered_set>

int main()
{
  int n;
  scanf("%d", &n);
  int almost_primes = 0;
  for (int j = 6; j <= n; ++j)
  {
    int i = 2;
    int n = j;
    std::unordered_set<int> factors;
    while (i * i <= n)
    {
      if (n % i == 0)
      {
        factors.insert(i);
        n /= i;
      }
      else
      {
        ++i;
      }
    }
    if (n != 1)
      factors.insert(n);
    almost_primes += factors.size() == 2;
  }
  printf("%d\n", almost_primes);
  return 0;
}
