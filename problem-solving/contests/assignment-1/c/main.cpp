/*
Given n elements, get the second smallest
*/
#include <cstdio>
#include <algorithm>

const int N = 107;
int items[N];

int main()
{
  int n;
  scanf("%d", &n);
  int minimum = 200;
  int second_min = 200;
  for (int i = 0; i < n; ++i)
    scanf("%d", items + i);
  for (int i = 0; i < n; ++i)
    minimum = std::min(minimum, items[i]);
  for (int i = 0; i < n; ++i)
  {
    int prev_second_min = second_min;
    second_min = std::min(second_min, items[i]);
    if (second_min == minimum)
      second_min = prev_second_min;
  }
  if (second_min == 200)
    printf("NO\n");
  else
    printf("%d\n", second_min);
}
