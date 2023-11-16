/*
factors = []
while i <= sqrt(n)
  try to divide by i
  if divisible
    factors.push(i)
    n /= i
    i = 2
  else
    i++
if factors.size() > k
  multiply the first (factors.size() - k + 1) numbers by each other
*/
#include <stdio.h>

const int N = 1e5 + 5;
int factors[N];

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  int i = 2;
  int factors_size = 0;
  while (i * i <= n)
  {
    if (n % i == 0)
    {
      factors[factors_size++] = i;
      n /= i;
    }
    else
    {
      ++i;
    }
  }
  if (n != 1)
    factors[factors_size++] = n;
  if (factors_size < k)
  {
    printf("-1\n");
  }
  else if (factors_size > k)
  {
    int product = 1;
    int diff = factors_size - k + 1;
    for (int i = 0; i < diff; ++i)
    {
      product *= factors[i];
    }
    printf("%d ", product);
    for (int i = diff; i < factors_size; ++i)
    {
      printf("%d%c", factors[i], " \n"[i == factors_size - 1]);
    }
  }
  else
  {
    for (int i = 0; i < factors_size; ++i)
    {
      printf("%d%c", factors[i], " \n"[i == factors_size - 1]);
    }
  }
}
