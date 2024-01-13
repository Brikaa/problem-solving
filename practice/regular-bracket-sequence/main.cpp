#include <stdio.h>

const int N = 1e6 + 5;
char brackets[N];

int main()
{
  scanf("%s", brackets);
  int s = 0;
  int b = 0;
  for (char *bracket = brackets; *bracket; ++bracket)
  {
    bool opening = *bracket == '(';
    bool closing = *bracket == ')' && b > 0;
    b += opening;
    b -= closing;
    s += opening + closing;
  }
  printf("%d\n", s - b);
  return 0;
}
