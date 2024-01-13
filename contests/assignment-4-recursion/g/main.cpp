#include <iostream>
#include <vector>
#include <string>

typedef unsigned int ui;
typedef unsigned long long ull;

const ui D = 105;
ui d;
std::string dictionary[D];
std::string current_rule;
std::vector<std::string> current_combination;

void solve(ui idx)
{
  if (current_rule[idx] == '#')
  {
    for (ui i = 0; i < d; ++i)
    {
      current_combination.push_back(dictionary[i]);
      solve(idx + 1);
      current_combination.pop_back();
    }
  }
  else if (current_rule[idx] == '0')
  {
    for (ui i = 0; i <= 9; ++i)
    {
      current_combination.push_back(std::to_string(i));
      solve(idx + 1);
      current_combination.pop_back();
    }
  }
  else
  {
    for (ui i = 0; i < current_combination.size(); ++i)
      std::cout << current_combination[i] << (i == current_combination.size() - 1 ? "\n" : "");
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  while (std::cin >> d)
  {
    std::cout << "--\n";
    for (ui i = 0; i < d; ++i)
      std::cin >> dictionary[i];
    ui r;
    std::cin >> r;
    while (r--)
    {
      std::cin >> current_rule;
      solve(0);
    }
  }
  return 0;
}
