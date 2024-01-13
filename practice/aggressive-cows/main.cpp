/*
  - ok
    - as long as I don't reach the minimum distance, don't assign
    - count the assigned
    - return assigned >= no_cows
*/
#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;
int positions[N];
int n, c;

bool ok(int required_distance)
{
  int assigned = 1;
  int last_assigned = positions[1];
  for (int i = 2; i <= n; ++i)
  {
    if (positions[i] - last_assigned >= required_distance)
    {
      ++assigned;
      last_assigned = positions[i];
    }
  }
  return assigned >= c;
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; ++i)
    {
      scanf("%d", positions + i);
    }
    std::sort(positions + 1, positions + n + 1);
    int l = 0;
    int r = 1e9 + 3;
    while (r - l > 1)
    {
      int mid = (r + l) / 2;
      if (ok(mid))
        l = mid;
      else
        r = mid;
    }
    printf("%d\n", l);
  }
  return 0;
}
