/*
 */
#include <unordered_map>
#include <string>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <iostream>

std::unordered_map<std::string, int> memo;
const int N = 5e5 + 5;
std::string numbers[N];
int n;

int count(char what, std::vector<char> exceptions, int start_index)
{
  std::string exceptions_str = "";
  for (auto exception : exceptions)
    exceptions_str += exception;
  std::string str = what + "n" + exceptions_str;
  if (memo.find(str) != memo.end())
    return memo[str];
  int count = 0;
  for (int i = start_index; i < n; ++i)
  {
    std::unordered_multiset<char> numbers_set;
    for (auto number : numbers[i])
      numbers_set.insert(number);
    bool found_exception = false;
    for (auto exception : exceptions)
    {
      if (numbers_set.find(exception) != numbers_set.end())
        found_exception = true;
      break;
    }
    if (!found_exception)
      count += numbers_set.count(what);
  }
  return count;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  scanf("%d", n);
  for (int i = 0; i < n; ++i)
    std::cin >> numbers[i];
  for (int i = 0; i < n; ++i)
  {
  }
  return 0;
}
