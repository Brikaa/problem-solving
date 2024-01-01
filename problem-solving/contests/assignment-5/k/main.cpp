#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui N = 1e5 + 5;
std::vector<std::unordered_set<ui>> adj;
char word[N];
ui no_nodes;
ui visited_components[N];
char visited_letters[N];
bool visited[N];

void dfs(ui source)
{
  visited[source] = true;
  visited_components[no_nodes] = source;
  visited_letters[no_nodes++] = word[source];
  for (ui neig : adj[source])
  {
    if (!visited[neig])
    {
      visited[neig] = true;
      dfs(neig);
    }
  }
}

int main()
{
  ui t;
  scanf("%u", &t);
  while (t--)
  {
    scanf("%s", word);
    ui n = std::strlen(word);
    adj.clear();
    adj.resize(n);
    std::fill(std::begin(visited), std::end(visited), 0);

    ui pairs;
    scanf("%u", &pairs);
    for (ui p = 0; p < pairs; ++p)
    {
      ui i, j;
      scanf("%u%u", &i, &j);
      if (i != j)
      {
        adj[i].insert(j);
        adj[j].insert(i);
      }
    }
    for (ui i = 0; i < n; ++i)
    {
      if (!visited[i])
      {
        no_nodes = 0;
        dfs(i);
        std::sort(visited_letters, visited_letters + no_nodes);
        std::sort(visited_components, visited_components + no_nodes);
        for (ui j = 0; j < no_nodes; ++j)
          word[visited_components[j]] = visited_letters[j];
      }
    }
    puts(word);
  }
  return 0;
}
