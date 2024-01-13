#include <string>
#include <map>
#include <iostream>
#include <cstdio>

int main()
{
  // std::ios_base::sync_with_stdio(false);
  // std::cin.tie(0);
  // std::cout.tie(0);
  int t;
  std::string t_str;
  std::getline(std::cin, t_str);
  t = atoi(t_str.c_str());
  bool first = true;
  while (t--)
  {
    std::map<std::string, int> trees;
    if (first)
    {
      std::string dump;
      std::getline(std::cin, dump);
    }
    if (!first)
      printf("\n");
    first = false;
    int population = 0;
    while (true)
    {
      std::string name;
      if (!std::getline(std::cin, name) || name == "")
        break;
      ++trees[name];
      ++population;
    }
    for (auto tree : trees)
      printf("%s %.4f\n", tree.first.c_str(), (tree.second / (double)population) * 100);
  }
  return 0;
}
