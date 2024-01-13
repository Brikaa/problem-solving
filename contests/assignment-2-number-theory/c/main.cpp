#include <cstdio>

int main()
{
  while (true)
  {
    int n;
    scanf("%d", &n);
    if (n == 0)
      break;
    int divisor = n;
    for (int i = 2; i * i <= n; ++i)
    {
      if (n % i == 0)
      {
        divisor = i;
        break;
      }
    }
    printf("%d\n", divisor);
  }
  return 0;
}
