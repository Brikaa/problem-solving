#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

std::unordered_set<std::string> last_names;
std::unordered_map<std::string, std::string> name_changes;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  while (n--)
  {
    std::string first, second;
    std::cin >> first >> second;
    last_names.erase(first);
    last_names.insert(second);
    name_changes[second] = first;
  }
  std::cout << last_names.size() << '\n';
  for (std::string last_name : last_names)
  {
    std::string first_name = last_name;
    while (name_changes.find(first_name) != name_changes.end())
      first_name = name_changes[first_name];
    std::cout << first_name << ' ' << last_name << '\n';
  }
  return 0;
}
