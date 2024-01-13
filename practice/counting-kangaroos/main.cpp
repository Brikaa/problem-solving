/*
- Maximum number of held kangaroos
1
2
3
4

5
6
7
8

4 5 8 17
    ^ ^

4 8 15 17
    ^   ^

4 8 9 13 15 17

- ok(req)
  - l = 1
  - r = req + 1
  - carrying = 0
  - while r <= n
    - if kangaroos[l] * 2 <= kangaroos[r]
      - carrying++
      - l++
    - r++
  - return carrying >= req
*/
#include <stdio.h>
#include <algorithm>

const int N = 5e5 + 5;
int kangaroos[N];
int n;

bool ok(int req)
{
  int l = 1;
  int r = req + 1;
  while (r <= n)
  {
    l += kangaroos[l] * 2 <= kangaroos[r];
    ++r;
  }
  return l - 1 >= req;
}

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d", kangaroos + i);
  }
  std::sort(kangaroos, kangaroos + n + 1);

  int l = 0;
  int r = n / 2 + 1;
  while (r - l > 1)
  {
    int mid = (l + r) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%d\n", n - l);
}
