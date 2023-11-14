/*
n number of houses
x required gold
"a" gold in each house

 1 4 3 2 4
         ^
         ^
*/
#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;
int gold[N];

int main()
{
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", gold + i);
  }
  int r = 0;
  int l = 0;
  int ans = n + 3;
  int sum = 0;
  while (sum >= x || r <= n)
  {
    if (sum >= x)
    {
      ans = std::min(ans, r - l);
      ++l;
      sum -= gold[l];
    }
    else
    {
      ++r;
      sum += gold[r];
    }
  }
  if (ans == n + 3)
  {
    printf("-1\n");
  }
  else
  {
    printf("%d\n", ans);
  }
  return 0;
}
