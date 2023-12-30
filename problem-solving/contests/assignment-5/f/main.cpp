/*
-----x---
-----xxxx
*/
#include <iostream>
#include <string>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 1e5 + 5;
std::string left_wall;
std::string right_wall;
ui current_index;
bool in_right;
bool visited[2][N];
ui n, k;

bool increase_current_index(int delta)
{
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
  std::string &current_wall = in_right ? right_wall : left_wall;
  if (current_wall[current_index] == 'X')
    return false;
  while (current_index != n - 1 && current_wall[current_index + 1] != 'X')
    if (!increase_current_index(1))
      return false;
  bool solved = false;
  // After I go to the opposite wall, I can jump higher than where I was
  // const ui original_index = current_index;
  while (~current_index && current_wall[current_index] != 'X')
  {
    in_right = !in_right;
    if (!increase_current_index(k))
      return false;
    solved |= solve();
    if (solved)
      break;
    in_right = !in_right;
    increase_current_index(-k);
    increase_current_index(-1);
  }
  return solved;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n >> k;
  std::cin >> left_wall;
  std::cin >> right_wall;
  std::cout << (solve() ? "YES" : "NO") << '\n';
  return 0;
}
