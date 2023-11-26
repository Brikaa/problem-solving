/*
n works
ai proficiency of worker i
Form a group containing the maximum number of workers while the difference between the minimum and maximum
proficiency is <= 5

ok
  - sliding window, if there exists a window whose max - min <= 5; return true

sort by proficiency
ok
*/
#include <cstdio>
#include <algorithm>

const int N = 2e5 + 5;
int n;
int workers[N];

bool ok(int req) {
  if (req > n)
    return false;
  for (int i = req; i <= n; ++i) {
    if (workers[i] - workers[i - req + 1] <= 5)
      return true;
  }
  return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", workers + i);
  std::sort(workers + 1, workers + n + 1);
  int l = 1;
  int r = n + 3;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%d\n", l);
  return 0;
}
