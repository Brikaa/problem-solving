#include <cstdio>

const int N = 103;
int matrix[N][N];

int main()
{
  while (true)
  {
    int n;
    scanf("%d", &n);
    if (n == 0)
      break;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        scanf("%d", &(matrix[i][j]));

    int problematic_column = -1;
    int problematic_row = -1;
    bool corrupt = false;
    for (int r = 0; r < n && !corrupt; ++r)
    {
      int sum = 0;
      for (int c = 0; c < n; ++c)
        sum += matrix[r][c];
      if (sum % 2 == 1 && problematic_row != -1)
        corrupt = true;
      else if (sum % 2 == 1)
        problematic_row = r;
    }
    for (int c = 0; c < n && !corrupt; ++c)
    {
      int sum = 0;
      for (int r = 0; r < n; ++r)
        sum += matrix[r][c];
      if (sum % 2 == 1 && problematic_column != -1)
        corrupt = true;
      else if (sum % 2 == 1)
        problematic_column = c;
    }
    if (!corrupt && ((problematic_column == -1) ^ (problematic_row == -1)))
      corrupt = true;
    if (corrupt)
      printf("Corrupt\n");
    else if (problematic_column != -1)
      printf("Change bit (%d,%d)\n", problematic_row + 1, problematic_column + 1);
    else
      printf("OK\n");
  }
}
