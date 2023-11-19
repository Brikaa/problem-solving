#include <stdio.h>
#include <algorithm>
#include <cmath>

const int N = 1e5 + 5;
const int M = N;

int houses[N];
int towers[M];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", houses + i);
  }
  for (int i = 0; i < m; ++i)
  {
    scanf("%d", towers + i);
  }
  int rp = 0;
  int r = 0;
  for (int i = 0; i < n; ++i)
  {
    while (rp < m && houses[i] > towers[rp])
      ++rp;
    if (rp == 0)
    {
      r = std::max(abs(towers[rp] - houses[i]), r);
    }
    else if (rp == m)
    {
      r = std::max(abs(houses[i] - towers[rp - 1]), r);
    }
    else
    {
      r = std::max(std::min(abs(houses[i] - towers[rp - 1]), abs(towers[rp] - houses[i])), r);
    }
  }
  printf("%d\n", r);
}
