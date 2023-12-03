/*
Sequence of numbers
Check the absolute differences between each number and its previous one form 1..n-1
*/
#include <cstdio>
#include <cmath>
#include <unordered_set>

int main()
{
  int n;
  while (scanf("%d", &n) != EOF)
  {
    std::unordered_set<int> differences;
    int prev;
    scanf("%d", &prev);
    for (int i = 2; i <= n; ++i)
    {
      int next;
      scanf("%d", &next);
      differences.insert(abs(next - prev));
      prev = next;
    }
    bool healthy = true;
    for (int i = 1; i <= n - 1; ++i)
    {
      if (differences.find(i) == differences.end())
      {
        healthy = false;
        printf("Not jolly\n");
        break;
      }
    }
    if (healthy)
    {
      printf("Jolly\n");
    }
  }
}
