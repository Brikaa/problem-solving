#include <iostream>
#include <unordered_map>

int main()
{
  int n;
  std::cin >> n;
  std::unordered_map<int, int> map;

  for (int i = 0; i < n; ++i)
  {
    int no;
    std::cin >> no;
    map[no]++;
  }

  int no_to_check_for;
  std::cin >> no_to_check_for;
  std::cout << map[no_to_check_for] << '\n';
}
