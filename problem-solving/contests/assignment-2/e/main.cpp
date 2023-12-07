/*
4
132 2 32 4321

expected
1
4
9
6
*/

#include <cstdio>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>

const int N = 5e5 + 5;
std::unordered_set<char> numbers[N];
std::unordered_set<char> all_digits;
std::unordered_map<char, long long> friends;

long long nc2(int n)
{
  if (n < 2)
    return 0;
  long long res = 1;
  for (int i = 1; i <= 2; ++i)
  {
    res *= n - i + 1;
    res /= i;
  }
  return res;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i)
  {
    std::string number;
    std::cin >> number;
    for (auto c : number)
    {
      numbers[i].insert(c);
      all_digits.insert(c);
    }
  }
  for (auto i = all_digits.begin(); i != all_digits.end(); ++i)
  {
    auto target_char = *i;
    std::unordered_map<char, int> exceptions;
    for (int e = 0; e < n; ++e)
    {
      if (numbers[e].find(target_char) != numbers[e].end())
      {
        ++friends[target_char];
        for (auto j = all_digits.begin(); j != i; ++j)
        {
          exceptions[*j] += numbers[e].find(*j) != numbers[e].end();
        }
      }
    }
    fprintf(stderr, "friends[%c] before: %lld\n", target_char, friends[target_char]);
    friends[target_char] = nc2(friends[target_char]);
    for (auto j = all_digits.begin(); j != i; ++j)
    {
      fprintf(stderr, "i: %c, exceptions[%c]: %d\n", target_char, *j, exceptions[*j]);
      friends[target_char] -= nc2(exceptions[*j]);
    }
    fprintf(stderr, "friends[%c]: %lld\n", target_char, friends[target_char]);
  }

  long long no_friends = 0;
  for (auto i : all_digits)
    no_friends += friends[i];
  printf("%lld\n", no_friends);
  return 0;
}
