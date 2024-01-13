#include <algorithm>
#include <cstdio>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 1e5 + 5;
ull first_row[N];
ull second_row[N];
ui n;
ull memo[N][2][2];
bool visited[N][2][2];

ull solve(ui idx, bool first_available, bool second_available)
{
  if (idx >= n)
    return 0;
  ull &ret = memo[idx][first_available][second_available];
  bool &vis = visited[idx][first_available][second_available];
  if (vis)
    return ret;
  vis = true;
  ret = solve(idx + 1, true, true);
  if (first_available)
    ret = std::max(ret, first_row[idx] + solve(idx + 1, false, true));
  if (second_available)
    ret = std::max(ret, second_row[idx] + solve(idx + 1, true, false));
  return ret;
}

int main()
{
  scanf("%u", &n);
  for (ui i = 0; i < n; ++i)
    scanf("%llu", first_row + i);
  for (ui i = 0; i < n; ++i)
    scanf("%llu", second_row + i);
  printf("%llu\n", solve(0, true, true));
  return 0;
}
