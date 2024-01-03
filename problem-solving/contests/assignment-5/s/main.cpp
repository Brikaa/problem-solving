#include <vector>
#include <iostream>
#include <string>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 105;
std::vector<std::vector<ui>> adj;
char grid[N][N];
ui visited[N];
ui vid;
ui rows;
ui columns;

ui dfs(ui source)
{
  visited[source] = vid;
  ui no = 1;
  for (auto neig : adj[source])
    if (visited[neig] != vid)
      no += dfs(neig);
  return no;
}

void check_and_add(ui cr, ui cc, ui nr, ui nc)
{
  if (nr >= rows || nc >= columns)
    return;
  if (grid[cr][cc] == grid[nr][nc])
    adj[cr * columns + cc].push_back(nr * columns + nc);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  ui t;
  std::cin >> t;
  std::cin.ignore();
  while (t--)
  {
    ++vid;
    rows = 0;
    columns = 0;
    ui ir, ic;
    std::cin >> ir >> ic;
    std::cerr << vid << '\n';
    std::cin.ignore();
    std::string line;

    while (std::getline(std::cin, line), line != "")
    {
      columns = line.size() + 2;
      grid[rows + 1][0] = grid[rows + 1][columns - 1] = '1';
      for (ui c = 1; c <= line.size(); ++c)
        grid[rows + 1][c] = line[c - 1];
      ++rows;
    }
    rows += 2;
    for (ui c = 0; c < columns; ++c)
      grid[0][c] = grid[rows - 1][c] = '1';

    adj.clear();
    adj.resize(rows * columns);

    for (ui r = 0; r < rows; ++r)
    {
      for (ui c = 0; c < columns; ++c)
      {
        check_and_add(r, c, r + 1, c);
        check_and_add(r, c, r - 1, c);
        check_and_add(r, c, r, c + 1);
        check_and_add(r, c, r, c - 1);
      }
    }

    std::cout << dfs(ir * columns + ic) << (t == 0 ? "\n" : "\n\n");
  }
  return 0;
}
