#include <cstdio>

const int N = 1e5 + 5;
long long p[N];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", p + i);
  for (int i = 1; i <= n; ++i)
    p[i] += p[i - 1];
  int k;
  scanf("%d", &k);
  while (k--)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    ++l;
    ++r;
    printf("%lld\n", p[r] - p[l - 1]);
  }
}
