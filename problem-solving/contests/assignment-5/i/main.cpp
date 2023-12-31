/*
- If conflict keep moving the conflict edge up opposite to a conflicting edge
  till it becomes the out edge of a node with no conflicts
  - Conflict: two edges coming out of a node into two different nodes
*/
#include <vector>
#include <cstdio>
#include <unordered_set>

typedef unsigned int ui;
typedef unsigned long long ull;
const ui N = 1e5 + 5;
std::vector<std::unordered_set<ui>> adj;
std::vector<ui> to_fix;

int main()
{
  ui n, k;
  scanf("%u%u", &n, &k);
  adj.resize(n + 5);
  for (ui mgr = 1; mgr <= k; ++mgr)
  {
    ui no;
    scanf("%u", &no);
    while (no--)
    {
      ui managed;
      scanf("%u", &managed);
      adj[managed].insert(mgr);
    }
  }

  for (ui i = 1; i <= n; ++i)
  {
    if (adj[i].size() > 1)
      to_fix.push_back(i);
  }

  while (!to_fix.empty())
  {
    ui managed = to_fix.back();
    to_fix.pop_back();
    while (adj[managed].size() > 1)
    {
      bool found = false;
      for (auto manager_it = adj[managed].begin(); manager_it != adj[managed].end() && !found; manager_it++)
      {
        ui manager = *manager_it;
        for (auto another_manager_it = manager_it; another_manager_it != adj[managed].end() && !found; another_manager_it++)
        {
          ui another_manager = *another_manager_it;
          if (another_manager == manager)
            continue;
          // Try to make another_manager managed by manager
          // manager can't be managed by another_manager
          if (adj[manager].find(another_manager) == adj[manager].end())
          {
            // Does another manager have a problem?
            adj[another_manager].insert(manager);
            if (adj[another_manager].size() > 1)
              to_fix.push_back(another_manager);
            // Remove manager from adj of managed
            adj[managed].erase(manager_it);
            found = true;
          }
        }
      }
    }
  }
  for (ui i = 1; i <= n; ++i)
    printf("%u\n", adj[i].size() == 0 ? 0 : *(adj[i].begin()));
  return 0;
}
