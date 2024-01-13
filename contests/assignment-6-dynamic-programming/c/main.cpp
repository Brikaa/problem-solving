#include <cstdio>
#include <cstring>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

ui n;
const ui N = 2e3 + 5;
ui values[N];
ui sizes[N];
ui memo[N][N];

ui solve(ui idx, ui remaining_capacity)
{
  ui &ret = memo[idx][remaining_capacity];
  if (~ret)
    return ret;
  if (idx >= n)
    ret = 0;
  else if (sizes[idx] > remaining_capacity)
    ret = solve(idx + 1, remaining_capacity);
  else
    ret = std::max(values[idx] + solve(idx + 1, remaining_capacity - sizes[idx]), solve(idx + 1, remaining_capacity));
  return ret;
}

int main()
{
  std::memset(memo, -1, sizeof(memo));
  ui capacity;
  scanf("%u%u", &capacity, &n);
  for (ui i = 0; i < n; ++i)
    scanf("%u%u", sizes + i, values + i);
  printf("%u\n", solve(0, capacity));
  return 0;
}
