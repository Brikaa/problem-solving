#include <cstdio>
#include <unordered_map>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 205;
const ui Q = 15;
ui n;
ui arr[N];
ui d;

ui solve(ui idx, ui remaining, ui sum)
{
  if (remaining == 0)
    return sum % d == 0;
  if (idx >= n)
    return 0;
  return solve(idx + 1, remaining - 1, sum + arr[idx]) + solve(idx + 1, remaining, sum);
}

int main()
{
  ui q;
  scanf("%u%u", &n, &q);
  for (ui i = 0; i < n; ++i)
    scanf("%u", arr + i);
  while (q--)
  {
    ui m;
    scanf("%u%u", &d, &m);
    printf("%u\n", solve(0, m, 0));
  }
  return 0;
}
