#include <cstdio>
#include <vector>

typedef unsigned int ui;
typedef unsigned long long ull;

const int Z = 1e4;
int not_primes[Z];
std::vector<int> primes;
const int N = 1500;
const int K = 20;
long long n;
long long memo[1220][K][N];
int visited[1220][K][N];
int vid;

long long solve(ui idx, int rem, long long sum)
{
  if (rem == 0)
    return sum == n;
  if (primes[idx] > n)
    return 0;
  long long &ret = memo[idx][rem][sum];
  if (visited[idx][rem][sum] != vid)
  {
    ret = solve(idx + 1, rem - 1, sum + primes[idx]) + solve(idx + 1, rem, sum);
    visited[idx][rem][sum] = vid;
  }
  return ret;
}

int main()
{
  for (int i = 2; i * i < Z; ++i)
  {
    if (!not_primes[i])
    {
      for (int j = i * i; j < Z; j += i)
        not_primes[j] = true;
    }
  }
  for (int i = 2; i < Z; ++i)
  {
    if (!not_primes[i])
      primes.push_back(i);
  }
  int k;
  while (scanf("%lld%d", &n, &k), n || k)
  {
    ++vid;
    printf("%lld\n", solve(0, k, 0));
  }
  return 0;
}
