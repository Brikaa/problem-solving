/*
Suspicious activity is counted when someone answers a leaked question with difficulty d1 correctly
but fails to answer a not leaked question with difficulty d2 correctly and (d1 > d2).

For each answered correctly leaked question, count answered incorrectly not leaked question with lower difficulties
*/

#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    std::vector<int> leaked_difficulties;
    std::vector<int> not_leaked_difficulties;
    int n;
    scanf("%d", &n);
    while (n--)
    {
      int d;
      char leaked;
      char r;
      scanf("%d %c %c", &d, &leaked, &r);
      if (leaked == '0' && r == 'i')
        not_leaked_difficulties.push_back(d);
      else if (leaked == '1' && r == 'c')
        leaked_difficulties.push_back(d);
    }
    std::sort(not_leaked_difficulties.begin(), not_leaked_difficulties.end());
    long long ans = 0;
    for (auto d : leaked_difficulties)
    {
      ans += (std::lower_bound(
                  not_leaked_difficulties.begin(), not_leaked_difficulties.end(), d) -
              not_leaked_difficulties.begin());
    }
    printf("%lld\n", ans);
  }
  return 0;
}
