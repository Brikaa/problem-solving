/*
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;
ui s, t;

bool valid(ui start, const std::vector<ui> &v)
{
  for (ui i = start + 1; i < t; ++i)
  {
    if (std::__gcd(v[start], v[i]) != 1)
      return false;
  }
  return true;
}

int main()
{
  ui T;
  scanf("%u", &T);
  while (T--)
  {
    scanf("%u%u", &s, &t);
    std::queue<std::vector<ui>> q;
    std::vector<ui> target;
    std::vector<ui> initial;
    for (ui i = 0; i < t - 1; ++i)
      initial.push_back(1);
    initial.push_back(s - t + 1);
    q.push(initial);
    ui last = t - 1;
    while (!q.empty())
    {
      std::vector<ui> element = q.front();
      q.pop();
      for (ui i = 0; i < t; ++i)
        printf("%u%c", element[i], " \n"[i == t - 1]);
      if (last != 0 && element[last - 1] != 1)
        --last;
      if (last == 0)
        continue;
      while (element[last - 1] < element[last])
      {
        ++element[last - 1];
        --element[last];
        if (element[last - 1] < element[last] && valid(last - 1, element))
          q.push(element);
      }
    }
  }
  return 0;
}
