#include <cstdio>
#include <cstring>

const long long N = 205;
const long long D = 25;
long long n;
long long arr[N];
long long d;
long long memo[N][N][D];
long long visited[N][N][D];
long long vid;

long long solve(long long idx, long long remaining, long long mod)
{
  if (remaining == 0)
    return mod == 0;
  if (idx >= n)
    return 0;
  if (visited[idx][remaining][mod] == vid)
    return memo[idx][remaining][mod];
  long long m = (mod + arr[idx]) % d;
  if (m < 0) m += d;
  long long ret = solve(idx + 1, remaining - 1, m) + solve(idx + 1, remaining, mod);
  memo[idx][remaining][mod] = ret;
  visited[idx][remaining][mod] = vid;
  return ret;
}

int main()
{
  long long q;
  long long t = 1;
  while (scanf("%lld%lld", &n, &q), q != 0 || n != 0)
  {
    for (long long i = 0; i < n; ++i)
      scanf("%lld", arr + i);
    printf("SET %lld:\n", t++);
    for (long long query = 1; query <= q; ++query)
    {
      ++vid;
      long long m;
      scanf("%lld%lld", &d, &m);
      printf("QUERY %lld: %lld\n", query, solve(0, m, 0));
    }
  }
  return 0;
}
