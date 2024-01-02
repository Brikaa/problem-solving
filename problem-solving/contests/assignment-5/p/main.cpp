#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 5e3 + 3;
std::vector<std::vector<ui>> adj;
ui a_visited[N];
ui b_visited[N];
ui a_distances[N];
ui b_distances[N];
ui qid;

bool no_check(ui _)
{
  return false;
}

bool stop_check(ui i)
{
  if (a_distances[i] == b_distances[i])
  {
    printf("The fleas meet at %u.\n", i + 1);
    return true;
  }
  if (b_distances[i] == 1 + a_distances[i])
  {
    for (ui j : adj[i])
    {
      if (b_visited[j] == qid)
      {
        printf("The fleas jump forever between %u and %u.\n", std::min(i + 1, j + 1), std::max(i + 1, j + 1));
        return true;
      }
    }
  }
  return false;
}

void bfs(ui *visited, ui *distances, ui source, std::function<bool(ui)> check)
{
  std::queue<ui> q;
  distances[source] = 0;
  q.push(source);
  while (!q.empty())
  {
    ui elem = q.front();
    q.pop();
    visited[elem] = qid;
    if (check(elem))
      break;
    for (ui neig : adj[elem])
      if (visited[neig] != qid)
      {
        distances[neig] = distances[elem] + 1;
        q.push(neig);
      }
  }
}

int main()
{
  ui n;
  while (scanf("%u", &n), n)
  {
    adj.clear();
    adj.resize(n);
    for (ui i = 0; i < n - 1; ++i)
    {
      ui x, y;
      scanf("%u%u", &x, &y);
      --x;
      --y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    ui q;
    scanf("%u", &q);
    while (q--)
    {
      ui a, b;
      scanf("%u%u", &a, &b);
      --a;
      --b;
      ++qid;
      bfs(a_visited, a_distances, a, no_check);
      bfs(b_visited, b_distances, b, stop_check);
      for (ui i = 0; i < n; ++i)
      {
      }
    }
  }
  return 0;
}
