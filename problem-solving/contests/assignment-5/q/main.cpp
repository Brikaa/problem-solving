#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;

std::unordered_map<char, std::vector<char>> adj;
std::unordered_map<char, char> prev;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ui t;
  std::cin >> t;
  while (t--)
  {
    adj.clear();
    ui n, q;
    std::cin >> n >> q;
    for (ui i = 0; i < n; ++i)
    {
      std::string c1, c2;
      std::cin >> c1 >> c2;
      adj[c1[0]].push_back(c2[0]);
      adj[c2[0]].push_back(c1[0]);
    }
    while (q--)
    {
      prev.clear();
      std::string city1, city2;
      std::cin >> city1 >> city2;
      char c1 = city1[0];
      char c2 = city2[0];
      std::string res = "";

      std::queue<char> q;
      q.push(c1);
      while (!q.empty())
      {
        char elem = q.front();
        q.pop();
        if (elem == c2)
          break;
        for (auto neig : adj[elem])
        {
          if (prev.find(elem) == prev.end() || prev[elem] != neig)
          {
            prev[neig] = elem;
            q.push(neig);
          }
        }
      }

      char cur = c2;
      while (cur != c1)
      {
        res += cur;
        cur = prev[cur];
      }
      res += c1;
      std::reverse(res.begin(), res.end());
      std::cout << res << '\n';
    }
    if (t != 0)
      std::cout << '\n';
  }
  return 0;
}
