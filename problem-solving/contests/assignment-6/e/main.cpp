#include <cmath>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

typedef unsigned int ui;
typedef unsigned long long ull;

const int N = 105;
const int D = 505;
int n;
int total_coins;
int coins[N];
std::unordered_map<int, std::unordered_map<int, int>> memo;

// difference = right_coins - left_coins
int solve(int idx, int difference)
{
  if (memo[idx].find(difference) != memo[idx].end())
    return memo[idx][difference];
  int &ret = memo[idx][difference];
  if (idx >= n)
    ret = std::abs(difference);
  else
    ret = std::min(solve(idx + 1, difference - coins[idx]), solve(idx + 1, difference + coins[idx]));
  return ret;
}

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    memo.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
      scanf("%d", coins + i);
      total_coins += coins[i];
    }
    printf("%d\n", solve(0, 0));
  }
  return 0;
}
