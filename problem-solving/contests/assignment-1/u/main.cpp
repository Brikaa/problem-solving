/*
1 2 21
1 + 2 = 3
3 + 21 = 24
total = 27

2 + 21 = 23
23 + 1 = 24
total = 47

x + y + z
cost = x + y + x + y + z = 2x + 2y + z

x + y + z + w
cost = x + y + x + y + z + x + y + z + w = 3x + 3y + 2z + w

for minimum cost x, y < z < w

a1 a2 a3 a4 a5
a1 + a2
a1 + a2 + a3
a1 + a2 + a3 + a4
a1 + a2 + a3 + a4 + a5
cost = 4a1 + 4a2 + 3a3 + 2a4 + a5

x y z w
a1 + a2
a3 + a4
a1 + a2 + a3 + a4
cost = 2a1 + 2a2 + 2a3 + 2a4
or
cost = 3a1 + 3a2 + 2a1 + a4

34 + 60 + 61 + 62
34 + 60 = 94
94 + 61 = 155
155 + 62 = 217
cost = 466
34 + 60 = 94
61 + 62 = 123
94 + 123 = 217
cost = 434

- Each time add the smallest two numbers

cost = 0 + 3 + 6
1 2 3
3 3
6
*/
#include <algorithm>
#include <cstdio>
#include <queue>

int main()
{
  while (true)
  {
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> numbers;
    int n;
    scanf("%d", &n);
    if (n == 0)
      break;
    while (n--)
    {
      long long number;
      scanf("%lld", &number);
      numbers.push(number);
    }
    long long cost = 0;
    while (numbers.size() > 1)
    {
      long long n1 = numbers.top();
      numbers.pop();
      long long n2 = numbers.top();
      numbers.pop();
      long long sum = n1 + n2;
      cost += sum;
      numbers.push(sum);
    }
    printf("%lld\n", cost);
  }
  return 0;
}
