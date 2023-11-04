#include <iostream>
#include <set>
#include <string>

int main()
{

  int test_cases;
  std::cin >> test_cases;

  while (test_cases--)
  {
    std::set<char> s1_set;
    std::string s1;
    std::cin >> s1;
    int s1_size = s1.size();
    for (int i = 0; i < s1_size; ++i)
    {
      s1_set.insert(s1[i]);
    }
    std::string s2;
    std::cin >> s2;
    bool found = false;
    int s2_size = s2.size();
    for (int i = 0; i < s2_size; ++i)
    {
      if (s1_set.find(s2[i]) != s1_set.end())
      {
        std::cout << "YES\n";
        found = true;
        break;
      }
    }
    if (!found)
    {
      std::cout << "NO\n";
    }
  }
}
