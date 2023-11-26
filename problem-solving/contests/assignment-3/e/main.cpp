/*
A certain point
for each d from that point
if (point + d is oob || arr[point + d] == 1) && (point - d is oob || arr[point - d] == 1)

d is from 0 to max(n - p, p - 1)
*/
#include <cstdio>
#include <algorithm>

const int N = 107;
int cities[N];

int main()
{
  int n, p;
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", cities + i);
  }
  int stop = std::max(n - p, p - 1);
  int ans = 0;
  for (int i = 0; i <= stop; ++i)
  {
    ans += (p + i > n || cities[p + i]) && (p - i < 1 || cities[p - i]);
    ans += i != 0 && p + i <= n && cities[p + i] && p - i >= 1 && cities[p - i];
  }
  printf("%d\n", ans);
}
