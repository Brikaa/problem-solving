#include <cstdio>
#include <unordered_map>

std::unordered_map<int, int> memo;
const int N = 1e5 + 5;
bool primes[N + 3];

int g(int x)
{
  if (x == 1)
    return 1;
  else if (x == 2)
    return 2;
  else if (x == 0 || primes[x])
    return 0;
  else if (memo.find(x) != memo.end())
    return memo[x];
  else
  {
    int divisor = 1;
    for (int i = 2; i * i <= x; ++i)
      if (x % i == 0)
        divisor = i;
    int result = g(divisor) + g(x / divisor);
    memo[x] = result;
    return result;
  }
}

int main()
{
  for (int i = 2; i <= N; ++i)
    primes[i] = true;
  for (int i = 2; i * i <= N; ++i)
  {
    if (primes[i])
    {
      for (int j = i * i; j <= N; j += i)
        primes[j] = false;
    }
  }
  int n;
  scanf("%d", &n);
  printf("%d\n", g(n));
  return 0;
}
