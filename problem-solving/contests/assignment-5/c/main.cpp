/*
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

typedef unsigned int ui;
typedef unsigned long long ull;
ui s, t;
std::vector<ui> current_combination;
std::vector<std::vector<ui>> combinations;

void solve(ui sum, ui parent)
{
  if (sum >= s && current_combination.size() != t)
    return;
  if (sum == s && current_combination.size() == t)
    combinations.push_back(current_combination);
  ui stop = parent == 0 ? s : parent;
  for (ui i = stop; i >= 1; --i)
  {
    current_combination.push_back(i);
    solve(sum + i, i);
    current_combination.pop_back();
  }
}

int main()
{
  ui T;
  scanf("%u", &T);
  while (T--)
  {
    scanf("%u%u", &s, &t);
    solve(0, 0);
    for (std::vector<ui> &combination : combinations)
      for (ui i = 0; i < combination.size(); ++i)
        printf("%u%c", combination[i], " \n"[i == combination.size() - 1]);
  }
  return 0;
}
