#include <unordered_set>
#include <cstdio>

std::unordered_set<int> levels;

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= 2; ++i)
  {
    int p;
    scanf("%d", &p);
    while (p--)
    {
      int level;
      scanf("%d", &level);
      levels.insert(level);
    }
  }
  bool pass = true;
  for (int i = 1; i <= n; ++i)
  {
    if (levels.find(i) == levels.end())
    {
      pass = false;
      break;
    }
  }
  if (pass)
    printf("I become the guy.\n");
  else
    printf("Oh, my keyboard!\n");
  return 0;
}
