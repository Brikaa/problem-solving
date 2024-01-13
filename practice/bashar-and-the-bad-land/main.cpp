/*
x required golden coins
n houses
"a" gold in each house

7
1 3 4 2 3
  ^ ^
*/
#include <stdio.h>

const int N = 1e5 + 5;
int gold[N];
int n;
int x;

bool ok(int req_distance)
{
  long long sum = 0;
  for (int i = 1; i <= req_distance; ++i)
  {
    sum += gold[i];
  }
  for (int i = req_distance + 1; i <= n; ++i)
  {
    if (sum >= x)
      return true;
    sum -= gold[i - req_distance];
    sum += gold[i];
  }
  return sum >= x;
}

int main()
{
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", gold + i);
  }
  int l = 0;
  int r = n + 1;
  while (r - l > 1)
  {
    int mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  if (r == n + 1)
  {
    printf("-1\n");
  }
  else
  {
    printf("%d\n", r);
  }
  return 0;
}
