/*
When a new element is added to ans remove its non divisors from max divisors
96 88 3 2
99 88 2 3
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

typedef unsigned int uint;
// typedef unsigned long long ulong;
const uint N = 1e3 + 5;
long long numbers[N];

int main()
{
  uint t;
  scanf("%u", &t);
  while (t--)
  {
    uint n;
    scanf("%u", &n);
    for (uint i = 0; i < n; ++i)
      scanf("%lld", numbers + i);
    long long max = 0;
    for (uint i = 0; i < n; ++i)
    {
      if (std::abs(numbers[i]) > std::abs(max))
        max = numbers[i];
    }
    std::vector<long long> max_divisors;
    for (long long i = 1; i * i <= std::abs(max); ++i)
    {
      if (max % i == 0)
      {
        max_divisors.push_back(i);
        max_divisors.push_back(std::abs(max) / i);
      }
    }
    if (max == 0)
      max_divisors.push_back(1);
    std::sort(max_divisors.begin(), max_divisors.end(), std::greater());
    std::vector<long long> ans;
    std::vector<bool> index_is_taken(n, false);
    int first_non_zero_index = -1;
    for (auto divisor : max_divisors)
    {
      if (divisor == -1)
        continue;
      for (uint i = 0; i < n; ++i)
      {
        if (!index_is_taken[i] && numbers[i] % divisor == 0)
        {
          ans.push_back(numbers[i]);
          index_is_taken[i] = true;
          if (first_non_zero_index == -1 && numbers[i] != 0)
            first_non_zero_index = ans.size() - 1;
          // remove non divisors from max divisors
          for (uint j = 0; j < max_divisors.size(); ++j)
          {
            if (numbers[i] % max_divisors[j] != 0)
              max_divisors[j] = -1;
          }
        }
      }
    }
    if (first_non_zero_index != -1 && first_non_zero_index > 0)
    {
      ans[0] = ans[first_non_zero_index];
      ans[first_non_zero_index] = 0;
    }
    for (uint i = 0; i < ans.size(); ++i)
      printf("%lld%c", ans[i], " \n"[i == ans.size() - 1]);
    assert(ans.size() == n);
  }
  return 0;
}
