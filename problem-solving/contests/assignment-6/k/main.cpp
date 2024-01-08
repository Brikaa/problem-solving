#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

typedef unsigned int ui;
typedef unsigned long long ull;

const int N = 32;
const int T = 1e3 + 3;
int values[N];
int depths[N];
int costs[N];
int n;
int memo[N][T];
int visited[N][T];
int vid;

int solve(int idx, int remaining_time)
{
  if (idx >= n)
    return 0;
  int &vis = visited[idx][remaining_time];
  int &ret = memo[idx][remaining_time];
  if (vis == vid)
    return ret;
  vis = vid;
  if (costs[idx] > remaining_time)
    ret = solve(idx + 1, remaining_time);
  else
    ret = std::max(values[idx] + solve(idx + 1, remaining_time - costs[idx]), solve(idx + 1, remaining_time));
  return ret;
}

int cost(int w, int depth)
{
  return w * depth + 2 * w * depth;
}

int main()
{
  int t, w;
  bool first = true;
  while (scanf("%d%d%d", &t, &w, &n) != EOF)
  {
    if (!first)
      puts("");
    first = false;
    ++vid;
    for (int i = 0; i < n; ++i)
    {
      scanf("%d%d", depths + i, values + i);
      costs[i] = cost(w, depths[i]);
    }
    int best = solve(0, t);

    std::vector<std::pair<int, int>> sol;
    int taken_values = 0;
    int remaining_time = t;
    for (int i = 0; i < n; ++i)
    {
      int res = solve(i + 1, remaining_time);
      if (res + taken_values != best)
      {
        sol.push_back(std::make_pair(depths[i], values[i]));
        taken_values += values[i];
        remaining_time -= costs[i];
      }
    }

    printf("%d\n%lu\n", best, sol.size());
    for (auto p : sol)
      printf("%d %d\n", p.first, p.second);
  }
  return 0;
}
