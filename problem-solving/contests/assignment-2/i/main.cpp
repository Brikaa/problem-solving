/*
prime factors of least common multiple of arr
*/
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
  {
    int n;
    scanf("%d", &n);
    long long multiple = 1;
    while (n--)
    {
      long long number;
      scanf("%lld", &number);
      multiple *= number;
    }
    std::unordered_set<long long> prime_factors;
    long long m = 2;
    while (m * m <= multiple)
    {
      if (multiple % m == 0)
      {
        prime_factors.insert(m);
        multiple /= m;
      }
      else
        ++m;
    }
    if (multiple != 1)
      prime_factors.insert(multiple);
    printf("Case #%d: %d\n", t, (int)prime_factors.size());
    std::vector<long long> v;
    v.insert(v.end(), prime_factors.begin(), prime_factors.end());
    std::sort(v.begin(), v.end());
    for (auto p : v)
      printf("%lld\n", p);
  }
}
