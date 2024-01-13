/*
For each element in b how many elements in a are less than or equal to it
*/
#include <cstdio>
#include <algorithm>

const int N = 2e5 + 5;
int a[N];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  std::sort(a, a + n);
  while (m--)
  {
    int bi;
    scanf("%d", &bi);
    int idx = std::upper_bound(a, a + n, bi) - a;
    printf("%d%c", idx, " \n"[m == 0]);
  }
  return 0;
}
