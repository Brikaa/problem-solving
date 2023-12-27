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
    return opt2;
  return opt1;
}

void print(ull best_sum)
{
  ull current_capacity = 0;
  for (ui i = 0; i < n; ++i)
  {
    // fprintf(stderr, "debug: %llu\n", current_capacity + weights[i] + solve(capacity - weights[i], i + 1));
    if (current_capacity + weights[i] + solve(capacity - current_capacity - weights[i], i + 1) == best_sum)
    {
      printf("%llu ", weights[i]);
      current_capacity += weights[i];
    }
  }
}

int main()
{
  while (scanf("%llu%u", &capacity, &n) != EOF)
  {
    for (ui i = 0; i < n; ++i)
    {
      scanf("%llu", weights + i);
    }
    ull best_sum = solve(capacity, 0);
    print(best_sum);
    printf("sum:%llu\n", best_sum);
  }
  return 0;
}
