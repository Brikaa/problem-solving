/*
row * c + col = x

2,1 = 2 * 4 + 1 = 9
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

typedef int ui;
typedef unsigned long long ull;

const ui R = 203;
const ui C = 203;
char grid[R][C];
std::vector<std::vector<ui>> adj;
ui distances_a[R * C];
ui distances_b[R * C];
ui distances_c[R * C];
ui visited_a[R * C];
ui visited_b[R * C];
ui visited_c[R * C];
ui vid;

void bfs(ui *distances, ui *visited, ui source)
{
  std::queue<ui> q;
  distances[source] = 0;
  visited[source] = vid;
  q.push(source);
  while (!q.empty())
  {
    ui elem = q.front();
    q.pop();
    for (auto neig : adj[elem])
    {
      if (visited[neig] != vid)
      {
        visited[neig] = vid;
        q.push(neig);
        distances[neig] = distances[elem] + 1;
      }
    }
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  ui t;
  std::cin >> t;
  while (t--)
  {
    ++vid;
    ui r, c;
    std::cin >> r >> c;
    adj.clear();
    adj.resize(r * c);
    for (ui row = 0; row < r; ++row)
    {
      std::string line;
      std::cin >> line;
      for (ui col = 0; col < c; ++col)
      {
        grid[row][col] = line[col];
      }
    }
    ui a_source, b_source, c_source;
    // Build the graph
    for (ui row = 0; row < r; ++row)
    {
      for (ui col = 0; col < c; ++col)
      {
        ui current = row * c + col;
        if (grid[row][col] == '1')
          a_source = current;
        else if (grid[row][col] == '2')
          b_source = current;
        else if (grid[row][col] == '3')
          c_source = current;
        if (col != 0 && grid[row][col - 1] != '#')
          adj[current].push_back(current - 1);
        if (row != 0 && grid[row - 1][col] != '#')
          adj[current].push_back((row - 1) * c + col);
        if (col != (c - 1) && grid[row][col + 1] != '#')
          adj[current].push_back(current + 1);
        if (row != (r - 1) && grid[row + 1][col] != '#')
          adj[current].push_back((row + 1) * c + col);
      }
    }
    bfs(distances_a, visited_a, a_source);
    bfs(distances_b, visited_b, b_source);
    bfs(distances_c, visited_c, c_source);

    // For each point, try to set it as the meeting point and check who has to walk the most
    ui ans = 1e9;
    for (ui point = 0; point < r * c; ++point)
    {
      if (distances_a[point] == 0 && distances_b[point] == 0 && distances_c[point] == 0)
        continue;
      ans = std::min(ans, std::max(std::max(distances_a[point], distances_b[point]), distances_c[point]));
    }
    std::cout << ans << '\n';
  }
  return 0;
}
