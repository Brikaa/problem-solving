#include <cstdio>

const int K = 1e6 + 5;
bool not_primes[K];
const int N = 1e5 + 4;
int primes[N];

int main()
{
  for (int i = 2; i * i < K; ++i)
  {
    if (!not_primes[i])
    {
      for (int j = i * i; j < K; j += i)
        not_primes[j] = true;
    }
  }
  int next = 1;
  for (int i = 2; i < K; ++i)
  {
    if (!not_primes[i])
      primes[next++] = i;
  }
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int n;
    scanf("%d", &n);
    printf("%d\n", primes[n]);
  }
  return 0;
}
