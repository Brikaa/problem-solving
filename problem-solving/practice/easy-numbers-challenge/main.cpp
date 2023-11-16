/*
1073741824

d(i * j * k)
for i 1..a
for j 1..b
for k 1..c

- To get number of divisors 1..N
  - for every number in 2..n
    - for i in number .. n, i += number
      - divisors[i]++

- Get divisors from 1 ... a * b * c
- 3 loops adding d[i * j * k] to the total sum
*/
#include <stdio.h>

const int N = 1e6 + 5;
int divisors[N];

int main()
{
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int n = a * b * c;
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; j += i)
      ++divisors[j];

  long long no_divisors = 0;
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= c; k++)
        no_divisors += divisors[i * j * k];
  printf("%lld\n", no_divisors);
  return 0;
}
