/*
N elements
output unordered pairs whose sum is a power of two

1 2 3 4 5 6
    ^

2
1 1

4
1 3
2 2

8
1 7
2 6
3 5
4 4

16
1 15
2 14
3 13

for each element
  for i 2..3e9 i*=2
    satisfying += count of i - element
...
*/
#include <cstdio>
#include <unordered_map>

const int N = 1e5 + 5;
int numbers[N];
std::unordered_map<long long, int> numbers_count;

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    long long number;
    scanf("%lld", &number);
    ++numbers_count[number];
    numbers[i] = number;
  }
  long long max = 2e9 + 5;
  long long satisfying = 0;
  for (int i = 0; i < n; ++i)
    for (long long j = 2; j < max; j *= 2)
    {
      long long diff = j - numbers[i];
      int count = numbers_count[diff];
      if (diff == numbers[i])
        --count;
      satisfying += count;
    }
  printf("%lld\n", satisfying / 2);
  return 0;
}
