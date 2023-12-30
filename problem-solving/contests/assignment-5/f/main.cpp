/*
-----x---
-----xxxx
*/
#include <iostream>
#include <string>

typedef int ui;
typedef unsigned long long ull;

const ui N = 1e5 + 5;
std::string left_wall;
std::string right_wall;
ui current_index;
bool in_right;
bool visited[2][N];
ui n, k;
ui water_level;

bool increase_current_index(int delta)
{
  std::cerr << current_index << ' ' << current_index + delta << '\n';
  current_index += delta;
  if (visited[in_right][current_index])
    return false;
  visited[in_right][current_index] = true;
  return true;
}

bool solve()
{
  if (current_index >= n)
    return true;
  if (water_level >= current_index)
    return false;
  std::string &current_wall = in_right ? right_wall : left_wall;
  if (current_wall[current_index] == 'X')
    return false;

  bool solved = false;

  while (current_index != n - 1 && current_wall[current_index + 1] != 'X')
  {
    in_right = !in_right;
    if (!increase_current_index(k))
      return false;
    ++water_level;
    solved |= solve();
    if (solved)
      return true;
    in_right = !in_right;
    increase_current_index(-k);
    --water_level;

    if (!increase_current_index(1))
      return false;
    ++water_level;
  }

  while (~current_index && current_wall[current_index] != 'X')
  {
    in_right = !in_right;
    if (!increase_current_index(k))
      return false;
    ++water_level;
    solved |= solve();
    if (solved)
      return true;
    in_right = !in_right;
    increase_current_index(-k);
    --water_level;

    if (!increase_current_index(-1))
      return false;
    ++water_level;
    if (water_level >= current_index)
      return false;
  }
  return solved;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  water_level = -1;
  std::cin >> n >> k;
  std::cin >> left_wall;
  std::cin >> right_wall;
  std::cout << (solve() ? "YES" : "NO") << '\n';
  return 0;
}
