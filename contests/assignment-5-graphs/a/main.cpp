/*
- Pick the employees who lead to the least number of workers
*/
#include <cstdio>
#include <vector>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 1e5 + 5;
std::vector<std::vector<ui>> adj;
std::vector<std::vector<ui>> levels;
std::vector<ui> solutions;
ui n, t;

bool less_than(ui n1, ui n2)
{
  return solutions[n1] < solutions[n2];
}

ui solve(ui node)
{
  if (adj[node].size() == 0)
    return 1;
  for (ui child : adj[node])
    solutions[child] = solve(child);
  std::sort(adj[node].begin(), adj[node].end(), less_than);
  ui no_workers = 0;
  ui taken = 0;
  while (taken < adj[node].size() * t / 100.0)
    no_workers += solutions[adj[node][taken++]];
  return no_workers;
}

int main()
{
  solutions.resize(N);
  while (scanf("%u%u", &n, &t), n != 0)
  {
    adj.clear();
    adj.resize(n + 3);
    for (ui i = 1; i <= n; ++i)
    {
      ui parent;
      scanf("%u", &parent);
      adj[parent].push_back(i);
    }
    printf("%u\n", solve(0));
  }
  return 0;
}
