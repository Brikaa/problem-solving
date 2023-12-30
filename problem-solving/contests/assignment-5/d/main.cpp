/*
row * c + col = x

2,1 = 2 * 4 + 1 = 9

4
3
3
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cassert>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui R = 205;
const ui C = 205;
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
    r += 2;
    c += 2;
    adj.clear();
    adj.resize(r * c);
    for (ui row = 1; row < r - 1; ++row)
    {
      std::string line;
      std::cin >> line;
      for (ui col = 1; col < c - 1; ++col)
      {
        grid[row][col] = line[col - 1];
      }
    }
    for (ui row = 0; row < r; ++row)
    {
      grid[row][0] = '.';
      grid[row][c - 1] = '.';
    }
    for (ui column = 0; column < r; ++column)
    {
      grid[0][column] = '.';
      grid[r - 1][column] = '.';
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
      if (visited_a[point] != vid && visited_b[point] != vid && visited_c[point] != vid)
        continue;
      assert((visited_a[point] == vid && visited_b[point] == vid && visited_c[point] == vid));
      ans = std::min(ans, std::max(std::max(distances_a[point], distances_b[point]), distances_c[point]));
    }
    std::cout << ans << '\n';
  }
  return 0;
}
