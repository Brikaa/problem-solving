/*
   0 0 E
   T T 0
   0 0 0
   1 T 0
       0
       s
*/
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui R = 1005;
const ui C = 1005;
char grid[R][C];
std::vector<std::vector<ui>> adj;
bool visited[R * C];
ui distances[R * C];
std::vector<ui> enemy_cells;
std::vector<ui> enemy_count_in_cell;

void bfs(ui source)
{
  visited[source] = true;
  distances[source] = 0;
  std::queue<ui> q;
  q.push(source);
  while (!q.empty())
  {
    ui elem = q.front();
    q.pop();
    for (auto neig : adj[elem])
    {
      if (!visited[neig])
      {
        visited[neig] = true;
        distances[neig] = distances[elem] + 1;
        q.push(neig);
      }
    }
  }
}

int main()
{
  ui rows, columns;
  scanf("%u%u", &rows, &columns);
  for (ui r = 0; r < rows; ++r)
    scanf("%s", grid[r]);
  adj.resize(rows * columns);
  enemy_count_in_cell.resize(rows * columns);
  std::fill(std::begin(distances), std::end(distances), 1e9);

  ui my_character_cell;
  ui exit_cell;
  for (ui r = 0; r < rows; ++r)
  {
    for (ui c = 0; c < columns; ++c)
    {
      const ui current = r * columns + c;
      const ui top = (r - 1) * columns + c;
      const ui bottom = (r + 1) * columns + c;
      if (grid[r][c] == 'T')
        continue;
      else if (grid[r][c] == 'E')
        exit_cell = current;
      else if (grid[r][c] == 'S')
        my_character_cell = current;
      else if (grid[r][c] != '0')
      {
        enemy_cells.push_back(current);
        enemy_count_in_cell[current] = grid[r][c] - '0';
      }
      if (r != 0 && grid[r - 1][c] != 'T')
        adj[current].push_back(top);
      if (r != rows - 1 && grid[r + 1][c] != 'T')
        adj[current].push_back(bottom);
      if (c != 0 && grid[r][c - 1] != 'T')
        adj[current].push_back(current - 1);
      if (c != columns - 1 && grid[r][c + 1] != 'T')
        adj[current].push_back(current + 1);
    }
  }

  bfs(exit_cell);
  ui battles = 0;
  for (auto enemy_cell : enemy_cells)
    battles += (distances[enemy_cell] <= distances[my_character_cell]) * enemy_count_in_cell[enemy_cell];
  printf("%u\n", battles);
  return 0;
}
