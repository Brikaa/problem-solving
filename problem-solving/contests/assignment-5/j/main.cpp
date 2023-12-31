#include <cstdio>
#include <vector>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 103;
ui grid[N][N];
ui pid;
std::vector<std::vector<ui>> adj;
ui visited[N * N];
ui vid;

void dfs(ui source)
{
  visited[source] = vid;
  for (auto neig : adj[source])
    if (visited[neig] != vid)
      dfs(neig);
}

int main()
{
  ui n;
  while (scanf("%u", &n), n)
  {
    ++vid;
    adj.clear();
    adj.resize(n * n);
    for (ui partition = 0; partition < n - 1; ++partition)
    {
      ++pid;
      for (ui pair = 0; pair < n; ++pair)
      {
        ui i, j;
        scanf("%u%u", &i, &j);
        grid[i - 1][j - 1] = pid;
      }
    }
    for (ui r = 0; r < n; ++r)
    {
      for (ui c = 0; c < n; ++c)
      {
        const ui current = r * n + c;
        const ui top = (r - 1) * n + c;
        const ui bottom = (r + 1) * n + c;
        if (r != 0 && grid[r - 1][c] == grid[r][c])
          adj[current].push_back(top);
        if (r != n - 1 && grid[r + 1][c] == grid[r][c])
          adj[current].push_back(bottom);
        if (c != 0 && grid[r][c - 1] == grid[r][c])
          adj[current].push_back(current - 1);
        if (c != n - 1 && grid[r][c + 1] == grid[r][c])
          adj[current].push_back(current + 1);
      }
    }
    ui no_components = 0;
    for (ui i = 0; i < n * n && no_components <= n; ++i)
    {
      if (visited[i] != vid)
      {
        ++no_components;
        dfs(i);
      }
    }
    printf("%s\n", no_components == n ? "good" : "wrong");
  }
  return 0;
}
