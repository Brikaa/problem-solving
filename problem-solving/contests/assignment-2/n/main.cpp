/*
In how many ways can a number be represented as a sum of consecutive primes
- I can get the sum of consecutive primes from their beginning till a certain index
- Prefix sum array of primes
- Frequency array till 10000
-
*/
#include <cstdio>
#include <vector>

const unsigned int N = 1e5 + 5;
const unsigned int K = 2e5 + 5;
bool not_primes[N];
unsigned long long primes_prefix_sum[N];
unsigned long long combinations[K];
std::vector<unsigned int> primes;

int main()
{
  for (unsigned int i = 2; i * i < N; ++i)
  {
    if (!not_primes[i])
    {
      for (unsigned int j = i * i; j < N; j += i)
        not_primes[j] = true;
    }
  }
  for (unsigned int i = 2; i < N; ++i)
  {
    if (!not_primes[i])
      primes.push_back(i);
  }
  for (unsigned int i = 1; i < primes.size(); ++i)
    primes_prefix_sum[i] = primes_prefix_sum[i - 1] + primes[i - 1];
  for (unsigned int i = 1; i < primes.size(); ++i)
  {
    unsigned long long element = primes_prefix_sum[i];
    for (unsigned int j = 0; j < primes.size() && element >= 2; element -= primes[j++])
      if (element < N)
        ++combinations[element];
  }
  while (true)
  {
    unsigned int n;
    scanf("%u", &n);
    if (n == 0)
      break;
    printf("%llu\n", combinations[n]);
  }
  return 0;
}
