/*
r
pi qi
*/
#include <cstdio>
#include <algorithm>

struct Enemy
{
  int power;
  int bonus;
};

const int N = 1e3 + 3;
Enemy enemies[N];

bool less_than(Enemy &e1, Enemy &e2)
{
  return e1.power < e2.power;
}

int main()
{
  int r, n;
  scanf("%d%d", &r, &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &(enemies[i].power), &(enemies[i].bonus));

  std::sort(enemies, enemies + n, less_than);
  bool can_defeat = true;
  for (int i = 0; i < n && can_defeat; ++i)
  {
    if (r <= enemies[i].power)
      can_defeat = false;
    else
      r += enemies[i].bonus;
  }
  if (can_defeat)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
