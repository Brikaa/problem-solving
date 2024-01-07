/*
 */
#include <cstdio>
#include <algorithm>
#include <unordered_map>

typedef unsigned int ui;
typedef unsigned long long ull;

const int N = 103;
const int K = 1e4 + 5;
int k, n;
int costs[N];
int values[N];
std::unordered_map<int, std::unordered_map<int, std::unordered_map<bool, int>>> memo;
std::unordered_map<int, std::unordered_map<int, std::unordered_map<bool, int>>> visited;
int vid;

int solve(int idx, int remaining_money, bool refund_used)
{
  if (k - remaining_money > 2000 && !refund_used)
  {
    remaining_money += 200;
    refund_used = true;
  }
  if (idx >= n)
  {
    if (remaining_money < 0)
      return -1e9;
    return 0;
  }
  int &vis = visited[idx][remaining_money][refund_used];
  int &ret = memo[idx][remaining_money][refund_used];
  if (vis == vid)
    return ret;
  vis = vid;
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
    for (int i = 0; i < n; ++i)
      scanf("%u%u", costs + i, values + i);
    printf("%u\n", solve(0, k, false));
  }
  return 0;
}
