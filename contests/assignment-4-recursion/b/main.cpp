#include <cstdio>
#include <vector>
#include <string>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 10;
const ui M = N;
ui n, m;
char maze[N][M];
std::vector<std::string> sol;
const std::string letters = "IEOHOVA#";

void solve(ui r, ui c, char prev)
{
  if (maze[r][c] == '#')
  {
    for (ui i = 0; i < sol.size(); ++i)
      printf("%s%c", sol[i].c_str(), " \n"[i == sol.size() - 1]);
    return;
  }
  if (~(c - 1) && letters.find(maze[r][c - 1]) != std::string::npos && maze[r][c - 1] != prev)
  {
    sol.push_back("left");
    solve(r, c - 1, maze[r][c]);
    sol.pop_back();
  }
  if (~(r - 1) && letters.find(maze[r - 1][c]) != std::string::npos)
  {
    sol.push_back("forth");
    solve(r - 1, c, maze[r][c]);
    sol.pop_back();
  }
  if (((c + 1) < m) && letters.find(maze[r][c + 1]) != std::string::npos && maze[r][c + 1] != prev)
  {
    sol.push_back("right");
    solve(r, c + 1, maze[r][c]);
    sol.pop_back();
  }
}

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    sol.clear();
    scanf("%u%u", &n, &m);
    for (ui i = 0; i < n; ++i)
      scanf("%s", maze[i]);
    ui at_row = 0;
    ui at_column = 0;
    bool found = false;
    for (; at_row < n && !found; ++at_row)
    {
      for (at_column = 0; at_column < m && !found; ++at_column)
      {
        if (maze[at_row][at_column] == '@')
          found = true;
      }
    }
    --at_row;
    --at_column;
    fprintf(stderr, "%u %u\n", at_row, at_column);
    solve(at_row, at_column, '@');
    for (ui i = 0; i < sol.size(); ++i)
      fprintf(stderr, "%s%c", sol[i].c_str(), " \r"[i == sol.size() - 1]);
  }
  return 0;
}
