#include <cstdio>
#include <vector>

typedef unsigned int ui;
typedef unsigned long long ull;

const int Z = 1e4;
int not_primes[Z];
std::vector<ull> primes;
const int N = 1500;
const int K = 20;
ull n;
ull memo[1220][K][N];
ui visited[1220][K][N];
ui vid;

ull solve(ui idx, ull rem, ull sum)
{
  if (rem == 0)
    return sum == n;
  if (sum + primes[idx] > n)
    return 0;
  ull &ret = memo[idx][rem][sum];
  if (visited[idx][rem][sum] != vid)
  {
    ret = solve(idx + 1, rem - 1, sum + primes[idx]) + solve(idx + 1, rem, sum);
    visited[idx][rem][sum] = vid;
  }
  return ret;
}

int main()
{
  for (ui i = 2; i * i < Z; ++i)
  {
    if (!not_primes[i])
    {
      for (ui j = i * i; j < Z; j += i)
        not_primes[j] = true;
    }
  }
  for (ui i = 2; i < Z; ++i)
  {
    if (!not_primes[i])
      primes.push_back(i);
  }
  ull k;
  while (scanf("%llu%llu", &n, &k), n || k)
  {
    ++vid;
    printf("%llu\n", solve(0, k, 0));
  }
  return 0;
}
