#include <queue>
#include <cstdio>

typedef unsigned int ui;
typedef unsigned long long ull;

struct Point
{
  int x;
  int y;
};

const int N = 50;
bool visited[N][N];
Point points[N * N];

int distance(const Point &p1, const Point &p2)
{
  int x_comp = p2.x - p1.x;
  int y_comp = p2.y - p1.y;
  return (x_comp) * (x_comp) + (y_comp) * (y_comp);
}

int main()
{
  ui n;
  while (scanf("%u", &n), n)
  {
    for (ui i = 0; i < n; ++i)
    {
      scanf("%d%d", &(points[i].x), &(points[i].y));
      points[i].x += 20;
      points[i].y += 20;
      visited[points[i].x][points[i].y] = false;
    }
    if (n <= 3)
    {
      puts("All stations are reachable.");
      continue;
    }
    std::queue<Point> q;
    visited[points[0].x][points[0].y] = true;
    q.push(points[0]);
    while (!q.empty())
    {
      Point elem = q.front();
      q.pop();
      Point min1 = {100, 100};
      bool westernmost_used = false;
      for (ui i = 0; i < n; ++i)
      {
        if (points[i].x == elem.x && points[i].y == elem.y)
          continue;
        if (distance(elem, points[i]) < distance(elem, min1))
        {
          min1 = points[i];
          westernmost_used = false;
        }
        else if (distance(elem, points[i]) == distance(elem, min1))
        {
          if (points[i].x < min1.x)
            min1 = points[i];
          westernmost_used = true;
        }
      }
      Point min2 = {100, 100};
      for (ui i = 0; i < n; ++i)
      {
        if ((points[i].x == elem.x && points[i].y == elem.y) || (points[i].x == min1.x && points[i].y == min1.y))
          continue;
        if (
            distance(elem, points[i]) < distance(elem, min2) ||
            (distance(elem, points[i]) == distance(elem, min2) &&
             ((westernmost_used && points[i].y < min2.y) || (!westernmost_used && points[i].x < min2.x))))
          min2 = points[i];
      }
      if (!visited[min1.x][min1.y])
      {
        visited[min1.x][min1.y] = true;
        q.push(min1);
      }
      if (!visited[min2.x][min2.y])
      {
        visited[min2.x][min2.y] = true;
        q.push(min2);
      }
    }

    bool found = false;
    for (ui i = 0; i < n && !found; ++i)
    {
      const Point &point = points[i];
      if (!visited[point.x][point.y])
        found = true;
    }
    if (found)
      puts("There are stations that are unreachable.");
    else
      puts("All stations are reachable.");
  }
  return 0;
}
