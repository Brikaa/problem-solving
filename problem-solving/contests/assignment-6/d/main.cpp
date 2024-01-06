#include <cstdio>
#include <unordered_map>

typedef int ui;
typedef unsigned long long ull;

const ui N = 205;
const ui Q = 15;
ui n;
ui arr[N];
ui d;
std::unordered_map<ui, std::unordered_map<ui, std::unordered_map<ui, ui>>> memo;

ui solve(ui idx, ui remaining, ui sum)
{
  if (memo[idx][remaining].find(sum) != memo[idx][remaining].end())
    return memo[idx][remaining][sum];
  if (remaining == 0)
    return sum % d == 0;
  if (idx >= n)
    return 0;
  ui ret = solve(idx + 1, remaining - 1, sum + arr[idx]) + solve(idx + 1, remaining, sum);
  memo[idx][remaining][sum] = ret;
  return ret;
}

int main()
{
  ui q;
  ui t = 1;
  while (scanf("%u%u", &n, &q), q != 0 || n != 0)
  {
    for (ui i = 0; i < n; ++i)
      scanf("%u", arr + i);
    printf("SET %u:\n", t++);
    for (ui query = 1; query <= q; ++query)
    {
      memo.clear();
      ui m;
      scanf("%u%u", &d, &m);
      printf("QUERY %u: %u\n", query, solve(0, m, 0));
    }
  }
  return 0;
}
