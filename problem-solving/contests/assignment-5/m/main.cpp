#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 505;
std::vector<std::vector<ui>> dependency_adj;
std::vector<std::vector<ui>> dependents_adj;
std::vector<ui> zero_in_degrees;
ui completion_times[N];
ui min_start_times[N];
ui vid;

ui max_start_time(ui target, std::vector<ui> in_degrees)
{
  std::queue<ui> q;
  for (auto elem : zero_in_degrees)
    q.push(elem);
  ui time = 0;
  while (!q.empty())
  {
    ui elem = q.front();
    q.pop();
    if (elem == target)
      continue;
    time += completion_times[elem];
    for (auto neig : dependents_adj[elem])
    {
      --in_degrees[neig];
      if (in_degrees[neig] == 0)
        q.push(neig);
    }
  }
  return time;
}

void compute_min_start_times(std::vector<ui> in_degrees)
{
  std::queue<ui> q;
  for (auto elem : zero_in_degrees)
  {
    min_start_times[elem] = 0;
    q.push(elem);
  }
  while (!q.empty())
  {
    ui elem = q.front();
    q.pop();
    for (auto neig : dependents_adj[elem])
    {
      min_start_times[neig] += min_start_times[elem] + completion_times[elem];
      --in_degrees[neig];
      if (in_degrees[neig] == 0)
        q.push(neig);
    }
  }
}

int main()
{
  ui v, e;
  while (scanf("%u%u", &v, &e), v || e)
  {
    ++vid;
    printf("Case #%u:\n", vid);

    dependency_adj.clear();
    dependency_adj.resize(v);
    dependents_adj.clear();
    dependents_adj.resize(v);
    zero_in_degrees.clear();
    std::fill(std::begin(min_start_times), std::end(min_start_times), 0);

    for (ui i = 0; i < v; ++i)
      scanf("%u", completion_times + i);

    for (ui i = 0; i < e; ++i)
    {
      ui x, y;
      scanf("%u%u", &x, &y);
      --y;
      --x;
      dependency_adj[y].push_back(x);
      dependents_adj[x].push_back(y);
    }

    std::vector<ui> in_degrees;
    in_degrees.resize(v);
    for (ui i = 0; i < v; ++i)
    {
      for (auto neig : dependents_adj[i])
        ++in_degrees[neig];
    }

    for (ui i = 0; i < v; ++i)
      if (in_degrees[i] == 0)
        zero_in_degrees.push_back(i);

    compute_min_start_times(in_degrees);

    ui q;
    scanf("%u", &q);
    for (ui i = 0; i < q; ++i)
    {
      ui x;
      scanf("%u", &x);
      --x;
      printf("%u\n", max_start_time(x, in_degrees) - min_start_times[x]);
    }
    puts("");
  }
  return 0;
}
