#include <iostream>
#include <vector>
#include <string>
#include <queue>

typedef unsigned int ui;
typedef unsigned long long ull;
const ui N = 29;
std::vector<std::vector<ui>> adj;
std::vector<ui> search_space;
std::queue<ui> bfs_queue;
char grid[N][N];
ui visited[N * N];
ui vid;

void bfs(ui source)
{
  visited[source] = vid;
  bfs_queue.push(source);
  while (!bfs_queue.empty())
  {
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
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ui n;
  while (std::cin >> n)
  {
    ++vid;
    adj.clear();
    adj.resize(n * n);
    search_space.clear();
    // Construct grid
    std::string line = "";
    for (ui r = 0; r < n; ++r)
    {
      std::cin >> line;
      for (ui c = 0; c < n; ++c)
        grid[r][c] = line[c];
    }

    // Construct graph
    for (ui r = 0; r < n; ++r)
    {
      for (ui c = 0; c < n; ++c)
      {
        if (grid[r][c] == '0')
          continue;
        const ui current = r * n + c;
        const ui top = (r - 1) * n + c;
        const ui bottom = (r + 1) * n + c;

        search_space.push_back(current);
        if (r != 0 && c != 0 && grid[r - 1][c - 1] == '1')
          adj[current].push_back(top - 1);
        if (r != 0 && grid[r - 1][c] == '1')
          adj[current].push_back(top);
        if (r != 0 && c != n - 1 && grid[r - 1][c + 1] == '1')
          adj[current].push_back(top + 1);

        if (c != n - 1 && grid[r][c + 1] == '1')
          adj[current].push_back(current + 1);

        if (r != n - 1 && c != 0 && grid[r + 1][c - 1] == '1')
          adj[current].push_back(bottom - 1);
        if (r != n - 1 && grid[r + 1][c] == '1')
          adj[current].push_back(bottom);
        if (r != n - 1 && c != n - 1 && grid[r + 1][c + 1] == '1')
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
      {
        bfs(node);
        ++ans;
      }
    }
    std::cout << "Image number " << vid << " contains " << ans << " war eagles." << '\n';
  }
  return 0;
}
