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

ui solve(ui fi, ui si)
{
  if (fi == first_size && si == second_size)
    return 0;
  if (fi == first_size)
    return 1 + solve(fi, si + 1);
  if (si == second_size)
    return 1 + solve(fi + 1, si);
  if (first[fi] == second[si])
    return solve(fi + 1, si + 1);
  ui opt1 = solve(fi + 1, si + 1);
  ui opt2 = solve(fi + 1, si);
  ui opt3 = solve(fi, si + 1);
  return 1 + std::min(opt1, std::min(opt2, opt3));
}

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    scanf("%s", first);
    scanf("%s", second);
    first_size = strlen(first);
    second_size = strlen(second);
    printf("%u\n", solve(0, 0));
  }
  return 0;
}
