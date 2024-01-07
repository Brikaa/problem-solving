#include <algorithm>
#include <cstdio>
#include <cstring>

typedef unsigned int ui;
typedef unsigned long long ull;

const int N = 1e3 + 5;
const int OX = 25;
const int NI = 82;
int n;
int oxygen[N];
int nitrogen[N];
int weight[N];
int required_oxygen;
int required_nitrogen;
int memo[N][OX][NI];

int solve(int idx, int current_oxygen, int current_nitrogen)
{
  int &ret = memo[idx][current_oxygen][current_nitrogen];
  if (~ret)
    return ret;
  if (current_nitrogen >= required_nitrogen && current_oxygen >= required_oxygen)
    ret = 0;
  else if (idx >= n)
    ret = 1e9;
  else
    ret = std::min(
        weight[idx] + solve(idx + 1, current_oxygen + oxygen[idx], current_nitrogen + nitrogen[idx]),
        solve(idx + 1, current_oxygen, current_nitrogen));
  return ret;
}

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    std::memset(memo, -1, sizeof(memo));
    scanf("%d%d%d", &required_oxygen, &required_nitrogen, &n);
    for (int i = 0; i < n; ++i)
      scanf("%u%u%u", oxygen + i, nitrogen + i, weight + i);
    printf("%d\n", solve(0, 0, 0));
  }
  return 0;
}
