#include <algorithm>
#include <cstdio>
#include <cstring>

typedef unsigned int ui;
typedef unsigned long long ull;

const int N = 55;
const int CAP = 1e3 + 5;
int weights[N];
int values[N];
int capacity;
int n;
int memo[N][CAP];

int solve(int idx, int remaining_capacity)
{
  if (idx >= n)
    return 0;
  int &ret = memo[idx][remaining_capacity];
  if (~ret)
    return ret;
  if (weights[idx] > remaining_capacity)
    ret = solve(idx + 1, remaining_capacity);
  else
    ret = std::max(values[idx] + solve(idx + 1, remaining_capacity - weights[idx]), solve(idx + 1, remaining_capacity));
  return ret;
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    std::memset(memo, -1, sizeof(memo));
    int cap;
    scanf("%d%d", &cap, &n);
    for (int i = 0; i < n; ++i)
      scanf("%d%d", weights + i, values + i);
    printf("Hey stupid robber, you can get %d.\n", solve(0, cap));
  }
  return 0;
}
