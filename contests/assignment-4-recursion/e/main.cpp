#include <cstdio>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 8;
ui board[N][N];
bool placed[N][N];

bool valid(ui r, ui c)
{
  ui c_factor = 1;
  for (ui i = r - 1; ~i; --i)
  {
    if (placed[i][c] || (c >= c_factor && placed[i][c - c_factor]) || (c + c_factor < N && placed[i][c + c_factor]))
      return false;
    ++c_factor;
  }
  return true;
}

ui solve(ui r, ui sum)
{
  if (r == N)
    return sum;
  ui res = 0;
  for (ui c = 0; c < N; ++c)
  {
    if (valid(r, c))
    {
      placed[r][c] = true;
      res = std::max(res, solve(r + 1, sum + board[r][c]));
      placed[r][c] = false;
    }
  }
  return res;
}

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    for (ui r = 0; r < N; ++r)
      for (ui c = 0; c < N; ++c)
        scanf("%u", &(board[r][c]));
    printf("%5u\n", solve(0, 0));
  }
  return 0;
}
