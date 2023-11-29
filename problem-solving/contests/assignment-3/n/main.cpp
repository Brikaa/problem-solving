/*
Set of integers n
Number of ordered pairs (xi, yi) that satisfy |x - y| <= |x| and |x + y| >= |y| or |x - y| >= |x| and |x + y| <= |y|

If x >= 0, look for x < y <= 2x
if x < 0, look for y >= ceil(-x / 2) or x < y <= 0


-1 1 satisfies
|-1 - 1| = 2 >= |-1|
|-1 + 1| = 0 <= |1|

-5 -1 satisfies
|-5 - -1| = 4 <= |-5|
|-5 + -1| = 6 >= |-1|

-1 0 satisfies
|-1 - 0| = 1 <= |-1|
|-1 + 0| = 1 >= 0

-5 -4
|-5 - -4| = 1 <= |-5|
|-5 + -4| = 9 >= |-4|

-2 1 satisfies
|-2 -1| = |-3| >= |-2|
|-2 + 1| = |-1| <= 1

-3 1 does not satisfy

5 11 does not satisfy
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
      satisfying += n - (std::upper_bound(points, points + n, ceil(-x / 2.0) - 1) - points);
      satisfying +=
          (std::upper_bound(points, points + n, 0) - points) - (std::upper_bound(points, points + n, x) - points);
    }
  }
  printf("%d\n", satisfying);
}
