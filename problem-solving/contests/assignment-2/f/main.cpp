/*
a1 a2 a3 a4

Prefix sum squared
a1 a1+a2 a1+a2+a3 a1+a2+a3+a4
*
a1 a1+a2 a1+a2+a3 a1+a2+a3+a4

Prefix sum of squares
a1^2 a1^2+a2^2 a1^2+a2^2+a3^2 a1^2+a2^2+a3^2+a4^2

Prefix sum squared (last)
a1*a1 + a2*a2 + a3*a3 + a4*a4 + 2*a1*a2 + 2*a1*a3 + 2*a1*a4 + 2*a2*a3 + 2*a2*a4 + 2*a3*a4

Add to prefix sum of squares (last)
2*a1*a1 + 2*a2*a2 + 2*a3*a3 + 2*a4*a4 + 2*a1*a2 + 2*a1*a3 + 2*a1*a4 + 2*a2*a3 + 2*a2*a4 + 2*a3*a4

Divide by two
a1*a1 + a2*a2 + a3*a3 + a4*a4 + a1*a2 + a1*a3 + a1*a4 + a2*a3 + a2*a4 + a3*a4

a1*a1 a1*a1+a1*a2+a2*a2 a1*a1+a1*a2+a1*a3+a2*a2+a2*a3+a3*a3 a1*a1+a1*a2+a1*a3+a1*a4+a2*a2+a2*a3+a2*a4+a3*a3+a3*a4+a4*a4

Need to start at a2 and end at a4
a2*a2+a2*a3+a2*a4+a3*a3+a3*a4+a4*a4
Subtract res[l] from res[r]
a1*a3+a1*a4+a2*a3+a2*a4+a3*a3+a3*a4+a4*a4
subtract a1*a3 + a1*a4
a2*a3+a2*a4+a3*a3+a3*a4+a4*a4
add a2*a2
a2*a2+a2*a3+a2*a4+a3*a3+a3*a4+a4*a4

We subtract range sum from l+1 to r times prefix sum to l-1

*/
#include <cstdio>

const int N = 1e5 + 5;

long long numbers[N];
long long prefix_sum[N];
long long prefix_sum_squared[N];
long long prefix_sum_of_squares[N];
long long prefix_sum_res[N];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", numbers + i);
  for (int i = 1; i <= n; ++i)
  {
    prefix_sum[i] = prefix_sum[i - 1] + numbers[i];
    prefix_sum_of_squares[i] = prefix_sum_of_squares[i - 1] + numbers[i] * numbers[i];
  }
  for (int i = 1; i <= n; ++i)
    prefix_sum_squared[i] = prefix_sum[i] * prefix_sum[i];
  for (int i = 1; i <= n; ++i)
    prefix_sum_res[i] = prefix_sum_of_squares[i] + prefix_sum_squared[i];
  for (int i = 1; i <= n; ++i)
    prefix_sum_res[i] /= 2;
  int k;
  scanf("%d", &k);
  while (k--)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    ++l;
    ++r;
    printf(
        "%lld\n",
        prefix_sum_res[r] - prefix_sum_res[l] + numbers[l] * numbers[l] - (prefix_sum[r] - prefix_sum[l]) * prefix_sum[l - 1]);
  }
}
