/*
*/
#include <cstdio>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 103;
const ui K = 1e4 + 5;
ui k, n;
ui costs[N];
ui values[N];
ui memo[N][K][2];
ui visited[N][K][2];
ui vid;

ui solve(ui idx, ui remaining_money, bool refund_used)
{
  if (idx >= n)
    return 0;
  if (k - remaining_money >= 2000 && !refund_used)
  {
    remaining_money += 200;
    refund_used = true;
  }
  ui &vis = visited[idx][remaining_money][refund_used];
  ui &ret = memo[idx][remaining_money][refund_used];
  if (vis)
    return ret;
  if (costs[idx] > remaining_money)
    ret = solve(idx + 1, remaining_money, refund_used);
  else
    ret = std::max(
        values[idx] + solve(idx + 1, remaining_money - costs[idx], refund_used),
        solve(idx + 1, remaining_money, refund_used));
  return ret;
}

int main()
{
  while (scanf("%u%u", &k, &n) != EOF)
  {
    ++vid;
    for (ui i = 0; i < n; ++i)
      scanf("%u%u", costs + i, values + i);
    printf("%u\n", solve(0, k, false));
  }
  return 0;
}
