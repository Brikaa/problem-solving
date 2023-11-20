#include <cstdio>
#include <stack>

int main()
{
  std::stack<int> factors;
  int n, k;
  scanf("%d%d", &n, &k);
  int i = 2;
  while (i * i <= n)
  {
    if (n % i == 0)
    {
      factors.push(i);
      n /= i;
    }
    else
      ++i;
  }
  if (n > 1)
    factors.push(n);
  if ((int)factors.size() < k)
    printf("-1\n");
  else
  {
    while ((int)factors.size() > k)
    {
      int a = factors.top();
      factors.pop();
      int b = factors.top();
      factors.pop();
      factors.push(a * b);
    }
    while (!factors.empty())
    {
      printf("%d%c", factors.top(), " \n"[factors.size() == 1]);
      factors.pop();
    }
  }
}
