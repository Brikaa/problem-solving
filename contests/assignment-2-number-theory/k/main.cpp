#include <cstdio>
#include <utility>
#define uint unsigned int

const uint NO_NUMBERS = 2e7;
const uint NO_PRIMES = 2e6 + 6;
const uint NO_PAIRS = NO_PRIMES / 2;
bool not_primes[NO_NUMBERS];
uint primes[NO_PRIMES];
std::pair<uint, uint> prime_pairs[NO_PAIRS];

int main()
{
  for (uint i = 2; i * i < NO_NUMBERS; ++i)
  {
    if (!not_primes[i])
    {
      for (uint j = i * i; j < NO_NUMBERS; j += i)
        not_primes[j] = true;
    }
  }
  uint next = 1;
  for (uint i = 2; i < NO_NUMBERS; ++i)
  {
    if (!not_primes[i])
      primes[next++] = i;
  }
  next = 1;
  for (uint i = 2; i < NO_PRIMES; ++i)
  {
    if (primes[i] - primes[i - 1] == 2)
      prime_pairs[next++] = std::make_pair(primes[i - 1], primes[i]);
  }
  fprintf(stderr, "%u\n", next);
  uint n;
  while (scanf("%u", &n) != EOF)
    printf("(%u, %u)\n", prime_pairs[n].first, prime_pairs[n].second);
  return 0;
}
