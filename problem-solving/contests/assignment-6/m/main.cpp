/*
FOXOD
FOOD
*/
#include <algorithm>
#include <cstdio>
#include <cstring>

typedef unsigned int ui;
typedef unsigned long long ull;

const int N = 2e3 + 5;
char first[N];
ui first_size;
char second[N];
ui second_size;
ui memo[N][N];
ui visited[N][N];
ui vid;

ui solve(ui fi, ui si)
{
  if (fi == first_size && si == second_size)
    return 0;
  ui &vis = visited[fi][si];
  ui &ret = memo[fi][si];
  if (vis != vid)
  {
    vis = vid;
    if (fi == first_size)
      ret = 1 + solve(fi, si + 1);
    else if (si == second_size)
      ret = 1 + solve(fi + 1, si);
    else if (first[fi] == second[si])
      ret = solve(fi + 1, si + 1);
    else
    {
      ui opt1 = solve(fi + 1, si + 1);
      ui opt2 = solve(fi + 1, si);
      ui opt3 = solve(fi, si + 1);
      ret = 1 + std::min(opt1, std::min(opt2, opt3));
    }
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
    scanf("%s", first);
    scanf("%s", second);
    first_size = strlen(first);
    second_size = strlen(second);
    printf("%u\n", solve(0, 0));
  }
  return 0;
}
