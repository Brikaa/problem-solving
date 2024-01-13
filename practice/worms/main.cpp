/*
n no piles
ai worms in ith pile
- Form prefix sum for piles
*/
#include <stdio.h>

const int N = 1e5 + 5;
int piles[N];
int piles_prefix_sum[N];

bool ok(int required_pile, int target)
{
  return target <= piles_prefix_sum[required_pile];
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", piles + i);
  }
  for (int i = 1; i <= n; ++i)
  {
    piles_prefix_sum[i] = piles_prefix_sum[i - 1] + piles[i];
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i)
  {
    int q;
    scanf("%d", &q);
    int l = 0;
    int r = n + 1;
    while (r - l > 1)
    {
      int mid = (l + r) / 2;
      if (ok(mid, q))
      {
        r = mid;
      }
      else
      {
        l = mid;
      }
    }
    printf("%d\n", r);
  }
}
