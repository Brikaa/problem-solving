#include <cstdio>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 23;
ui n;
ull capacity;
ull weights[N];

ull solve(ull cap, ui current_index)
{
  if (current_index >= n)
    return 0;
  if (weights[current_index] > cap)
    return solve(cap, current_index + 1);
  ull opt1 = solve(cap, current_index + 1);
  ull opt2 = weights[current_index] + solve(cap - weights[current_index], current_index + 1);
  if (opt2 >= opt1)
  {
    printf("%llu ", weights[current_index]);
    return opt2;
  }
  return opt1;
}

int main()
{
  while (scanf("%llu%u", &capacity, &n) != EOF)
  {
    for (ui i = 0; i < n; ++i)
    {
      scanf("%llu", weights + i);
    }
    printf("sum: %llu\n", solve(capacity, 0));
  }
  return 0;
}
