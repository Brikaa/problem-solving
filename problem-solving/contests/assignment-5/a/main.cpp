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
std::vector<ui> leaves;

ui count_leaves(ui node, ui parent)
{
  if (adj[node].size() == 0)
    return 0;
  ui no_leaves = 0;
  for (ui child : adj[node])
  {
    if (child == parent)
      continue;
    if (adj[child].size() == 0)
      ++no_leaves;
    else
      no_leaves += count_leaves(child, node);
  }
  return no_leaves;
}

bool less_than(ui n1, ui n2)
{
  return leaves[n1] < leaves[n2];
}

int main()
{
  leaves.resize(N);
  ui n, t;
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
    for (ui second : adj[0])
    {
      leaves[second] = count_leaves(second, 0);
    }
    std::sort(adj[0].begin(), adj[0].end());
    // Beware that N could be 1
    ui no_workers = 0;
    ui taken = 0;
    while (taken < adj[0].size() * t / 100.0)
      no_workers += leaves[taken++];
    printf("%u\n", no_workers);
  }
  return 0;
}
