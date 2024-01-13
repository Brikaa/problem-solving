/*
Given the leader and the last lap times
Find out at which lap the leader overtakes the last

1 2
lap 0.5*lap
2lap 1lap

5 7
1 5/7
2 10/7
3 15/7
4 20/7

1 * x - 5 / 7 * x >= 1
x * (1 - 5/7) >= 1
x >= 1/(1 - 5/7)
*/
#include <cstdio>
#include <cmath>

int main()
{
  int first, last;
  while (scanf("%d%d", &first, &last) != EOF)
    printf("%d\n", (int)ceil(1 / (1 - first / (double)last)));
}
