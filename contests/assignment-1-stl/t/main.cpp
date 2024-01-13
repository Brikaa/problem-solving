/*
t1 t2 t3
t3 >= t1 + t2

1 2 3 22 23 27 29
*/
#include <cstdio>
#include <algorithm>

const int N = 1e5 + 5;
int queue[N];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", queue + i);
  std::sort(queue, queue + n);
  int time = 0;
  int angry = 0;
  for (int i = 0; i < n; ++i)
  {
    if (time > queue[i])
      angry += time > queue[i];
    else
      time += queue[i];
  }
  printf("%d\n", n - angry);
  return 0;
}
