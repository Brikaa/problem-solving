#include <cstdio>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 23;
ui n;
ull capacity;
ui weights[N];

ull solve(ull cap, ui current_index)
{
  if (current_index >= n)
    return 0;
  if (weights[current_index] > cap)
    return solve(cap, current_index + 1);
  return std::max(
      solve(cap, current_index + 1),
      weights[current_index] + solve(cap - weights[current_index], current_index + 1));
}

int main()
{
  while (scanf("%llu%u", &capacity, &n) != EOF)
  {
    for (ui i = 0; i < n; ++i)
    {
      scanf("%u", weights + i);
    }
    printf("sum: %llu\n", solve(capacity, 0));
  }
  return 0;
}
