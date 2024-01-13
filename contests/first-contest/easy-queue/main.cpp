#include <iostream>
#include <queue>

int main()
{
  std::ios::sync_with_stdio(0);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t;
  std::cin >> t;
  std::queue<int> queue;
  while (t--)
  {
    int query;
    std::cin >> query;
    if (query == 1)
    {
      int target;
      std::cin >> target;
      queue.push(target);
    }
    else if (query == 2)
    {
      if (!queue.empty())
      {
        queue.pop();
      }
    }
    else if (query == 3)
    {
      if (queue.empty())
      {
        std::cout << "Empty!\n";
      }
      else
      {
        int element = queue.front();
        std::cout << element << '\n';
      }
    }
  }
}
