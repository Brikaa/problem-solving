/*
1 - 5
2 - 6
3 - 7
4 - 8
5 - 9
6 - 10
7 - 11
8 - 12

1     2    3   4    5   6    7   8    9   10    11    12
x     x    x   x    y   x    x   x    x    y     x     x

1     2    3   4    5   6    7   8    9   10    11    12
x     x    x   y    y   x    x   x    y    y    x      x

1     2    3   4    5   6    7   8    9   10    11    12
x     x    y   y    y   x    x   y    y    y    x     x

1     2    3   4    5   6    7   8    9   10    11    12
x     y    y    y   y   x     y   y    y   y    x      y

s, d in each five months block
4, 1: 2 deficits
3, 2: 4 deficits
2, 3: 6 deficits
1, 4: 9 deficits

*/
#include <cstdio>

typedef unsigned int ui;
typedef unsigned long long ull;

int main()
{
  long long s, d;
  while (scanf("%lld%lld", &s, &d) != EOF)
  {
    long long x = 0;
    for (long long i = 1; i <= 4; ++i)
      if (i * s <= (5 - i) * d)
        x = i;

    long long delta = -1;
    if (x == 4)
      delta = 10 * s - 2 * d;
    else if (x == 3)
      delta = 8 * s - 4 * d;
    else if (x == 2)
      delta = 6 * s - 6 * d;
    else if (x == 1)
      delta = 3 * s - 9 * d;

    if (delta <= 0)
      printf("Deficit\n");
    else
      printf("%lld\n", delta);
  }
  return 0;
}
