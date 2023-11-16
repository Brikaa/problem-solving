/*
n pies
ri radius
f friends

- ok(req)
  - received = 0
  # x * req = pie_volume
  # x = pie_volume / req
  - for pie in pies
    - received += pie_volume / req
  - return received >= f

- while (r - l > 1e-9)
*/
#include <stdio.h>
#include <cmath>

const int N = 1e4 + 3;
int radii[N];
int n;
int f;

bool ok(double req)
{
  int received = 0;
  for (int i = 1; i <= n; ++i)
  {
    received += (acos(-1) * radii[i] * radii[i]) / req;
  }
  return received >= f + 1;
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d", &n, &f);
    for (int i = 1; i <= n; ++i)
    {
      scanf("%d", radii + i);
    }
    double l = 0;
    double r = 1e9;
    while (r - l > 1e-5)
    {
      double mid = (l + r) / 2;
      if (ok(mid))
        l = mid;
      else
        r = mid;
    }
    printf("%.4f\n", l);
  }
  return 0;
}
