#include <cstdio>
#include <vector>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 1e5 + 5;
std::vector<std::vector<ui>> adj;
ui distance[N];
ui prev[N];
ui visited[N];
ui vid;

void dfs(ui node)
{
  for (ui child : adj[node])
  {
    if (visited[child] == vid && distance[node] + 1 < distance[child])
    {
      distance[child] = distance[node] + 1;
      prev[child] = node;
    }
    else if (visited[child] != vid)
    {
      visited[child] = vid;
      prev[child] = node;
      distance[child] = distance[node] + 1;
      dfs(child);
    }
  }
}

int main()
{
  bool first = true;
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    ++vid;
    if (!first)
      printf("\n");
    first = false;
    ui n;
    scanf("%u", &n);

    adj.clear();
    adj.resize(n + 3);

    for (ui i = 0; i < n; ++i)
    {
      ui id, ppl;
      scanf("%u%u", &id, &ppl);
      for (ui j = 0; j < ppl; ++j)
      {
        ui p;
        scanf("%u", &p);
        adj[id].push_back(p);
      }
    }

    ui a, b;
    scanf("%u%u", &a, &b);

    visited[a] = vid;
    distance[a] = 0;
    prev[a] = -1;
    dfs(a);

    ui target = prev[b];
    ui intermediate = 0;
    while (target != a)
    {
      target = prev[target];
      ++intermediate;
    }
    printf("%u %u %u\n", a, b, intermediate);
  }
  return 0;
}
