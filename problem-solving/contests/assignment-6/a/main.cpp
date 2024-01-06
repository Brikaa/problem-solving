#include <cstdio>
#include <cstring>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;
const ui N = 13;
ui arr[N];
ui memo[N];

ui solve(ui idx)
{
  ui& ret = memo[idx];
  if (~ret)
    return ret;
  ret = 1;
  ui best_sol = 0;
  for (ui i = idx - 1; ~i; --i)
  {
    if (arr[i] < arr[idx])
      best_sol = std::max(best_sol, solve(i));
  }
  ret += best_sol;
  return ret;
}

int main()
{
  std::memset(memo, -1, sizeof(memo));
  ui n;
  scanf("%u", &n);
  ui longest = 0;
  for (ui i = 0; i < n; ++i)
  {
    scanf("%u", arr + i);
    longest = std::max(longest, solve(i));
  }
  printf("%u\n", longest);
  return 0;
}
