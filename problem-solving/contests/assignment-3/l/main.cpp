/*
n holes
k strips
minimize longest strip length

ok(req)
  - For each hole
    - Try to cover holes till req distance
*/
#include <cstdio>

const int N = 1e5 + 5;
int holes[N];
int n, k;

bool ok(int req)
{
  int no_strips = 0;
  for (int i = 1; i <= n;)
  {
    int j = i + 1;
    for (; j <= n && holes[j] - holes[i] + 1 <= req; j++)
    {
    }
    ++no_strips;
    i = j;
  }
  return no_strips <= k;
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
      scanf("%d", holes + i);
    int l = 0;
    int r = holes[n] - holes[1] + 5;
    while (r - l > 1)
    {
      int mid = (r + l) / 2;
      if (ok(mid))
        r = mid;
      else
        l = mid;
    }
    printf("%d\n", r);
  }
}
