#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
typedef unsigned int uint;

const uint N = 1e5 + 5;
bool not_primes[N];
std::unordered_set<std::string> primes;
std::vector<std::vector<std::pair<uint, std::string>>> memo(256, std::vector<std::pair<uint, std::string>>(256));
uint vid;
std::string string;

std::string largest_prime_substring(int start, int end)
{
  if (start > end)
    return "";
  if (memo[start][end].second != "" && memo[start][end].first == vid)
    return memo[start][end].second;
  std::string sub = string.substr(start, end - start + 1);
  if (primes.find(sub) != primes.end())
    return sub;
  std::string opt1 = largest_prime_substring(start + 1, end);
  std::string opt2 = largest_prime_substring(start, end - 1);
  std::string res = opt1.length() > opt2.length() ? opt1 : opt2;
  memo[start][end].first = vid;
  memo[start][end].second = res;
  return res;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for (uint i = 2; i * i < N; ++i)
  {
    if (!not_primes[i])
    {
      for (uint j = i * i; j < N; j += i)
        not_primes[j] = true;
    }
  }
  for (uint i = 2; i < N; ++i)
    if (!not_primes[i])
      primes.insert(std::to_string(i));
  while (true)
  {
    ++vid;
    std::cin >> string;
    if (string == "0")
      break;
    std::cout << largest_prime_substring(0, string.size() - 1) << '\n';
  }
}
