/*
Set of integers n
Number of ordered pairs (xi, yi) that satisfy
x < y
|x - y| <= |x| and |x + y| >= |y| and |x| < |y| or
|x - y| >= |x| and |x + y| <= |y| and |x| > |y| or
|x - y| >= |y| and |x + y| <= |x| and |x| < |y| or
|x - y| <= |y| and |x + y| >= |x| and |x| > |y|

If x >= 0, look for x < y <= 2x
if x < 0, look for ceil(-x / 2) <= y < -x or x < y <= -2x


if x >= 0, look for
  x < y <= 2x
  impossible
  impossible
  impossible

if x < 0, look for
  impossible
  ceil(-x / 2) <= y < -x
  -x < y <= -2x
  x < y <= floor(x / 2)

  ===> ceil(-x / 2) <= y <= -2x or x < y <= floor(x / 2)

-3 2 5
^  ^

-3 5
8
*/
#include <algorithm>
#include <cstdio>
#include <cmath>

const int N = 2e5 + 5;
long long points[N];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", points + i);
  std::sort(points, points + n);
  long long satisfying = 0;
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
      satisfying +=
          (std::upper_bound(points, points + n, floor(x / 2.0)) - points) -
          (std::upper_bound(points, points + n, x) - points);
      satisfying +=
          (std::upper_bound(points, points + n, -2 * x) - points) -
          (std::upper_bound(points, points + n, ceil(-x / 2.0) - 1) - points);
    }
  }
  printf("%lld\n", satisfying);
}
