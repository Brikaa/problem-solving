#include <cstdio>
#include <deque>

typedef unsigned int ui;
typedef unsigned long long ull;

struct Return
{
  ull sum;
  std::deque<ull> elements;
};

const ui N = 23;
ui n;
ull capacity;
ull weights[N];

Return solve(ull cap, ui current_index)
{
  if (current_index >= n)
    return Return{0, std::deque<ull>()};
  if (weights[current_index] > cap)
    return solve(cap, current_index + 1);
  Return ret1 = solve(cap, current_index + 1);
  Return ret2 = solve(cap - weights[current_index], current_index + 1);
  if (weights[current_index] + ret2.sum > ret1.sum)
  {
    ret2.elements.push_front(weights[current_index]);
    ret2.sum += weights[current_index];
    return ret2;
  }
  return ret1;
}

int main()
{
  while (scanf("%llu%u", &capacity, &n) != EOF)
  {
    for (ui i = 0; i < n; ++i)
      scanf("%llu", weights + i);
    Return ret = solve(capacity, 0);
    for (ull weight : ret.elements)
    {
      printf("%llu ", weight);
    }
    printf("sum:%llu\n", ret.sum);
  }
  return 0;
}
