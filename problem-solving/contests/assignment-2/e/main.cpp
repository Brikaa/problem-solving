/*
4
132 2 32 4321

expected
1
4
9
10

*/

#include <cstdio>
#include <set>
#include <unordered_map>
#include <string>
#include <iostream>

const int N = 5e5 + 5;
int n;
std::set<char> numbers[N];
std::unordered_map<std::string, int> memo;

int get_count(const std::string &combination)
{
  if (memo.find(combination) != memo.end())
    return memo[combination];
  int count = 0;
  for (int i = 0; i < n; ++i)
  {
    for (auto c : combination)
    {
      if (numbers[i].find(c) != numbers[i].end())
      {
        ++count;
        break;
      }
    }
  }
  --count;
  memo[combination] = count;
  return count;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for (int i = 0; i < n; ++i)
  {
    std::string number;
    std::cin >> number;
    for (auto c : number)
      numbers[i].insert(c);
  }
  long long friends = 0;
  for (int i = 0; i < n; ++i)
  {
    std::string combination = "";
    for (auto c : numbers[i])
      combination += c;
    friends += get_count(combination);
  }
  printf("%lld\n", friends / 2);
  return 0;
}
