/*
n, m

1   2   3   4   5   6   7
2   4   6   8   10  12  14
3   6   9   12  15  18  21
4   8   12  16  20  24  28
5   10  15  20  25  30  35

For each number, I can get how many numbers are less than it and equal to it in each row

4
  4 / 1 = 1 equal, 3 less
  4 / 2 = 1 equal, 1 less
  4 / 3 = 1 less
  4 / 4 = 1 equal
  4 / 5 = none

5
  5 / 1 = 1 equal, 4 less
  5 / 2 = 2 less
  5 / 3 = 1 less
  5 / 4 = 1 less
  5 / 5 = 1 equal
  5 / 6 = none

12
  12 / 1 = We don't have 12 elements, so 7 (m) less
  12 / 2 = 1 equal, 5 less
  ...


*/
#include <cstdio>
long long n, m;
long long target;

bool ok(long long req, bool &has_equals_ref)
{
  if (req <= 0)
    return false;
  long long equal = 0;
  long long less = 0;

  for (long long r = 1; r <= n; ++r)
  {
    if (req / r == 0)
      break;
    if (req / ((double)r) > m)
      less += m;
    else if (req % r == 0)
    {
      ++equal;
      less += req / r - 1;
    }
    else
    {
      less += req / r;
    }
  }

  if (equal > 0)
  {
    has_equals_ref = true;
    --equal;
  }
  else
  {
    has_equals_ref = false;
  }
  return (less + equal) >= target - 1;
}

int main()
{
  scanf("%lld%lld%lld", &n, &m, &target);
  long long l = 0;
  long long r = n * m;
  bool has_equals = true;
  while (r - l > 1)
  {
    bool has_equals_ref = false;
    long long mid = (l + r) / 2;
    if (ok(mid, has_equals_ref))
    {
      has_equals = has_equals_ref;
      r = mid;
    }
    else
      l = mid;
  }
  printf("%lld\n", r + !has_equals);
  return 0;
}
