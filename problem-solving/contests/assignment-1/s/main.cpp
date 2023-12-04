/*
Ensure removeMin is valid
Ensure getMin is valid and correct

at removeMin
  - If there are no elements in the heap, insert one before it and removeMin
at getMin x
  - If the heap is empty or the top of heap is more than x, insert x and getMin x
  - If top of heap is less than x, remove till top > x or heap is empty, insert x and getMin x
*/
#include <queue>
#include <vector>
#include <string>
#include <iostream>

std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::vector<std::string> operations;
  int n;
  std::cin >> n;
  while (n--)
  {
    std::string operation;
    std::cin >> operation;
    if (operation == "insert")
    {
      int param;
      std::cin >> param;
      pq.push(param);
      operations.push_back("insert " + std::to_string(param));
    }
    else if (operation == "removeMin")
    {
      if (pq.size() == 0)
      {
        pq.push(1);
        operations.push_back("insert 1");
      }
      pq.pop();
      operations.push_back("removeMin");
    }
    else
    {
      int x;
      std::cin >> x;
      while (pq.size() > 0 && pq.top() < x)
      {
        pq.pop();
        operations.push_back("removeMin");
      }
      if (pq.size() == 0 || pq.top() > x)
      {
        pq.push(x);
        operations.push_back("insert " + std::to_string(x));
      }
      operations.push_back("getMin " + std::to_string(x));
    }
  }
  std::cout << operations.size() << '\n';
  for (auto operation : operations)
    std::cout << operation << '\n';
  return 0;
}
