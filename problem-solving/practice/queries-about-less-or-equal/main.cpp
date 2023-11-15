#include <stdio.h>
#include <algorithm>

const int N = 2e5 + 5;
int a[N];

bool ok(int req, int target)
{
  return a[req] <= target;
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", a + i);
  }
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; ++i)
  {
    int element;
    scanf("%d", &element);
    int l = 0;
    int r = n + 1;
    while (r - l > 1)
    {
      int mid = (l + r) / 2;
      if (ok(mid, element))
      {
        l = mid;
      }
      else
      {
        r = mid;
      }
    }
    printf("%d%c", l, " \n"[i == m]);
  }
  return 0;
}
