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
bool visited[2][N];
ui n, k;

// bool increase_current_index(int delta)
// {
//   std::cerr << current_index << ' ' << current_index + delta << '\n';
//   current_index += delta;
//   if (visited[in_right][current_index])
//     return false;
//   visited[in_right][current_index] = true;
//   return true;
// }

bool solve(ui water_level, ui in_right, ui current_index)
{
  if (current_index >= n)
    return true;
  if (water_level >= current_index)
    return false;
  std::string &current_wall = in_right ? right_wall : left_wall;
  if (current_wall[current_index] == 'X')
    return false;

  while (current_index != n - 1 && current_wall[current_index + 1] != 'X')
  {
    if (solve(water_level + 1, !in_right, current_index + k))
      return true;

    ++current_index;
    ++water_level;
  }

  while (~current_index && current_wall[current_index] != 'X')
  {
    if (solve(water_level + 1, !in_right, current_index + k))
      return true;

    --current_index;
    ++water_level;
    if (water_level >= current_index)
      return false;
  }
  return false;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n >> k;
  std::cin >> left_wall;
  std::cin >> right_wall;
  std::cout << (solve(-1, false, 0) ? "YES" : "NO") << '\n';
  return 0;
}
