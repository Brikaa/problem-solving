/*
N rooms
xi position of free room i

- Sliding window of size k + 1
l = r - k
inner_minimum_max_distance = rooms[r] - rooms[l]
for j (l + 1) -> (r - 1)
  minimize inner_minimum_max_distance on max(rooms[j] - rooms[l], rooms[r] - rooms[j])
minimize minimum_max_distance on inner_minimum_max_distance
*/
#include <cstdio>
#include <algorithm>

const int N = 1e5 + 5;
int rooms[N];
char rooms_str[N];

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", rooms_str);
  int free = 0;
  for (int i = 0; i <= n; ++i)
    if (rooms_str[i] == '0')
      rooms[++free] = i + 1;

  int minimum_max_distance = rooms[free] - rooms[1] + 15;
  for (int r = k + 1; r <= free; ++r)
  {
    int l = r - k;
    int inner_minimum_max_distance = rooms[r] - rooms[l];
    for (int j = l + 1; j <= r - 1; ++j)
    {
      inner_minimum_max_distance = std::min(
          inner_minimum_max_distance, std::max(rooms[j] - rooms[l], rooms[r] - rooms[j]));
    }
    minimum_max_distance = std::min(minimum_max_distance, inner_minimum_max_distance);
  }
  printf("%d\n", minimum_max_distance);
  return 0;
}
