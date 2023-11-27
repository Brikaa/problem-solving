/*
N rooms
xi position of free room i

- Sliding window of size k + 1
l = r - k
mid = (l + r) / 2
minimize max_distance on min(
  max(rooms[mid] - rooms[l], rooms[r] - rooms[mid]),
  max(rooms[mid + 1] - rooms[l], rooms[r] - rooms[mid + 1])


1 6 7 8 10
  ^
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

  int max_distance = rooms[free] - rooms[1] + 15;
  for (int i = k + 1; i <= free; ++i)
  {
    int l = i - k;
    int mid = (l + i) / 2;
    max_distance = std::min(
        max_distance,
        std::min(
            std::max(rooms[mid] - rooms[l], rooms[i] - rooms[mid]),
            std::max(rooms[mid + 1] - rooms[l], rooms[i] - rooms[mid + 1])));
  }
  printf("%d\n", max_distance);
  return 0;
}
