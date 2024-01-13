#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> names;

int main()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  while (n--)
  {
    std::string name;
    std::cin >> name;
    if (!names[name])
    {
      std::cout << "OK\n";
      ++names[name];
    }
    else
    {
      std::cout << name + std::to_string(names[name]++) << '\n';
    }
  }
  return 0;
}
