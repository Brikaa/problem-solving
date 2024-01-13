/*
-----x---
-----xxxx

============= Test case 1.in =============
YES
============= Test case 2.in =============
NO
============= Test case 3.in =============
NO
============= Test case 4.in =============
YES
============= Test case 5.in =============
YES
============= Test case 6.in =============
YES
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

bool solve(ui water_level, ui in_right, ui current_index)
{
  if (current_index >= n)
    return true;
  if (visited[in_right][current_index])
    return false;
  visited[in_right][current_index] = true;
  if (water_level >= current_index)
    return false;
  std::string &current_wall = in_right ? right_wall : left_wall;
  if (current_wall[current_index] == 'X')
    return false;
  return solve(water_level + 1, !in_right, current_index + k) ||
         solve(water_level + 1, in_right, current_index + 1) ||
         solve(water_level + 1, in_right, current_index - 1);
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
