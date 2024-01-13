#include <cstdio>

typedef unsigned int ui;
typedef unsigned long long ull;

ui n, k;
const int N = 103;
const int K = 103;
ui memo[3][N][K];
ui visited[3][N][K];
ui vid;

ui solve(ui prev, ui idx, ui no_equals)
{
  if (no_equals > k)
    return 0;
  if (idx == n)
    return no_equals == k;
  ui &vis = visited[prev][idx][no_equals];
  ui &ret = memo[prev][idx][no_equals];
  if (vis != vid)
  {
    vis = vid;
    ret = solve(0, idx + 1, no_equals) + solve(1, idx + 1, no_equals + (prev == 1));
  }
  return ret;
}

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    ++vid;
    ui t;
    scanf("%u%u%u", &t, &n, &k);
    printf("%u %u\n", t, solve(2, 0, 0));
  }
  return 0;
}
