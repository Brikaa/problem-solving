/*
n buildings
xi position of building i
3 towers of power d

- ok(req)
  - Start at 1
  - End at 2 * req
  - Start at 2 * req + 1
  - End at 4 * req
  - Start at 4 * req + 1
  - End at 6 * req
  - All houses should be covered

  1   6
*/
#include <cstdio>
#include <algorithm>

const int N = 2e5 + 5;
int n;
int houses[N];

bool ok(double req)
{
  int no_towers = 0;
  for (int i = 1; i <= n;)
  {
    int j = i + 1;
    for (; j <= n && houses[j] - houses[i] <= 2 * req; ++j)
    {
    }
    ++no_towers;
    i = j;
  }
  return no_towers <= 3;
}

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", houses + i);
  std::sort(houses + 1, houses + n + 1);
  double l = 0;
  double r = houses[n] - houses[1];
  while (r - l > 1e-7)
  {
    double mid = (r + l) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.6f\n", r);
  return 0;
}
