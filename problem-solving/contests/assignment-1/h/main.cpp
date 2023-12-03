#include <cstdio>
#include <deque>
#include <vector>

int main()
{
  while (true)
  {
    int n;
    scanf("%d", &n);
    if (n == 0)
      break;
    std::deque<int> dq;
    for (int i = 1; i <= n; ++i)
      dq.push_back(i);
    std::vector<int> discarded;
    while (dq.size() >= 2)
    {
      discarded.push_back(dq.front());
      dq.pop_front();
      dq.push_back(dq.front());
      dq.pop_front();
    }
    printf("Discarded cards:%c", " \n"[discarded.size() == 0]);
    int s = discarded.size();
    for (int i = 0; i < s; ++i)
      printf("%d%s", discarded[i], i == s - 1 ? "\n" : ", ");
    printf("Remaining card: %d\n", dq.front());
  }
}
