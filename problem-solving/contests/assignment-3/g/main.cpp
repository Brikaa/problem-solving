/*
Choose a number of elements in "a" where max of these elements - min of these elements < d
The sum of elements of the same corresponding indexes in b shall be maximum

- Sort elements in a
- Two pointers
  - Maximize b sum
  - if a[r].value - a[l].value < d
    - right pointer++
    - b sum += b[a[r].index]
  - else
    - b sum -= b[a[l].index]
    - left pointer++
*/
#include <cstdio>
#include <iostream>
#include <algorithm>

struct ElementInA
{
  int index;
  long long value;
};
const int N = 1e5 + 5;
ElementInA a[N];
long long b[N];

bool less_than(ElementInA a1, ElementInA a2)
{
  return a1.value < a2.value;
}

int main()
{
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; ++i)
  {
    std::cin >> a[i].value >> b[i];
    a[i].index = i;
  }
  std::sort(a + 1, a + n + 1, less_than);
  int l = 1;
  int r = 1;
  long long best_b_sum = b[a[r].index];
  long long b_sum = best_b_sum;
  while (r != n || l != n)
  {
    if (a[r].value - a[l].value < d && r != n)
    {
      r++;
      b_sum += b[a[r].index];
    }
    else
    {
      b_sum -= b[a[l].index];
      l++;
    }
    if (a[r].value - a[l].value < d)
    {
      best_b_sum = std::max(best_b_sum, b_sum);
    }
  }
  std::cout << best_b_sum << '\n';
  return 0;
}
