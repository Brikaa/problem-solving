#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> smaller_zero; // must contain an odd number of negative numbers
  std::vector<int> greater_zero;
  std::vector<int> zero; // must contain all zeroes

  while (n--)
  {
    int number;
    std::cin >> number;
    if (number == 0)
    {
      zero.push_back(number);
    }
    else if (number > 0)
    {
      greater_zero.push_back(number);
    }
    else
    {
      smaller_zero.push_back(number);
    }
  }

  if (greater_zero.size() == 0)
  {
    int p1 = smaller_zero.back();
    smaller_zero.pop_back();
    int p2 = smaller_zero.back();
    smaller_zero.pop_back();
    greater_zero.push_back(p1);
    greater_zero.push_back(p2);
  }

  if (smaller_zero.size() % 2 == 0) {
    int p1 = smaller_zero.back();
    smaller_zero.pop_back();
    zero.push_back(p1);
  }

  std::cout << smaller_zero.size() << ' ';
  for (auto i : smaller_zero)
  {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  std::cout << greater_zero.size() << ' ';
  for (auto i : greater_zero)
  {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  std::cout << zero.size() << ' ';
  for (auto i : zero)
  {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}
