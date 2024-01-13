#include <cstdio>
#include <algorithm>

const int N = 1e5 + 5;
long long prices[N];
int n;
long long k;

bool ok(int req)
{
  if (req > n)
    return false;
  long long spent = 0;
  for (int i = 1; i <= req; ++i)
    spent += prices[i];
  if (spent <= k)
    return true;
  else
    return false;
}

int main()
{
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", prices + i);
  std::sort(prices + 1, prices + n + 1);
  int l = 0;
  int r = n + 1;
  while (r - l > 1)
  {
    int mid = (l + r) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%d\n", l);
  return 0;
}
