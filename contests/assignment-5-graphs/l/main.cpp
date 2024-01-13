#include <cstdio>
#include <queue>
#include <unordered_map>

typedef int ui;
typedef long long ull;

std::unordered_map<int, std::unordered_map<int, int>> visited;
int vid;

struct Node
{
  int first;
  int second;
  int steps;
};

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    ++vid;
    int first_cap, second_cap, required;
    scanf("%d%d%d", &first_cap, &second_cap, &required);
    Node root = {0, 0, 0};
    std::queue<Node> q;
    q.push(root);
    bool found = false;
    while (!q.empty())
    {
      Node elem = q.front();
      q.pop();
      if (elem.first < 0 || elem.second < 0 || elem.first > first_cap || elem.second > second_cap || visited[elem.first][elem.second] == vid)
        continue;
      if (elem.first == required || elem.second == required)
      {
        printf("%d\n", elem.steps);
        found = true;
        break;
      }
      visited[elem.first][elem.second] = vid;
      q.push({elem.first - (second_cap - elem.second), second_cap, elem.steps + 1});
      q.push({0, elem.second, elem.steps + 1});
      q.push({first_cap, elem.second, elem.steps + 1});
      q.push({0, elem.second + elem.first, elem.steps + 1});

      q.push({first_cap, elem.second - (first_cap - elem.first), elem.steps + 1});
      q.push({elem.first, 0, elem.steps + 1});
      q.push({elem.first, second_cap, elem.steps + 1});
      q.push({elem.first + elem.second, 0, elem.steps + 1});
    }
    if (!found)
      puts("-1");
  }
  return 0;
}
