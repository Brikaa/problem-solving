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


5 6 7 8
5 + 5 + 6 + 7


*/
#include <cstdio>
#include <algorithm>

int main()
{
  long long n, k;
  scanf("%lld%lld", &n, &k);
  long long s = 2;
  long long e = 2;
  long long min_splitters = k + 5;
  long long water_flows = (e - s + 1) * (e + s - 2) / 2 + 1;
  while (s <= e && s <= k && e <= k)
  {
    if (water_flows == n)
    {
      min_splitters = std::min(min_splitters, e - s + 1);
      if (min_splitters == 1)
        break;
    }
    if (water_flows >= n)
      ++s;
    else
      ++e;
    water_flows = (e - s + 1) * (e + s - 2) / 2 + 1;
  }
  if (water_flows == n)
    min_splitters = std::min(min_splitters, e - s + 1);
  if (min_splitters == k + 5)
    printf("-1\n");
  else
    printf("%lld\n", min_splitters);
}
