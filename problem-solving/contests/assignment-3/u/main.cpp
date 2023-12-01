/*
Given a sequence of integers
Find the minimum number of colors where if Ai and Aj have the same color then Ai < Aj

check largest stop < current number, and if possible, use the same color

priority queue stops
colors = 1
for number in numbers
  if (number <= prev)
    stops.insert(prev)
    target = lower_bound(stops.begin(), stops.end(), number)
    if (target == begin)
      colors++
    else
      stops.remove(target.prev())

1 -
2 -
3 -
98 -
1 *
2 *
3 *
4 *
1 ^
2 ^
3 ^
100 ^
99 -
100 -
101 -
102 -
5 *
6 *
7 *
8 *

expected results
2
4
3
3
*/
#include <cstdio>
#include <set>
#include <vector>

const int N = 1e5 + 5;
std::multiset<int> stops;
int numbers[N];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", numbers + i);
  }
  int colors = 1;
  for (int i = 1; i < n; ++i)
  {
    if (numbers[i] <= numbers[i - 1])
    {
      auto target = std::lower_bound(stops.begin(), stops.end(), numbers[i]);
      if (target == stops.begin())
        ++colors;
      else
        stops.erase(std::prev(target));
      stops.insert(numbers[i - 1]);
    }
  }
  printf("%d\n", colors);
  return 0;
}
