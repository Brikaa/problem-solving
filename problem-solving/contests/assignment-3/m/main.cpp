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
#include <vector>

const int N = 2e5 + 5;
int n;
int houses[N];
double towers[3];

bool ok(double req, std::vector<double> &towers_ref)
{
  int no_towers = 0;
  for (int i = 1; i <= n;)
  {
    int j = i + 1;
    for (; j <= n && houses[j] - houses[i] <= 2 * req; ++j)
    {
    }
    towers_ref.push_back((houses[j - 1] + houses[i]) / 2.0);
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
    std::vector<double> towers_ref;
    double mid = (r + l) / 2;
    if (ok(mid, towers_ref))
    {
      r = mid;
      towers[0] = towers_ref[0];
      towers[1] = towers_ref[1];
      towers[2] = towers_ref[2];
    }
    else
      l = mid;
  }
  printf("%.6f\n%.6f %.6f %.6f\n", r, towers[0], towers[1], towers[2]);
  return 0;
}
