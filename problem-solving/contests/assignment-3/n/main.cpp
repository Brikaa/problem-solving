/*
Set of integers n
Number of ordered pairs (xi, yi) that satisfy |x - y| <= |x| and |x + y| >= |y| or |x - y| >= |x| and |x + y| <= |y|

If x >= 0, look for x <= y <= 2x
if x < 0, look for y >= 0 TODO: check this

*/
#include <algorithm>
#include <cstdio>

const int N = 2e5 + 5;
long long points[N];

int main()
{
  int n;
  scanf("%d", &n);
  int ge_zero = 0;
  for (int i = 0; i < n; ++i)
  {
    scanf("%lld", points + i);
    ge_zero += points[i] >= 0;
  }
  std::sort(points, points + n);
  int satisfying = 0;
  for (int i = 0; i < n; ++i)
  {
    long long x = points[i];
    if (x >= 0)
    {
      satisfying +=
          (std::upper_bound(points, points + n, 2 * x) - points) - (std::upper_bound(points, points + n, x) - points);
    }
    else
    {
      satisfying += ge_zero;
    }
  }
  printf("%d\n", satisfying);
}
