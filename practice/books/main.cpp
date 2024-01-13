/*
- n books
- mi minutes for book i
*/
#include <stdio.h>

const int N = 1e5;
int books[N];
int n, free_time;

bool ok(int req)
{
  int time_consumed = 0;
  for (int i = 1; i <= req; ++i)
  {
    time_consumed += books[i];
  }
  for (int i = req + 1; i <= n; ++i)
  {
    if (time_consumed <= free_time)
      return true;
    time_consumed -= books[i - req];
    time_consumed += books[i];
  }
  return time_consumed <= free_time;
}

int main()
{
  scanf("%d%d", &n, &free_time);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", books + i);
  }
  int l = 0;
  int r = n + 1;
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
