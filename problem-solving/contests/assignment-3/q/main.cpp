/*
n diamonds, X money
buy a number of consecutive diamonds where value is max but does not exceed X
*/
#include <cstdio>
#include <algorithm>

const int N = 3e5 + 5;
int diamonds[N];

int main()
{
  int n;
  long long x;
  scanf("%d%lld", &n, &x);
  for (int i = 0; i < n; ++i)
    scanf("%d", diamonds + i);
  int s = 0;
  int e = 0;
  long long value = diamonds[0];
  long long best_value = -1;

  while (e < n && s < n)
  {
    if (value <= x)
    {
      best_value = std::max(best_value, value);
      value += diamonds[++e];
    }
    else
    {
      value -= diamonds[s++];
    }
  }

  printf("%lld\n", best_value);
}
