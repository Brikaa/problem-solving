#include <cstdio>
#include <vector>
#include <queue>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 1e5 + 5;
std::vector<std::vector<ui>> adj;
ui distance[N];
ui visited[N];
ui vid;

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
    std::queue<ui> p;
    p.push(a);
    bool found = false;
    while (!p.empty() && !found)
    {
      ui parent = p.front();
      p.pop();
      for (ui child : adj[parent])
      {
        if (visited[child] != vid)
        {
          distance[child] = distance[parent] + 1;
          visited[child] = vid;
          p.push(child);
        }
        if (child == b)
        {
          printf("%u %u %u\n", a, b, distance[parent]);
          found = true;
          break;
        }
      }
    }
  }
  return 0;
}
