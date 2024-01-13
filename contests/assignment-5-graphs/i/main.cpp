#include <vector>
#include <cstdio>
#include <queue>

typedef unsigned int ui;
typedef unsigned long long ull;
const ui N = 1e5 + 5;
std::vector<std::vector<ui>> adj;
ui ans[N];
ui in_degrees[N];

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
      adj[mgr].push_back(managed);
      ++in_degrees[managed];
    }
  }

  std::queue<ui> q;
  for (ui i = 1; i <= n; ++i)
    if (in_degrees[i] == 0)
      q.push(i);

  ui last = 0;
  while (!q.empty())
  {
    ui elem = q.front();
    q.pop();
    ans[elem] = last;
    last = elem;
    for (auto neig : adj[elem])
    {
      --in_degrees[neig];
      if (in_degrees[neig] == 0)
        q.push(neig);
    }
  }

  for (ui i = 1; i <= n; ++i)
    printf("%u\n", ans[i]);
  return 0;
}
