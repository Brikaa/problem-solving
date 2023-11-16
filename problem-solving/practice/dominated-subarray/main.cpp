/*
array a
for element in array
  - if element is repeated
  - get index of old element
  - adjust the map with the index of the new element
  - if element existed
    - size = index of new - index of old + 1
    - best_size = min(size, best_size)
*/
#include <stdio.h>
#include <algorithm>
#include <unordered_map>

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    std::unordered_map<int, int> element_to_last_index;
    int n;
    scanf("%d", &n);
    int best_size = 1e5 + 5;
    for (int i = 1; i <= n; ++i)
    {
      int element;
      scanf("%d", &element);
      int old_index = element_to_last_index[element];
      element_to_last_index[element] = i;
      if (old_index != 0)
        best_size = std::min(i - old_index + 1, best_size);
    }
    if (best_size == 1e5 + 5)
    {
      printf("-1\n");
    }
    else
    {
      printf("%d\n", best_size);
    }
  }
  return 0;
}
