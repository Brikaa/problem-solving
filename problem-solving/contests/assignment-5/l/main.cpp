#include <cstdio>
#include <queue>

typedef int ui;
typedef long long ull;

struct Node
{
  int first;
  int second;
  int steps;
};

// vid - 1 = unvisited
// vid = processing
// vid + 1 = visited

// ull solve(ull first, ull second)
// {
//   const ull idx = first * second_cap + second;
//   if (visited[idx] == vid || first < 0 || second < 0 || first > first_cap || second > second_cap)
//     return 1e9;
//   else if (first == required || second == required)
//     return 0;
//   else if (visited[idx] == vid + 1)
//     return memo[idx];
//   visited[idx] = vid;
//   ull &ret = memo[idx];
//   ull opt1 = solve(first - (second_cap - second), second_cap);
//   ull opt2 = solve(0, second);
//   ull opt3 = solve(first_cap, second);
//   ull opt4 = solve(0, second + first);
//   ull min1 = std::min(std::min(opt1, opt4), std::min(opt2, opt3));

//   opt1 = solve(first_cap, second - (first_cap - first));
//   opt2 = solve(first, 0);
//   opt3 = solve(first, second_cap);
//   opt4 = solve(first + second, 0);
//   ull min2 = std::min(std::min(opt1, opt4), std::min(opt2, opt3));

//   ret = 1 + std::min(min1, min2);
//   visited[idx] = vid + 1;
//   return ret;
// }

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
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
      if (elem.first < 0 || elem.second < 0 || elem.first > first_cap || elem.second > second_cap)
        continue;
      if (elem.first == required || elem.second == required)
      {
        printf("%d\n", elem.steps);
        found = true;
        break;
      }
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
