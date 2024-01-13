#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> dictionary;
int main()
{
  int m, n;
  std::cin >> m >> n;
  while (m--)
  {
    std::string word;
    int worth;
    std::cin >> word >> worth;
    dictionary[word] = worth;
  }
  while (n--)
  {
    int salary = 0;
    std::string word;
    while (true)
    {
      std::cin >> word;
      if (word == ".")
        break;
      salary += dictionary[word];
    }
    std::cout << salary << '\n';
  }
  return 0;
}
