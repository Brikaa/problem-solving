#include <cstdio>
#include <unordered_map>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

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
  if (visited[first][second] == vid)
    return 1e9;
  else if (visited[first][second] == vid + 1)
    return memo[first][second];
  visited[first][second] = vid;
  ull &ret = memo[first][second];
  if (first == required || second == required)
    ret = 0;
  else
  {
    ull opt1 = first <= first - (second_cap - second) ? 1e9 : 1 + solve(first - (second_cap - second), second_cap);
    ull opt2 = first == 0 ? 1e9 : 1 + solve(0, second);
    ull opt3 = first == first_cap ? 1e9 : 1 + solve(first_cap, second);
    ull min1 = std::min(opt1, std::min(opt2, opt3));

    opt1 = second <= second - (first_cap - first) ? 1e9 : 1 + solve(first_cap, second - (first_cap - first));
    opt2 = second == 0 ? 1e9 : 1 + solve(first, 0);
    opt3 = second == second_cap ? 1e9 : 1 + solve(first, second_cap);
    ull min2 = std::min(opt1, std::min(opt2, opt3));

    ret = std::min(min1, min2);
  }
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
