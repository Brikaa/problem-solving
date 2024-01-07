#include <algorithm>
#include <cstdio>
#include <unordered_map>

typedef unsigned int ui;
typedef unsigned long long ull;

const int N = 1e3 + 5;
const int OX = 25;
const int NI = 82;
int n;
int oxygen[N];
int nitrogen[N];
int weight[N];
std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, int>>> memo;

int solve(int idx, int remaining_oxygen, int remaining_nitrogen)
{
  if (remaining_oxygen <= 0 && remaining_nitrogen <= 0)
    return 0;
  if (idx >= n)
    return 1e9;
  if (memo[idx][remaining_oxygen].find(remaining_nitrogen) != memo[idx][remaining_oxygen].end())
    return memo[idx][remaining_oxygen][remaining_nitrogen];
  int &ret = memo[idx][remaining_oxygen][remaining_nitrogen];
  ret = std::min(
      weight[idx] + solve(idx + 1, remaining_oxygen - oxygen[idx], remaining_nitrogen - nitrogen[idx]),
      solve(idx + 1, remaining_oxygen, remaining_nitrogen));
  return ret;
}

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    memo.clear();
    int required_oxygen;
    int required_nitrogen;
    scanf("%d%d%d", &required_oxygen, &required_nitrogen, &n);
    for (int i = 0; i < n; ++i)
      scanf("%d%d%d", oxygen + i, nitrogen + i, weight + i);
    printf("%d\n", solve(0, required_oxygen, required_nitrogen));
  }
  return 0;
}
