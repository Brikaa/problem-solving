/*
no smaller = no greater
no smaller = no greater - 1
no_greater - no_smaller = 0 or 1
2 4 5 3 1

no_greater - no_smaller = 2, need to increase smaller,
For each index in right, get the number of indices in left that calibrate the difference
diff_right + diff_left = 0 or 1
try to find diff_left = 0 - diff_right or 1 - diff_right
*/
#include <cstdio>
#include <unordered_map>

const int N = 2e5 + 5;
std::unordered_map<int, int> left_differences;
int numbers[N];

int main()
{
  int n, x;
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; ++i)
    scanf("%d", numbers + i);
  int idx = 0;
  for (; numbers[idx] != x; ++idx)
    ;
  int no_smaller = 0;
  int no_greater = 0;
  long long ans = 0;
  for (int i = idx - 1; ~i; --i)
  {
    no_smaller += numbers[i] < x;
    no_greater += numbers[i] > x;
    int diff_left = no_greater - no_smaller;
    ans += diff_left == 0 || diff_left == 1;
    ++left_differences[diff_left];
  }
  no_smaller = 0;
  no_greater = 0;
  for (int i = idx + 1; i < n; ++i)
  {
    no_smaller += numbers[i] < x;
    no_greater += numbers[i] > x;
    int diff_right = no_greater - no_smaller;
    ans += diff_right == 0 || diff_right == 1;
    ans += left_differences[-diff_right];
    ans += left_differences[1 - diff_right];
  }
  printf("%lld\n", ans + 1);
  return 0;
}
