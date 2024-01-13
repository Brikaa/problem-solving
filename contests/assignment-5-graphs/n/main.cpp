/*
aaabbaab

babbbaaabb
*/
#include <string>
#include <unordered_map>
#include <iostream>

typedef unsigned int ui;
typedef unsigned long long ull;

std::unordered_map<std::string, bool> memo;

bool solve(std::string target)
{
  if (target == "")
    return true;
  if (memo.find(target) != memo.end())
    return memo[target];
  bool solved = false;
  ui no_consecutive = 1;
  ui consecutive_start = 0;
  ui size = target.size();
  for (ui i = 1; i < size + 1 && !solved; ++i)
  {
    if (i < size && target[i] == target[i - 1])
      ++no_consecutive;
    else
    {
      if (no_consecutive >= 2)
        solved |= solve(
          target.substr(0, consecutive_start)
          + target.substr(consecutive_start + no_consecutive, size - i));
      no_consecutive = 1;
      consecutive_start = i;
    }
  }
  memo[target] = solved;
  return solved;
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
    std::string s;
    std::cin >> s;
    std::cout << solve(s) << '\n';
  }
  return 0;
}
