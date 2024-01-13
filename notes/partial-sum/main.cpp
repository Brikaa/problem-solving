#include <stdio.h>

int main()
{
  int n = 6;
  int arr[n] = {1, 4, 6, 5, 2, 3};
  /*
    3
    0 3
    1 4
    3 5
    [2, 6, 8, 8, 4, 4]
  */
  int queries[n];
  for (int i = 0; i < n; ++i)
  {
    queries[i] = 0;
  }
  int no_queries;
  scanf("%d", &no_queries);
  while (no_queries--)
  {
    int start, end;
    scanf("%d %d", &start, &end);
    queries[start] += 1;
    if (end < n - 1)
    {
      queries[end + 1] -= 1;
    }
  }
  for (int i = 1; i < n; ++i)
  {
    queries[i] += queries[i - 1];
  }
  for (int i = 0; i < n; ++i)
  {
    arr[i] += queries[i];
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
