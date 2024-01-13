/*
prime factors of least common multiple of arr
*/
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>

const int N = 107;
long long numbers[N];

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
  {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%lld", numbers + i);
    std::unordered_set<long long> prime_factors;
    for (int i = 0; i < n; ++i)
    {
      long long number = numbers[i];
      long long m = 2;
      while (m * m <= number)
      {
        if (number % m == 0)
        {
          prime_factors.insert(m);
          number /= m;
        }
        else
          ++m;
      }
      if (number != 1)
        prime_factors.insert(number);
    }
    std::vector<long long> v;
    v.insert(v.end(), prime_factors.begin(), prime_factors.end());
    std::sort(v.begin(), v.end());
    printf("Case #%d: %d\n", t, (int)prime_factors.size());
    for (auto p : v)
      printf("%lld\n", p);
  }
  return 0;
}
