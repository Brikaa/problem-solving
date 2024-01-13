#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
typedef unsigned int uint;

const uint N = 1e5 + 1;
bool not_primes[N];
std::vector<std::string> primes;
std::string string;


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
      primes.push_back(std::to_string(i));
  while (true)
  {
    std::cin >> string;
    if (string == "0")
      break;
    for (int i = primes.size() - 1; i >= 0; --i)
    {
      if (string.find(primes[i]) != std::string::npos)
      {
        std::cout << primes[i];
        break;
      }
    }
    std::cout << '\n';
  }
}
