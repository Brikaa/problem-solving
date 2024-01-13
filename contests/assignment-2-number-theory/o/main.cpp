#include <cstdio>
#include <vector>
typedef unsigned int uint;

const uint N = 2e6;
bool not_primes[N];
std::vector<uint> primes;
uint gaps[N];

int main()
{
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
      primes.push_back(i);
  for (uint i = 1; i < primes.size(); ++i)
  {
    uint difference = primes[i] - primes[i - 1];
    for (uint j = primes[i - 1] + 1; j < primes[i]; ++j)
      gaps[j] = difference;
  }
  while (true)
  {
    uint n;
    scanf("%u", &n);
    if (n == 0)
      break;
    printf("%u\n", gaps[n]);
  }
  return 0;
}
