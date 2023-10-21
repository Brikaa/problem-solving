#include <iostream>

const int N = 2e5 + 3;
char program[N];
int sum_prefix[N];
int max_prefix[N];
int min_prefix[N];

int main()
{
  /*
    - Number of distinct values = max(values) - min(values)

    |         ----------       |
              ^        ^
              l        r
    - For second part
      - new_sum_start = sum_prefix[l - 1] + arr[r + 1]
      - sum_start_delta = new_sum_start - sum_prefix[r + 1]
      - new_max = max_prefix[n - 1] + sum_start_delta
      - new_min = min_prefix[n - 1] + sum_start_delta
    - number of distinct values = max(max_prefix[l - 1], new_max) - min(min_prefix[l - 1], new_min)
    - Need:
      - sum_prefix
      - max_prefix, min_prefix: on the sum prefix

    - TODO: we need to use a suffix sum for the second part
  */
  int t;
  std::cin >> t;
  while (t--)
  {
    int n, m;
    std::cin >> n >> m;
    std::cin >> program;
    sum_prefix[0] = ((program[0] == '+') << 1) - 1;
    max_prefix[0] = sum_prefix[0];
    min_prefix[0] = sum_prefix[0];
    for (int i = 1; i < n; ++i)
    {
      sum_prefix[i] = sum_prefix[i - 1] + ((program[i] == '+') << 1) - 1;
      max_prefix[i] = std::max(max_prefix[i - 1], sum_prefix[i]);
      min_prefix[i] = std::min(min_prefix[i - 1], sum_prefix[i]);
    }
    while (m--)
    {
      int l, r;
      std::cin >> l >> r;
      int new_sum_start = sum_prefix[l - 1] + ((program[r + 1] == '+') << 1) - 1;
      int sum_start_delta = new_sum_start - sum_prefix[r + 1];
      int new_max = max_prefix[n - 1] + sum_start_delta;
      int new_min = min_prefix[n - 1] + sum_start_delta;
      std::cout << (std::max(max_prefix[l - 1], new_max) - std::min(min_prefix[l - 1], new_min)) << '\n';
    }
  }
  return 0;
}
