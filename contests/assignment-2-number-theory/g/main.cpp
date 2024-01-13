/*
Query 1: range sum
Query 2: add an element to the beginning of the array
Range sum is calculated using prefix sum
We don't want to loop over all prefix sum every time an element is added
So, every time an element is added
  - Know how it affects the values in prefix sum
    - Do I care unless that value is included in the prefix sum?
  - Know how it affects the indices
    - When asked for l r, it is l - added, r - added
    - l can be negative
    - We will have an inverted negative-indexed prefix sum array
    - So when l is negative, calculate the prefix sum of positive-indexed part till r
      and sum it with the prefix sum of the negative-indexed part till -l
    - When l is positive, do normal range sum
So, early get the queries of type 2 and form the inverted prefix sum array, but we need to know what "added" is at each
query

1 2, added 1
0 1
-1->-1 1->1

1 2, added 2
-1 0
-1->-2

3 2 1 0 0
1 2, added 3
-2 -1
-2->-3

if l <= 0
  l--
if r <= 0
  r--
if they are both less than zero, take inverted from -r to -l
if only l is less than zero, take prefix till r and inverted till -l
else take normal l to r


6 7 8 9 10
*/
#include <cstdio>

const int N = 2e5 + 5;
const int Q = N;
long long added[Q];
long long inverted_prefix_sum[Q];
long long prefix_sum[N];
long long queries[Q][3];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", prefix_sum + i);
  for (int i = 1; i <= n; ++i)
    prefix_sum[i] += prefix_sum[i - 1];
  int q;
  scanf("%d", &q);
  {
    int inv = 1;
    for (int i = 1; i <= q; ++i)
    {
      int type;
      scanf("%d", &type);
      queries[i][0] = type;
      if (type == 1)
        scanf("%lld%lld", &(queries[i][1]), &(queries[i][2]));
      else
      {
        long long number;
        scanf("%lld", &number);
        queries[i][1] = number;
        inverted_prefix_sum[inv++] = number;
        added[i] = 1;
      }
    }
  }
  for (int i = 1; i <= q; ++i)
  {
    added[i] += added[i - 1];
    inverted_prefix_sum[i] += inverted_prefix_sum[i - 1];
  }
  for (int i = 1; i <= q; ++i)
  {
    if (queries[i][0] == 2)
      continue;
    int l = queries[i][1] - added[i];
    int r = queries[i][2] - added[i];
    if (l <= 0)
      --l;
    if (r <= 0)
      --r;
    long long res;
    if (l < 0 && r < 0)
      res = inverted_prefix_sum[-l] - inverted_prefix_sum[-r - 1];
    else if (l < 0)
      res = prefix_sum[r] + inverted_prefix_sum[-l];
    else
      res = prefix_sum[r] - prefix_sum[l - 1];
    printf("%lld\n", res);
  }
  return 0;
}
