#include <cstdio>
#include <unordered_map>

const long long N = 205;
long long n;
long long arr[N];
long long d;
std::unordered_map<long long, long long> memo[N][N];
std::unordered_map<long long, long long> visited[N][N];
long long vid;

long long solve(long long idx, long long remaining, long long sum)
{
  if (n - idx < remaining)
    return 0;
  if (remaining == 0)
    return sum % d == 0;
  if (visited[idx][remaining][sum] == vid)
    return memo[idx][remaining][sum];
  long long ret = solve(idx + 1, remaining - 1, sum + arr[idx]) + solve(idx + 1, remaining, sum);
  memo[idx][remaining][sum] = ret;
  visited[idx][remaining][sum] = vid;
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
