/*
Need n pipes using x splitters
Splitters can be of size 2, 3, 4, ..., k

2 increases by 1
3 increases by 2
and so on


2 3 4 5 6 7
^         ^
1 + 2 + 3 + 4 + 5 + 6 + 1
22
(e - s + 1) * (e + s - 2) / 2 + 1

e = min(n, k)
(e - s + 1) * (e + s - 2) / 2 + 1 >= n

*/
#include <cstdio>
#include <algorithm>

int main()
{
  long long n, k;
  scanf("%lld%lld", &n, &k);
  long long e = std::min(n, k);
  if ((e - 2 + 1) * (e + 2 - 2) / 2 + 1 < n)
  {
    printf("-1\n");
    return 0;
  }
  long long l = 2;
  long long r = e + 2;
  while (r - l > 1)
  {
    long long mid = (l + r) / 2;
    if ((e - mid + 1) * (e + mid - 2) / 2 + 1 >= n)
      l = mid;
    else
      r = mid;
  }
  printf("%lld\n", e - l + 1);
}
