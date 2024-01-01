#include <cstdio>
#include <unordered_map>
#include <algorithm>

typedef int ui;
typedef long long ull;

ull required;
ull first_cap;
ull second_cap;
std::unordered_map<ull, std::unordered_map<ull, ull>> memo;
std::unordered_map<ull, std::unordered_map<ull, ull>> visited;
// vid - 1 = unvisited
// vid = processing
// vid + 1 = visited
ull vid;

ull solve(ull first, ull second)
{
  if (visited[first][second] == vid || first < 0 || second < 0 || first > first_cap || second > second_cap)
    return 1e9;
  else if (first == required || second == required)
    return 0;
  else if (visited[first][second] == vid + 1)
    return memo[first][second];
  visited[first][second] = vid;
  ull &ret = memo[first][second];
  ull opt1 = solve(first - (second_cap - second), second_cap);
  ull opt2 = solve(0, second);
  ull opt3 = solve(first_cap, second);
  ull opt4 = solve(0, second + first);
  ull min1 = std::min(std::min(opt1, opt4), std::min(opt2, opt3));

  opt1 = solve(first_cap, second - (first_cap - first));
  opt2 = solve(first, 0);
  opt3 = solve(first, second_cap);
  opt4 = solve(first + second, 0);
  ull min2 = std::min(std::min(opt1, opt4), std::min(opt2, opt3));

  ret = 1 + std::min(min1, min2);
  visited[first][second] = vid + 1;
  return ret;
}

int main()
{
  ull t;
  scanf("%llu", &t);
  while (t--)
  {
    vid += 3;
    scanf("%llu%llu%llu", &first_cap, &second_cap, &required);
    ull res = solve(0, 0);
    if (res >= 1e9)
      puts("-1");
    else
      printf("%llu\n", res);
  }
  return 0;
}
