/*
- If I am about to pop with nothing to pop
  - Don't count
- If I end up with positive number
  - Remove it from remaining size
*/
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
    if (*bracket == '(')
    {
      ++b;
      ++s;
    }
    else if (*bracket == ')' && b > 0)
    {
      --b;
      ++s;
    }
  }
  printf("%d\n", s - b);
  return 0;
}
