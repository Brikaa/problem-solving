#include <cstdio>
#include <cstring>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

const int N = 1e3+5;
int source[N];
int destination[N];
int memo[N];
ui n;

int solve(ui idx)
{
  int& ret = memo[idx];
  if (~ret)
    return ret;
  ret = 1;
  int max_sol = 0;
  for (ui i = 0; i < n; ++i)
    if (i != idx && source[i] <= source[idx] && destination[i] <= destination[idx])
      max_sol = std::max(max_sol, solve(i));
  ret += max_sol;
  return ret;
}

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    std::memset(memo, -1, sizeof(memo));
    scanf("%u", &n);
    for (ui i = 0; i < n; ++i)
      scanf("%u", source + i);
    for (ui i = 0; i < n; ++i)
      scanf("%u", destination + i);
    int ans = 0;
    for (ui i = 0; i < n; ++i)
      ans = std::max(ans, solve(i));
    printf("%d\n", ans);
  }
  return 0;
}
