#include <cmath>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <cstring>

typedef unsigned int ui;
typedef unsigned long long ull;

const int N = 105;
const int D = 1e3 + 5;
int n;
int total_coins;
int coins[N];
std::unordered_map<int, std::unordered_map<int, int>> memo;


/* difference = (right - left) ** 2
              = right^2 - 2*right*left + left^2
  To add to left:
    + x^2 + 2x - 2*(no_coins-left)*x
  To add to right:
    + x^2 + 2x - 2*left*x
*/
/*
  difference = |right-left|
*/
int solve(int idx, int difference)
{
  if (memo[idx].find(difference) != memo[idx].end())
    return memo[idx][difference];
  int &ret = memo[idx][difference];
  if (idx >= n)
    ret = difference;
  else
    ret = std::min(solve(idx + 1, std::abs(difference - coins[idx])), solve(idx + 1, std::abs(difference + coins[idx])));
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
