#include <set>
#include <iostream>
#include <string>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  std::cin >> t;
  while (t--)
  {
    std::string first, second;
    std::cin >> first >> second;
    std::set<char> first_set;
    for (auto c : first)
      first_set.insert(c);
    bool found = false;
    for (auto c : second)
    {
      if (first_set.find(c) != first_set.end())
      {
        found = true;
        break;
      }
    }
    if (found)
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }
}
