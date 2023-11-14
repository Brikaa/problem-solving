/*
k: admissibility threshold
recipe: l, r -> temperature range
question: a, b -> how many admissible temps fall within this range

1 1 1 2 2 1 1
0 0 0 1 1 0 0
0 0 0 1 2 2 2
    ^     ^

p[i] = p[1] + p[2] + p[3] + ... + p[i - 1] + p[i]
p[j] = p[1] + p[2] + p[3] + ... + p[i] + p[i + 1] + ... + p[j]
*/
#include <stdio.h>

const int TEMP_MAX = 2e5 + 5;
int temps_recommendations[TEMP_MAX];

int main()
{
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);
  while (n--)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    temps_recommendations[l]++;
    temps_recommendations[r + 1]--;
  }
  for (int i = 1; i < TEMP_MAX; ++i)
  {
    temps_recommendations[i] += temps_recommendations[i - 1];
  }
  for (int i = 1; i < TEMP_MAX; ++i)
  {
    temps_recommendations[i] = temps_recommendations[i] >= k;
  }
  for (int i = 1; i < TEMP_MAX; ++i)
  {
    temps_recommendations[i] += temps_recommendations[i - 1];
  }
  while (q--)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", temps_recommendations[b] - temps_recommendations[a - 1]);
  }
}
