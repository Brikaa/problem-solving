#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;
const ui N = 29;
std::vector<std::vector<ui>> adj;
std::vector<ui> search_space;
std::queue<ui> bfs_queue;
char grid[N][N];
ui visited[N * N];
ui vid;

ui bfs(ui source)
{
  visited[source] = vid;
  ui no = 0;
  bfs_queue.push(source);
  while (!bfs_queue.empty())
  {
    ++no;
    ui elem = bfs_queue.front();
    bfs_queue.pop();
    for (auto neig : adj[elem])
    {
      if (visited[neig] != vid)
      {
        visited[neig] = vid;
        bfs_queue.push(neig);
      }
    }
  }
  return no;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ui t;
  std::cin >> t;
  std::cin.ignore();
  std::cin.ignore();
  while (t--)
  {
    ++vid;
    search_space.clear();
    // Construct grid
    ui rows = 0;
    ui columns = 0;
    std::string line = "";
    while (std::getline(std::cin, line), !line.empty())
    {
      columns = 0;
      for (auto c : line)
        grid[rows][columns++] = c;
      ++rows;
    }
    adj.clear();
    adj.resize(rows * columns);
    // Construct graph
    for (ui r = 0; r < rows; ++r)
    {
      for (ui c = 0; c < columns; ++c)
      {
        if (grid[r][c] == '0')
          continue;
        const ui current = r * columns + c;
        const ui top = (r - 1) * columns + c;
        const ui bottom = (r + 1) * columns + c;

        search_space.push_back(current);
        if (r != 0 && c != 0 && grid[r - 1][c - 1] == '1')
          adj[current].push_back(top - 1);
        if (r != 0 && grid[r - 1][c] == '1')
          adj[current].push_back(top);
        if (r != 0 && c != columns - 1 && grid[r - 1][c + 1] == '1')
          adj[current].push_back(top + 1);

        if (c != columns - 1 && grid[r][c + 1] == '1')
          adj[current].push_back(current + 1);

        if (r != rows - 1 && c != 0 && grid[r + 1][c - 1] == '1')
          adj[current].push_back(bottom - 1);
        if (r != rows - 1 && grid[r + 1][c] == '1')
          adj[current].push_back(bottom);
        if (r != rows - 1 && c != columns - 1 && grid[r + 1][c + 1] == '1')
          adj[current].push_back(bottom + 1);

        if (c != 0 && grid[r][c - 1] == '1')
          adj[current].push_back(current - 1);
      }
    }

    // Count components
    ui ans = 0;
    for (auto node : search_space)
    {
      if (visited[node] != vid)
        ans = std::max(ans, bfs(node));
    }
    std::cout << ans << (t == 0 ? "\n" : "\n\n");
  }
  return 0;
}
