#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 103;
ui grid[N][N];
ui pid;
std::vector<std::vector<ui>> adj;
ui partitions[N * N];
bool taken_partitions[N * N];
bool visited[N * N];

ui dfs(ui source)
{
  visited[source] = true;
  ui no = 1;
  for (auto neig : adj[source])
    if (!visited[neig])
      no += dfs(neig);
  return no;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  ui n;
  while (std::cin >> n, n)
  {
    std::cin.ignore();
    std::memset(grid, 0, sizeof(grid));
    std::fill(std::begin(visited), std::end(visited), 0);
    std::fill(std::begin(taken_partitions), std::end(taken_partitions), 0);
    std::fill(std::begin(partitions), std::end(partitions), 0);
    adj.clear();
    adj.resize(n * n);
    pid = 0;

    for (ui partition = 0; partition < n - 1; ++partition)
    {
      ++pid;
      std::string line;
      std::getline(std::cin, line);
      std::stringstream ss(line);
      ui i, j;
      while (ss >> i >> j)
      {
        grid[i - 1][j - 1] = pid;
        partitions[(i - 1) * n + j - 1] = pid;
      }
    }
    for (ui r = 0; r < n; ++r)
    {
      for (ui c = 0; c < n; ++c)
      {
        const ui current = r * n + c;
        if (r != 0 && grid[r - 1][c] == grid[r][c])
          adj[current].push_back((r - 1) * n + c);
        if (r != n - 1 && grid[r + 1][c] == grid[r][c])
          adj[current].push_back((r + 1) * n + c);
        if (c != 0 && grid[r][c - 1] == grid[r][c])
          adj[current].push_back(current - 1);
        if (c != n - 1 && grid[r][c + 1] == grid[r][c])
          adj[current].push_back(current + 1);
      }
    }
    ui no_components = 0;
    bool valid = true;
    for (ui i = 0; i < n * n && no_components <= n && valid; ++i)
    {
      if (!visited[i])
      {
        ui no = dfs(i);
        if (no != n || taken_partitions[partitions[i]])
        {
          valid = false;
          break;
        }
        ++no_components;
        taken_partitions[partitions[i]] = true;
      }
    }
    printf("%s\n", no_components == n && valid ? "good" : "wrong");
  }
  return 0;
}
