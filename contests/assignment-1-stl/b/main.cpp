/*
 1 2 3 4
1x
2      x
3
4
5


*/
#include <unordered_set>
#include <cstdio>
#include <algorithm>
#include <string>

std::unordered_set<std::string> positions;

int main()
{
  while (true)
  {
    positions.clear();
    int w, h, n;
    scanf("%d%d%d", &w, &h, &n);
    if (w == 0)
      break;
    while (n--)
    {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      int begin_x = std::min(x1, x2);
      int end_x = std::max(x1, x2);
      int begin_y = std::min(y1, y2);
      int end_y = std::max(y1, y2);
      for (int x = begin_x; x <= end_x; ++x)
        for (int y = begin_y; y <= end_y; ++y)
          positions.insert(std::to_string(x) + "," + std::to_string(y));
    }
    for (auto position : positions)
    {
    }
    int empty_spots = w * h - positions.size();
    if (empty_spots == 0)
      printf("There is no empty spots.\n");
    else if (empty_spots == 1)
      printf("There is one empty spot.\n");
    else
      printf("There are %d empty spots.\n", empty_spots);
  }
}
