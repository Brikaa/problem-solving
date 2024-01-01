#include <cstdio>
#include <unordered_map>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

ui required;
ui first_cap;
ui second_cap;
std::unordered_map<ui, std::unordered_map<ui, ui>> memo;
std::unordered_map<ui, std::unordered_map<ui, ui>> visited;
ui vid;

ui solve(ui first, ui second, ui steps)
{
  fprintf(stderr, "%u %u %u\n", first_cap, second_cap, steps);
  if (visited[first][second] == vid)
    return memo[first][second];
  visited[first][second] = vid;
  ui &ret = memo[first][second];
  if (first > first_cap || second > second_cap)
    ret = -1;
  else if (first == required || second == required)
    ret = steps;
  else
    ret = std::min(
        std::min(
            std::min(
                solve(first - (second_cap - second), second_cap, steps + 1),
                solve(first_cap, second - (first_cap - first), steps + 1)),
            std::min(solve(0, second, steps + 1), solve(first, 0, steps + 1))),
        std::min(solve(first_cap, second, steps + 1), solve(first, second_cap, steps + 1)));
  return ret;
}

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    ++vid;
    scanf("%u%u%u", &first_cap, &second_cap, &required);
    ui res = solve(0, 0, 0);
    if (res > 1e9)
      puts("-1");
    else
      printf("%u\n", res);
  }
  return 0;
}
